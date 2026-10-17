# Personal-to-lab synchronization

## A. Architecture and source of truth

```text
DyDuy/fpga-vision-enhancement main
  → guarded GitHub Actions job → SSH with LAB_SSH_KEY
  → validate lab main and preserve initial archive
  → commit-tree(personal tree, parents: lab head + personal head)
  → normal push to PIISAlab/fpga-vision-enhancement main
```

The personal repository is the source of truth. Each successful synchronization makes the lab's **tracked file tree exactly match** the personal snapshot, including additions, updates and deletions. Lab-only legacy paths therefore disappear from the new `main` tree; their commits remain reachable through the first parent and the archive branch. The two repositories keep different commit IDs. Implementation: [workflow, “Synchronize exact tree” step](../.github/workflows/sync_to_lab.yml).

## B. History and authentication

Git's `commit-tree` creates a commit from an existing tree and explicit parents. This workflow uses the lab head as first parent and personal head as second parent, retaining both histories without a content merge or force push. Each sync commit records `Personal-source: <full SHA>`. Reference: [Git `commit-tree`, Description and Options](https://git-scm.com/docs/git-commit-tree#_description); implementation: [workflow, commit creation and recognized-sync validation](../.github/workflows/sync_to_lab.yml).

The job gives `GITHUB_TOKEN` only `contents: read` and does not persist checkout credentials. Lab writes use the existing personal-repository secret **`LAB_SSH_KEY`**; its corresponding key must have write access to the lab repository, including permission to push workflow files under applicable repository rules. The key is not changed by this workflow. GitHub's built-in token is limited to its containing repository: [GitHub, About `GITHUB_TOKEN`](https://docs.github.com/en/actions/concepts/security/github_token#about-the-github_token). See [workflow, `permissions`, checkout and temporary SSH setup](../.github/workflows/sync_to_lab.yml).

SSH uses a temporary private-key file, restrictive permissions, cleanup on exit and strict verification against GitHub's pinned Ed25519 host key. It does not trust a runtime `ssh-keyscan` response. Pin source: [GitHub SSH key fingerprints, Ed25519 known-host entry](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/githubs-ssh-key-fingerprints); implementation: [workflow, temporary SSH setup](../.github/workflows/sync_to_lab.yml).

## C. Triggers and initial preservation

Pushes to personal `main` and manual **Actions → Sync personal main to lab → Run workflow** runs on `main` trigger synchronization. The job requires both repository `DyDuy/fpga-vision-enhancement` and ref `refs/heads/main`; its copy in the lab cannot run the sync job. Runs share a concurrency group, with running jobs not canceled. Checkout explicitly reads the latest personal `main` with full history. Configuration: [workflow, `on`, `concurrency`, `jobs.sync.if` and checkout](../.github/workflows/sync_to_lab.yml).

Initial synchronization accepts only this lab head:

```text
5ff38042e4a0ab0dc9f7cbb01101b70e52fd6336
```

Before changing lab `main`, it must preserve that commit at:

```text
refs/heads/archive/pre-personal-sync-2026-10-18
```

An existing archive must point to that exact commit. Archive creation uses a normal push and must succeed before the main push. Subsequent runs also require that archive to remain intact. These constants and checks are in [workflow, bootstrap/archive validation](../.github/workflows/sync_to_lab.yml).

## D. Operation, failures and recovery

After bootstrap, lab `main` must be a recognized sync commit: the expected subject, exactly two parents, first-parent ancestry from the pinned lab baseline, one `Personal-source` trailer equal to the second parent, and a tree identical to that parent's tree. The previous personal source must be an ancestor of the newly checked-out personal source. Matching source and tree produce a no-op only after these checks pass. Each successful run reports old lab, new lab and personal source IDs with commit links in the Actions summary. Implementation: [workflow, recognized-sync validation, ancestry check and summary](../.github/workflows/sync_to_lab.yml).

The workflow stops on a missing secret, unexpected bootstrap/archive head, manual lab commit, source rewind, authentication/rules failure or rejected normal push. It neither force-pushes nor resets a worktree. If the final push is rejected because lab `main` changed concurrently, inspect the new lab head before retrying. Implementation: [workflow, validation and normal pushes](../.github/workflows/sync_to_lab.yml).

Make project changes in personal `main`. For accidental lab-only changes, first preserve and review those commits, then bring intended content into the personal repository. Restoring synchronization after an unexpected lab head requires an explicit reviewed maintenance decision about the baseline/recognition policy; do not bypass the guard or force-push to make a run green. The archive and merge ancestry permit inspection or a separate recovery branch without rewriting lab history. Policy enforced by [workflow, bootstrap and recognized-sync guards](../.github/workflows/sync_to_lab.yml).

Runtime is Git, Bash and OpenSSH on `ubuntu-latest`, with checkout pinned to a reviewed commit. Full-history checkout and fetch costs grow with repository history; no build, test or artifact deployment runs in this job. Protected-branch rules and key permissions can prevent publication; this workflow does not alter them. Configuration and scope: [workflow, `runs-on`, checkout and sync step](../.github/workflows/sync_to_lab.yml).
