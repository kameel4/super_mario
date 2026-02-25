#include "third_level.hpp"

using biv::ThirdLevel;

ThirdLevel::ThirdLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

biv::GameLevel* ThirdLevel::get_next() {
	return next;
}

bool ThirdLevel::is_final() const noexcept {
	return true;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void ThirdLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);

	ui_factory->create_ship({10, 25}, 30, 2);
	ui_factory->create_ship({48, 20}, 22, 2);
	ui_factory->create_ship({76, 16}, 19, 2);
	ui_factory->create_ship({102, 22}, 20, 2);
	ui_factory->create_ship({130, 17}, 24, 2);
	ui_factory->create_ship({160, 24}, 29, 2);

	ui_factory->create_box({56, 12}, 6, 3);
	ui_factory->create_full_box({62, 12}, 5, 3);

	ui_factory->create_full_box({82, 8}, 5, 3);
	ui_factory->create_box({87, 8}, 5, 3);
	ui_factory->create_full_box({92, 8}, 5, 3);

	ui_factory->create_box({140, 9}, 6, 3);
	ui_factory->create_full_box({146, 9}, 5, 3);

	ui_factory->create_jumping_enemy({108, 20}, 3, 2);
	ui_factory->create_flying_enemy({170, 18}, 3, 2);

	ui_factory->create_ship({200, 20}, 20, 7);
}
