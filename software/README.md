# Software

```text
software/
├── hps/
│   ├── src/                one canonical viewer and memory benchmark
│   ├── include/            address contract
│   └── build.sh            ARM Linux hard-float cross-build
├── matlab/
│   └── Thuat_toan.m        original algorithm prototype
└── python/
    ├── image_hex.py        portable strict image/HEX conversion
    ├── build_fpga.py       fresh Qsys/Quartus pipeline
    ├── check_project.py    active-input and tooling checks
    ├── archive_quartus_outputs.py
    ├── verify_artifact_manifest.py
    ├── requirements.txt
    └── tests/              staging and conversion tests
```

All commands run from repository root. Generated output belongs under `build/`. HPS applications require matching target Linux and MMIO configuration. MATLAB is not a validated fixed-point reference of the active RTL. Old hard-coded Python scripts and nonidentical historical app copies are archived, not maintained as additional software entry points.
