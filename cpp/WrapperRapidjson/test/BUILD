cc_test(
    name = "test_AdapterCardImageExtractor",
    srcs = ["test_AdapterCardImageExtractor.cpp"],
    copts = [
        "-Iexternal/gtest/include",
        "-std=c++17"
        ],
    data = ["//cpp/AdapterCardImageExtractor/images:step8_1447109970617_tcm1488-264382.jpg"],
    deps = [
        "//cpp/AdapterCardImageExtractor/lib:libAdapterCardImageExtractor",
        "@gtest//:gtest",
        "@gtest//:gtest_main"
    ],
)