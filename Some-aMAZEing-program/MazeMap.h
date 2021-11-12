/*
 * MazeMap.h
 *
 *  Created on: 12 нояб. 2021 г.
 *      Author: unyuu
 */

#ifndef MAZEMAP_H_
#define MAZEMAP_H_

#include <vector>
#include <cmath>


class MazeMap
{
public:
	enum CellType
	{
		EMPTY = 0,
		WALL = 1
	};
protected:
	std::vector<int> _data;
	int _width {}, _height {};
	double _start_x {}, _start_y {}, _start_dir {};
public:
	MazeMap(const char *filename);
	virtual ~MazeMap() = default;

	int height() const { return _height; }
	int width() const  { return _width;  }

	double start_x() const { return _start_x; }
	double start_y() const { return _start_y; }
	double start_dir() const { return _start_dir; }

	int cell(int col, int row) {
		if (col < 0 or col >= width() or row < 0 or row >= height())
			return WALL;
		return _data[width() * row + col];
	}

	bool is_space(int col, int row) {
		if (cell(col, row) == EMPTY) return true;
		return false;
	}

	bool is_space(double col, double row) {
		return is_space(int(floor(col)), int(floor(row)));
	}
};

#endif /* MAZEMAP_H_ */
