exe : main.o file.o pile.o 
	gcc -o exe main.o file.o pile.o -g
	
main.o : main.c 
	gcc main.c -g -Wall -Wextra -c
file.o : file.c file.h
	gcc file.c -g -Wall -Wextra -c 
pile.o : pile.c pile.h 
	gcc pile.c -g -Wall -Wextra -c  

clean :
	rm *.o
cleaner : clean
	rm exe
