#include <stdlib.h>
#include "commun.h"
#include "pile.h"
int TestPile()
{
    pile_t *pile ;
	int CodeErreur ;
	CodeErreur = InitialiserPile(&pile, 2) ;
	donnee_t temp ;
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

int InitialiserPile(pile_t **pile, int taille)
{
	int CodeErreur = OK ;
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

void LibererPile(pile_t ** pile)
{
	free((*pile) -> PileElement) ;
	free((*pile)) ;
	(*pile) = NULL ;

}

int DepilerPile(pile_t **pile, donnee_t * ElementDepiler)
{
	int CodeErreur = OK ;
	if ( EstVidePile(*pile))
	{

		CodeErreur = DEPILER_IMPOSSIBLE ;
	}
	else
	{
		(*ElementDepiler) = (*pile) -> PileElement[(*pile) -> NombreElementActuel] ; // TODO : On met nul sur la valeur qu'on supprime ?
        (*pile) -> NombreElementActuel = ( (*pile) -> NombreElementActuel ) -1 ;
	}
	return CodeErreur ;

}

int EmpilerPile(pile_t **pile, donnee_t valeur)
{
	int CodeErreur = OK ;

    if ( (*pile) -> NombreElementActuel == ( (*pile) -> TaillePile) )
	{
		CodeErreur = EMPILER_IMPOSSIBLE ;
	}
	else
	{
		(*pile) -> NombreElementActuel ++ ;
		(*pile) -> PileElement[(*pile) -> NombreElementActuel] = valeur ;
	}
	return CodeErreur ;
}

int EstVidePile(pile_t *pile)
{
	return (pile -> NombreElementActuel == 0) ;
}
