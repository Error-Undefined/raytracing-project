# Define the compiler and the linker.
CXX = gcc
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags.
CFLAGS =  -Og -Wall -Wextra -pedantic-errors 
CFLAGS += -g
CFLAGS += $(DEPFLAGS)
LDFLAGS = -lm
LDFLAGS += -g

# Targets
PROGS = main
all: $(PROGS)

BIN_NAME = main
# Targets rely on implicit rules for compiling and linking

TARGET_O_FILES = main.o ./src/fileout.o ./src/vector3.o ./src/renderer.o ./src/hittable_list.o ./src/hit.o ./src/ray.o ./src/scatter.o

main: $(TARGET_O_FILES)
			$(CC) $(TARGET_O_FILES) -o $(BIN_NAME) $(LDFLAGS)
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
