const DATABASE = "fpga-vision-preview";
const STORE = "runs";

export async function openHistory() {
  if (!globalThis.indexedDB) throw new Error("This browser does not support history storage.");
  const database = await new Promise((resolve, reject) => {
    const request = indexedDB.open(DATABASE, 1);
    request.onupgradeneeded = () => request.result.createObjectStore(STORE, { keyPath: "id" });
    request.onsuccess = () => resolve(request.result);
    request.onerror = () => reject(request.error);
    request.onblocked = () => reject(new Error("History storage is open in another tab."));
  });
  database.onversionchange = () => database.close();

  function transaction(mode, operation) {
    return new Promise((resolve, reject) => {
      let value;
      const transaction = database.transaction(STORE, mode);
      const request = operation(transaction.objectStore(STORE));
      request.onsuccess = () => { value = request.result; };
      transaction.oncomplete = () => resolve(value);
      transaction.onerror = () => reject(transaction.error || request.error);
      transaction.onabort = () => reject(transaction.error || new Error("Could not save history."));
    });
  }

  return {
    all: () => transaction("readonly", store => store.getAll()),
    save: record => transaction("readwrite", store => store.put(record)),
    remove: id => transaction("readwrite", store => store.delete(id)),
    clear: () => transaction("readwrite", store => store.clear())
  };
}
