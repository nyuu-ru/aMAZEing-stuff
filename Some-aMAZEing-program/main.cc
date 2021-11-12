/*
 * main.cc
 *
 *  Created on: 12 нояб. 2021 г.
 *      Author: unyuu
 */

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <memory>
#include <stdexcept>

#include "MazeWindow.h"

int main(int, char **)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	try {
		MazeWindow w;

		w.main_loop();
	} catch (const std::exception &e) {
		std::cerr << "Во время выполнения программы возникла проблема:\n" <<
				e.what() << std::endl;
		return 1;
	} catch (...) {
		std::cerr << "Во время выполнения прогарммы возникла "
				"неизвестная проблема." << std::endl;
		return 2;
	}

	return 0;
}


