# PROJET MASTERMIND

## Introduction

This project implements the classic game Mastermind, demonstrating skills of group work with git, modular programming, documentation, and debugging in a C environment. Furthermore, the git commits act as a journal of the improving group networking skills acquired throughout the project.

## Usage Manual

To play the game, follow these steps:

1. Compile the program using the Makefile: `make all` or simply `make`.
  
2. Run the executable located in `bin/` directory: `./bin/mastermind`.
  
3. Follow the instructions to play the game *[How to run the program](#how-to-run-the-program)*.


## Requirements

**Before heading to the project, please make sure that you have the needed tools in your system**:  

    GCC : The C compiler.
    Make : For generating files and combining the separated ones.
    Doxygen : To generate a documentation of the program.
    Valgrind : To analyse the memory usage of the program.

To configure these tools, employ the appropriate commands based on your operating system:

### Ubuntu/Debian

~~~{.sh}
sudo apt install gcc
sudo apt install make
sudo apt install doxygen
sudo apt install valgrind
~~~

### Fedora/CentOS/Red Hat

~~~{.sh}
sudo dnf install gcc
sudo dnf install make
sudo dnf install doxygen
sudo dnf install valgrind
~~~

### Archlinux

~~~{.sh}
sudo pacman -S gcc
sudo pacman -S make
sudo pacman -S doxygen
sudo pacman -S valgrind
~~~

## How to navigate through the Ubuntu Terminal

~~~{.sh}
To list all the available directories and files in your current position enter this: `ls`
To access/enter the directory you aim for enter this: `cd "name_of_your_directory"/`
To return/leave from the current directory you are located on enter this: `cd ..`
~~~

### Makefile

Makefile contains a bunch of useful commands to improve your experience with the project, automating boring and repetitive tasks. Here are the commands to help you throughout your journey:

- `make clean`: Clean the auto generated files.
  
- `make all`: Compile the project source files into an executable placed in `bin/`
  
- `make doc`: Create a html formatted documentation in `doc/` directory.

- `make valgrind`: Debugging with valgrind command.

- `make gdb`: Debugging with gdb command.

- `make archive`: Archive the project.
  
- `make help`: Show the Makefile help.


## How to run the program
  
* The program will ask you to input a number, you can chose any number you wish, after doing so, press **enter**.   
* The only thing that rests to do is to enjoy!

## Challenges Encountered

One of the main challenges was ensuring memory management efficiency and avoiding memory leaks, which was addressed using Valgrind as part of our debugging process.

....more explanation...

## Debugging command

The memory debug was perfomed with `make valgrind`, nonetheless the explicit command is:

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/fizzbuzz
```

If errors were identified, then it was used jointly with the -s option to show in detail the errors, using makefile please do:

```bash
make EXTRA_VG_FLAGS="-s" valgrind
```

Further to this, if the error was not totally detected then `make gdb` was used with breakpoints in the suspicious functions.

#### Known Issues

- Issues.

## Special Notes

- **Commits**: Our Git history demonstrates the growth of understanding git over time, the improvement of atomic commit messages, and the structure of the commits.
  
- **Future improvements**: It could incorporate additional features like improving the output or interaction with the user. For instance, a bunch of examples are:
  
  - example.
    
  - example.
    
  - example.
    

Thank you for exploring the MASTERMIND project. Your feedback and contributions are welcomed!

