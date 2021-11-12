/*
 * MazeMap.cc
 *
 *  Created on: 12 нояб. 2021 г.
 *      Author: unyuu
 */

#include "MazeMap.h"
#include <fstream>
#include <stdexcept>
#include <sstream>

MazeMap::MazeMap(const char *filename)
{
	std::ifstream file { filename };
	if (not file) {
		throw std::runtime_error(
				std::string("Не удалось открыть файл карты ") +
				std::string(filename));
	}

	std::string line;
	std::getline(file, line);
	std::stringstream config_line { line };
	config_line >> _width >> _height >> _start_x >> _start_y >> _start_dir;
	_data.resize(_width * _height);

	for (int row = 0; row < _height; ++row) {
		std::getline(file, line);
		for (int col = 0; col < _width; ++col)
			_data[_width * row + col] = (line[col] == '#')?WALL:EMPTY;
	}
}
