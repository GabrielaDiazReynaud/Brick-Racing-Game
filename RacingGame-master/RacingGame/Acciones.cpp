#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include"Acciones.h"
#include "Interfaz.h"


Acciones::Acciones() {

}

void Acciones::install2() {
	al_init();
	al_install_keyboard();
	al_init_image_addon();
}

void Acciones::accionPrincipal() {

	while (bye==false) {

		al_get_keyboard_state(&keyState);

		if (al_key_down(&keyState, ALLEGRO_KEY_1)) {
			i.borrarMenuPrincipal();
			i.impresionJuego();
			accionJugador();




		}

		if (al_key_down(&keyState, ALLEGRO_KEY_2)) {
			i.borrarMenuPrincipal();
			i.fondoRating();
			accionRating();

		}

		if (al_key_down(&keyState, ALLEGRO_KEY_3)) {
			bye = true;

		}

	}

}

void Acciones::accionJugador() {
	
	const int FPS = 20;
	const int FPS2 = 100;
	eventQueue = al_create_event_queue();
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_flip_display();
	i.initEnemigos();
	done1 = false;
	i.reinicio();
	srand(time(NULL));
	ALLEGRO_TIMER* timer = NULL;
	timer = al_create_timer(1.0 /FPS);
	timerC = al_create_timer(1.0 /FPS2);
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));
	al_register_event_source(eventQueue, al_get_timer_event_source(timerC));
	al_start_timer(timer);
	al_start_timer(timerC);
	while (done1 == false && i.nivel!=11 && i.vidas>0) {
	
			i.intento();
			i.intento2();
	
		al_wait_for_event(eventQueue, &events);
		
		
				if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
					switch (events.keyboard.keycode) {
					case ALLEGRO_KEY_RIGHT:

						if (i.playerx < 350 && i.pausa!=true) {
							dir = RIGHT;
						}
						break;

					case ALLEGRO_KEY_LEFT:
						if (i.playerx > 100 && i.pausa != true) {
							dir = LEFT;
						}

						break;

					case ALLEGRO_KEY_UP:
						if (i.playery > 150 && i.pausa != true) {
							dir = UP;
						}

						break;

					case ALLEGRO_KEY_ESCAPE:
						if (i.pausa != true) {
							done1 = true;

						}
						break;
					
					case ALLEGRO_KEY_P:
						i.pausa = true;
						while (i.pausa == true) {
							i.pausarJuego();
							al_stop_timer(timer);
							al_stop_timer(timerC);
							i.borrarPausa();
							if (unavez == 0) {
								al_destroy_event_queue(eventQueue);
								unavez++;
							}
							al_get_keyboard_state(&keyState);

							if (al_key_down(&keyState, ALLEGRO_KEY_SPACE)) {
								
								i.pausa = false;
								unavez = 0;
								eventQueue = al_create_event_queue();
								al_register_event_source(eventQueue, al_get_keyboard_event_source());
								al_register_event_source(eventQueue, al_get_timer_event_source(timer));
								al_register_event_source(eventQueue, al_get_timer_event_source(timerC));
								al_start_timer(timer);
								al_start_timer(timerC);
								al_clear_to_color(al_map_rgb(0, 0, 0));
						}
						}

						break;
					}

				}
				if (events.type == ALLEGRO_EVENT_TIMER ) {

					if (events.timer.source == timerC) {
						switch (dir) {
						case RIGHT:
							if (i.playerx < 350) {

								i.playerx += 150;
							}

							break;

						case LEFT:
							if (i.playerx > 100) {
								i.playerx -= 150;
							}

							break;

						case UP:
							if (i.playery > 150) {
								
								if (i.a >= 3) {
									i.t++;
									i.aumento += 40;
									if (i.t > 400) {
										
										i.nivel++;
										i.t = 0;

									}
								}
							}

							break;
						}
					
						dir = DOWN;
						
					}
					
					if (events.timer.source == timer ) {
							
						i.printEnemigos();
						i.aumento = 0;


					}
				}
			   al_flip_display();
		}

		al_destroy_event_queue(eventQueue);
		al_destroy_timer(timer);
		al_destroy_timer(timerC);

		

		i.playerx = 200;
		i.playery = 475;
		al_clear_to_color(al_map_rgb(0, 0, 0));

		if (i.vidas <= 0 || i.nivel == 11 ) {
			accionTerminal();
		}
		accionRegreso1();

	
}

void Acciones::accionRating() {
	eventQueue = al_create_event_queue();
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	done1 = false;
	while (done1 == false) {

		al_wait_for_event(eventQueue, &events);

		if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (events.keyboard.keycode) {

			case ALLEGRO_KEY_ESCAPE:
				done1 = true;
				
				break;
			}
		}


	}
	i.borrarRating();
	al_destroy_event_queue(eventQueue);
	accionRegreso1();

}

void Acciones::accionRegreso1() {

	i.impresionMenuPrincipal2();



}



void Acciones::accionTerminal() {
	i.actualizarPuntaje();
	while (i.doneGame == false) {
		if (i.nivel == 11) {
			i.printWin();
			al_flip_display();
			i.borrarWin();
	}
		else  if (i.vidas <=0 ) {
			i.printGameover();
			al_flip_display();
			i.borrarGameOver();
		}

		
		al_get_keyboard_state(&keyState);
		if (al_key_down(&keyState, ALLEGRO_KEY_SPACE)) {
			i.doneGame = true;
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}
	i.doneGame = false;
}