/*
 * Window.h
 *
 *  Created on: 12 нояб. 2021 г.
 *      Author: unyuu
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>
#include <memory>

class Window
{
public:
	static constexpr int DEFAULT_WIDTH = 800;
	static constexpr int DEFAULT_HEIGHT = 600;
protected:
	std::shared_ptr<SDL_Window> _window;
	std::shared_ptr<SDL_Renderer> _renderer;
	int _width {}, _height {};

	virtual void render() {}
public:
	Window(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~Window() = default;

	void main_loop();

	int height() const { return _height; }
	int width() const  { return _width;  }
};

#endif /* WINDOW_H_ */
