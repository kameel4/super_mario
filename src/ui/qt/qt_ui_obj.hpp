#pragma once

#include <QColor>

namespace biv {
	class QtUIObject {
		public:
			virtual int get_bottom() const noexcept = 0;
			virtual QColor get_color() const noexcept = 0;
			virtual int get_height() const noexcept = 0;
			virtual int get_left() const noexcept = 0;
			virtual int get_right() const noexcept = 0;
			virtual int get_top() const noexcept = 0;
	};
}
