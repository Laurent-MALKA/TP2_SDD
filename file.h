#ifndef FILE_H
#define FILE_H

;typedef struct file
{
	int TailleFile ;
	int NombreElementActuel ;
    donnee_t * FileElement ;
	donnee_t * debut ;
	donnee_t * fin ;
}file_t ;

int TestFile() ;

int InitialiserFile(file_t **file, int taille) ;
void LibererFile(file_t ** file) ;
int EntreeFile(file_t **file, donnee_t valeur) ;
int SortieFile(file_t **file, donnee_t * valeur) ;
int EstVideFile(file_t *file) ;

#endif
