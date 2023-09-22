#include <iostream>
#include "map.h"
#include <random>
#include <string>

//terrains de jeu et du joueur
int game_field[HEIGHT][WIDTH];
int player_field[HEIGHT][WIDTH];

//génération aléatoire du coffre sur le terrain du jeu
void random()
{
	srand(time(0));

	const int idxRandomH = rand() % HEIGHT;
	const int idxRandomW = rand() % WIDTH;

	game_field[idxRandomH][idxRandomW] = chest;
}

//fonction pour faire apparaitre l'écran joueur
int mark()
{
	int a = 0;
	for (int raw = 0; raw < 4; raw++)
	{
		for (int columne = 0; columne < 4; columne++)
		{
			int case_state = player_field[columne][raw];
			switch (case_state)
			{
			case Void:
				std::cout << '-';
				break;
			case dig:
				std::cout << '0';
				break;
			default:
				break;
			}
		}
		std::cout << '\n';
	}
	return EXIT_SUCCESS;
}

//fonction qui sécurise et garantit que l'imput est bel et bien un chiffre
int valid_input()
{

    bool isValidInput = true;
    int result = -1;

    std::string inputString;
    do
    {
        std::getline(std::cin, inputString);

        isValidInput = true;
        for (char inputChar : inputString)
        {
            if (!isdigit(inputChar))
            {
                // not valid input -----------------
                std::cout << "[" << inputChar << "] is not a number" << std::endl;
                isValidInput = false;
                break;
            }
        }

        if (isValidInput)
        {
            //std::cout << "Your number is: " << inputString << "\n";
            std::string value = inputString.substr(0, 10);

            result = std::stoi(inputString);

            std::cout << "Your number is: " << result << "\n";
            break;
        }
    } while (!isValidInput);
    return result;
}

//fonction qui prend en compte les coordonnées du joueur
void imput_player(int& x, int& y)
{
	std::cout << "a treasure is hidden in your screen, try to find it by giving the coordinate of a tile\n";
	std::cout << "What is the value of X (going from left to right) ?\n";
	//std::cin >> x;
	x = valid_input();

    std::cout << "What is the value of Y (going from top to bottom) ?\n";
    //std::cin >> y;
    y = valid_input();
}