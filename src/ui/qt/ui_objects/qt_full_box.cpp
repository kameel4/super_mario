#include "qt_full_box.hpp"

using biv::QtFullBox;

QtFullBox::QtFullBox(
	const Coord& top_left,
	const int width, const int height,
	UIFactory* ui_factory
) : FullBox(top_left, width, height, ui_factory) {}

QColor QtFullBox::get_color() const noexcept {
	if (is_active_) {
		return QColor(255, 220, 0);
	}
	return QColor(255, 140, 0);
}
