/****************************************************************************************
	Par  : Frédérick Henri
	Date : 09/08/2013

	Ce module offre diverses fonctions permettant de manipuler les bits d'un
	caractère. Les fonctions offertes sont :
	- get_bit    : Retourne la valeur d'un bit.
	- set_bit    : Fixe la valeur d'un bit.
	- set_bits   : Fixe la valeur des bits dans un intervalle donn?
	- flip_bit   : Inverse la valeur d'un bit.
	- flip_bits  : Inverse la valeur des bits dans un intervalle donn?
	- count      : Compte le nombre de bits valant 0 ou 1.
	- nth_bit    : Retourne l'indice du nieme bit valant 0 ou 1.
	- print_bits : Affiche les bits d'un caractère.
****************************************************************************************/




/*	Si la constante de compilation MODULE_BITS existe déj? alors on ne compile pas
	le code qui suit.
*/
#if !defined(MODULE_BITS)
#define MODULE_BITS




/****************************************************************************************
								DÉFINITIONS DE CONSTANTES
****************************************************************************************/
/* Le nombre de bits dans un char. */
#define NB_BITS_CHAR	(sizeof(char) * 8)




/****************************************************************************************
								DÉCLARATIONS DE FONCTIONS
****************************************************************************************/
/*
	GET_BIT

	Cette fonction retourne la valeur du ieme bit d'un caractère.

	PARAMÈTRES :
		- car        : Le caractère ?consulter (type : unsigned char).
		- indice_bit : L'indice du bit ?consulter (type : int).
					   On suppose que ce paramètre se trouve dans l'intervalle
					   [0, NB_BITS_CHAR[. Il est ?noter que le bit le moins
					   significatif porte l'indice 0.

	VALEUR DE RETOUR : 1 si le bit vaut 1 et 0 sinon (type : int).

	EXEMPLES D'APPEL :
		unsigned char c = 'C';				// On sait que 'C' vaut 67 (= 01000011).
		printf("%i\n", get_bit(c, 7));		// Affiche 0.
		printf("%i\n", get_bit(c, 6));		// Affiche 1.
		printf("%i\n", get_bit(c, 5));		// Affiche 0.
		printf("%i\n", get_bit(c, 4));		// Affiche 0.
		printf("%i\n", get_bit(c, 3));		// Affiche 0.
		printf("%i\n", get_bit(c, 2));		// Affiche 0.
		printf("%i\n", get_bit(c, 1));		// Affiche 1.
		printf("%i\n", get_bit(c, 0));		// Affiche 1.
*/
int get_bit(unsigned char car, int indice_bit);



/*
	SET_BIT

	Cette fonction retourne le caractère reçu o?le bit spécifi?a ét?
	fix??la valeur "valeur_bit".

	PARAMÈTRES :
		- car        : Le caractère ?modifier (type : unsigned char).
		- indice_bit : L'indice du bit ?modifier (type : int).
					   On suppose que ce paramètre se trouve dans l'intervalle
					   [0, NB_BITS_CHAR[. Il est ?noter que le bit le moins
					   significatif porte l'indice 0.
	    - valeur_bit : La valeur ?assigner au bit (type : int).
					   On suppose que ce paramètre se trouve dans l'intervalle [0, 1].

	VALEUR DE RETOUR : Le caractère reçu o?le bit spécifi?possède désormais la
					   valeur "valeur_bit" (type : unsigned char).

	EXEMPLES D'APPEL :
		unsigned char c = 'C';				// On sait que 'C' vaut 67 (= 01000011).
		c = set_bit(c, 0, 0);				 
		print_bits(c);					    // Affiche 01000010.

		c = 'A';							// On sait que 'A' vaut 65 (= 01000001).
		c = set_bit(c, 2, 1);
		print_bits(c);					    // Affiche 01000101.
*/
unsigned char set_bit(unsigned char car, int indice_bit, int valeur_bit);



/*
	SET_BITS

	Cette fonction retourne le caractère reçu o?les bits dans l'intervalle spécifi?
	ont ét?fix??la valeur "valeur_bit".

	PARAMÈTRES :
		- car          : Le caractère ?modifier (type : unsigned char).
		- indice_debut : L'indice du premier bit ?modifier (type : int).
					     On suppose que ce paramètre se trouve dans l'intervalle
					     [0, NB_BITS_CHAR[. Il est ?noter que le bit le moins
					     significatif porte l'indice 0.
		- indice_fin   : L'indice du dernier bit ?modifier (type : int).
					     On suppose que ce paramètre se trouve dans l'intervalle
					     [indice_debut, NB_BITS_CHAR[.
	    - valeur_bit   : La valeur ?assigner aux bits dans l'intervalle (type : int).
					     On suppose que ce paramètre se trouve dans l'intervalle [0, 1].

	VALEUR DE RETOUR : Le caractère reçu o?les bits dans l'intervalle spécifi?
					   possède désormais la valeur "valeur_bit" (type : unsigned char).

	EXEMPLES D'APPEL :
		unsigned char c = 'C';				// On sait que 'C' vaut 67 (= 01000011).
		c = set_bits(c, 0, 3, 1);
		print_bits(c);					    // Affiche 01001111.

		c = 'C';							// On sait que 'C' vaut 67 (= 01000011).
		c = set_bits(c, 0, 3, 0);
		print_bits(c);					    // Affiche 01000000.
*/
unsigned char set_bits(unsigned char car, int indice_debut, int indice_fin,
					   int valeur_bit);


/*
	FLIP_BIT

	Cette fonction retourne le caractère reçu o?l'on a invers?la valeur du
	bit spécifi?

	PARAMÈTRES :
		- car        : Le caractère ?modifier (type : unsigned char).
		- indice_bit : L'indice du bit ?inverser (type : int).
					   On suppose que ce paramètre se trouve dans l'intervalle
					   [0, NB_BITS_CHAR[. Il est ?noter que le bit le moins
					   significatif porte l'indice 0.

	VALEUR DE RETOUR : Le caractère reçu o?la valeur du bit spécifi?est
					   inversée (type : unsigned char).

	EXEMPLES D'APPEL :
		unsigned char c = 'C';				// On sait que 'C' vaut 67 (= 01000011).
		c = flip_bit(c, 0);				 
		print_bits(c);					    // Affiche 01000010.

		c = 'A';							// On sait que 'A' vaut 65 (= 01000001).
		c = flip_bit(c, 3);
		print_bits(c);					    // Affiche 01001001.
*/
unsigned char flip_bit(unsigned char car, int indice_bit);



/*
	FLIP_BITS

	Cette fonction retourne le caractère reçu o?l'on a invers?la valeur des
	bits dans l'intervalle spécifi?

	PARAMÈTRES :
		- car          : Le caractère ?modifier (type : unsigned char).
		- indice_debut : L'indice du premier bit ?modifier (type : int).
					     On suppose que ce paramètre se trouve dans l'intervalle
					     [0, NB_BITS_CHAR[. Il est ?noter que le bit le moins
					     significatif porte l'indice 0.
		- indice_fin   : L'indice du dernier bit ?modifier (type : int).
					     On suppose que ce paramètre se trouve dans l'intervalle
					     [indice_debut, NB_BITS_CHAR[.

	VALEUR DE RETOUR : Le caractère reçu o?les bits dans l'intervalle spécifi?
					   ont tous chang?de valeur (type : unsigned char).

	EXEMPLES D'APPEL :
		unsigned char c = 'C';				// On sait que 'C' vaut 67 (= 01000011).
		c = flip_bits(c, 0, 3);
		print_bits(c);					    // Affiche 01001100.

		c = 'C';							// On sait que 'C' vaut 67 (= 01000011).
		c = set_bits(c, 1, 6);
		print_bits(c);					    // Affiche 00111101.
*/
unsigned char flip_bits(unsigned char car, int indice_debut, int indice_fin);



/*
	COUNT

	Cette fonction retourne le nombre du caractère reçu valant "valeur_bit".

	PARAMÈTRES :
		- car        : Le caractère ?consulter (type : unsigned char).
	    - valeur_bit : La valeur ?dénombrer dans le caractère (type : int).
					   On suppose que ce paramètre se trouve dans l'intervalle [0, 1].

	VALEUR DE RETOUR : Le nombre de bits valant "valeur_bit" dans le
					   caractère reçu (type : int).
					   Cette valeur se trouvera dans l'intervalle [0, NB_BITS_CHAR].

	EXEMPLES D'APPEL :
		unsigned char c = 'C';				// On sait que 'C' vaut 67 (= 01000011).
		printf("%i\n", count(c, 1));		// Affiche 3.
		printf("%i\n", count(c, 0));		// Affiche 5.
*/
int count(unsigned char car, int valeur_bit);



/*
	NTH_BIT

	Cette fonction retourne l'indice du nieme bit dans un caractère dont la valeur
	correspond ?"valeur_bit".

	PARAMÈTRES :
		- car        : Le caractère ?consulter (type : unsigned char).
	    - valeur_bit : La valeur de bit recherchée (type : int).
					   On suppose que ce paramètre se trouve dans l'intervalle [0, 1].
		- n			 : L'occurrence cherchée (type : int).
					   On suppose que n se trouve dans l'intervalle
					   [1, count(car, valeur_bit)].

	VALEUR DE RETOUR : L'indice de la nième occurrence d'un bit valant "valeur_bit"
					   dans le caractère reçu (type : int).
					   Cette valeur se trouvera dans l'intervalle [0, NB_BITS_CHAR[.

	EXEMPLES D'APPEL :
		unsigned char c = 'C';				// On sait que 'C' vaut 67 (= 01000011).
		printf("%i\n", nth_bit(c, 1, 1));	// Affiche 0.
		printf("%i\n", nth_bit(c, 1, 2));	// Affiche 1.
		printf("%i\n", nth_bit(c, 1, 3));	// Affiche 6.
		printf("%i\n", nth_bit(c, 0, 1));	// Affiche 2.
		printf("%i\n", nth_bit(c, 0, 2));	// Affiche 3.
		printf("%i\n", nth_bit(c, 0, 3));	// Affiche 4.
		printf("%i\n", nth_bit(c, 0, 4));	// Affiche 5.
		printf("%i\n", nth_bit(c, 0, 5));	// Affiche 7.
*/
int nth_bit(unsigned char car, int valeur_bit, int n);



/*
	PRINT_BITS

	Cette fonction affiche les bits d'un caractère.

	PARAMÈTRES :
		- car        : Le caractère ?consulter (type : unsigned char).

	VALEUR DE RETOUR : Aucune.

	EXEMPLES D'APPEL :
		unsigned char c = 'C';			// On sait que 'C' vaut 67 (= 01000011).
		print_bits(c);					// Affiche 01000011.
*/
void print_bits(unsigned char car);	




#endif