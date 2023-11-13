import os

if os.path.isfile("src/pastelpch.h.gch") == False:
    os.system("g++ src/pastelpch.h")

if os.path.isdir("bin") == False:
    os.mkdir("bin")

# https://stackoverflow.com/a/2909998/18121288
cpp_dirs = []
for path, subdirs, files in os.walk("."):
    for name in files:
        if (name.endswith(".cpp")):
            cpp_dirs.append(path + "\\*.cpp")
            break

all_src_files = " ".join(cpp_dirs)
script = f"g++ {all_src_files} -Isrc/ -o bin/pastel.exe"
os.system(script)
