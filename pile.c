#include "commun.h"
#include "pile.h" 
int InitialiserPile(pile_t **pile, int taille, char * type)
{
	int CodeErreur = OK ; 
	(*pile) = malloc(sizeof(pile_t)) ;
	if ( (*pile) == NULL)
	{
		CodeErreur = ALLOCATION_IMPOSSIBLE ;
	}
	else
	{
		(*pile) -> TaillePile = taille ;
		(*pile) -> NombreElementActuel = 0 ;
	        (*pile) -> PileElement = malloc (sizeof(type) * taille) ; 
		if ( (*pile) -> PileElement == NULL)
		{
			CodeErreur = ALLOCATION_IMPOSSIBLE ; 
			free(*pile) ; 
			(*pile) = NULL ;
		}
	}
}

void LibererPile(pile_t ** pile)
{
	free((*pile) -> PileElement) ; 
	free((*pile)) ; 
	(*pile) = NULL ;

}

int DepilerPile(pile_t **pile, void* ElementDepiler)
{
	int CodeErreur = OK ;
	if ( EstVide(pile))
	{
		CodeErreur = DEPILER_IMPOSSIBLE ; 
	}
	else
	{
		ElementDepiler = *(( (*pile) -> PileElement) + ( (*pile) -> NombreElementActuel) -1 ) ;
	      	(*pile) -> NombreElementActuel = ( (*pile) -> NombreElementActuel ) -1 ;
	}
	return CodeErreur ; 

}

int EmpilerPile(pile_t **pile, void valeur)
{
	int CodeErreur = OK ; 
       	if ( (*pile) -> NombreElementActuel == ( (*pile) -> TaillePile) )
	{
		CodeErreur = EMPILER_IMPOSSIBLE ; 
	}	
	else
	{
		(*pile) -> NombreElementActuel ++ ;
		(( (*pile) -> PileElement) + (*pile) -> NombreElementActuel) = valeur ; 
	}
	return CodeErreur ; 
}

int EstVide(pile_t *pile) 
{
	return (pile -> NombreElementActuel = 0) ;
}
