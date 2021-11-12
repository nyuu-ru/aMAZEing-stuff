/*
 * Window.cc
 *
 *  Created on: 12 нояб. 2021 г.
 *      Author: unyuu
 */

#include <stdexcept>
#include "Window.h"

Window::Window(int width, int height)
: _width(width), _height(height)
{
	_window = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow("Some generic window",
			                 SDL_WINDOWPOS_CENTERED_DISPLAY(1),
			                 SDL_WINDOWPOS_CENTERED_DISPLAY(1),
			                 width, height,
			                 0),
			SDL_DestroyWindow);
	if (_window == nullptr)
		throw std::runtime_error(
				std::string("Не могу создать окно: ") +
				std::string(SDL_GetError()));

	_renderer = std::shared_ptr<SDL_Renderer>(
			SDL_CreateRenderer(_window.get(), -1,
			                   SDL_RENDERER_ACCELERATED |
			                   SDL_RENDERER_PRESENTVSYNC),
			SDL_DestroyRenderer);
	if (_renderer == nullptr)
		throw std::runtime_error(
				std::string("Не могу создать рендерер: ") +
				std::string(SDL_GetError()));
}

void Window::main_loop()
{
	auto keys = SDL_GetKeyboardState(nullptr);
	SDL_Event event;
	for (;;) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				return;
		}
		handle_keys(keys);

		render();
		SDL_RenderPresent(_renderer.get());
	}
}
