{
    "targets": [
        {
            "target_name": "cpupower",
            "sources": [
                "cpupower.cc",
                "cpupower/yespower.h",
                "cpupower/yespower-opt.c",
                "cpupower/sha256.c",
            ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ],
            "cflags_cc": [
                "-std=c++0x"
            ],
        }
    ]
}
