#ifndef PILE_H
#define PILE_H

#include <stdio.h>



;typedef struct pile
{
	int TaillePile ;
	int NombreElementActuel ;
	donnee_t * PileElement ;
}pile_t ;

int TestPile() ;

int InitialiserPile(pile_t **pile, int taille) ;
void LibererPile(pile_t ** pile) ;
int DepilerPile(pile_t **pile, donnee_t * ElementDepiler) ;
int EmpilerPile(pile_t **pile, donnee_t valeur) ;
int EstVidePile(pile_t *pile) ;
#endif
