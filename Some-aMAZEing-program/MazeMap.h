/*
 * MazeMap.h
 *
 *  Created on: 12 нояб. 2021 г.
 *      Author: unyuu
 */

#ifndef MAZEMAP_H_
#define MAZEMAP_H_

#include <vector>


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
public:
	MazeMap(const char *filename);
	virtual ~MazeMap() = default;

	int height() const { return _height; }
	int width() const  { return _width;  }

	int cell(int col, int row) {
		if (col < 0 or col >= width() or row < 0 or row >= height())
			return WALL;
		return _data[width() * row + col];
	}
};

#endif /* MAZEMAP_H_ */
