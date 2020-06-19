load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_import(
  name = "mylib",
  hdrs = glob(["*.h"]),
)

cc_binary(
    name = "OpenSSLAdapter",
    srcs = glob([
            "*.cpp",
           ]),
    deps = [
            ":mylib",
            "@ssl//:lib",
            "@crypto//:lib",
           ],
)

