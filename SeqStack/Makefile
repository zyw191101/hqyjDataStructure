CC = gcc
CFLAGS = -c

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

main: $(OBJS)
	$(CC) $^ -o $@
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@
.PHONY:clean
clean:
	rm -f $(OBJS)
