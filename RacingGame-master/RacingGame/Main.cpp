#include<allegro5/allegro.h>
#include"Interfaz.h"
#include"Acciones.h"

int main() {
	Acciones action;
	Interfaz visual;
	action.install2();
	visual.install();
	visual.impresionMenuPrincipal1();


	action.accionPrincipal();



}