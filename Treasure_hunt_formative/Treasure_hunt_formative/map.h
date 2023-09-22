#pragma once
#include <iostream>
#include <random>

//definition des param�tres des terrains
#define WIDTH 4
#define HEIGHT 4

//enum�rations des �l�ments tiles utilis�e
enum enigma
{
	Void,
	chest,
	dig,
};

//terain g�n�r� avec un tr�sort al�atoire
extern int game_field[HEIGHT][WIDTH];

//terrain donn� au joueur
extern int player_field[HEIGHT][WIDTH];

//les diff�rentes fonctions n�cessaires au programme
int mark();
void random();
int valid_input();
void imput_player(int& x, int& y);