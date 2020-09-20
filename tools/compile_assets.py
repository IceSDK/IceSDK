import os
import sys


def Main():
    current = os.path.dirname(__file__)
    old_path = os.getcwd()

    platform = sys.argv[1]  # win, linux, osx
    build_dir = sys.argv[2]  # out dir
    target = sys.argv[3]

    executable = os.path.realpath("%s/%s/AssetCompiler" % (current, platform))

    print("%s %s %s/Assets" % (executable, "./Assets", build_dir))

    os.chdir(target)
    os.system("%s %s %s/Assets" % (executable, "./Assets", build_dir))
    os.chdir(old_path)


if __name__ == "__main__":
    Main()
