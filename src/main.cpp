#include <thread>

#include <QApplication>
#include <QWidget>

#include "first_level.hpp"
#include "game.hpp"
#include "game_level.hpp"
#include "game_map.hpp"
#include "mario.hpp"
#include "os_control_settings.hpp"
#include "qt_ui_factory.hpp"
#include "ui_factory.hpp"
#include "user_input.hpp"

int main(int argc, char* argv[]) {
	using namespace std::chrono_literals;

	QApplication app(argc, argv);
	biv::os::init_settings();

	biv::Game game;
	biv::UIFactory* ui_factory = new biv::QtUIFactory(&game);
	biv::GameMap* game_map = ui_factory->get_game_map();
	biv::GameLevel* game_level = new biv::FirstLevel(ui_factory);
	biv::Mario* mario = ui_factory->get_mario();

	game_map->show();

	biv::os::UserInput user_input;
	do {
		app.processEvents();

		QWidget* game_widget = dynamic_cast<QWidget*>(game_map);
		if (game_widget && !game_widget->isVisible()) {
			game.finish();
		}

		user_input = biv::os::get_user_input();
		bool map_left = biv::os::has_input(user_input, biv::os::UserInput::MAP_LEFT);
		bool map_right = biv::os::has_input(user_input, biv::os::UserInput::MAP_RIGHT);
		if (map_left && !map_right) {
			mario->move_map_left();
			if (!game.check_static_collisions(mario)) {
				game.move_map_left();
			}
			mario->move_map_right();
		} else if (map_right && !map_left) {
			mario->move_map_right();
			if (!game.check_static_collisions(mario)) {
				game.move_map_right();
			}
			mario->move_map_left();
		}
		if (biv::os::has_input(user_input, biv::os::UserInput::MARIO_JUMP)) {
			mario->jump();
		}
		if (biv::os::has_input(user_input, biv::os::UserInput::EXIT)) {
			game.finish();
		}

		game.move_objs_horizontally();
		game.check_horizontally_static_collisions();

		game.move_objs_vertically();
		game.check_mario_collision();
		game.check_vertically_static_collisions();

		if (
			game_map->is_below_map(mario->get_top())
			|| !mario->is_active()
		) {
			game_level->restart();
			mario = ui_factory->get_mario();
			std::this_thread::sleep_for(1000ms);
		}

		if (game.is_level_end()) {
			if (!game_level->is_final()) {
				game_level = game_level->get_next();
				mario = ui_factory->get_mario();
				std::this_thread::sleep_for(1000ms);
				game.start_level();
			} else {
				game.finish();
			}
		}

		game_map->refresh();
		std::this_thread::sleep_for(10ms);
	} while (!game.is_finished());

	return 0;
}
