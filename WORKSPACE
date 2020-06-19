load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

new_local_repository(
    name = "opencv",
    path = "/home/dragomir/Workspace/vii/third_party/opencv/install",
    build_file = "opencv.BUILD",
)

new_local_repository(
    name = "x86_64-linux-gnu",
    path = "/usr/lib/x86_64-linux-gnu",
    build_file = "x86_64-linux-gnu.BUILD"
)

new_local_repository(
    name = "ssl",
    path = "/usr/lib/x86_64-linux-gnu",
    build_file = "ssl.BUILD"
)

new_local_repository(
    name = "bitcoin_common",
    path = "/home/dragomir/Workspace/business_model/bitcoin/src",
    build_file = "bitcoin_common.BUILD"
)


new_local_repository(
    name = "crypto",
    path = "/usr/lib/x86_64-linux-gnu",
    build_file = "crypto.BUILD"
)

git_repository(
    name = "gtest",
    remote = "https://github.com/google/googletest",
    branch = "v1.10.x",
)

http_archive(
    name = "openssl",
    url = "https://github.com/openssl/openssl/archive/openssl-3.0.0-alpha2.zip",
    sha256 = "9c7296389cf1e98c214c3b14188d09909c0fc020d9cae3127538218c3b2db148",
    build_file = "@//:openssl.BUILD",    
    strip_prefix = "openssl-openssl-3.0.0-alpha2",
)
