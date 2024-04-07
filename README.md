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

#### Loading a combination from a file

- **From terminal with echo**: The user can upload their own combination to the **secret-sequence.txt** file with the echo command as shown here:  `echo <color sequence> > secret_sequence.txt`.  
- **From the file itself**: The user can access the secret-sequence.txt from the same directory as (makefile OR bin/secret-sequence.txt). And from there they can write their own combination of 4 valid letters from the 6 colors.  