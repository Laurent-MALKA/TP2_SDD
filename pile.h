#ifndef PILE_H
#define PILE_H

#include <stdio.h>

typedef struct pile
{
	int TaillePile ; 
	int NombreElementActuel ;
	void* PileElements ;
}pile_t

void InitialiserPile(pile_t **pile, int taille, char * type) ;
void LibererPile(pile_t ** pile) ;
void* DepilerPile(pile_t **pile, void* ElementDepiler) ;
void EmpilerPile(pile_t **pile, void valeur) ;
int EstVide(pile_t *pile) ;
#endif
