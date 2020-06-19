cc_library(
    name = "opencv",
    srcs = glob(["lib/*.so*"]),
    hdrs = glob(["include/**/*.hpp", "include/**/*.h"]),
    includes = ["include", "include/opencv4"],
    linkopts = [
        "-ldl",
    ],
    visibility = ["//visibility:public"], 
    linkstatic = 1,
)