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
 * \param CodeErreur Le code erreur que le programme a cree
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
		case NOMBRE_ARGUMENTS_INCORRECT:
			printf("Nombre d'arguments incorrect\n") ;
			break ;

	}
}

/**
 * \fn int InverserPile(pile_t ** pile)
 * \brief Fonction qui inverse les valeurs d'une pile. Pour ce faire, on initialise une file, de la taille du nombre d'element de la pile. On depile chaque element de la pile et on l'insere dans la file. 
 Puis on defile chaque element de la file et on les rempile dans la pile.
 * \param **pile L'adresse de la pile que l'on veut inverser
 * \return CodeErreur Indique si le programme a pu realiser l'inversion : 1 si OK sinon autre chose
*/

int InverserPile(pile_t ** pile)
{
	int 		CodeErreur;
	file_t        * file;
	donnee_t	valeur;

	CodeErreur = InitialiserFile(&file, (*pile)->NombreElementActuel);
	if (CodeErreur == OK)
	{
		while( (!EstVidePile(*pile)) && (CodeErreur == OK))
		{
			CodeErreur = DepilerPile(pile,&valeur);
			if (CodeErreur == OK)
			{
				CodeErreur = EntreeFile(&file,valeur);
			}
		}
		if (CodeErreur == OK)
		{
			while( (!EstVideFile(file)) && (CodeErreur == OK))
			{
				CodeErreur = SortieFile(&file,&valeur);
				if (CodeErreur == OK) 
				{
					CodeErreur = EmpilerPile(pile,valeur);
				}
			}
		}
		LibererFile(&file) ;
	}
	return CodeErreur;
}
