/*
 * MazeWindow.h
 *
 *  Created on: 12 нояб. 2021 г.
 *      Author: unyuu
 */

#ifndef MAZEWINDOW_H_
#define MAZEWINDOW_H_

#include "Window.h"
#include "MazeMap.h"
#include "Player.h"
#include <memory>

class MazeWindow: public Window
{
protected:
	static constexpr int CELL_WIDTH = 60;
	static constexpr int CELL_HEIGHT = 60;
	std::shared_ptr<MazeMap> _map;
	Player player;

	virtual void handle_keys(const Uint8 *keys) override;
	virtual void render() override;

public:
	static constexpr int WINDOW_WIDTH = 1920;
	static constexpr int WINDOW_HEIGHT = 1080;
public:
	MazeWindow();
	virtual ~MazeWindow() = default;
};

#endif /* MAZEWINDOW_H_ */
