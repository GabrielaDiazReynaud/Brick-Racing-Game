#pragma once
#ifndef ACCIONES_H
#define ACCIONES_H
#include<allegro5/allegro.h>
#include<allegro5/keyboard.h>
#include <allegro5/allegro_image.h>
#include "Interfaz.h"

enum Direction{UP,DOWN,LEFT,RIGHT};

class Acciones {
public:
	
	bool done1 = false;
	bool done2 = false;
	int mov = 0;
	int dir = DOWN;
	int unavez = 0;
	bool bye = false;
	ALLEGRO_EVENT_QUEUE* eventQueue;

	ALLEGRO_EVENT events;

	ALLEGRO_KEYBOARD_STATE keyState;

	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_TIMER* timerC = NULL;
	ALLEGRO_TIMER* tiempo = NULL;
	Interfaz i;
	
	Acciones();
	void install2();
	void accionTerminal();
	void accionRating();
	void accionPrincipal();
	void accionJugador();
	void accionRegreso1();


};
#endif
