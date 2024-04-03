# PROJET MASTERMIND

(explain the game)

## How it works

(explain the functioning of the program)

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
To access/enter the directory you aim for enter this: `cd [name_of_your_directory]/`
To return/leave from the current directory you are located on enter this: `cd ..`
~~~

## How to run the program

* First place yourself in the same directory as the Makefile and type this to compile: `make`  
* To run the program you must enter this in your terminal while you are placed in the directory **bin/**: `./main`  
* The program will ask you to input a number, you can chose any number you wish, after doing so, press **enter**.  
* To archive the program enter in the terminal: `make archive`  
* To clean the generated object files and executable enter in the terminal: `make clean`  
* To analyze the program's memory usage enter in the terminal: `make valgrind`  
* To generate a documentation with Doxygen enter in the terminal: `make doc`  
* To check the documentation, go to `doc/html/index.html` and open the file in a Web browser.  
* Enjoy!

### Documentation

This project's documentation is generated using Doxygen with **doxygen-awesome-css** theme and a basic hand-made custom.css providing a modern appearance for enhanced readability.

#### Prerequisites

Before generating the documentation, ensure you have the following prerequisites installed:

- **Doxygen**: Required for documentation generation.
- **Graphviz**: Necessary for diagram creation.

if you do not have them installed checkout these commands:

- **Ubuntu/Debian**
  

```bash
sudo apt install graphviz doxygen
```

- **Fedora/CentOS/Red Hat**
  

```bash
sudo dnf install graphviz doxygen
```

- **Archlinux**
  

```bash
sudo pacman -S graphviz doxygen
```

Additionnaly, the styling relies in `doxygen-awesome-css` theme and it is in fact, included in this repository as a submodule. To ensure it is available and generate the documentation correctly, please refer to *[Generating Documentation](#generating-documentation) step*

#### Generating Documentation

1. **Submodule Initialization**: Make sure the **doxygen-awesome-css** theme is initialized and updated executing the following command. **no need move into `docsrc` directory, the command takes apropiate action** :
  
  ```bash
  git submodule update --init --recursive
  ```
  
2. **Documentation Generation**: Utilize the Makefile command to produce HTML documentation in the **docs/** directory.
  
  ```bash
  make doc
  ```
  

#### Viewing Documentation

To view the generated documentation, follow these steps:

1. Navigate to `doc/html/`.
2. Open **index.html** with a web browser to access documentation, including detailed function descriptions, class overviews, and project workflows accompanied by diagrams.
