#include "flying_enemy.hpp"

using biv::FlyingEnemy;

FlyingEnemy::FlyingEnemy(const Coord& top_left, const int width, const int height)
	: Enemy(top_left, width, height),
	  left_limit(top_left.x - FLY_RANGE),
	  right_limit(top_left.x + FLY_RANGE) {
	hspeed = FLY_SPEED;
	vspeed = 0;
}

void FlyingEnemy::move_map_left() noexcept {
	Enemy::move_map_left();
	left_limit -= MapMovable::MAP_STEP;
	right_limit -= MapMovable::MAP_STEP;
}

void FlyingEnemy::move_map_right() noexcept {
	Enemy::move_map_right();
	left_limit += MapMovable::MAP_STEP;
	right_limit += MapMovable::MAP_STEP;
}

void FlyingEnemy::move_horizontally() noexcept {
	top_left.x += hspeed;
	if (top_left.x <= left_limit) {
		top_left.x = left_limit;
		hspeed = FLY_SPEED;
	} else if (top_left.x >= right_limit) {
		top_left.x = right_limit;
		hspeed = -FLY_SPEED;
	}
}

void FlyingEnemy::move_vertically() noexcept {}

void FlyingEnemy::process_mario_collision(Collisionable* mario) noexcept {
	mario->kill();
}

void FlyingEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void FlyingEnemy::process_vertical_static_collision(Rect* obj) noexcept {}
