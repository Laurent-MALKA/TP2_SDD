#include "pile.h"

/**
 * \file pile.c
 * \brief Fonctions qui implementent la structure de donnees de la pile
 * \author MALKA Laurent et GLADIEUX CUNHA Dimitri
 * \date 07 mars 2018
 */

 /**
 * \fn int TestPile()
 * \brief Fonction qui teste le bon fonctionnement de la pile avec tous les cas (enumere dans le rapport)
 * \return CodeErreur Le code code d'erreur, qui vaut OK (1) si tout s'est bien passe sinon le code d'erreur associe
*/

int TestPile()
{
	pile_t        *	pile ;
	int 		CodeErreur ;
	donnee_t 	temp ;

	CodeErreur = InitialiserPile(&pile, 5) ;
	if (CodeErreur == OK)
	{
		CodeErreur = EmpilerPile(&pile,5) ;
		if (CodeErreur == OK)
		{
			CodeErreur = EmpilerPile(&pile,2) ;
			if (CodeErreur == OK)
			{
				CodeErreur = DepilerPile(&pile,&temp) ;
				if (CodeErreur == OK)
				{
					CodeErreur = DepilerPile(&pile,&temp) ;
				}
			}
		}
	}
	LibererPile(&pile) ;
	return CodeErreur ;
}

/**
 * \fn int InitialiserPile(pile_t **pile, int taille)
 * \brief Fonction qui initialise la pile (si l'allocation est possible) avec le nombre d'elements actuel de la pile (= 0), la taille maximale de la pile et alloue une liste contigue de type donnee_t (et la libere si la liberation est impossible) de taille max.
 * \param **pile L'adresse de la pile que l'on veut initialiser
 * \param taille La taille maximale de la pile
 * \return CodeErreur Le code code d'erreur, qui vaut OK (1) si la fonction a pu initialiser la pile, sinon ALLOCATION_IMPOSSIBLE (0) (l'allocation dynamique n'a pas ete possible)
*/

int InitialiserPile(pile_t **pile, int taille)
{
	int  		CodeErreur = OK ;

	(*pile) = NULL ;
	(*pile) = malloc(sizeof(pile_t)) ;

	if ( pile == NULL)
	{

		CodeErreur = ALLOCATION_IMPOSSIBLE ;
	}
	else
	{
		(*pile) -> TaillePile = taille ;
		(*pile) -> NombreElementActuel = 0 ;
		(*pile) -> PileElement = (donnee_t*) malloc(sizeof(donnee_t) * taille) ;
		if ( (*pile) -> PileElement == NULL)
		{
			CodeErreur = ALLOCATION_IMPOSSIBLE ;
			free(*pile) ;
			(*pile) = NULL ;
		}
	}
	return CodeErreur ;
}

/**
 * \fn void LibererPile(pile_t ** pile)
 * \brief Fonction qui libere la place memoire de la pile (la liste contigue plus le pointeur pile), et met le pointeur de pile a NULL
 * \param **pile L'adresse de la pile que l'on veut liberer
*/

void LibererPile(pile_t ** pile)
{
	free((*pile) -> PileElement) ;
	free((*pile)) ;
	(*pile) = NULL ;
}

/**
 * \fn int DepilerPile(pile_t **pile, donnee_t * ElementDepile)
 * \brief Fonction qui depile (enleve le dernier element insere dans la pile). Remarque : Si la pile est vide on ne peut pas depiler. On peut recuperer l'element depile. Le nombre d'elements d'actuel decremente
 * \param **pile L'adresse de la pile que l'on depiler
 * \param *ElementDepile L'adresse ou l'on va stocker la valeur de l'element depile
 * \return CodeErreur Le code code d'erreur, qui vaut OK (1) si la fonction a pu depiler, sinon DEPILER_IMPOSSIBLE (2) (impossible de depiler une pile vide)
*/

int DepilerPile(pile_t **pile, donnee_t * ElementDepile)
{
	int			 CodeErreur = OK ;

	if ( EstVidePile(*pile))
	{

		CodeErreur = DEPILER_IMPOSSIBLE ;
	}
	else
	{
		(*pile) -> NombreElementActuel -- ;
		(*ElementDepile) = (*pile) -> PileElement[(*pile) -> NombreElementActuel] ; 
        
	}
	return CodeErreur ;
}

/**
 * \fn int EmpilerPile(pile_t **pile, donnee_t valeur)
 * \brief Fonction qui enpile (ajoute un element a la fin de la liste contigue). Remarque : Si la pile est pleine on ne peut pas empiler. Le nombre d'elements actuel s'incremente.
 * \param **pile L'adresse de la pile que l'on depiler
 * \param valeur Valeur que l'on veut ajouter dans notre pile
 * \return CodeErreur Le code code d'erreur, qui vaut OK (1) si la fonction a pu empiler, sinon EMPILER_IMPOSSIBLE (3) (impossible d'empiler une pile pleine)
*/

int EmpilerPile(pile_t **pile, donnee_t valeur)
{
	int			 CodeErreur = OK ;

    if ( (*pile) -> NombreElementActuel == ( (*pile) -> TaillePile) )
	{
		CodeErreur = EMPILER_IMPOSSIBLE ;
	}
	else
	{
		(*pile) -> PileElement[(*pile) -> NombreElementActuel] = valeur ;
		(*pile) -> NombreElementActuel ++ ;
	}
	return CodeErreur ;
}

/**
 * \fn int EstVidePile(pile_t *pile)
 * \brief Fonction qui informe si notre pile est vide. On regarde si le nombre d'elements actuel est egal a 0
 * \param *pile La pile dont on veut savoir si elle est vide
 * \return booleen 1 si la pile est vide et 0 si la pile n'est pas vide
*/

int EstVidePile(pile_t *pile)
{
	return (pile -> NombreElementActuel == 0) ;
}

