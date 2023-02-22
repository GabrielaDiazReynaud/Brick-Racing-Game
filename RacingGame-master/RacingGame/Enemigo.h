#pragma once
#pragma once
#ifndef ENEMIGO_H
#define ENEMIGO_H
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
class Enemigo {
public:
	int posx;
	int posy;
	int speed;
	bool activo;
	ALLEGRO_BITMAP* enemy;
	Enemigo();
	void setActivo(bool);
	void setPosY(int);
	void setPosX(int);
	void setPosY2(int);
	int getPosY();
	int getPosX();




};
#endif 
