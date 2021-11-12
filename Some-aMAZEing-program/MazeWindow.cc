/*
 * MazeWindow.cc
 *
 *  Created on: 12 нояб. 2021 г.
 *      Author: unyuu
 */

#include "MazeWindow.h"

MazeWindow::MazeWindow()
: Window(WINDOW_WIDTH, WINDOW_HEIGHT)
{
	SDL_SetWindowTitle(_window.get(), "aMAZEing window");
}

void MazeWindow::render()
{
	SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 255);
	SDL_RenderClear(_renderer.get());

	SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 255, 255);
	for (int row = 0; row < _map.height(); ++row) {
		for (int col = 0; col < _map.width(); ++col) {
			SDL_Rect r {
				CELL_WIDTH*col, CELL_HEIGHT*row,
				CELL_WIDTH, CELL_HEIGHT
			};
			if (_map.cell(col, row) == MazeMap::WALL)
				SDL_RenderFillRect(_renderer.get(), &r);
		}
	}
}
