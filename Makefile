TARGET	:= genericVector

CC	:= gcc
CFLAGS	:= -Wall -Werror


default: genericVector.o main.o
	$(CC) -o $(TARGET) $^

main.o: main.c
	$(CC) $(CFLAGS) -c $<

%.o: %.c
	$(CC) $(FLAGS) -c $<

clean:
	rm *.o $(TARGET)
