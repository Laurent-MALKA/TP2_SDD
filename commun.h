#ifndef COMMUN_H
#define COMMUN_H

#include <stdio.h>

/**
 * \file commun.h
 * \brief Fichier d'en tete commun a tous les fichiers
 * \author MALKA Laurent et GLADIEUX CUNHA Dimitri
 * \date 07 mars 2018
*/

/**
 * \typedef donnee_t Permet de choisir quel type on veut dans notre structure de donnee
*/

typedef int donnee_t ;

/**
 * \enum CodesErreurs
 * \brief Enumeration des codes erreurs
*/

enum CodesErreurs
{
	ALLOCATION_IMPOSSIBLE, /*!< L'allocation en memoire est impossible */
	OK, /*!< Le programme s'est execute correctement. */
	DEPILER_IMPOSSIBLE, /*!< Impossible de depiler car la pile est vide */
	EMPILER_IMPOSSIBLE,/*!< Impossible de d'empiler car la pile est pleine */
	ENFILER_IMPOSSIBLE,/*!< Impossible de d'enfiler car la file est pleine */
	DEFILER_IMPOSSIBLE, /*!< Impossible de defiler car la file est vide */
	NOMBRE_ARGUMENTS_INCORRECT /*!< La taille de la structure de donnee n'est pas renseignee*/
};

#endif
