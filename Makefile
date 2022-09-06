rns: node.o rns.c
	gcc rns.c node.c -o rns
node.o: node.c
	gcc node.c -o node.o
clean:
	rm -f *.o
	rm -f rns