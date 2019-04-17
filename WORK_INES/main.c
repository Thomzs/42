#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int **tables[5][7][4];
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
	j = 0
	while (j < 7) //Compteur pour les jours
	{
	    k = 0;
	    while (j < 4) //compteur pour les heures
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
	scanf("Entrez le jour et l'heure souhaitee\n%d %d", &jour, &heure);
	    //Entree des variables par l utilisateur
	i = 0;
	while (i < 5) //la on check sur toutes les tables si elles sont dispo
	    //la premiere dispo on la reserve, sinon on redemande a l utilisateur un date
	{
	    if (heure =< 22 && date => 19 && table[i][jour][heure] == 0 &&
		table[i][jour][heure + 1] == 0)
	    {
		table[i][jour][heure] = 1;
		table[i][jour][heure + 1] = 1;
		break ; // si on a pu reserver un table, on redemande rien a l'utilisateur
	    }
	    k++;
	}
	printf("Vous avez entre une mauvaise date, ou aucune table de disponible...\n")
	    //On passe ici que en cas d'erreur.
    }
}
