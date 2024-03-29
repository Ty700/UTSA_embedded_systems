### Description:

This project involves creating a Morse code translator in C that controls an LED on the Milk-V Duo to blink Morse code representations of text inputs. The objective is to blend software development with hands-on hardware interaction, focusing on embedded systems programming, C language, and unit testing using Unity.

#### How to:
``` 
BUILD FOR HOST MACHINE:

python3 hostBuild.py make clean         <= Cleans host project

python3 hostBuild.py make prepare       <= Builds and runs host project WITHOUT UNIT TESTS OR DEBUG STATEMENTS
python3 hostBuild.py make verbose       <= Prepare + DEBUG STATEMENTS.

python3 hostBuild.py make test          <= Builds and runs host project WITH UNIT TESTS AND WITHOUT DEBUG STATMENTS
python3 hostBuild.py make verbose_test  <= test + DEBUG STATEMENTS

BUILD FOR TARGET (run each cmd):

python3 targetBuild.py cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=/app/milkv_duo.cmake ..
python3 targetBuild.py cmake --build .

```

