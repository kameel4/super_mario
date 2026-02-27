#include "qt_money.hpp"

using biv::QtMoney;

QtMoney::QtMoney(const Coord& top_left, const int width, const int height)
	: Money(top_left, width, height) {}

QColor QtMoney::get_color() const noexcept {
	return QColor(255, 215, 0);
}
