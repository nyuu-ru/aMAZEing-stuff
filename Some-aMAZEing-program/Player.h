/*
 * Player.h
 *
 *  Created on: 12 нояб. 2021 г.
 *      Author: unyuu
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <memory>
#include <cmath>
#include "MazeMap.h"

class Player
{
public:
	static constexpr double TURN_ANGLE = acos(-1) / 90;
	static constexpr double STEP_LENGTH = 0.05;
protected:
	double _x {}, _y {};
	double _dir {};
	std::shared_ptr<MazeMap> _map;
public:
	Player() = default;
	virtual ~Player() = default;

	void spawn(std::shared_ptr<MazeMap> &map);

	double dir() const { return _dir; }
	double x() const   { return _x;   }
	double y() const   { return _y;   }

	void walk_forward(double dist = STEP_LENGTH);
	void walk_backward(double dist = STEP_LENGTH);
	void shift_right(double dist = STEP_LENGTH);
	void shift_left(double dist = STEP_LENGTH);
	void turn_right(double angle = TURN_ANGLE);
	void turn_left(double angle = TURN_ANGLE);

	void move_left(double dist = STEP_LENGTH);
	void move_right(double dist = STEP_LENGTH);
	void move_up(double dist = STEP_LENGTH);
	void move_down(double dist = STEP_LENGTH);
};

#endif /* PLAYER_H_ */
