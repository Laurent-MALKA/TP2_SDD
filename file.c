#include "file.h"
/**
 * \file file.c
 * \brief Fonctions qui implementent la structure de donnees de la file
 * \author MALKA Laurent et GLADIEUX CUNHA Dimitri
 * \date 07 mars 2018
 */

 /**
 * \fn int TestFile()
 * \brief Fonction qui teste le bon fonctionnement de la file avec tous les cas (enumere dans le rapport)
 * \return CodeErreur Le code code d'erreur, qui retourne Ok (1) si tout s'est bien passe sinon le code d'erreur associe
*/
int TestFile()
{
    file_t * file ;
    int CodeErreur ;
    donnee_t temp ;
    CodeErreur = InitialiserFile(&file,10) ;
    if (CodeErreur == OK)
    {
        CodeErreur = EntreeFile(&file,3) ;
        if (CodeErreur == OK)
        {
            CodeErreur = EntreeFile(&file,4) ;

            if (CodeErreur == OK)
            {
                CodeErreur = EntreeFile(&file,5) ;
                if (CodeErreur == OK)
                {
                    CodeErreur = SortieFile(&file,&temp) ;
                    if (CodeErreur == OK)
                    {
                        CodeErreur = SortieFile(&file,&temp) ;
                        if (CodeErreur == OK)
                        {
                            CodeErreur = SortieFile(&file,&temp) ;
                        }
                    }
                }
            }
        }
    }
    return CodeErreur ;
}
/**
 * \fn int InitialiserFile(file_t **file, int taille)
 * \brief Fonction qui initialise la file (si l'allocation a ete possible) avec le nombre d'element actuel a 0, la taille maximale de la file et alloue une liste contigue (si l'allocation a ete possible) de taille max. Initialise les pointeuirs de debut et de fin de la liste contigue FileElement
 * \param **file Adresse de la file que l'on veut initialiser
 * \param taille Taille max de la file
 * \return CodeErreur Le code code d'erreur, qui retourne Ok (1) si la fonction a pu initialiser la file, sinon 0 (l'allocation dynamique n'a pas ete possible)
*/
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
            (*file) -> fin = &((*file) -> FileElement[taille-1]) ; 
        }
	}
	return CodeErreur ;
}
/**
 * \fn void LibererFile(file_t ** file)
 * \brief Fonction qui libere la place memoire de la file (la liste contigue plus les pointeurs debut,fin et la file)
 * \param **file Adresse de la file que l'on veut liberer
 */
void LibererFile(file_t ** file)
{
	free((*file) -> FileElement) ;
	free((*file)) ;
	(*file) = NULL ;
}
/**
 * \fn int EntreeFile(file_t **file, donnee_t valeur)
 * \brief Fonction qui enfile (insere un element insere dans la file, a l'endroit du pointeur fin). Remarque : Si la file est pleine on ne peut pas enfiler.
 * Principe : On recherche l'indice ou l'on doit inserer l'element avec l'adresse de fin - l'adresse de FileElement, et on applique le modulo de la taille de la file (pour revenir a FileElement si on a atteind la liste contigue).
 * \param **file Adresse de la file que l'on defiler
 * \param valeur Valeur que l'on veut ajouter dans notre file
 * \return CodeErreur Le code code d'erreur, qui retourne Ok (1) si la fonction a pu enfiler, sinon 4 (impossible de d'enfiler une file pleine)
*/
int EntreeFile(file_t **file, donnee_t valeur)
{
    int CodeErreur = OK ;
    int indFin = 0;
    if ( (*file) -> NombreElementActuel == (*file) -> TailleFile)
    {
        CodeErreur = ENFILER_IMPOSSIBLE ;
    }
    else
    {
		indFin = (int)((*file) -> fin - (*file) -> FileElement);
		(*file) -> fin = &((*file)->FileElement[(indFin+1)%(*file)->TailleFile]) ;
		(*file) -> fin[0] = valeur ;
        (*file) -> NombreElementActuel ++ ;
    }
    return CodeErreur ;

}
/**
 * \fn int SortieFile(file_t **file, donnee_t * *ElementDefiler)
 * \brief Fonction qui defile (enleve le premier element insere dans la file). Remarque : Si la file est vide on ne peut pas defiler. On peut recuperer l'element defiler.
 * Principe : On decale le pointeur de debut de 1 case sur la droite. Mais si on arrive au bout de Pile Element, alors il faut revenir au debut de ce dernier.
 * \param **file Adresse de la file que l'on defiler
 * \param *ElementDefiler Adresse ou l'on va stocker la valeur de l'element defiler
 * \return CodeErreur Le code code d'erreur, qui retourne Ok (1) si la fonction a pu defiler, sinon 5 (impossible de defiler une pile vide)
*/
int SortieFile(file_t **file, donnee_t *ElementDefiler)
{
    int CodeErreur = OK ;
    int indDeb ;
    if ( (*file) -> NombreElementActuel == 0)
    {
        CodeErreur = DEFILER_IMPOSSIBLE ;
    }
    else
    {
		(*file) -> NombreElementActuel -- ;
		if (ElementDefiler != NULL) 
		{
			(*ElementDefiler) =  *((*file) -> debut) ; 
		}
		indDeb = (int)((*file) -> debut - (*file) -> FileElement);
		(*file) -> debut = &((*file)->FileElement[(indDeb+1)%(*file)->TailleFile]) ;
    }
    return CodeErreur ;
}
/**
 * \fn int EstVidePile(pile_t *pile)
 * \brief Fonction qui informe si notre file est vide
 * \param *file file dont on veut savoir si elle est vide
 * \return booleen 1 si la pile est vide et autre chose si la file n'est pas vide
*/
int EstVideFile(file_t *file)
{
	return (file -> NombreElementActuel == 0) ;
}
