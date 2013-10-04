/****************************************************************************************
	Par  : Chuan DONG
	Date : 23/09/2013

	Ce module sert à tester chacune des fonctions du module bits
	
	- main : Cette fonction réalise l'ensemble des tests en appelant toutes les fonctions
			 de tests.
	- tester_count : Cette fonction teste la fonction count.
	- tester_flip_bit : Cette fonction teste la fonction flip_bit.
	- tester_flip_bits : Cette fonction teste la fonction flip_bits.
	- tester_get_bit : Cette fonction teste la fonction get_bit.
	- tester_nth_bit : Cette fonction teste la fonction nth_bit.
	- tester_print_bits : Cette fonction teste la fonction print_bits.
	- tester_set_bit : Cette fonction teste la fonction set_bit.
	- tester_set_bits : Cette fonction teste la fonction set_bits.
****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "bits.h"

/****************************************************************************************
							DÉCLARATIONS DE FONCTIONS
****************************************************************************************/
/*
	TESTER_COUNT

	Cette fonction teste la fonction count
*/
void tester_count(void);

/*
	TESTER_FILP_BIT

	Cette fonction teste la fonction flip_bit
*/
void tester_flip_bit(void);

/*
	TESTER_FILP_BITS

	Cette fonction teste la fonction flip_bits
*/
void tester_flip_bits(void);

/*
	TESTER_GET_BIT

	Cette fonction teste la fonction get_bit
*/
void tester_get_bit(void);


/*
	TESTER_NTH_BIT

	Cette fonction teste la fonction nth_bit
*/
void tester_nth_bit(void);

/*
	TESTER_PRINT_BITS

	Cette fonction teste la fonction print_bits
*/
void tester_print_bits(void);

/*
	TESTER_SET_BIT

	Cette fonction teste la fonction set_bit
*/
void tester_set_bit(void);

/*
	TESTER_SET_BITS

	Cette fonction teste la fonction set_bits
*/
void tester_set_bits(void);


/****************************************************************************************
								FONCTION MAIN()
****************************************************************************************/
int main(void)
{
	tester_count();
	tester_flip_bit();
	tester_flip_bits();
	tester_get_bit();
	tester_nth_bit();
	tester_print_bits();
	tester_set_bit();
	tester_set_bits();
}

/****************************************************************************************
								DÉFINITIONS DE FONCTIONS
****************************************************************************************/
void tester_count(void)
{
	/* Caractères à tester */
	unsigned char test_67 = 'C';  /*  67 - 0100 0011                         */
	unsigned char test_0 = NULL;  /*   0 - 0000 0000, Ici il n'est pas 'NUL' */
	unsigned char test_255 = 'ÿ'; /* 255 - 1111 1111                         */

	printf("%i", test_0);

	printf("TEST : COUNT\n\n");

	printf("      Test #1 : 67 - 0100 0011\n");
	printf("      valeur_bit : 1\n");
	printf("      Valeur attendue : 3\n");
	printf("      Valeur obtenue  : %i\n\n", count(test_67, 1));

	printf("      Test #2 : 67 - 0100 0011\n");
	printf("      valeur_bit : 0\n");
	printf("      Valeur attendue : 5\n");
	printf("      Valeur obtenue  : %i\n\n", count(test_67, 0));

	printf("      Test #3 : 0 - 0000 0000\n");
	printf("      valeur_bit : 1\n");
	printf("      Valeur attendue : 0\n");
	printf("      Valeur obtenue  : %i\n\n", count(test_0, 1));

	printf("      Test #4 : 255 - 1111 1111\n");
	printf("      valeur_bit : 1\n");
	printf("      Valeur attendue : 8\n");
	printf("      Valeur obtenue  : %i\n\n", count(test_255, 1));
}

void tester_flip_bit(void)
{
	/* Caractères à tester */
	unsigned char test_67 = 'C'; /* 67 - 0100 0011 */

	printf("TEST : FLIP_BIT\n\n");

	printf("      Test #1 : 67 - 0100 0011\n");
	printf("      indice_bit : 0 \n");
	printf("      Valeur attendue : 66 - 01000011 \n");
	printf("      Valeur obtenue  : %i - ", flip_bit(test_67, 0));
	print_bits(test_67);
	printf("\n\n");

	printf("      Test #2 : 67 - 0100 0011\n");
	printf("      indice_bit : 6\n");
	printf("      Valeur attendue : 3 - 00000011 \n");
	printf("      Valeur obtenue  : %i - ", flip_bit(test_67, 6));
	print_bits(flip_bit(test_67, 6));
	printf("\n\n");

	printf("      Test #3 : 67 - 0100 0011\n");
	printf("      indice_bit : 7\n");
	printf("      Valeur attendue : 195 - 11000011 \n");
	printf("      Valeur obtenue  : %i - ", flip_bit(test_67, 7));
	print_bits(flip_bit(test_67, 7));
	printf("\n\n");

	printf("      Test #4 : 67 - 0100 0011\n");
	printf("      indice_bit : 3\n");
	printf("      Valeur attendue : 75 - 01001011 \n");
	printf("      Valeur obtenue  : %i - ", flip_bit(test_67, 3));
	print_bits(flip_bit(test_67, 3));
	printf("\n\n");
}

void tester_flip_bits(void)
{
	/* Caractère à tester */
	unsigned char test_67 = 'C'; /* 67 - 0100 0011 */

	printf("TEST : FLIP_BITS\n\n");

	printf("      Test #1 : 67 - 0100 0011\n");
	printf("      indice_debut : 0 \n");
	printf("      indice_fin   : 7 \n");
	printf("      Valeur attendue : 188 - 10111100 \n");
	printf("      Valeur obtenue  : %i - ", flip_bits(test_67, 0, 7));
	print_bits(flip_bits(test_67, 0, 7));
	printf("\n\n");

	printf("      Test #2 : 67 - 0100 0011\n");
	printf("      indice_debut : 0 \n");
	printf("      indice_fin   : 3 \n");
	printf("      Valeur attendue : 76 - 01001100 \n");
	printf("      Valeur obtenue  : %i - ", flip_bits(test_67, 0, 3));
	print_bits(flip_bits(test_67, 0, 3));
	printf("\n\n");

	printf("      Test #3 : 67 - 0100 0011\n");
	printf("      indice_debut : 1 \n");
	printf("      indice_fin   : 5 \n");
	printf("      Valeur attendue : 125 - 01111101 \n");
	printf("      Valeur obtenue  : %i - ", flip_bits(test_67, 1, 5));
	print_bits(flip_bits(test_67, 1, 5));
	printf("\n\n");
}

void tester_get_bit(void)
{
	/* Caractère à tester */
	unsigned char test_67 = 'C'; /* 67 - 0100 0011 */

	printf("TEST : GET_BIT\n\n");

	printf("      Test #1 : 67 - 0100 0011\n");
	printf("      indice_bit : 7 \n");
	printf("      Valeur attendue : 0 \n");
	printf("      Valeur obtenue  : %i \n\n", get_bit(test_67, 7));

	printf("      Test #2 : 67 - 0100 0011\n");
	printf("      indice_bit : 6 \n");
	printf("      Valeur attendue : 1 \n");
	printf("      Valeur obtenue  : %i \n\n", get_bit(test_67, 6));

	printf("      Test #3 : 67 - 0100 0011\n");
	printf("      indice_bit : 5 \n");
	printf("      Valeur attendue : 0 \n");
	printf("      Valeur obtenue  : %i \n\n", get_bit(test_67, 5));

	printf("      Test #4 : 67 - 0100 0011\n");
	printf("      indice_bit : 4 \n");
	printf("      Valeur attendue : 0 \n");
	printf("      Valeur obtenue  : %i \n\n", get_bit(test_67, 4));

	printf("      Test #5 : 67 - 0100 0011\n");
	printf("      indice_bit : 3 \n");
	printf("      Valeur attendue : 0 \n");
	printf("      Valeur obtenue  : %i \n\n", get_bit(test_67, 3));

	printf("      Test #6 : 67 - 0100 0011\n");
	printf("      indice_bit : 2 \n");
	printf("      Valeur attendue : 0 \n");
	printf("      Valeur obtenue  : %i \n\n", get_bit(test_67, 2));

	printf("      Test #7 : 67 - 0100 0011\n");
	printf("      indice_bit : 1 \n");
	printf("      Valeur attendue : 1 \n");
	printf("      Valeur obtenue  : %i \n\n", get_bit(test_67, 1));

	printf("      Test #8 : 67 - 0100 0011\n");
	printf("      indice_bit : 0 \n");
	printf("      Valeur attendue : 1 \n");
	printf("      Valeur obtenue  : %i \n\n", get_bit(test_67, 0));
}

void tester_nth_bit(void)
{
	/* Caractère à tester */
	unsigned char test_67 = 'C'; /* 67 - 0100 0011 */

	printf("TEST : NTH_BIT\n\n");

	printf("      Test #1 : 67 - 0100 0011\n");
	printf("      valeur_bit : 1 \n");
	printf("      nb_occurence : 1  \n");
	printf("      Valeur attendue : 0 \n");
	printf("      Valeur obtenue  : %i \n\n", nth_bit(test_67, 1, 1));

	printf("      Test #2 : 67 - 0100 0011\n");
	printf("      valeur_bit : 1 \n");
	printf("      nb_occurence : 2  \n");
	printf("      Valeur attendue : 1 \n");
	printf("      Valeur obtenue  : %i \n\n", nth_bit(test_67, 1, 2));

	printf("      Test #3 : 67 - 0100 0011\n");
	printf("      valeur_bit : 1 \n");
	printf("      nb_occurence : 3  \n");
	printf("      Valeur attendue : 6 \n");
	printf("      Valeur obtenue  : %i \n\n", nth_bit(test_67, 1, 3));

	printf("      Test #4 : 67 - 0100 0011\n");
	printf("      valeur_bit : 0 \n");
	printf("      nb_occurence : 1  \n");
	printf("      Valeur attendue : 2 \n");
	printf("      Valeur obtenue  : %i \n\n", nth_bit(test_67, 0, 1));

	printf("      Test #5 : 67 - 0100 0011\n");
	printf("      valeur_bit : 0 \n");
	printf("      nb_occurence : 5  \n");
	printf("      Valeur attendue : 7 \n");
	printf("      Valeur obtenue  : %i \n\n", nth_bit(test_67, 0, 5));

}

void tester_print_bits(void)
{
	/* Caractères à tester */
	unsigned char test_67 = 'C';  /*  67 - 0100 0011 */
	unsigned char test_63 = '?';  /*  63 - 0011 1111 */
	unsigned char test_125 = '}'; /* 125 - 0111 1101 */

	printf("TEST : PRINT_BIT\n\n");

	printf("      Test #1 : \n");
	printf("      Valeur attendue : 67 - 01000011 \n");
	printf("      Valeur obtenue  : 67 - ");
	print_bits(test_67);
	printf("\n\n");

	printf("      Test #2 : \n");
	printf("      Valeur attendue : 63 - 00111111 \n");
	printf("      Valeur obtenue  : 63 - ");
	print_bits(test_63);
	printf("\n\n");

	printf("      Test #3 : \n");
	printf("      Valeur attendue : 125 - 01111101 \n");
	printf("      Valeur obtenue  : 125 - ");
	print_bits(test_125);
	printf("\n\n");
}

void tester_set_bit(void)
{
	/* Caractère à tester */
	unsigned char test_67 = 'C'; /* 67 - 0100 0011 */

	printf("TEST : SET_BIT\n\n");

	printf("      Test #1 : 67 - 0100 0011\n");
	printf("      indice_bit : 0 \n");
	printf("      valeur_bit : 0 \n");
	printf("      Valeur attendue : 66 - 01000010 \n");
	printf("      Valeur obtenue  : %i - ", set_bit(test_67, 0, 0));
	print_bits(set_bit(test_67, 0, 0));
	printf("\n\n");

	printf("      Test #2 : 67 - 0100 0011\n");
	printf("      indice_bit : 6 \n");
	printf("      valeur_bit : 0 \n");
	printf("      Valeur attendue : 3 - 00000011 \n");
	printf("      Valeur obtenue  : %i - ", set_bit(test_67, 6, 0));
	print_bits(set_bit(test_67, 6, 0));
	printf("\n\n");

	printf("      Test #3 : 67 - 0100 0011\n");
	printf("      indice_bit : 7 \n");
	printf("      valeur_bit : 1 \n");
	printf("      Valeur attendue : 195 - 11000011 \n");
	printf("      Valeur obtenue  : %i - ", set_bit(test_67, 7, 1));
	print_bits(set_bit(test_67, 7, 1));
	printf("\n\n");

	printf("      Test #4 : 67 - 0100 0011\n");
	printf("      indice_bit : 3 \n");
	printf("      valeur_bit : 1 \n");
	printf("      Valeur attendue : 75 - 01001011 \n");
	printf("      Valeur obtenue  : %i - ", set_bit(test_67, 3, 1));
	print_bits(set_bit(test_67, 3, 1));
	printf("\n\n");
}

void tester_set_bits(void)
{
	/* Caractère à tester */
	unsigned char test_67 = 'C'; /* 67 - 0100 0011 */

	printf("TEST : SET_BITS\n\n");

	printf("      Test #1 : 67 - 0100 0011\n");
	printf("      indice_debut : 0  \n");
	printf("      indice_fin : 7  \n");
	printf("      valeur_bit : 1  \n");
	printf("      Valeur attendue : 255 - 11111111 \n");
	printf("      Valeur obtenue  : %i - ", set_bits(test_67, 0, 7, 1));
	print_bits(set_bits(test_67, 0, 7, 1));
	printf("\n\n");

	printf("      Test #2 : 67 - 0100 0011\n");
	printf("      indice_debut : 0  \n");
	printf("      indice_fin : 3  \n");
	printf("      valeur_bit : 1  \n");
	printf("      Valeur attendue : 79 - 01001111 \n");
	printf("      Valeur obtenue  : %i - ", set_bits(test_67, 0, 3, 1));
	print_bits(set_bits(test_67, 0, 3, 1));
	printf("\n\n");

	printf("      Test #3 : 67 - 0100 0011 \n");
	printf("      indice_debut : 0  \n");
	printf("      indice_fin : 7  \n");
	printf("      valeur_bit : 0  \n");
	printf("      Valeur attendue : 0 - 00000000 \n");
	printf("      Valeur obtenue  : %i - ", set_bits(test_67, 0, 7, 0));
	print_bits(set_bits(test_67, 0, 7, 0));
	printf("\n\n");

	printf("      Test #4 : 67 - 0100 0011\n");
	printf("      indice_debut : 1  \n");
	printf("      indice_fin : 5  \n");
	printf("      valeur_bit : 0  \n");
	printf("      Valeur attendue : 65 - 01000001 \n");
	printf("      Valeur obtenue  : %i - ", set_bits(test_67, 1, 5, 0));
	print_bits(set_bits(test_67, 1, 5, 0));
	printf("\n\n");
}

