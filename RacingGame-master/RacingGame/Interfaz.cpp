#include<allegro5/allegro.h>

#include"Interfaz.h"
#include"Enemigo.h"
#include<vector>
#include<algorithm>
Interfaz::Interfaz() {


}
void Interfaz::install() {
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();
}
void Interfaz::impresionMenuPrincipal1() {
	if (cont == 0) {
		display = al_create_display(450, 550);
		cont = 1;
	}
	font = al_load_ttf_font("gamef.ttf", 30, 0);
	font0 = al_load_ttf_font("gamef.ttf", 30, 0);
	font1 = al_load_ttf_font("gamef.ttf", 25, 0);
	font2 = al_load_ttf_font("gamef.ttf", 25, 0);
	font3 = al_load_ttf_font("gamef.ttf", 25, 0);
	font4 = al_load_ttf_font("gamef.ttf", 25, 0);
	image = al_load_bitmap("carM.png");
	al_draw_bitmap(image, 70, 80, NULL);
	al_draw_text(font, al_map_rgb(255, 255, 255), 110, 25, 0, "BRICK GAME");
	al_draw_text(font0, al_map_rgb(255, 255, 255), 150, 85, 0, "RACING");
	al_draw_text(font1, al_map_rgb(57, 255, 0), 145, 280, 0, "1- START");
	al_draw_text(font2, al_map_rgb(255, 255, 0), 135, 330, 0, "2- RATINGS");
	al_draw_text(font3, al_map_rgb(255, 0, 0), 160, 380, 0, "3- QUIT");
	al_flip_display();
}

void Interfaz::impresionMenuPrincipal2() {

	font = al_load_ttf_font("gamef.ttf", 30, 0);
	font0 = al_load_ttf_font("gamef.ttf", 30, 0);
	font1 = al_load_ttf_font("gamef.ttf", 25, 0);
	font2 = al_load_ttf_font("gamef.ttf", 25, 0);
	font3 = al_load_ttf_font("gamef.ttf", 25, 0);
	font4 = al_load_ttf_font("gamef.ttf", 25, 0);
	image = al_load_bitmap("carM.png");
	al_draw_bitmap(image, 70, 80, NULL);
	al_draw_text(font, al_map_rgb(255, 255, 255), 110, 25, 0, "BRICK GAME");
	al_draw_text(font0, al_map_rgb(255, 255, 255), 150, 85, 0, "RACING");
	al_draw_text(font1, al_map_rgb(57, 255, 0), 145, 280, 0, "1- START");
	al_draw_text(font2, al_map_rgb(255, 255, 0), 135, 330, 0, "2- RATINGS");
	al_draw_text(font3, al_map_rgb(255, 0, 0), 160, 380, 0, "3- QUIT");
	al_flip_display();
}


void Interfaz::fondoRating() {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	font7 = al_load_ttf_font("gamef.ttf", 25, 0);
	al_draw_text(font7, al_map_rgb(253, 255, 0), 150, 20, 0, "RATINGS");
	imprimirRating();

}

void Interfaz::borrarRating() {
	al_destroy_font(font7);
	al_clear_to_color(al_map_rgb(0, 0, 0));
}

void Interfaz::borrarFondo() {
	al_destroy_bitmap(image2);
	al_destroy_font(font5);
	al_destroy_font(font6);
	al_destroy_font(nivelesP);
	al_destroy_font(puntos);
	al_destroy_font(vidasF);

}

void Interfaz::borrarMenuPrincipal() {
	al_destroy_bitmap(image);
	al_destroy_font(font);
	al_destroy_font(font0);
	al_destroy_font(font1);
	al_destroy_font(font2);
	al_destroy_font(font3);
	al_destroy_font(font4);

	al_clear_to_color(al_map_rgb(0, 0, 0));
}

void Interfaz::crearMenuPrincipal() {
	font = al_load_ttf_font("gamef.ttf", 30, 0);
	font0 = al_load_ttf_font("gamef.ttf", 30, 0);
	font1 = al_load_ttf_font("gamef.ttf", 25, 0);
	font2 = al_load_ttf_font("gamef.ttf", 25, 0);
	font3 = al_load_ttf_font("gamef.ttf", 25, 0);
	font4 = al_load_ttf_font("gamef.ttf", 25, 0);
	image = al_load_bitmap("carM.png");
}

void Interfaz::impresionJuego() {
	vidasF = al_load_ttf_font("gamef.ttf", 25, 0);

	puntos = al_load_ttf_font("gamef.ttf", 25, 0);
	nivelesP= al_load_ttf_font("gamef.ttf", 25, 0);
	font5 = al_load_ttf_font("gamef.ttf", 25, 0);
	font6 = al_load_ttf_font("gamef.ttf", 25, 0);
	image2 = al_load_bitmap("fondo1.png");
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_draw_bitmap(image2, 0, 0, NULL);
	image3 = al_load_bitmap("carro1.png");
	al_draw_text(font5, al_map_rgb(255, 255, 255), 0, 0, 0, "NIVEL=");
	al_draw_text(nivelesP, al_map_rgb(255, 255, 255), 100, 0, 0, "1");
	al_draw_text(vidasF, al_map_rgb(255, 255, 255), 200, 0, 0, "VIDAS= 3");
	al_draw_text(font6, al_map_rgb(255, 255, 255), 0, 50, 0, "PUNTOS= ");
	al_draw_text(puntos, al_map_rgb(255, 255, 255), 150, 50, 0, "0");


	al_flip_display();
}

void Interfaz::borrarJuego() {
	al_destroy_bitmap(image2);
	al_destroy_bitmap(image3);
	al_destroy_font(font5);
	al_destroy_font(font6);
	al_destroy_font(nivelesP);
	al_destroy_font(puntos);
	al_destroy_font(vidasF);
	//al_destroy_font(vidasF2);
	al_clear_to_color(al_map_rgb(0, 0, 0));
}

void Interfaz::impresionFondo(){
	puntos =al_load_ttf_font("gamef.ttf", 25, 0);
    nivelesP = al_load_ttf_font("gamef.ttf", 25, 0);
	font5 = al_load_ttf_font("gamef.ttf", 25, 0);
	font6 = al_load_ttf_font("gamef.ttf", 25, 0);
	image2 = al_load_bitmap("fondo1.png");
	vidasF = al_load_ttf_font("gamef.ttf", 25, 0);

	al_draw_bitmap(image2, 0, 0, NULL);
	sprintf(nivelPrint,"NIVEL = %d", nivel);
	sprintf(vidasPrint, "VIDAS = %d", vidas);

	al_draw_text(font5, al_map_rgb(255, 255, 255), 0, 0, 0, nivelPrint);
	al_draw_text(vidasF, al_map_rgb(255, 255, 255), 200, 0, 0, vidasPrint);
	
	if (nivel == 1) {
		puntaje = 0;
		al_draw_text(puntos, al_map_rgb(255, 255, 255), 150, 50, 0, "0");
	}
	else if (nivel == 2) {
		puntaje = 20;
		velocidad = 7;
		inicialisacionT = 10;
		inicialisacionT2 = 15;
		al_draw_text(puntos, al_map_rgb(255, 255, 255), 150, 50, 0, "20 ");
	}

	else if (nivel == 3) {
		velocidad = 9;
		puntaje = 60;
		inicialisacionT = 15;
		inicialisacionT2 = 25;
		al_draw_text(puntos, al_map_rgb(255, 255, 255), 150, 50, 0, "60 ");
	}
	else if (nivel == 4) {
		velocidad = 11;
		puntaje = 120;
		inicialisacionT = 20;
		inicialisacionT2 = 35;
		al_draw_text(puntos, al_map_rgb(255, 255, 255), 150, 50, 0, "120 ");
	}
	else if (nivel == 5) {
		velocidad = 13;
		puntaje = 200;
		inicialisacionT = 25;
		inicialisacionT2 = 40;
		al_draw_text(puntos, al_map_rgb(255, 255, 255), 150, 50, 0, "200 ");
	}
	else if (nivel == 6) {
		velocidad = 15;
		puntaje = 300;
		inicialisacionT = 25;
		inicialisacionT2 = 40;
		al_draw_text(puntos, al_map_rgb(255, 255, 255), 150, 50, 0, "300 ");
	}
	else if (nivel == 7) {
		velocidad = 17;
		puntaje = 430;
		inicialisacionT = 25;
		inicialisacionT2 = 45;
		al_draw_text(puntos, al_map_rgb(255, 255, 255), 150, 50, 0, "430 ");
	}
	else if (nivel == 8) {
		velocidad = 19;
		puntaje = 600;
		inicialisacionT = 25;
		inicialisacionT2 = 45;
		al_draw_text(puntos, al_map_rgb(255, 255, 255), 150, 50, 0, "600");
	}
	else if (nivel == 9) {
		velocidad = 21;
		puntaje = 820;
		inicialisacionT = 25;
		inicialisacionT2 = 45;
		al_draw_text(puntos, al_map_rgb(255, 255, 255), 150, 50, 0, "820 ");
	}
	else if (nivel == 10) {
		velocidad = 23;
		puntaje = 1100;
		inicialisacionT = 28;
		inicialisacionT2 = 50;
		al_draw_text(puntos, al_map_rgb(255, 255, 255), 150, 50, 0, "1100 ");
	}
	else if (nivel == 11) {
		puntaje = 1500;
	}

	al_draw_text(font6, al_map_rgb(255, 255, 255), 0, 50, 0, "PUNTOS= ");


}

void Interfaz::initEnemigos() {
	carros[0] = new Enemigo();
	carros[1] = new Enemigo();
	carros[2] = new Enemigo();

}

void Interfaz::printEnemigos() {
	t++;
	
	al_clear_to_color(al_map_rgb(0, 0, 0));
	impresionFondo();
    
	al_draw_bitmap(image3, playerx, 475, NULL);
	for (int x = 0; x < 3; x++) {

		if (carros[x]->activo == true) {


			al_draw_bitmap(carros[x]->enemy, carros[x]->posx, carros[x]->posy, NULL);
			
			carros[x]->setPosY(velocidad+aumento);
			
			if (carros[x]->getPosY() > 550) {
				carros[x]->setPosY2(50);
				carros[x]->setActivo(false);
				if (carros[x]->getPosX() == 50) {
					al_destroy_bitmap(carros[x]->enemy);
					
				}
			}
	
		}
		Collision();
		
	}
	if (vidas != 0) {
		borrarFondo();
	}
	
	if (t > 400) {
		nivel++;
		t = 0;

	}
	
}

void Interfaz::borrarEnemigos() {
	for (int x = 0; x < 3; x++) {
		if (carros[x]->activo == true) {

			al_destroy_bitmap(carros[x]->enemy);
			carros[x]->setActivo(false);
			carros[x]->setPosY2(50);
		}
	}
}

void Interfaz::Collision() {
	for (int x = 0; x < 3; x++) {
		if (carros[x]->activo == true) {
			if (playerx + 80 < carros[x]->getPosX() || playerx > carros[x]->getPosX() + 80 || playery + 72 < carros[x]->getPosY() || playery > carros[x]->posy + 72) {

			}
			else{
				vidas --;
				if (vidas == 2) {
					borrarEnemigos();
				}
				else if (vidas == 1) {
					borrarEnemigos();
				}
				al_clear_to_color(al_map_rgb(0, 0, 0));
				a = 0;
				t = 0;
				
				
			}

		}
	}
}

void Interfaz::intento() {
	int numeroCarril = rand() % 3;
if(a<3){
	if (t == 0 ) {
		if (carros[0]->activo == false) {
			a++;
			
			carros[0]->enemy = al_load_bitmap("carroEnemigo1.png");
			if (numeroCarril == 0) {
				carros[0]->setPosX(50);

			}
			else if (numeroCarril == 1) {
				carros[0]->setPosX(200);
			}
			else if (numeroCarril == 2) {
				carros[0]->setPosX(350);
			}
			carros[0]->setActivo(true);

		}


	}
	else if (t == 35-inicialisacionT) {
		if (carros[1]->activo == false) {
			a++;
			carros[1]->enemy = al_load_bitmap("carroEnemigo1.png");
			if (numeroCarril == 0) {
				carros[1]->setPosX(50);

			}
			else if (numeroCarril == 1) {
				carros[1]->setPosX(200);
			}
			else if (numeroCarril == 2) {
				carros[1]->setPosX(350);
			}
			carros[1]->setActivo(true);

		}

	}

	else if (t == 65 - inicialisacionT2) {
		if (carros[2]->activo == false) {
			a++;
			carros[2]->enemy = al_load_bitmap("carroEnemigo1.png");
			if (numeroCarril == 0) {
				carros[2]->setPosX(50);

			}
			else if (numeroCarril == 1) {
				carros[2]->setPosX(200);
			}
			else if (numeroCarril == 2) {
				carros[2]->setPosX(350);
			}
			carros[2]->setActivo(true);

		}
	}

	}
}

void Interfaz::intento2() {
	if (a >= 3) {
		int numeroCarril = rand() % 3;

		if (carros[0]->activo == false) {
			carros[0]->setPosY2(50);
			carros[0]->enemy = al_load_bitmap("carroEnemigo1.png");
			if (numeroCarril == 0) {
				carros[0]->setPosX(50);

			}
			else if (numeroCarril == 1) {
				carros[0]->setPosX(200);
			}
			else if (numeroCarril == 2) {
				carros[0]->setPosX(350);
			}
			carros[0]->setActivo(true);

		}


		else if (carros[1]->activo == false) {
			carros[1]->setPosY2(50);
			carros[1]->enemy = al_load_bitmap("carroEnemigo1.png");
			if (numeroCarril == 0) {
				carros[1]->setPosX(50);

			}
			else if (numeroCarril == 1) {
				carros[1]->setPosX(200);
			}
			else if (numeroCarril == 2) {
				carros[1]->setPosX(350);
			}
			carros[1]->setActivo(true);

		}

		else if (carros[2]->activo == false) {
			carros[2]->setPosY2(50);
			carros[2]->enemy = al_load_bitmap("carroEnemigo1.png");
			if (numeroCarril == 0) {
				carros[2]->setPosX(50);

			}
			else if (numeroCarril == 1) {
				carros[2]->setPosX(200);
			}
			else if (numeroCarril == 2) {
				carros[2]->setPosX(350);
			}
			carros[2]->setActivo(true);

		}

	

	}
}

void Interfaz::reinicio() {
	a = 0;
	t = 0;
	puntaje = 0;
	vidas = 3;
	nivel = 1;
	velocidad = 5;
	inicialisacionT = 0;
	inicialisacionT2 = 0;
	for (int x = 0; x < 3; x++) {
		carros[x]->setActivo(false);
		carros[x]->setPosY2(50);
	}

}

void Interfaz::printGameover() {

	GameOver = al_load_ttf_font("gamef.ttf", 25, 0);
	al_draw_text(GameOver, al_map_rgb(255, 0, 0), 130, 200, 0, "GAME OVER");
	puntajeFinal = al_load_ttf_font("gamef.ttf", 15, 0);
	sprintf(pointsPrint, "PUNTAJE FINAL = %d", puntaje);
	al_draw_text(puntajeFinal, al_map_rgb(255, 255, 255), 50, 280, 0, pointsPrint);
	spaceBar= al_load_ttf_font("gamef.ttf", 20, 0);
	al_draw_text(spaceBar, al_map_rgb(152, 152, 152), 110, 380, 0, "--- SPACE BAR ---");

	
}
void Interfaz::printWin() {
	Win = al_load_ttf_font("gamef.ttf", 25, 0);
	al_draw_text(Win, al_map_rgb(57, 255, 0), 155, 200, 0, "YOU WIN");
	puntajeFinal = al_load_ttf_font("gamef.ttf", 15, 0);
	sprintf(pointsPrint, "PUNTAJE FINAL = %d", puntaje);
	al_draw_text(puntajeFinal, al_map_rgb(255, 255, 255), 50, 280, 0, pointsPrint);
	spaceBar = al_load_ttf_font("gamef.ttf", 20, 0);
	al_draw_text(spaceBar, al_map_rgb(152, 152, 152), 110, 380, 0, "--- SPACE BAR ---");

}

void Interfaz::pausarJuego(){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	pausaP = al_load_ttf_font("gamef.ttf", 25, 0);
	al_draw_text(pausaP, al_map_rgb(191, 0, 255), 160, 200, 0, "PAUSE");
	spaceBar = al_load_ttf_font("gamef.ttf", 20, 0);
	al_draw_text(spaceBar, al_map_rgb(152, 152, 152), 110, 300, 0, "--- SPACE BAR ---");
	al_flip_display();

}
void Interfaz::borrarPausa() {
	al_destroy_font(pausaP);
	al_destroy_font(spaceBar);


}
void Interfaz::borrarGameOver() {
	al_destroy_font(GameOver);
	al_destroy_font(puntajeFinal);
	al_destroy_font(spaceBar);
}
void Interfaz::borrarWin() {
	al_destroy_font(Win);
	al_destroy_font(puntajeFinal);
	al_destroy_font(spaceBar);
}

void Interfaz::actualizarPuntaje() {
	if (nivel == 1) {
		puntaje = 0;
	}
	else if (nivel == 2) {
		puntaje = 20;
	}
	else if (nivel == 3) {
		puntaje = 60;
	}
	else if (nivel == 4) {
		puntaje = 120;
	}
	else if (nivel == 5) {
		puntaje = 200;
	}
	else if (nivel == 6) {
		puntaje = 300;
	}
	else if (nivel == 7) {
		puntaje = 430;
	}
	else if (nivel == 8) {
		puntaje = 600;
	}
	else if (nivel == 9) {
		puntaje = 820;
	}
	else if (nivel == 10) {
		puntaje = 1100;
	}
	else if (nivel == 11)
	{
		puntaje = 1500;
	}
		ratingChart.insert(ratingChart.begin(), puntaje);

		
}

void Interfaz::imprimirRating() {
	sort(ratingChart.begin(), ratingChart.end(), greater<int>());
	topten1= al_load_ttf_font("gamef.ttf", 25, 0);
	topten2 = al_load_ttf_font("gamef.ttf", 25, 0);
	topten3 = al_load_ttf_font("gamef.ttf", 25, 0);
	topten4 = al_load_ttf_font("gamef.ttf", 25, 0);
	topten5 = al_load_ttf_font("gamef.ttf", 25, 0);
	topten6 = al_load_ttf_font("gamef.ttf", 25, 0);
	topten7 = al_load_ttf_font("gamef.ttf", 25, 0);
	topten8 = al_load_ttf_font("gamef.ttf", 25, 0);
	topten9 = al_load_ttf_font("gamef.ttf", 25, 0);
	topten10 = al_load_ttf_font("gamef.ttf", 25, 0);
	
	int espacio = 50;
	int cont = 0;
	for (auto x : ratingChart) {
		if (cont <= 9 && cont<ratingChart.size( ) ){
			if (cont == 0) {
				sprintf(pointsPrint, "1 = %d", x);
				al_draw_text(topten1, al_map_rgb(255, 255, 255), 0, espacio, 0, pointsPrint);
				cont++;
				espacio+=40;
			}
			else if (cont == 1) {
				sprintf(pointsPrint, "2 = %d", x);
				al_draw_text(topten2, al_map_rgb(255, 255, 255), 0, espacio, 0, pointsPrint);
				cont++;
				espacio+=40;
			}
			else if (cont == 2) {
				sprintf(pointsPrint, "3 = %d", x);
				al_draw_text(topten3, al_map_rgb(255, 255, 255), 0, espacio, 0, pointsPrint);
				cont++;
				espacio+=40;
			}
			else if (cont == 3) {
				sprintf(pointsPrint, "4 = %d", x);
				al_draw_text(topten4, al_map_rgb(255, 255, 255), 0, espacio, 0, pointsPrint);
				cont++;
				espacio+=40;
			}
			else if (cont == 4) {
				sprintf(pointsPrint, "5 = %d", x);
				al_draw_text(topten5, al_map_rgb(255, 255, 255), 0, espacio, 0, pointsPrint);
				cont++;
				espacio+=40;
			}
			else if (cont == 5) {
				sprintf(pointsPrint, "6 = %d", x);
				al_draw_text(topten6, al_map_rgb(255, 255, 255), 0, espacio, 0, pointsPrint);
				cont++;
				espacio+=40;
			}
			else if (cont == 6) {
				sprintf(pointsPrint, "7 = %d", x);
				al_draw_text(topten7, al_map_rgb(255, 255, 255), 0, espacio, 0, pointsPrint);
				cont++;
				espacio+=40;
			}
			else if (cont == 7) {
				sprintf(pointsPrint, "8 = %d", x);
				al_draw_text(topten8, al_map_rgb(255, 255, 255), 0, espacio, 0, pointsPrint);
				cont++;
				espacio+=40;
			}
			else if (cont == 8) {
				sprintf(pointsPrint, "9 = %d", x);
				al_draw_text(topten9, al_map_rgb(255, 255, 255), 0, espacio, 0, pointsPrint);
				cont++;
				espacio+=40;
			}
			else if (cont == 9) {
				sprintf(pointsPrint, "10 = %d", x);
				al_draw_text(topten10, al_map_rgb(255, 255, 255), 0, espacio, 0, pointsPrint);
				cont++;
				espacio+=40;
			}
		}
	}
	al_flip_display();
	al_destroy_font(topten1);
	al_destroy_font(topten2); 
	al_destroy_font(topten3);
	al_destroy_font(topten4);
	al_destroy_font(topten5);
	al_destroy_font(topten6);
	al_destroy_font(topten7);
	al_destroy_font(topten8);
	al_destroy_font(topten9);
	al_destroy_font(topten10);
}