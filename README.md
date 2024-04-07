# PROJET MASTERMIND

## Introduction

This project implements the classic game Mastermind, demonstrating skills of group work with git, modular programming, documentation, and debugging in a C environment. Furthermore, the git commits act as a journal of the improving group networking skills acquired throughout the project.

## Usage Manual

To play the game, follow these steps:

1. Compile the program using the Makefile: `make all` or simply `make`.

2. Run the executable located in `bin/` directory: `./bin/mastermind`.

3. Follow the instructions to play the game *[How to run the program](#how-to-run-the-program)*.


### Makefile

Makefile contains a bunch of useful commands to improve your experience with the project, automating boring and repetitive tasks. Here are the commands to help you throughout your journey:

- `make clean`: Clean the auto generated files.

- `make all`: Compile the project source files into an executable placed in `bin/`

- `make doc`: Create a html formatted documentation in `doc/` directory.

- `make valgrind`: Debugging with valgrind command.

- `make gdb`: Debugging with gdb command.

- `make archive`: Archive the project.

- `make help`: Show the Makefile help.

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

### How to run the program

* The program will ask you to input a number, you can chose any number you wish, after doing so, press **enter**.
* The only thing that rests to do is to enjoy!

### Loading a combination from a file

- **From terminal with echo**: The user can upload their own combination to the **secret-sequence.txt** file with the echo command as shown here: `echo "color sequence" > secret_sequence.txt`.
- **From the file itself**: The user can access the secret-sequence.txt from the same directory as (makefile OR bin/secret-sequence.txt). And from there they can write their own combination of 4 valid letters from the 6 colors.

## Challenges Encountered

One of the main challenges was ensuring `read_code_from_file()` function to read the file. This was addressed using `getcwd()` from the library `unistd.h` as a part of our debugging process.

```bash
void read_code_from_file(char *sequence) {
    // char cwd[1024]; // Store current directory path
    // if (getcwd(cwd, sizeof(cwd)) != NULL) { // If directory path is retrieved
    //     printf("Current working dir: %s\n", cwd); // Print current directory
    // } else {
    //     perror("getcwd() error"); // Print error if getcwd fails
    // }
```
With this, we could easily locate the path the function was working on and change the file path accordingly.

## Debugging command

The memory debug was perfomed with `make valgrind`, nonetheless the explicit command is:

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/mastermind
```

If errors were identified, then it was used jointly with the -s option to show in detail the errors, using makefile please do:

```bash
make EXTRA_VG_FLAGS="-s" valgrind
```

Further to this, if the error was not totally detected then `make gdb` was used with breakpoints in the suspicious functions.

## Special Notes

- **Commits**: Our Git history demonstrates the growth of understanding git over time, the improvement of atomic commit messages, and the structure of the commits.

- **Future improvements**: It could incorporate additional features like improving the output or interaction with the user. For instance, a bunch of examples are:

  - Incorporate a new mode with 6 colours to enhance flexibility and user experience.

  - Ameliorate the output with a grafic interface using an specialized software (e.g `qte`).


Thank you for exploring the MASTERMIND project. Your feedback and contributions are welcomed!


