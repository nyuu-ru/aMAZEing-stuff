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

	_map = std::make_shared<MazeMap>("map01.txt");
	player.spawn(_map);
}

void MazeWindow::render()
{
	SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 255);
	SDL_RenderClear(_renderer.get());

	SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 255, 255);
	for (int row = 0; row < _map->height(); ++row) {
		for (int col = 0; col < _map->width(); ++col) {
			SDL_Rect r {
				CELL_WIDTH*col, CELL_HEIGHT*row,
				CELL_WIDTH, CELL_HEIGHT
			};
			if (_map->cell(col, row) == MazeMap::WALL)
				SDL_RenderFillRect(_renderer.get(), &r);
		}
	}

	SDL_SetRenderDrawColor(_renderer.get(), 255, 64, 64, 255);
	SDL_Rect player_rect {
		int(CELL_WIDTH * player.x()) - 4,
		int(CELL_HEIGHT * player.y()) - 4,
		9, 9
	};
	SDL_RenderFillRect(_renderer.get(), &player_rect);

	int x1, x2, y1, y2;
	x1 = int(CELL_WIDTH * player.x());
	y1 = int(CELL_HEIGHT * player.y());
	x2 = int(x1 + 50 * cos(player.dir()));
	y2 = int(y1 + 50 * sin(player.dir()));
	SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 0, 255);
	SDL_RenderDrawLine(_renderer.get(), x1, y1, x2, y2);


}

void MazeWindow::handle_keys(const Uint8 *keys)
{
	if (keys[SDL_SCANCODE_W]) player.walk_forward();
	if (keys[SDL_SCANCODE_S]) player.walk_backward();
	if (keys[SDL_SCANCODE_A]) player.shift_left();
	if (keys[SDL_SCANCODE_D]) player.shift_right();
	if (keys[SDL_SCANCODE_Q]) player.turn_left();
	if (keys[SDL_SCANCODE_E]) player.turn_right();

	if (keys[SDL_SCANCODE_UP]) player.move_up();
	if (keys[SDL_SCANCODE_DOWN]) player.move_down();
	if (keys[SDL_SCANCODE_LEFT]) player.move_left();
	if (keys[SDL_SCANCODE_RIGHT]) player.move_right();
}
