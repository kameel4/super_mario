#include "qt_game_map.hpp"

#include <algorithm>

#include <QColor>
#include <QPainter>
#include <QRect>

using biv::QtGameMap;

QtGameMap::QtGameMap(const int height, const int width)
	: QWidget(nullptr), GameMap(height, width) {
	setWindowTitle("Super Mario");
	setFixedSize(width * CELL_WIDTH, height * CELL_HEIGHT);
}

void QtGameMap::add_obj(QtUIObject* obj) {
	objs.push_back(obj);
}

void QtGameMap::clear() noexcept {}

void QtGameMap::refresh() noexcept {
	update();
}

void QtGameMap::remove_obj(QtUIObject* obj) {
	objs.erase(std::remove(objs.begin(), objs.end(), obj), objs.end());
}

void QtGameMap::remove_objs() {
	objs.clear();
}

void QtGameMap::show() const noexcept {
	const_cast<QtGameMap*>(this)->QWidget::show();
}

void QtGameMap::paintEvent(QPaintEvent*) {
	QPainter painter(this);

	painter.fillRect(rect(), QColor(194, 234, 255));

	const int water_top = (GameMap::height - 3) * CELL_HEIGHT;
	painter.fillRect(
		0, water_top,
		GameMap::width * CELL_WIDTH, 3 * CELL_HEIGHT,
		QColor(90, 170, 230)
	);

	for (QtUIObject* obj: objs) {
		const int left = obj->get_left();
		const int top = obj->get_top();
		const int right = obj->get_right();
		const int bottom = obj->get_bottom();

		const int clipped_left = std::max(0, left);
		const int clipped_top = std::max(0, top);
		const int clipped_right = std::min(GameMap::width, right);
		const int clipped_bottom = std::min(GameMap::height, bottom);

		if (clipped_left >= clipped_right || clipped_top >= clipped_bottom) {
			continue;
		}

		const int pixel_x = clipped_left * CELL_WIDTH;
		const int pixel_y = clipped_top * CELL_HEIGHT;
		const int pixel_w = (clipped_right - clipped_left) * CELL_WIDTH;
		const int pixel_h = (clipped_bottom - clipped_top) * CELL_HEIGHT;

		painter.fillRect(pixel_x, pixel_y, pixel_w, pixel_h, obj->get_color());
	}
}
