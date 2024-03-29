### Description:

This project involves creating a Morse code translator in C that controls an LED on the Milk-V Duo to blink Morse code representations of text inputs. The objective is to blend software development with hands-on hardware interaction, focusing on embedded systems programming, C language, and unit testing using Unity.

#### How to:
``` 
FOR HOST MACHINE:

python3 hostBuild.py make clean     <= Cleans host project
python3 hostBuild.py make prepare   <= Builds and runs host project w/out Unit test and Debug statements 
python3 hostBuild.py make verbose   <= Builds and runs host project with Debug statements and w/out Unit test
python3 hostBuild.py make test      <= Builds and runs host project with Unit test and Debug statements 

FOR TARGET (run each cmd):

python3 targetBuild.py cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=/app/milkv_duo.cmake ..
python3 targetBuild.py cmake --build .

```

