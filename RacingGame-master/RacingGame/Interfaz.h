#pragma once
#ifndef INTERFAZ_H
#define INTERFAZ_H
#include<allegro5/allegro.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_image.h>
#include"Enemigo.h"
#include <iostream>
#include <vector> 
using namespace std;

class Interfaz {
public:
	vector<int> ratingChart;
	int cont = 0;
	int playerx = 200;
	int playery = 475;
	int t = 0;
	int g = 0;
	int velocidad = 5;
	int aumento = 0;
	bool pausa = false;
	ALLEGRO_DISPLAY* display;
	ALLEGRO_FONT* font;
	ALLEGRO_FONT* font0;
	ALLEGRO_FONT* topten1;
	ALLEGRO_FONT* topten2;
	ALLEGRO_FONT* topten3;
	ALLEGRO_FONT* topten4;
	ALLEGRO_FONT* topten5;
	ALLEGRO_FONT* topten6;
	ALLEGRO_FONT* topten7;
	ALLEGRO_FONT* topten8;
	ALLEGRO_FONT* topten9;
	ALLEGRO_FONT* topten10;
	ALLEGRO_FONT* vidasF;
	//ALLEGRO_FONT* vidasF2;
	ALLEGRO_FONT* font1;
	ALLEGRO_FONT* font2;
	ALLEGRO_FONT* font3;
	ALLEGRO_FONT* font4;
	ALLEGRO_FONT* font5;
	ALLEGRO_FONT* font6;
	ALLEGRO_FONT* font7;
	ALLEGRO_FONT* nivelesP;
	ALLEGRO_FONT* puntos;
	ALLEGRO_FONT* GameOver;
	ALLEGRO_FONT* puntajeFinal;
	ALLEGRO_FONT* spaceBar;
	ALLEGRO_FONT* pausaP;
	ALLEGRO_FONT* Win;
	ALLEGRO_BITMAP* image;
	ALLEGRO_BITMAP* image2;
	ALLEGRO_BITMAP* image3;
	char* nivelPrint = new char[10];
	char* vidasPrint = new char[10];
	char* pointsPrint = new char[10];
	int y = 120;
	int a = 0;
	int nivel = 1;
	int puntaje = 0;
	int vidas = 3;
	bool doneGame = false;
	Enemigo* carros[3];
	int inicialisacionT = 0;
	int inicialisacionT2 = 0;
	Interfaz();
	void install();
	void impresionMenuPrincipal1();
	void printGameover();
	void printWin();
	void borrarGameOver();
	void borrarWin();
	void impresionMenuPrincipal2();
	void crearMenuPrincipal();
	void borrarMenuPrincipal();
	void borrarFondo();
	void impresionJuego();
	void borrarJuego();
	void impresionFondo();
	void fondoRating();
	void borrarRating();
	void initEnemigos();
	void printEnemigos();
	void borrarEnemigos();
	void actualizarPuntaje();
	void intento();
	void intento2();
	void Collision();
	void pausarJuego();
	void borrarPausa();
	void imprimirRating();
	void reinicio();

};
#endif 

