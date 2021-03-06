#ifndef FILE_H
#define FILE_H

#include <stdlib.h>
#include "commun.h"

/**
 * \file file.h
 * \brief Fichier d'en tete des fonctions du fichier file.c
 * \author MALKA Laurent et GLADIEUX CUNHA Dimitri
 * \date 07 mars 2018
*/

/**
 * \struct file
 * \brief Cette structure de donnnee comprend : la taille maximale de la pile (entier), le nombre actuel d'elements dans la pile (entier), une liste contigue de type donnee_t (ce type est une redefinition du type float, int , double, etc)
*/

typedef struct file
{
	int 		TailleFile ;/*!< Taille maximale de notre file. */
	int 		NombreElementActuel ;/*!< Nombre d'elements actuellement dans la pile */
	donnee_t      *	FileElement ;/*!< Liste contigue de type donnee_t et de taille TailleFile */
	donnee_t      *	debut ; /*!< Pointeur du debut de la file (la ou on defile) */
	donnee_t      *	fin ;/*!< Pointeur de la fin de la file (la ou on enfile) */
}file_t ;

int TestFile() ;

int InitialiserFile(file_t **file, int taille) ;
void LibererFile(file_t ** file) ;
int EntreeFile(file_t **file, donnee_t valeur) ;
int SortieFile(file_t **file, donnee_t *ElementDefile) ;
int EstVideFile(file_t *file) ;

#endif
