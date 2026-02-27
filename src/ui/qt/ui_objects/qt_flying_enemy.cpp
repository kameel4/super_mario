#include "qt_flying_enemy.hpp"

using biv::QtFlyingEnemy;

QtFlyingEnemy::QtFlyingEnemy(const Coord& top_left, const int width, const int height)
	: FlyingEnemy(top_left, width, height) {}

QColor QtFlyingEnemy::get_color() const noexcept {
	return QColor(128, 0, 128);
}
