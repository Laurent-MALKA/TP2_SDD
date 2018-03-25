#ifndef PILE_H
#define PILE_H

#include <stdio.h>
#include <stdlib.h>
#include "commun.h"

/**
 * \file pile.h
 * \brief Fichier d'en tete des fonctions du fichier pile.c
 * \author MALKA Laurent et GLADIEUX CUNHA Dimitri
 * \date 07 mars 2018
*/

/**
 * \struct pile
 * \brief Cette structure de donnnee comprend : la taille maximale de la pile (entier), le nombre actuel d'elements dans la pile (entier), une liste contigue de type donnee_t (ce type est une redefinition du type float, int , double, etc)
*/

typedef struct pile
{
	int 		TaillePile ; /*!< Taille maximale de notre pile. */
	int 		NombreElementActuel ;/*!< Nombre d'elements actuellement dans la pile */
	donnee_t      *	PileElement ;/*!< Liste contigue de type donnee_t et de taille TaillePile */
}pile_t ;

int TestPile() ;

int InitialiserPile(pile_t **pile, int taille) ;
void LibererPile(pile_t ** pile) ;
int DepilerPile(pile_t **pile, donnee_t * ElementDepile) ;
int EmpilerPile(pile_t **pile, donnee_t valeur) ;
int EstVidePile(pile_t *pile) ;
#endif
