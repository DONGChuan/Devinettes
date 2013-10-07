/****************************************************************************************
	Par  : Chuan DONG
	Date : 23/09/2013

	Le programme à produire consiste en un jeu de devinettes entre l'ordinateur et l'utilisateur. 
	L'ordinateur demande à l’utilisateur de choisir un nombre compris entre 1 et 100 et lui 
	annonce qu’il devinera ce nombre. C'est dans ce module que vous implémenterez le jeu de devinettes.

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
								DÉFINITIONS DE CONSTANTES
****************************************************************************************/
/* Les réponses de l'utilisateur */

#define RP_OUI_MIN 'o'
#define RP_OUI_MAJ 'O'
#define RP_NON_MIN 'n'
#define RP_NON_MAJ 'N'

/****************************************************************************************
							DECLARATIONS DE FONCTIONS
****************************************************************************************/
/*
	NB_ALEATOIRE

	Cette fonction retourne un nombre aléatoire entier dans l'intervalle [min, max].
	Chaque valeur de l'intervalle possèdee la même probabilité d'être choisi.

	PARAMÈTRES :
		- min : La plus petite valeur pouvant être générée (type : int).
		- max : La plus grande valeur pouvant être générée (type : int).
				On suppose que min est plus petit ou égal à max.
	
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

	Cette fonction reçoit un nombre de 8 bits représentant l'état de test de chaque bit. La 
	fonction choisit aléatoirement un bit n'ayant pas encore été testé et retourne son indice. 

	PARAMÈTRES :
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

	PARAMÈTRES :
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
	unsigned char liste_test_bit;     /* Liste des bits n'ont pas être testé */
	unsigned char resultat_devinette; /* Le résultat du devinette            */
	int i;                            /* Variable pour bloc FOR              */
	int indice;                       /* Indice de bit a tester              */
	int reponse_utilisateur;          /* Reponse de l'utilisateur            */

	/* Initialiser des variables */
	liste_test_bit = 0;
	resultat_devinette = 0;
	reponse_utilisateur = 0;

	/* Affichie l'introduction */
	afficher_introduction();

	for(i=0;i<NB_BITS_CHAR - 1;i++)
	{
		/* Obetient l'indice du bit à tester */
		indice = indice_prochain_bit_a_tester(liste_test_bit); 
		/* Mettre à jour la liste des bits à tester*/
		liste_test_bit = set_bit(liste_test_bit, indice, 1);
		/* Affiche à l'écran une grille de 10 lignes et 10 colonnes */
		afficher_grille_nombre(indice);
		/* Demande à l'utilisateur s’il voit son nombre à l’écran */
		reponse_utilisateur = utilisateur_voit_son_nombre();

		printf("\n");

		if(reponse_utilisateur == 1)
		{
			resultat_devinette = set_bit(resultat_devinette, indice, 1);
		}	
	}

	/* Affiche le résultat */
	printf("\n");
	printf("Le resultat :\n");
	printf("%i - (",resultat_devinette);
	print_bits(resultat_devinette);
	printf(")\n\n");

	return EXIT_SUCCESS;
}


/****************************************************************************************
								DEINITIONS DE FONCTIONS
****************************************************************************************/
/*
	Explication de l'expression :
	- rand()
	  Une valeur entière dans l'intervalle [0, RAND_MAX].
	- rand() / (RAND_MAX + 0.0000001)
	  Une valeur réelle dans l'intervalle [0, 1[.
	- rand() / (RAND_MAX + 0.0000001) * (max - min + 1)
	  Une valeur réelle dans l'intervalle [0, max - min + 1[.
	- (int)(rand() / (RAND_MAX + 0.0000001) * (max - min + 1))
	  Une valeur entière dans l'intervalle [0, max - min].
	- min + (int)(rand() / (RAND_MAX + 0.0000001) * (max - min + 1))
	  Une valeur entière dans l'intervalle [min, max].
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

	/* 
		Méthode 1 :
		On utilise directement la fonction nb_aleatoire() pour obtenir
		un numéro entre 0 et 6. Ensuite, on vérifie si le indice de ce 
		numéro a déjà être testé.
	*/
	do
	{       
		indice = nb_aleatoire(0, NB_BITS_CHAR - 2);
	}while(get_bit(car, indice) == 1);

	/*
		Méthode 2 :

		Ce méthode va obtenir directement l'indice pas encore être 
		testé en utilisant la fonction nth_bit()

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
				/* 4 espaces pour remplir les nombres n'ayant pas ce bit */
				printf("    "); 
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
	while(reponse != RP_OUI_MIN && reponse != RP_OUI_MAJ && reponse != RP_NON_MIN && reponse != RP_NON_MAJ)
	{ 
		printf("Error : enter o ou n, svp");
		printf("Voyez-vous votre nombre a l'ecran <o / n> ?");
		scanf("%c", &reponse);
	}

	if(reponse == RP_OUI_MIN || reponse == RP_OUI_MAJ) /* Si l'utilisateur voit ce nombre */
	{
		return 1;
	}
	else if(reponse == RP_NON_MIN || reponse == RP_NON_MAJ) /* Si l'utilisateur ne voit pas le nombre */
	{
		return 0;
	}
}


