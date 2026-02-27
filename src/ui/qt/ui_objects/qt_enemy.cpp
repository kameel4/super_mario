#include "qt_enemy.hpp"

using biv::QtEnemy;

QtEnemy::QtEnemy(const Coord& top_left, const int width, const int height)
	: Enemy(top_left, width, height) {}

QColor QtEnemy::get_color() const noexcept {
	return QColor(128, 0, 128);
}
