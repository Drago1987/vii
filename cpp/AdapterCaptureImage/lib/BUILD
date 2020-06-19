cc_library(
    name = "libCaptureImage",
    visibility = ["//visibility:public"],
    srcs = [
        "CaptureImage.cpp",
    ],
    hdrs = ["CaptureImage.h"],
    copts= [
        '-Wcpp',
        ],
    linkopts= [
        '-lX11',
        ],
    includes = ["./"],
    deps = [
        "@opencv//:opencv",
        "//cpp/Logger/lib:libLogger",
        ],
)

