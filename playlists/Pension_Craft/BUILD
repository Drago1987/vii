filegroup(
    name = "url_playlist",
    srcs = glob(
        ["*.txt"],
    ),
    visibility = ["//visibility:public"],
)

py_binary(
    name = "download_playlist",
    srcs = ["//tools/python:download_playlist"],
    data = [":url_playlist"],
)
