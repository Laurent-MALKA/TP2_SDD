#include "commun.h"
#include "pile.h"
#include "file.h"
#include "FonctionsAnnexes.h"
/**
 * \file main.c
 * \brief Fonction principale de notre programme qui teste notre implementation de la file et de la pile
 * \author MALKA Laurent et GLADIEUX CUNHA Dimitri
 * \date 07 mars 2018
 */

/**
 * \fn int main(void)
 * \brief Fonction main du programme. L'utilisateur doit rentrer au moins 1 argument en ligne de commande qui est la taille maximale de la pile (le nombre rentre est suppose correct). Ensuite, on initialise une pile (voir la fonction).
 * Si l'initialisation est possible, on empile les valeurs rentrees en ligne de commande par l'utilisateur (suppose correct). Si la pile est non vide et que tout s'est bien passe, on va inverser notre pile, et on affiche le premier element
 * de la pile pour montrer que l'inversion s'est bien deroule. On libere la pile si son initilisation a put etre possible
 * \return CodeErreur Retourne 0 si tout s'est bien passe sinon autre chose
*/
int main(int argc, char ** argv)
{
    int CodeErreur = OK ;
    int i = 2 , temp ;
    pile_t * pile ;
    donnee_t Element ; 
    if (argc >= 2)
    {
	temp = atoi(argv[1]) ;
    	CodeErreur = InitialiserPile(&pile,temp) ;
	while ( (i < argc) && (CodeErreur == OK) )
	{
		temp = atoi(argv[i]) ;
    		CodeErreur = EmpilerPile(&pile,temp) ;
		i++ ;
	}
	if ( (!EstVidePile(pile)) && (CodeErreur == OK) )
	{
    		CodeErreur = InverserPile(&pile) ;
    		CodeErreur = DepilerPile(&pile,&Element) ; 
    		printf("%d",Element) ;
	}	
    	LibererPile(&pile) ;
    }
    else
    {
	CodeErreur = NOMBRE_ARGUMENTS_INCORRECT ;
    }
    AffichageCodeErreur(CodeErreur);
    return !(CodeErreur == OK) ;
}
