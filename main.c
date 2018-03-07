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
 * \brief Fonction main du programme //TODO : a expliquer
 * \return CodeErreur Retourne 0 si tout s'est bien passe sinon autre chose
*/
//TODO : On enfile depile avec les argv pour montrer ??
int main(int argc, char** argv;)
{
    int CodeErreur ;
    CodeErreur = TestPile() ;
    if (CodeErreur == OK)
    {
        AffichageCodeErreur(CodeErreur) ;
        CodeErreur = TestFile() ;
    }
    AffichageCodeErreur(CodeErreur) ;
    return !(CodeErreur == OK) ;

}
