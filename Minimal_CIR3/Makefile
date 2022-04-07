# Configuration
FLAG = -g
CC = gcc
LIBS =

# Conditional configuration (we add ftd2xx.lib if we are on windows)
ifeq ($(OS),Windows_NT)
LIBS = ftd2xx.lib
endif


# Files
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

# Compilation
prog.exe: $(OBJ)
	$(CC) $(FLAG) $(OBJ) $(LIBS) -o $@

$(OBJ): %.o : %.c
	$(CC) $(FLAG) -c $< -o $@

# Clean the folder
clean:
	rm -rf *.exe *.o .zip  

# Create zip for automatic tests
zip: 
	zip test_files.zip *.c *.h -x main.c