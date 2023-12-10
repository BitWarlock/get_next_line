SRCS = main.c src/get_next_line.c src/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
EXE = gnl

all: $(EXE)

$(EXE): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(EXE)

clean:
	@rm -rf $(EXE)

buffer:
ifdef BUFFER_SIZE
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRCS) -o $(EXE)
else
	@echo "Error: BUFFER_SIZE is not specified. Usage: make buffer BUFFER_SIZE=<size>"
	@exit 1
endif

run: $(EXE)
	./$(EXE)

.PHONY: clean buffer
