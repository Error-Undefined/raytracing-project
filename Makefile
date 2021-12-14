# Define the compiler and the linker.
CXX = gcc
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags.
CFLAGS =  -Og -Wall -Wextra -pedantic-errors
CFLAGS += -g
CFLAGS += $(DEPFLAGS)
LDFLAGS = -g


# Targets
PROGS = main
all: $(PROGS)

# Targets rely on implicit rules for compiling and linking
main: main.o ./src/fileout.o

# Phony targets
.PHONY: all all_objs clean 

# Standard clean
clean:
	rm -f *.o $(PROGS)

# Clean .d files
depclean:
	rm -f *.d

fullclean:
	rm -f *.o *.d $(PROGS)
	rm -f ./src/*.o ./src/*.d

# Include the *.d files
SRC = $(wildcard *.c)
-include $(SRC:.c=.d)