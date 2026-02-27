#include "qt_jumping_enemy.hpp"

using biv::QtJumpingEnemy;

QtJumpingEnemy::QtJumpingEnemy(const Coord& top_left, const int width, const int height)
	: JumpingEnemy(top_left, width, height) {}

QColor QtJumpingEnemy::get_color() const noexcept {
	return QColor(128, 0, 128);
}
