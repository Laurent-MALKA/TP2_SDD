exe : main.o file.o pile.o FonctionsAnnexes.o 
	gcc -o exe main.o file.o pile.o FonctionsAnnexes.o -g	
main.o : main.c 
	gcc main.c -g -Wall -Wextra -c -ansi -pedantic 
file.o : file.c file.h
	gcc file.c -g -Wall -Wextra -c -ansi -pedantic
pile.o : pile.c pile.h 
	gcc pile.c -g -Wall -Wextra -c -ansi -pedantic 
FonctionsAnnexes.o : FonctionsAnnexes.c FonctionsAnnexes.h
	gcc FonctionsAnnexes.c -g -Wall -Wextra -c -ansi -pedantic

clean :
	rm *.o
cleaner : clean
	rm exe
