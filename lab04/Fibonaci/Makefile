CC = g++
TARGET = main
OBJ = fib.o main.o

CFLAGES = -c -Wall

$(TARGET) : $(OBJ)
	$(CC) -o $@ $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGES) $< -o $@

.PHONY:clean
clean:
	rm -f *.o $(TARGET)