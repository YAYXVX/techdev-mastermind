#  $$\      $$\           $$\                  $$$$$$\  $$\ $$\
#  $$$\    $$$ |          $$ |                $$  __$$\ \__|$$ |
#  $$$$\  $$$$ | $$$$$$\  $$ |  $$\  $$$$$$\  $$ /  \__|$$\ $$ | $$$$$$\
#  $$\$$\$$ $$ | \____$$\ $$ | $$  |$$  __$$\ $$$$\     $$ |$$ |$$  __$$\
#  $$ \$$$  $$ | $$$$$$$ |$$$$$$  / $$$$$$$$ |$$  _|    $$ |$$ |$$$$$$$$ |
#  $$ |\$  /$$ |$$  __$$ |$$  _$$<  $$   ____|$$ |      $$ |$$ |$$   ____|
#  $$ | \_/ $$ |\$$$$$$$ |$$ | \$$\ \$$$$$$$\ $$ |      $$ |$$ |\$$$$$$$\
#  \__|     \__| \_______|\__|  \__| \_______|\__|      \__|\__| \_______|
#


#---------------------------
# Prerequisites
# --------------------------
# Variables
CC ?= gcc
CFLAGS ?= -Wall -g -Iinc -Ilib/inc
LDFLAGS ?= -Llib -lcolor
DOCGEN = doxygen
EXTRA_CFLAGS ?=
VG_FLAGS ?= --leak-check=full --show-leak-kinds=all --track-origins=yes
EXTRA_VG_FLAGS ?=
VG_FLAGS += $(EXTRA_VG_FLAGS)
GDB_FLAGS ?=

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
LIB_SRC_DIR = lib/src
LIB_OBJ_DIR = lib/obj
BIN_DIR = bin
INC_DIR = inc
DOC_DIR = doc
DOCSRC_DIR = docsrc
ARCHIVES_DIR = archives

# Source and object files
MAIN_SOURCES = $(wildcard $(SRC_DIR)/*.c)
MAIN_OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(MAIN_SOURCES))
LIB_SOURCES = $(wildcard $(LIB_SRC_DIR)/*.c)
LIB_OBJECTS = $(patsubst $(LIB_SRC_DIR)/%.c, $(LIB_OBJ_DIR)/%.o, $(LIB_SOURCES))

# Library name
LIBRARY = $(LIB_DIR)/libcolor.a

# Executable name
EXEC = $(BIN_DIR)/mastermind

# Directories to exclude for archiving
EXCLUDE_DIRS = $(ARCHIVES_DIR) $(DOC_DIR) $(BIN_DIR) $(OBJ_DIR) $(LIB_OBJ_DIR)
EXCLUDES = $(foreach dir, $(EXCLUDE_DIRS), --exclude='$(dir)')

# Archive file name
ARCHIVE_NAME = mastermind-project-$(shell date +%Y%m%d%H%M%S).tar




#------------------------
# Main logic of the Makefile
#------------------------
.PHONY: all help clean doc archive archive_compress valgrind gdb library




all: library $(EXEC)

library: $(LIBRARY)

$(LIBRARY): $(LIB_OBJECTS)
	ar -crv $@ $(LIB_OBJECTS)
	ranlib $@

$(LIB_OBJ_DIR)/%.o: $(LIB_SRC_DIR)/%.c | $(LIB_OBJ_DIR)
	$(CC) $(CFLAGS) $(EXTRA_CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(EXTRA_CFLAGS) -c $< -o $@

$(EXEC): $(MAIN_OBJECTS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR) $(LIB_OBJ_DIR) $(BIN_DIR):
	mkdir -p $@




doc:
	cd $(DOCSRC_DIR) && $(DOCGEN)

archive:
	mkdir -p $(ARCHIVES_DIR)
	tar $(EXCLUDES) -cvf $(ARCHIVES_DIR)/$(ARCHIVE_NAME) .

archive_compress:
	mkdir -p $(ARCHIVES_DIR)
	tar $(EXCLUDES) -czvf $(ARCHIVES_DIR)/$(ARCHIVE_NAME).gz .

clean:
	rm -rf $(OBJ_DIR)/*.o $(LIB_OBJ_DIR)/*.o $(BIN_DIR) $(LIB_DIR)/*.a

valgrind:
	valgrind $(VG_FLAGS) ./$(EXEC)

gdb:
	gdb $(GDB_FLAGS) ./$(EXEC)




help:
	@echo "Usage: make [target]..."
	@echo ""
	@echo "Targets:"
	@echo "  all                 Compile the software and the color library"
	@echo "  library             Compile only the color library"
	@echo "  clean               Remove generated files"
	@echo "  doc                 Generate documentation with Doxygen"
	@echo "  archive             Create an archive of the project"
	@echo "  archive_compress    Create a compressed archive of the project"
	@echo "  valgrind            Run Valgrind with default and additional flags"
	@echo "  gdb                 Run GDB with default and additional flags"
	@echo ""
	@echo "Variables:"
	@echo "  CC                  The C compiler to use"
	@echo "  CFLAGS              Additional options for the compiler"
	@echo "  EXTRA_CFLAGS        Additional options to add to CFLAGS"
	@echo "  LDFLAGS             Linker flags, e.g., for linking with libraries"
	@echo "  VG_FLAGS            Default flags for Valgrind"
	@echo "  EXTRA_VG_FLAGS      Additional options to add to VG_FLAGS"
	@echo "  GDB_FLAGS           Flags for GDB. You can add additional flags with ="
	@echo "  DOCGEN              The documentation generator command, using Doxygen"
	@echo ""
	@echo "For example, to compile with additional compiler flags, use: make EXTRA_CFLAGS='-DDEBUG'"
	@echo "To run Valgrind with extra flags, use: make valgrind EXTRA_VG_FLAGS='--trace-children=yes'"
	@echo "To create a compressed archive of your project, use: make archive_compress"

