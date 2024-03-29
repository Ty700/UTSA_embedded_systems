#!/usr/bin/env python3

# builds the project to run on host machine (x86)

import subprocess
import sys
import os

def ensure_build_directory():
    if not os.path.exists("build"):
        os.makedirs("build")

def clean():
    current_directory = os.getcwd()
    os.chdir(f"{current_directory}/bin")

    files_to_delete = ["Executable", "test"]
    
    for file_name in files_to_delete:
        if os.path.exists(file_name):
            subprocess.run(["rm", "-rf", file_name])
            print(f"Deleted {file_name}")
        else:
            print(f"{file_name} not found")

    os.chdir("..")
    subprocess.run(["sudo", "rm", "-rf", "build/"])

def prepare():
    ensure_build_directory()
    current_directory = os.getcwd()
    os.chdir(f"{current_directory}/build")
    subprocess.run(["cmake", ".."])
    subprocess.run(["cmake", "--build", "."])
    os.chdir("../bin")
    subprocess.run(["./Executable"])

def verbose():
    ensure_build_directory()
    current_directory = os.getcwd()
    os.chdir(f"{current_directory}/build")
    subprocess.run(["cmake", "..", "-DDEBUG=ON"])
    subprocess.run(["cmake", "--build", "."])
    os.chdir("../bin")
    subprocess.run(["./Executable"])

def test():
    ensure_build_directory()
    current_directory = os.getcwd()
    os.chdir(f"{current_directory}/build")
    subprocess.run(["cmake", "..", "-DCOMPILE_TEST=ON", "-DDEBUG=ON"])
    subprocess.run(["cmake", "--build", "."])
    os.chdir("../bin")
    subprocess.run(["./test"])


if __name__ == "__main__":
    if(sys.argv[2] == "clean"):
        clean()
    elif(sys.argv[2] == "prepare"):
        prepare()
    elif(sys.argv[2] == "verbose"):
        verbose()
    elif(sys.argv[2] == "test"):
        test()
    else:
        print("Usage Error: python3 hostBuild.py make <clean | prepare | verbose | test>")