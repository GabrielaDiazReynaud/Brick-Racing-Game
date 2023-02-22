#include"Enemigo.h"
Enemigo::Enemigo() :activo(false) {

}

void Enemigo::setActivo(bool _activo) {
	this->activo = _activo;
}

void Enemigo::setPosY(int _y) {
	this->posy += _y;

}
void Enemigo::setPosY2(int _y) {
	this->posy = _y;

}

void Enemigo::setPosX(int _x) {
	this->posx = _x;

}

int Enemigo::getPosY() {
	return this->posy;
}
int Enemigo::getPosX() {
	return this->posx;
}