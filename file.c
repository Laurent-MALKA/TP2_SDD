#include <stdlib.h>
#include "commun.h"
#include "file.h"

int TestFile()
{
    file_t * file ;
    int CodeErreur ;
    CodeErreur = InitialiserFile(&file,3) ;
    printf("%d" ,EstVideFile(file)) ;
    return CodeErreur ;
}

int InitialiserFile(file_t **file, int taille)
{
    int CodeErreur = OK ;
	(*file) = NULL ;
	(*file) = malloc(sizeof(file_t)) ;

	if ( file == NULL)
	{
		CodeErreur = ALLOCATION_IMPOSSIBLE ;
	}
	else
	{
		(*file) -> TailleFile = taille ;
		(*file) -> NombreElementActuel = 0 ;
        (*file) -> FileElement = (donnee_t*) malloc(sizeof(donnee_t) * taille) ;
		if ( (*file) -> FileElement == NULL)
		{
			CodeErreur = ALLOCATION_IMPOSSIBLE ;
			free(*file) ;
			(*file) = NULL ;
		}
		else
        {
            (*file) -> debut = (*file) -> FileElement ;
            (*file) -> fin = (*file) -> FileElement+taille ; //TODO : a verif
        }
	}
	return CodeErreur ;
}
void LibererFile(file_t ** file)
{
	free((*file) -> FileElement) ;
	free((*file)) ;
	(*file) = NULL ;
}
int EntreeFile(file_t **file, donnee_t valeur)
{
    int CodeErreur = OK ;
    return CodeErreur ;

}
int SortieFile(file_t **file, donnee_t * valeur)
{
    int CodeErreur = OK ;
    return CodeErreur ;

}
int EstVideFile(file_t *file)
{
	return (file -> NombreElementActuel == 0) ;
}
