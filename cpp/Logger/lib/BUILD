cc_library(
    name = "libLogger",
    visibility = ["//visibility:public"],
    hdrs = [
        "LoggerInfo.hpp",
        "LoggerBase.hpp",
        "LoggerError.hpp",
        ],
    includes = ["./"],
    deps = [
        "@x86_64-linux-gnu//:boost_log",
        "@x86_64-linux-gnu//:boost_thread",
        "@x86_64-linux-gnu//:shared_pthread",
        "@x86_64-linux-gnu//:boost_system",
        ],
)

