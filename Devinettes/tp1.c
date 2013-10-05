/****************************************************************************************
	Par  : Chuan DONG
	Date : 23/09/2013

	C'est dans ce module que vous implémenterez le jeu de devinettes.

	- afficher_grille_nombre       : Cette fonction  affiche à l'écran une grille de 10 lignes et 10 colonnes.
	- afficher_introduction        : Cette fonction affiche à l'utilisateur des instructions concernant le jeu 
								     et attend qu'il appuie sur une touche avant de continuer.
	- indice_prochain_bit_a_tester : Cette fonction choisit aléatoirement un bit n'ayant pas encore été testé et 
	                                 retourne son indice.
	- main                         : Cette fonction initialise le générateur de nombres aléatoires.
	- nb_aléatoire                 : Cette fonction choisit aléatoirement et retourne un nombre entre ces deux bornes.
	- utilisateur_voit_son_nombre  : Cette fonction demande à l'utilisateur s’il voit son nombre à l’écran.
****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bits.h"

/****************************************************************************************
							D蒀LARATIONS DE FONCTIONS
****************************************************************************************/
/*
	NB_ALEATOIRE

	Cette fonction retourne un nombre al閍toire entier dans l'intervalle [min, max].
	Chaque valeur de l'intervalle poss鑔e la m阭e probabilit?d'阾re choisi.

	PARAM萒RES :
		- min : La plus petite valeur pouvant 阾re g閚閞閑 (type : int).
		- max : La plus grande valeur pouvant 阾re g閚閞閑 (type : int).
				On suppose que min est plus petit ou 間al ?max.
	
	VALEUR DE RETOUR : Un nombre dans l'intervalle [min, max] (type : int).
*/
int nb_aleatoire(int min, int max);

/*
	AFFICHER_INTRODUCTION

	Cette fonction affiche ?l'utilisateur des instructions concernant le jeu et attend
	qu'il appuie sur une touche avant de continuer.
*/
void afficher_introduction(void);

/*
	INDICE_PROCHAIN_BIT_A_TESTER

	Cette fonction re鏾it un nombre de 8 bits repr閟entant l'閠at de test de chaque 
	bit. La fonction choisit al閍toirement un bit n'ayant pas encore 閠?test?et 
	retourne son indice.

	PARAM萒RES :
		- char : Le caractere à tester (type : unsigned char).

	VALEUR DE RETOUR : Indice du bit à tester (type : int).
*/
int indice_prochain_bit_a_tester(unsigned char car);

/*
	AFFICHER_GRILLE_NOMBRE

	Cette fonction reçoit le bit actuellement testé. Elle affiche à l'écran une grille de 10
	lignes et 10 colonnes. Tous les nombres ayant un bit actif pour le bit actuellement testé
	sont affichés dans la grille. Tous les nombres n'ayant pas ce bit actif sont remplacés par
	3 espaces.

	PARAM萒RES :
		- indice : Le indice du bit actuellement testé (type : int).
*/
void afficher_grille_nombre(int indice);

/*
	UTILISATEUR_VOIT_SON_NOMBRE

	Cette fonction demande à l'utilisateur s’il voit son nombre à l’écran. La fonction
	redemande à l'utilisateur la question tant qu'il n'a pas entré l’un des caractères
	suivants : 'o', 'O', 'n' ou 'N'. La fonction retourne 1 lorsque l'utilisateur entre
	'o' ou 'O' et 0 dans le cas contraire.

	VALEUR DE RETOUR : Un nombre entier pour indiquer la réponse de l'utilisateur(type : int).
*/
int utilisateur_voit_son_nombre(void);

/****************************************************************************************
								FONCTION MAIN()
****************************************************************************************/
int main(void)
{
	unsigned char list_test_bit; /* List des bits indiquant les bits n'ont pas être testé */
	unsigned char resultat_bit;  /* Le résultat du devinette                              */
	int i;                       /* Variable pour bloc FOR                                */
	int indice;                  /* Indice de bit a tester                                */
	int reponse_exist;           /* Reponse de l'utilisateur                              */

	/* Initialiser des variables */
	list_test_bit = 0;
	resultat_bit = 0;
	reponse_exist = 0;

	/* Affichie l'introduction */
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

	/* Affiche le résultat */
	printf("\n");
	printf("Le resultat :\n");
	printf("%i - (",resultat_bit);
	print_bits(resultat_bit);
	printf(")\n\n");

	return EXIT_SUCCESS;
}


/****************************************************************************************
								D蒄INITIONS DE FONCTIONS
****************************************************************************************/
/*
	Explication de l'expression :
	- rand()
	  Une valeur enti鑢e dans l'intervalle [0, RAND_MAX].
	- rand() / (RAND_MAX + 0.0000001)
	  Une valeur r閑lle dans l'intervalle [0, 1[.
	- rand() / (RAND_MAX + 0.0000001) * (max - min + 1)
	  Une valeur r閑lle dans l'intervalle [0, max - min + 1[.
	- (int)(rand() / (RAND_MAX + 0.0000001) * (max - min + 1))
	  Une valeur enti鑢e dans l'intervalle [0, max - min].
	- min + (int)(rand() / (RAND_MAX + 0.0000001) * (max - min + 1))
	  Une valeur enti鑢e dans l'intervalle [min, max].
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
	getchar(); /* Une pause qui attend l'import quel input de l'utilisateur */
}

int indice_prochain_bit_a_tester(unsigned char car)
{
	int indice;	/* Indice du bit à tester */

	/* Méthode 1 */
	do
	{       
		indice = nb_aleatoire(0, NB_BITS_CHAR - 2);
	}while(get_bit(car, indice) == 1);

	/*
			Méthode 2 :
			indice = nth_bit(car, 0, nb_aleatoire(1, count(car, 0)));
	*/

	return indice;
}

void afficher_grille_nombre(int indice)
{
	int i,j;           /* Lignes et colonnes */
	unsigned char car; /* Caractère à tester */

	car = 1;

	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(get_bit(car, indice) == 1) /* Si la valeur du bit est 1   */
			{
				printf("%3i ", car); /* Chaque nombre s'occupe 3 espaces */
			}
			else
			{
				printf("    "); /* 4 espaces pour remplir les nombres n'ayant pas ce bit */
			}
			car++;
		}
		printf("\n");
	}
}

int utilisateur_voit_son_nombre(void)
{
	char reponse; /* Réponse de l'utilisateur */

	printf("Voyez-vous votre nombre a l'ecran <o / n> ?");
	scanf("%c", &reponse);
	getchar();

	/* 
		Si l'utilisateur entre d'autre réponse, on va relancer ce bloc 
		pour attendre une réponse correcte 
	*/
	while(reponse != 'o' && reponse != 'O' && reponse != 'n' && reponse != 'N')
	{ 
		printf("Error : enter o ou n, svp");
		printf("Voyez-vous votre nombre a l'ecran <o / n> ?");
		scanf("%c", &reponse);
	}

	if(reponse == 'o' || reponse == 'O') /* Si l'utilisateur voit ce nombre */
	{
		return 1;
	}
	else if(reponse == 'n' || reponse == 'N') /* Si l'utilisateur ne voit pas le nombre */
	{
		return 0;
	}
}

