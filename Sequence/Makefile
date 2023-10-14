CC=gcc
OBJS=sequence_sub_table.o sequence_main_table.o sequence_sub_table.h
main:$(OBJS)
	$(CC)  $^ -o $@
%.o:%.c
	$(CC) -c $^ -o $@

