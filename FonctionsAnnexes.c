#include "FonctionsAnnexes.h"

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
			printf("Impossible d'empier car la pile est pleine\n");
			break;
	}
}
