CC=gcc
SRC=main.c find_op.c init.c add.c commit.c checkout.c log.c
OBJ=$(SRC:.c=.o)
EXEC=vcs
all: $(EXEC)
%.o: %.c header.h
	$(CC) -c $< -o $@
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -f $(OBJ)


