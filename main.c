#include <stdio.h>

int main(void)
{
	pile_t *pile ;
	int CodeErreur ; 
	CodeErreur = InitialiserPile(&pile, 50 , "int") ;
	if (CodeErreur) 
	{
		printf("ff") ; 
	}	
	AffichageCodeErreur(CodeErreur) ; 
	return CodeErreur == OK;  
}

