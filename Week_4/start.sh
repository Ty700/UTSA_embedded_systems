#! /bin/bash

EXE_PATH="bin/"
EXE_NAME="Executable"

COMMANDS=(  "\033[33mRUNNING COMMAND: mkdir build\033[0m" 
            "\033[33mRUNNING COMMAND: cd build\033[0m" 
            "\033[33mRUNNING COMMAND: cmake ..\033[0m" 
            "\033[33mRUNNING COMMAND: cmake --build .\033[0m"
            "\033[33mRUNNING COMMAND: ./${EXE_PATH}${EXE_NAME}\033[0m"
        )

if [ ! -d "build" ]; then

    echo -e "${COMMANDS[0]}"
    mkdir build
    
    echo -e ${COMMANDS[1]}
    cd build

    echo -e ${COMMANDS[2]}
    cmake ..
    
    echo -e ${COMMANDS[3]}
    cmake --build .

    echo -e ${COMMANDS[4]}
    cd ..
    ./${EXE_PATH}${EXE_NAME}

else

    echo -e ${COMMANDS[1]}
    cd build

    echo -e ${COMMANDS[2]}
    cmake ..
    
    echo -e ${COMMANDS[3]}
    cmake --build .

    echo -e ${COMMANDS[4]}
    cd ..
    ./${EXE_PATH}${EXE_NAME}
fi