#include <stdio.h>
#include <stdlib.h>

#include "bits.h"

void tester_count(void)
{
	unsigned char test_1 = 67;//en char C!
	unsigned char test_3 = 0;
	unsigned char test_4 = 255;

	printf("TEST : COUNT\n\n");

	printf("      Test #1 : 67 - 0100 0011\n");
	printf("      valeur_bit : 1\n");
	printf("      Valeur attendue : 3\n");
	printf("      Valeur obtenue  : %i\n\n", count(test_1, 1));

	printf("      Test #2 : 67 - 0100 0011\n");
	printf("      valeur_bit : 0\n");
	printf("      Valeur attendue : 5\n");
	printf("      Valeur obtenue  : %i\n\n", count(test_1, 0));

	printf("      Test #3 : 0 - 0000 0000\n");
	printf("      valeur_bit : 1\n");
	printf("      Valeur attendue : 0\n");
	printf("      Valeur obtenue  : %i\n\n", count(test_3, 1));

	printf("      Test #4 : 255 - 1111 1111\n");
	printf("      valeur_bit : 1\n");
	printf("      Valeur attendue : 8\n");
	printf("      Valeur obtenue  : %i\n\n", count(test_4, 1));
}

void tester_flip_bit(void)
{
	unsigned char test_1 = 67;

	printf("TEST : FLIP_BIT\n\n");

	printf("      Test #1 : 67 - 0100 0011\n");
	printf("      indice_bit : 0 \n");
	printf("      Valeur attendue : 66 (0100 0010)\n");
	printf("      Valeur obtenue  : %i \n\n", flip_bit(test_1, 0));

	printf("      Test #2 : 67 - 0100 0011\n");
	printf("      indice_bit : 6\n");
	printf("      Valeur attendue : 3 (0000 0011)\n");
	printf("      Valeur obtenue  : %i \n\n", flip_bit(test_1, 6));

	printf("      Test #3 : 67 - 0100 0011\n");
	printf("      indice_bit : 7\n");
	printf("      Valeur attendue : 195 (1100 0011)\n");
	printf("      Valeur obtenue  : %i \n\n", flip_bit(test_1, 7));

	printf("      Test #4 : 67 - 0100 0011\n");
	printf("      indice_bit : 3\n");
	printf("      Valeur attendue : 75 (0100 1011)\n");
	printf("      Valeur obtenue  : %i \n\n", flip_bit(test_1, 3));
}

void tester_flip_bits(void)
{
	unsigned char test_1 = 67;

	printf("TEST : FLIP_BITS\n\n");

	printf("      Test #1 : 67 - 0100 0011\n");
	printf("      indice_debut : 0 \n");
	printf("      indice_fin   : 7 \n");
	printf("      Valeur attendue : 188 (1011 1100) \n");
	printf("      Valeur obtenue  : %i \n\n", flip_bits(test_1, 0, 7));

	printf("      Test #2 : 67 - 0100 0011\n");
	printf("      indice_debut : 0 \n");
	printf("      indice_fin   : 3 \n");
	printf("      Valeur attendue : 76 (0100 1100) \n");
	printf("      Valeur obtenue  : %i \n\n", flip_bits(test_1, 0, 3));

	printf("      Test #3 : 67 - 0100 0011\n");
	printf("      indice_debut : 1 \n");
	printf("      indice_fin   : 5 \n");
	printf("      Valeur attendue : 125 (0111 1101)  \n");
	printf("      Valeur obtenue  : %i \n\n", flip_bits(test_1, 1, 5));
}

void tester_get_bit(void)
{
	unsigned char test_1 = 67;

	printf("TEST : GET_BIT\n\n");

	printf("      Test #1 : 67 - 0100 0011\n");
	printf("      indice_bit : 7 \n");
	printf("      Valeur attendue : 0 \n");
	printf("      Valeur obtenue  : %i \n\n", get_bit(test_1, 7));

	printf("      Test #2 : 67 - 0100 0011\n");
	printf("      indice_bit : 6 \n");
	printf("      Valeur attendue : 1 \n");
	printf("      Valeur obtenue  : %i \n\n", get_bit(test_1, 6));

	printf("      Test #3 : 67 - 0100 0011\n");
	printf("      indice_bit : 5 \n");
	printf("      Valeur attendue : 0 \n");
	printf("      Valeur obtenue  : %i \n\n", get_bit(test_1, 5));

	printf("      Test #4 : 67 - 0100 0011\n");
	printf("      indice_bit : 4 \n");
	printf("      Valeur attendue : 0 \n");
	printf("      Valeur obtenue  : %i \n\n", get_bit(test_1, 4));

	printf("      Test #5 : 67 - 0100 0011\n");
	printf("      indice_bit : 3 \n");
	printf("      Valeur attendue : 0 \n");
	printf("      Valeur obtenue  : %i \n\n", get_bit(test_1, 3));

	printf("      Test #6 : 67 - 0100 0011\n");
	printf("      indice_bit : 2 \n");
	printf("      Valeur attendue : 0 \n");
	printf("      Valeur obtenue  : %i \n\n", get_bit(test_1, 2));

	printf("      Test #7 : 67 - 0100 0011\n");
	printf("      indice_bit : 1 \n");
	printf("      Valeur attendue : 1 \n");
	printf("      Valeur obtenue  : %i \n\n", get_bit(test_1, 1));

	printf("      Test #8 : 67 - 0100 0011\n");
	printf("      indice_bit : 0 \n");
	printf("      Valeur attendue : 1 \n");
	printf("      Valeur obtenue  : %i \n\n", get_bit(test_1, 0));
}

void tester_nth_bit(void)
{
	unsigned char test_1 = 67;

	printf("TEST : NTH_BIT\n\n");

	printf("      Test #1 : 67 - 0100 0011\n");
	printf("      valeur_bit : 1 \n");
	printf("      nb_occurence : 1  \n");
	printf("      Valeur attendue : 0 \n");
	printf("      Valeur obtenue  : %i \n\n", nth_bit(test_1, 1, 1));

	printf("      Test #2 : 67 - 0100 0011\n");
	printf("      valeur_bit : 1 \n");
	printf("      nb_occurence : 2  \n");
	printf("      Valeur attendue : 1 \n");
	printf("      Valeur obtenue  : %i \n\n", nth_bit(test_1, 1, 2));

	printf("      Test #3 : 67 - 0100 0011\n");
	printf("      valeur_bit : 1 \n");
	printf("      nb_occurence : 3  \n");
	printf("      Valeur attendue : 6 \n");
	printf("      Valeur obtenue  : %i \n\n", nth_bit(test_1, 1, 3));

	printf("      Test #4 : 67 - 0100 0011\n");
	printf("      valeur_bit : 0 \n");
	printf("      nb_occurence : 1  \n");
	printf("      Valeur attendue : 2 \n");
	printf("      Valeur obtenue  : %i \n\n", nth_bit(test_1, 0, 1));

	printf("      Test #5 : 67 - 0100 0011\n");
	printf("      valeur_bit : 0 \n");
	printf("      nb_occurence : 5  \n");
	printf("      Valeur attendue : 7 \n");
	printf("      Valeur obtenue  : %i \n\n", nth_bit(test_1, 0, 5));

}

void tester_print_bits(void)
{
	unsigned char test_1 = 67;
	unsigned char test_2 = 63;
	unsigned char test_3 = 125;

	printf("TEST : PRINT_BIT\n\n");

	printf("      Test #1 : \n");
	printf("      Valeur attendue : 67 - 01000011 \n");
	printf("      Valeur obtenue  : 67 - ");
	print_bits(test_1);
	printf("\n\n");

	printf("      Test #2 : \n");
	printf("      Valeur attendue : 63 - 00111111 \n");
	printf("      Valeur obtenue  : 63 - ");
	print_bits(test_2);
	printf("\n\n");

	printf("      Test #3 : \n");
	printf("      Valeur attendue : 125 - 01111101 \n");
	printf("      Valeur obtenue  : 125 - ");
	print_bits(test_3);
	printf("\n\n");
}

void tester_set_bit(void)
{
	unsigned char test_1 = 67;

	printf("TEST : SET_BIT\n\n");

	printf("      Test #1 : 67 - 0100 0011\n");
	printf("      indice_bit : 0 \n");
	printf("      valeur_bit : 0 \n");
	printf("      Valeur attendue : 66 (0100 0010) \n");
	printf("      Valeur obtenue  : %i\n\n", set_bit(test_1, 0, 0));

	printf("      Test #2 : 67 - 0100 0011\n");
	printf("      indice_bit : 6 \n");
	printf("      valeur_bit : 0 \n");
	printf("      Valeur attendue : 3 (0000 0011) \n");
	printf("      Valeur obtenue  : %i \n\n", set_bit(test_1, 6, 0));

	printf("      Test #3 : 67 - 0100 0011\n");
	printf("      indice_bit : 7 \n");
	printf("      valeur_bit : 1 \n");
	printf("      Valeur attendue : 195 (1100 0011) \n");
	printf("      Valeur obtenue  : %i \n\n", set_bit(test_1, 7, 1));

	printf("      Test #4 : 67 - 0100 0011\n");
	printf("      indice_bit : 3 \n");
	printf("      valeur_bit : 1 \n");
	printf("      Valeur attendue : 75 (0100 1011) \n");
	printf("      Valeur obtenue  : %i \n\n", set_bit(test_1, 3, 1));
}

void tester_set_bits(void)
{
	unsigned char test_1 = 67;

	printf("TEST : SET_BITS\n\n");

	printf("      Test #1 : 67 - 0100 0011\n");
	printf("      indice_debut : 0  \n");
	printf("      indice_fin : 7  \n");
	printf("      valeur_bit : 1  \n");
	printf("      Valeur attendue : 255 (1111 1111) \n");
	printf("      Valeur obtenue  : %i \n\n", set_bits(test_1, 0, 7, 1));

	printf("      Test #2 : 67 - 0100 0011\n");
	printf("      indice_debut : 0  \n");
	printf("      indice_fin : 3  \n");
	printf("      valeur_bit : 1  \n");
	printf("      Valeur attendue : 79 (0100 1111) \n");
	printf("      Valeur obtenue  : %i \n\n", set_bits(test_1, 0, 3, 1));

	printf("      Test #3 : 67 - 0100 0011 \n");
	printf("      indice_debut : 0  \n");
	printf("      indice_fin : 7  \n");
	printf("      valeur_bit : 0  \n");
	printf("      Valeur attendue : 0 (0000 0000) \n");
	printf("      Valeur obtenue  : %i \n\n", set_bits(test_1, 0, 7, 0));

	printf("      Test #4 : 67 - 0100 0011\n");
	printf("      indice_debut : 1  \n");
	printf("      indice_fin : 5  \n");
	printf("      valeur_bit : 0  \n");
	printf("      Valeur attendue : 65 (0100 0001) \n");
	printf("      Valeur obtenue  : %i \n\n", set_bits(test_1, 1, 5, 0));
}

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