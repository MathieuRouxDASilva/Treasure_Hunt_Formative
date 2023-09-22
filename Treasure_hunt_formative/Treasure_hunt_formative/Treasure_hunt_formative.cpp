#include <iostream>
#include <string>
#include "map.h"

int x;
int y;

//fonction main
int main()
{
	//création d'un coffre dans un slot aléatoire
	random();

	//set up de la boucle du jeu
	bool treasure_found = false;
	int b = 0;
	
	do
	{
		//affichage terrain joueur
		mark();

		//imput joueur
		imput_player(x, y);

		//systeme de vérification de la taille des coordonées
		if(x > WIDTH || y > HEIGHT)
		{
			std::cout << "Coordinate are too big, please imput a 1 digit number\n";
			continue;
		}

		//affichage du résultat: trésort ou non et marquage de l'emplacement séléctioné
		if (game_field[(x - 1)][(y - 1)] == chest)
		{
			std::cout << "you found the treasure !\n";
			treasure_found = true;
		}
		else
		{
			std::cout << "you did not found a treasure, a symbol apeared at the location you imputed\n";
			player_field[(x - 1)][(y - 1)] = dig;
			b = b++;
		}

		//système pour laisser que 5 tours au joueur
		if (b == 5)
		{
			std::cout << "\n" << "game over, no more tries\n";
			treasure_found = true;
		}
		else
			std::cout << "you have " << 5 - b << " moves left\n";

	} while (treasure_found == false);
}