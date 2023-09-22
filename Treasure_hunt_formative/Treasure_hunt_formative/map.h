#pragma once
#include <iostream>
#include <random>

//definition des paramètres des terrains
#define WIDTH 4
#define HEIGHT 4

//enumérations des éléments tiles utilisée
enum enigma
{
	Void,
	chest,
	dig,
};

//terain généré avec un trésort aléatoire
extern int game_field[HEIGHT][WIDTH];

//terrain donné au joueur
extern int player_field[HEIGHT][WIDTH];

//les différentes fonctions nécessaires au programme
int mark();
void random();
int valid_input();
void imput_player(int& x, int& y);