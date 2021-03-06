from sys import argv
from os import path, walk, makedirs
from shutil import rmtree
from argparse import ArgumentParser
from subprocess import run, PIPE

CC = "tools\\mwcceppc.exe"
CFLAGS = "-proc gekko -i . -I- -ir lib -ir lib/mato -ir include -ir src -ir include/loader -ir include/RevoSDK -ir include/STL -ir include/egg -ir include/RP -Cpp_exceptions off -enum int -O4,s -use_lmw_stmw on -fp hard -rostr -sdata 0 -sdata2 0 -msgstyle gcc"
SRC_DIR = "src/"
LIB_DIR = "lib/"
BUILD_DIR = "build/"
EXTERNALS_DIR = "externals/"
BASEROM_DIR = EXTERNALS_DIR + "baserom/"
LOADER_O_DIR = BUILD_DIR + "loader/"
MODULES_DIR = BUILD_DIR + "modules/"

def getLocalPath(path : str, dir : str) -> str:
    idx = path.find(dir)
    if (idx == -1): return path
    return path[idx : ]

def kamekLink(o_files : list, path : str, kamekArgs : str = "") -> None:
    # Create modules directory if necessary
    try:
        makedirs(MODULES_DIR)
    except FileExistsError: pass

    cmd = f"tools\\Kamek.exe {kamekArgs} {' '.join(o_files)} -externals={EXTERNALS_DIR}{args.region}.txt -output-kamek={path}"
    result = run(cmd, shell=True, stdout=PIPE, stderr=PIPE, universal_newlines=True)
    if (result.returncode != 0):
        print(result.returncode, result.stdout, result.stderr)
        exit()

def getBuildPath(path : str) -> str:
    if (path.find("src/")) != -1: return path.replace("src/", "build/")
    if (path.find("lib/")) != -1: return path.replace("lib/", "build/")
    return path

def compile(path : str) -> None:
    # Manipulate filepaths
    buildPath = path
    if (buildPath.endswith(".cpp")): buildPath = buildPath[0 : len(buildPath) - 4]
    if (buildPath.endswith(".c")): buildPath = buildPath[0 : len(buildPath) - 2]
    buildPath = getBuildPath(buildPath)
    buildPath = ''.join([buildPath, ".o"])
    buildPath = buildPath.replace("/", "\\")
    path = path.replace("/", "\\")

    # Make any required build directories
    try:
        makedirs(buildPath[0 : buildPath.rfind("\\")])
    except FileExistsError: pass

    # Compile
    cmd = f"{CC} {CFLAGS} -c -o {getLocalPath(buildPath, BUILD_DIR)} {getLocalPath(path, SRC_DIR)}"
    result = run(cmd, shell=True, stdout=PIPE, stderr=PIPE, universal_newlines=True)
    if (result.returncode != 0):
        print(result.returncode, result.stdout, result.stderr)
        exit()

if __name__ == "__main__":
    # Support "make clean"
    if (len(argv) == 2 and argv[1].lower() == "clean"):
        rmtree(BUILD_DIR, ignore_errors=True)
        exit()

    # Parse args
    parser = ArgumentParser()
    parser.add_argument("--region", choices=["USA"], required=True, help="Region to build")
    parser.add_argument("--define", required=False, help="Optional user define. Usually NDEBUG")
    args = parser.parse_args(argv[1:])

    # Chosen region
    CFLAGS = ''.join([CFLAGS, f" -DREGION_{args.region}"])

    # User define
    if (args.define != None): CFLAGS = ''.join([CFLAGS, f" -D{args.define}"])

    # Compile all C/C++ source
    print("\nCompiling libraries...")
    for _path, dir, files in walk(LIB_DIR, topdown=True):
        for file in files:
            if (file.endswith(".cpp") or file.endswith(".c")):
                local = path.join(_path, file).replace("\\", "/")
                print(f"\tCompiling {local}")
                compile(path.join(_path, file))
    print("\nCompiling source...")
    for _path, dir, files in walk(SRC_DIR, topdown=True):
        for file in files:
            if (file.endswith(".cpp") or file.endswith(".c")):
                local = path.join(_path, file).replace("\\", "/")
                print(f"\tCompiling {local}")
                compile(path.join(_path, file))

    # Link Kamek loader (DOL patch)
    kamek_o_files = []
    for _path, dir, files in walk(LOADER_O_DIR, topdown=True):
        for file in files:
            if (file.endswith(".o")):
                kamek_o_files.append(path.join(_path, file))
    if (len(kamek_o_files) > 0):
        print("\nLinking Kamek loader...")
        kamekLink(kamek_o_files, f"build/modules/Loader_{args.region}.bin",
        kamekArgs=f"-static=0x80001900 -input-dol={BASEROM_DIR}baserom_{args.region}.dol -output-dol={BUILD_DIR}main_{args.region}.dol")

    # Link executable
    game_o_files = []
    for _path, dir, files in walk(BUILD_DIR, topdown=True):
        for file in files:
            if (file.endswith(".o") and "build/loader" not in _path):
                game_o_files.append(path.join(_path, file))
    if (len(game_o_files) > 0):
        print("Linking executable...")
        kamekLink(game_o_files, f"build/modules/Main_{args.region}.bin")

    print("\nDone!")