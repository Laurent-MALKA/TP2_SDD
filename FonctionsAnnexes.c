#include "FonctionsAnnexes.h"

/**
 * \file FonctionsAnnexes.c
 * \brief Fonctions diverses necessaires au fonctionnement du programme
 * \author MALKA Laurent et GLADIEUX CUNHA Dimitri
 * \date 05 fevrier 2018
 */

/**
 * \fn void AffichageCodeErreur(int CodeErreur)
 * \brief Fonction qui affiche le code d'erreur genere par le programme
 * \param CodeErreur Code erreur que le programme a cree
*/

void AffichageCodeErreur(int CodeErreur)
{
	switch(CodeErreur)
	{
		case OK:
			printf("Aucune erreur\n");
			break;
		case DEPILER_IMPOSSIBLE:
			printf("Impossible de depiler car la pile est vide\n");
			break;
		case ALLOCATION_IMPOSSIBLE:
			printf("Impossible d'allouer la mémoire necessaire\n");
			break;
		case EMPILER_IMPOSSIBLE:
			printf("Impossible d'empiler car la pile est pleine\n");
			break;
        case ENFILER_IMPOSSIBLE:
            printf("Impossible d'enfiler car la file est pleine\n");
            break ;
        case DEFILER_IMPOSSIBLE:
            printf("Impossible de defiler car la file est vide\n");
            break ;

	}
}

int InverserPile(pile_t ** pile)
{
	int CodeErreur;
	file_t * file;
	CodeErreur = InitialiserFile(&file, (*pile)->TaillePile);
	donnee_t valeur;

	while(!EstVidePile(*pile))
	{
		DepilerPile(pile,&valeur);
		EntreeFile(&file,valeur);
	}
	while(!EstVideFile(file))
	{
		SortieFile(&file,&valeur);
		EmpilerPile(pile,valeur);
	}

	return CodeErreur;
}
