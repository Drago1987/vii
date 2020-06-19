load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_import(
  name = "mylib",
  hdrs = glob(["*.h"]),
  #static_library = "libmylib.a",
  #shared_library = "libmylib.so",
)

cc_binary(
    name = "UTCAdapter",
    srcs = glob([
            "*.cpp",
           ]),
    deps = [":mylib"],
)

