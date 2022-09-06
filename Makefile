rns: rns.c node.o
	gcc rns.c node.c -o rns
node.o: node.c
	gcc node.c -o node.o
clean:
	rm -f *.o
	rm -f *~
	rm -f rns