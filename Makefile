CC=gcc
OBJS +=linkedListMain.o linkedListSub.o
OBJS +=linkedListSub.h
main:$(OBJS)
	$(CC)  $^ -o $@
%.o:%.c
	$(CC) -c $^ -o $@

