#pragma once

#include <vector>

#include <QPaintEvent>
#include <QWidget>

#include "game_map.hpp"
#include "qt_ui_obj.hpp"

namespace biv {
	class QtGameMap : public QWidget, public GameMap {
		private:
			static const int CELL_WIDTH = 7;
			static const int CELL_HEIGHT = 12;
			std::vector<QtUIObject*> objs;

		public:
			QtGameMap(const int height, const int width);

			void add_obj(QtUIObject*);
			void clear() noexcept override;
			void refresh() noexcept override;
			void remove_obj(QtUIObject*);
			void remove_objs() override;
			void show() const noexcept override;

		protected:
			void paintEvent(QPaintEvent*) override;
	};
}
