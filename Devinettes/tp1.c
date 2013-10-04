#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bits.h"

/****************************************************************************************
							D�CLARATIONS DE FONCTIONS
****************************************************************************************/
/*
	NB_ALEATOIRE

	Cette fonction retourne un nombre al�atoire entier dans l'intervalle [min, max].
	Chaque valeur de l'intervalle poss�de la m�me probabilit� d'�tre choisi.

	PARAM�TRES :
		- min : La plus petite valeur pouvant �tre g�n�r�e (type : int).
		- max : La plus grande valeur pouvant �tre g�n�r�e (type : int).
				On suppose que min est plus petit ou �gal � max.
	
	VALEUR DE RETOUR : Un nombre dans l'intervalle [min, max] (type : int).
*/
int nb_aleatoire(int min, int max);

/*
	AFFICHER_INTRODUCTION

	Cette fonction affiche � l'utilisateur des instructions concernant le jeu et attend
	qu'il appuie sur une touche avant de continuer.
*/
void afficher_introduction(void);

/*
	INDICE_PROCHAIN_BIT_A_TESTER

	Cette fonction re�oit un nombre de 8 bits repr�sentant l'�tat de test de chaque 
	bit. La fonction choisit al�atoirement un bit n'ayant pas encore �t� test� et 
	retourne son indice.
*/
int indice_prochain_bit_a_tester(unsigned char car);
void afficher_grille_nombre(int indice);
int utilisateur_voit_son_nombre(void);


/****************************************************************************************
								FONCTION MAIN()
****************************************************************************************/
int main(void)
{
	unsigned char list_test_bit;
	unsigned char resultat_bit;
	int i;
	int indice;  /* Indice de bit a tester */
	int reponse_exist; /* Reponse de l'utilisateur */

	list_test_bit = 0;
	resultat_bit = 0;
	reponse_exist = 0;

	afficher_introduction();

	for(i=0;i<7;i++)
	{
		indice = indice_prochain_bit_a_tester(list_test_bit);
		list_test_bit = set_bit(list_test_bit, indice, 1);
		afficher_grille_nombre(indice);
		reponse_exist = utilisateur_voit_son_nombre();

		printf("\n");

		if(reponse_exist == 1)
		{
			resultat_bit = set_bit(resultat_bit, indice, 1);
		}	
	}

	printf("\n");
	printf("Le resultat :\n");
	printf("%i - (",resultat_bit);
	print_bits(resultat_bit);
	printf(")\n\n");

	return EXIT_SUCCESS;
}




/****************************************************************************************
								D�FINITIONS DE FONCTIONS
****************************************************************************************/
/*
	Explication de l'expression :
	- rand()
	  Une valeur enti�re dans l'intervalle [0, RAND_MAX].
	- rand() / (RAND_MAX + 0.0000001)
	  Une valeur r�elle dans l'intervalle [0, 1[.
	- rand() / (RAND_MAX + 0.0000001) * (max - min + 1)
	  Une valeur r�elle dans l'intervalle [0, max - min + 1[.
	- (int)(rand() / (RAND_MAX + 0.0000001) * (max - min + 1))
	  Une valeur enti�re dans l'intervalle [0, max - min].
	- min + (int)(rand() / (RAND_MAX + 0.0000001) * (max - min + 1))
	  Une valeur enti�re dans l'intervalle [min, max].
*/
int nb_aleatoire(int min, int max)
{
	return min + (int)(rand() / (RAND_MAX + 0.0000001) * (max - min + 1));
}

void afficher_introduction(void)
{
	printf("            *** MAGIE MAGIE MAGIE ***            \n\n");
	printf("choisissez un nombre entre 1 et 100 inclusivement.\n");
	printf("Repondez ensuite aux questions de l'ordinateur et\n");
	printf("celui-ce devinera le nombre que vous avez choisi!\n");
	printf("\n");
	printf("Press any key to continue . . . .");
	getchar();
}

int indice_prochain_bit_a_tester(unsigned char car)
{
	int indice;		/* */

	/* */
	do
	{
		indice = nb_aleatoire(0, NB_BITS_CHAR - 2);
	}while(get_bit(car, indice) == 1);

	return indice;
}



void afficher_grille_nombre(int indice)
{
	int i,j;
	unsigned char car;

	car = 1;

	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(get_bit(car, indice) == 1)
			{
				printf("%3i ", car);
			}
			else
			{
				printf("    ");
			}
			car++;
		}
		printf("\n");
	}
}

int utilisateur_voit_son_nombre(void)
{
	char reponse;

	printf("Voyez-vous votre nombre a l'ecran <o / n> ?");
	scanf("%c", &reponse);
	getchar();

	while(reponse != 'o' && reponse != 'O' && reponse != 'n' && reponse != 'N')
	{ 
		printf("Error : enter o ou n, svp");
		printf("Voyez-vous votre nombre a l'ecran <o / n> ?");
		scanf("%c", &reponse);
	}

	if(reponse == 'o' || reponse == 'O')
	{
		return 1;
	}
	else if(reponse == 'n' || reponse == 'N')
	{
		return 0;
	}
}

