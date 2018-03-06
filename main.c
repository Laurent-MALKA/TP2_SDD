#include "commun.h"
#include "pile.h"
#include "file.h"
#include "FonctionsAnnexes.h"
int main(void)
{
    int CodeErreur ;
    CodeErreur = TestPile() ;
    if (CodeErreur == OK)
    {
        CodeErreur = TestFile() ;
    }
    AffichageCodeErreur(CodeErreur) ;
    return !(CodeErreur == OK) ;

}
