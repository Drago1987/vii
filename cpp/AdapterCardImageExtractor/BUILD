cc_binary(
  name = "main",
  visibility = ["//visibility:public"],
  srcs = [
      "main.cpp",
  ],
  data = [
    "//cpp/AdapterCardImageExtractor/images:step8_1447109970617_tcm1488-264382.jpg",
  ],
  deps = [
      "//cpp/AdapterCardImageExtractor/lib:libAdapterCardImageExtractor",
      "@x86_64-linux-gnu//:boost_log",
      "@x86_64-linux-gnu//:boost_thread",
      "@x86_64-linux-gnu//:shared_pthread",
      "@x86_64-linux-gnu//:boost_system",
      ],
  linkstatic = 1,
)