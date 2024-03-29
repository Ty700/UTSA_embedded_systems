### Description:

This project involves creating a Morse code translator in C that controls an LED on the Milk-V Duo to blink Morse code representations of text inputs. The objective is to blend software development with hands-on hardware interaction, focusing on embedded systems programming, C language, and unit testing using Unity.

### How to build a binary

```
USAGE:

 ./build.py -<ARGUMENT>
   Example:
       ./build.py -p <= Builds a binary that will run on host machine without debug statements nor runs unit tests
       ./build.py -c <= Will remove the binary (and cmake build) created by ./build.py -h

    Important Notes:
        - Only one argument is allowed.
        - Building for host also runs the binary.
        - You can find the built binary in /bin/

 ARGUEMENTS:

    CLEANING:

       -c
           Feature:
               [X] Removes all binaries
               [X] Removes build directory
 
    BUILDING FOR HOST:

       Features for HOST options:
            [X] x86 binary       
       -p 
           Features: 
                [ ] Unit Tests
                [ ] Debug Statements
       -d
           Features: 
                [ ] Unit Tests
                [X] Debug Statements
       -u
           Features: 
                [X] Unit Tests
                [ ] Debug Statements
       -v
           Features: 
                [X] Unit Tests
                [X] Debug Statements
   
    BUILDING FOR TARGET:

        -t
            Features:
                [ ] A cookie
                [X] A working RISC-V binary for MILK (maybe)
```

