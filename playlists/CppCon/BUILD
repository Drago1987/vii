filegroup(
    name = "url_playlist",
    srcs = glob(
        ["*.txt"],
    ),
    visibility = ["//visibility:public"],
)

py_binary(
    name = "download_playlist_py",
    srcs = ["//tools/python:download_playlist_py"],
    data = [":url_playlist"],
)

sh_binary(
    name = "download_playlist_sh",
    srcs = ["//tools/shell:download_playlist_sh"],
    data = [":url_playlist"],
)
