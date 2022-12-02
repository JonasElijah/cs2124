main: message.o queue.o main.c
	gcc main.c message.c queue.c -o main
message.o: message.c
	gcc -c message.c -o message.o
queue.o: queue.c
	gcc -c queue.c -o queue.o
clean:
	rm -f main
	rm -f *.o