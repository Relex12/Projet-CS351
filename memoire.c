#include "memoire.h"

int lectureMem (int * mem, int adresse)
{
	if (adresse < 0)				// gestion d'erreur
	{
		printf("ADRESSE INTROUVABLE (< 0)\n");
		return -1;
	}
	else if (adresse >= MEMSIZE )		// gestion d'erreur
	{
		printf("ADRESSE INTROUVABLE (< MEMSIZE)\n");
		return -1;
	}
	else return mem[adresse];
}

void ecritureMem (int * mem, int adresse, int data)
{
	if (adresse < 0)				printf("ADRESSE INTROUVABLE (< 0)\n");			// gestion d'erreur
	else if (adresse >= MEMSIZE )	printf("ADRESSE INTROUVABLE (< MEMSIZE)\n");	// gestion d'erreur
	else	mem[adresse] =  data;
}

void afficheMem (int * mem)
{
	int i = 0;
	printf("*********** AFFICHAGE MEMOIRE ***********\n");
	while (i < 32)
	{
		printf("@ %d : %d\n", i, mem[i]);
		i++;
	}
}

#ifdef TESTS
int main(int argc, char const *argv[])
{
	for (int i = 0; i < 25; i++)		ecritureMem(memoire, i, i-5);
	afficheMem(memoire);
	for (int i = 0; i < 31; i=i+10)		printf("à l'adresse %d se trouve la donnée : %d\n", i, lectureMem(memoire, i));
	return 0;
}
#endif




/*		ANCIENNE VERSION PAR LISTE CHAINNEE
int lectureMem (liste *l, int adresse)
{
	element *e;
	e = *l;
	while (e!=NULL)
	{
		if (e->adresseOct == adresse)	return (e->data);
		e = e->suivant;
	}
	printf("ADRESSE INTROUVABLE\n");
	return -1;
}

int ecritureMem (liste* l, int data)
{
	element *e = (element* ) malloc(sizeof(element));
	e->data = data;
	e->suivant = *l;
	if (e->suivant == NULL)		e->adresseOct = 0;
	else 						e->adresseOct = (*l)->adresseOct + 1;
	*l = e;
	return (e->adresseOct);
}

void afficherListe (liste *l)
{
	element *e;
	e = *l;
	while (e!=NULL)
	{
		printf("data : %d \tadresse : %d\n", e->data, e->adresseOct);
		e = e->suivant;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	liste memoire = NULL;
	for (int i = 0; i < 25; i++)		ecritureMem(&memoire, i-5);
	afficherListe(&memoire);
	for (int i = 0; i < 31; i=i+10)		printf("valeur a l'adresse %d : %d\n", i, lectureMem(&memoire, i));
	return 0;
}
*/
