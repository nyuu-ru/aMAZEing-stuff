/*
 * Player.cc
 *
 *  Created on: 12 нояб. 2021 г.
 *      Author: unyuu
 */

#include "Player.h"

static constexpr double Pi = acos(-1);

void Player::spawn(std::shared_ptr<MazeMap> &map)
{
	_map = map;
	_x   = map->start_x();
	_y   = map->start_y();
	_dir = map->start_dir();
}

void Player::walk_forward(double dist)
{
	double nx = _x + dist * cos(_dir);
	double ny = _y + dist * sin(_dir);
	if (_map->is_space(nx, ny)) {
		_x = nx;
		_y = ny;
	}
}

void Player::walk_backward(double dist)
{
	walk_forward(-dist);
}

void Player::shift_right(double dist)
{
	double nx = _x + dist * cos(_dir + Pi/2);
	double ny = _y + dist * sin(_dir + Pi/2);
	if (_map->is_space(nx, ny)) {
		_x = nx;
		_y = ny;
	}
}

void Player::shift_left(double dist)
{
	shift_right(-dist);
}

void Player::turn_right(double angle)
{
	_dir += angle;
	if (_dir >= 2*Pi) _dir -= 2*Pi;
}

void Player::turn_left(double angle)
{
	_dir -= angle;
	if (_dir < 0)
		_dir += 2*Pi;
}

void Player::move_left(double dist)
{
	double nx = _x - dist;
	double ny = _y;
	if (_map->is_space(nx, ny)) {
		_x = nx;
		_y = ny;
	}
}

void Player::move_right(double dist)
{
	move_left(-dist);
}

void Player::move_up(double dist)
{
	double nx = _x;
	double ny = _y - dist;
	if (_map->is_space(nx, ny)) {
		_x = nx;
		_y = ny;
	}
}

void Player::move_down(double dist)
{
	move_up(-dist);
}
