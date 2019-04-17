#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int   creneau_libre(int tables[5][7][4], int j, int k)
{
    int i;

    i = 0;
    while (i < 5) //Pour savoir si un creneau est libre, on regarde toutes les tables
	//au creneau donne, si toutes sont prises le creneau est pris, sinon il est libre
    {
	if (tables[i][k][j] == 0)
	    return (1);
	i++;
    }
    return (0);
}

void  affichage_calendrier(int tables[5][7][4])
{
    int i;
    int j;
    int k;

    j = 0;
    printf("    | L | M | M | J | V | S | D \n");
    while (j < 4) //Compteur pour les jours
    {
        k = 0;
	printf("%dh ", 19 + j);
        while (k < 7) //compteur pour les heure
	{
	    if (creneau_libre(tables, j, k) == 1) //Si le creneau est libre on le laisse vide
		printf("|   ");
	    else
		printf("| X ");  // Sinon on indique qu'il est pris
	    k++;
	}
	printf("\n");
	j++;
    }
}

int main()
{
    int tables[5][7][4];
	//Declaration des 5 tables, sur 7 jours, de 19 a 23h. Un tableau a trois dimensions
    
    int i = 0;
    int j = 0;
    int k = 0;
	//Des compteurs betes
    int	  jour;
    int	  heure;
	//Les variables entrees par l utilisateur

    //Initialisation des tableaux avec des 0
    //Si 0 dans un creneau, il est libre. Si 1 il est pris.
  
    while (i < 5) // compteur pour les tables
    {
	j = 0;
	while (j < 7) //Compteur pour les jours
	{
	    k = 0;
	    while (k < 4) //compteur pour les heures
	    {
		tables[i][j][k] = 0;
		k++;
	    }
	    j++;
	}
	i++;
    }
    affichage_calendrier(tables);
	//Affiche le calendrier (captain obvious)
    while (1) //boucle pour redemander date/heure tant que l utilisateur entre des dates prises
    {
	printf("Entrez le jour et la date souhaitee\n");
	scanf("%d %d", &jour, &heure);
	    //Entree des variables par l utilisateur
	i = 0;
	while (i < 5 && i >= 0) //la on check sur toutes les tables si elles sont dispo
	    //la premiere dispo on la reserve, sinon on redemande a l utilisateur un date
	{
	    if (heure <= 22 && heure >= 19 && tables[i][jour - 1][heure - 19] == 0 &&
		tables[i][jour - 1][heure - 18] == 0)
	    {
		tables[i][jour - 1][heure - 19] = 1;
		tables[i][jour - 1][heure - 18] = 1;
		i = -1;
		break ; // si on a pu reserver un table, on redemande rien a l'utilisateur
	    }
	    i++;
	}
	if (i == -1)
	    break ;
	printf("Vous avez entre une mauvaise date, ou aucune table de disponible...\n");
	    //On passe ici que en cas d'erreur.
    }
}
