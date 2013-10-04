/****************************************************************************************
	Par  : Chuan DONG
	Date : 23/09/2013

	Ce module est de définir des fonctions de bits.h
****************************************************************************************/

#include "bits.h"
#include <stdio.h>

/* count: Compte le nombre de bits valant 0 ou 1. */
int count(unsigned char car, int valeur_bit){

	int bit_in_char;       /* Valeur de chaque bit dans un caractère  */
	int nb_valeur_bit = 0; /* Le nombre de bits valant "valeur_bit"   */
	int i;                 /* Variable pour bloc FOR                  */

	/* NB_BITS_CHAR est Nombre de bits dans un char                   */ 
	for (i = 0; i < NB_BITS_CHAR; ++i) 
	{
		bit_in_char = (car >> i) & 1;  /* Obtenir un bit dans car     */

		/* S'il égale valeur_bit, on le compte                        */
		if(bit_in_char == valeur_bit)  
		{		
			++nb_valeur_bit;
		}
	}

	/* Retourner Le nombre de bits valant "valeur_bit" */
	return nb_valeur_bit; 
}

/* get_bit: Retourne la valeur d'un bit */
int get_bit(unsigned char car, int indice_bit)
{
	char car_filp = 1; /* Filtrage pour trouver la position d'un bit         */
	int valeur_bit;

	car &= (car_filp << indice_bit); /* Mettre tous les autres bits à 0      */
	car >>= indice_bit;              /* Déplacer le bit d'indice_bit à droit */
	valeur_bit = car&1;              /* Obtenir la valeur de ce bit          */

	return valeur_bit;
}

/* set_bit: Fixe la valeur d'un bit */
unsigned char set_bit(unsigned char car, int indice_bit, int valeur_bit)
{
	char car_changed;  /* Le un caractère modifié                    */
	char car_filp = 1; /* Filtrage pour trouver la position d'un bit */
	int valeur_bit_car;

	/* Obtenir la valeur du bit que l'on voudrais fixer              */
	valeur_bit_car = car >> indice_bit & 1; 

	car_changed = car;

	/* 
		Si la valeur du bit déja égale valeur_bit, on n'a pas besoins 
		de le modifier, donc sauter ce bloc. Sinon, on appele la
		fonction flip_bit() qui inverse la valeur d'un bit
	*/
	if(valeur_bit_car != valeur_bit)
	{
		car_changed = flip_bit(car, indice_bit);
	}

	return car_changed;
}

/* set_bits: Fixe la valeur des bits dans un intervalle donné */
unsigned char set_bits(unsigned char car, int indice_debut, int indice_fin, int valeur_bit)
{
	int i; /* Variable pour bloc FOR */

	/* 
		On fix les bits entre [indice_debut, indice_fin] 
		en rappelant la fonction set_bit() 
	*/
	for (i = indice_debut; i <= indice_fin; ++i) 
	{
		car = set_bit(car, i, valeur_bit);
	}

	return car;
}

/* flip_bit : Inverse la valeur d'un bit */
unsigned char flip_bit(unsigned char car, int indice_bit){

	char car_filp = 1; /* C'est pour trouver la position d'un bit */

	/*
		Si indice_bit est 4, Le resultat de 1 << 4 est 0001 0000
		Donc car ^ 0001 0000 va inverser la valeur de 5ieme bit
	*/
	car ^= (car_filp << indice_bit);

	return car;
}

/* flip_bits: Inverse la valeur des bits dans un intervalle donné */
unsigned char flip_bits(unsigned char car, int indice_debut, int indice_fin)
{
	int i; /* Variable pour bloc FOR */

	/* 
		On inverse les bits entre [indice_debut, indice_fin] 
		en rappelant la fonction flip_bit()
	*/
	for (i = indice_debut; i <= indice_fin; ++i) 
	{
		car = flip_bit(car, i);
	}

	return car;
}

/* nth_bit: Retourne l'indice du nieme bit valant 0 ou 1 */
int nth_bit(unsigned char car, int valeur_bit, int n)
{
	int i = 0;         /* Indice du bit                        */
	int count_bit = 0; /* Nombre de bit égalant valeur_bit     */

	/* Jusqu'à nieme bit valant 0 ou 1, on s'arrete de compter */
	while(count_bit != n) 
	{
		if(get_bit(car, i) == valeur_bit) 
		{
			count_bit++;
		}

		i++;
	}

	/* Indice du bit commence à 0 donc moins un pour obtenir l'indice */
	i--; 

	return i; 
}

/* print_bits : Affiche les bits d'un caractère */
void print_bits(unsigned char car)
{
	int i; /* Variable pour bloc FOR            */

	/* Afficher un caractère bit par bit        */
	for (i = NB_BITS_CHAR - 1; i >= 0 ; --i) 
	{
		printf("%i", get_bit(car, i)); 
	}
}