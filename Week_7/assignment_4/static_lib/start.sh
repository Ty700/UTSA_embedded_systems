#! /bin/bash

EXE_PATH="bin/"
EXE_NAME="Executable"

COMMANDS=(  "RUNNING COMMAND: mkdir build" 
            "RUNNING COMMAND: cd build" 
            "RUNNING COMMAND: cmake .." 
            "RUNNING COMMAND: cmake --build ."
            "RUNNING COMMAND: ./${EXE_PATH}${EXE_NAME}"
        )

if [ ! -d "build" ]; then
    echo "I am a program doing program things."
    echo ${COMMANDS[0]}
    mkdir build
    
    echo ${COMMANDS[1]}
    cd build

    echo ${COMMANDS[2]}
    cmake ..
    
    echo ${COMMANDS[3]}
    cmake --build .

    echo ${COMMANDS[4]}
    cd ..
    ./${EXE_PATH}${EXE_NAME}

else

    echo "Derp Derp Imma computa"
    echo ${COMMANDS[1]}
    cd build

    echo ${COMMANDS[2]}
    cmake ..
    
    echo ${COMMANDS[3]}
    cmake --build .

    echo ${COMMANDS[4]}
    cd ..
    ./${EXE_PATH}${EXE_NAME}
fi