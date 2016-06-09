# Compiles all C files in the src directory

CFLAGS= -Wall -Wextra -Werror -Ofast
LDFLAGS= -lpthread
CC=clang

ODIR= obj
SDIR= src
EDIR= bin

SRCS := $(wildcard $(SDIR)/*.c)
_PRGS := $(patsubst %.c,%,$(SRCS))
PRGS := $(patsubst $(SDIR)/%,$(EDIR)/%,$(_PRGS))
_OBJS := $(patsubst %,%.o,$(PRGS))
OBJS := $(patsubst $(EDIR)/%,$(ODIR)/%,$(_OBJS))

all : $(PRGS)

## Compile the object files

$(ODIR)/%.o : $(SDIR)/%.c
	$(CC) -c $< $(CFLAGS) -o $@

## Compile the executables

OBJ = $(patsubst $(EDIR)/%,$(ODIR)/%.o,$@)
$(PRGS): $(OBJS)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	$(RM) $(PRGS) $(ODIR)/*.o
