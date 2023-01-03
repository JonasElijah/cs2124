rns: node.o sim.o Util.o queue.c rns.c
	gcc rns.c node.c sim.c Util.c queue.c -o rns
node.o: node.c
	gcc -c node.c -o node.o
sim.o: sim.c
	gcc -c sim.c -o sim.o
Util.o: Util.c
	gcc -c Util.c -o Util.o
queue.o: queue.c
	gcc -c queue.c -o queue.o
clean:
	rm -f *.o
	rm -f rns
	
