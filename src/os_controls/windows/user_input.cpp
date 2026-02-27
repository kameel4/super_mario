#include "user_input.hpp"

#include <windows.h>

using biv::os::UserInput;

UserInput biv::os::operator|(UserInput lhs, UserInput rhs) noexcept {
	return static_cast<UserInput>(
		static_cast<int>(lhs) | static_cast<int>(rhs)
	);
}

bool biv::os::has_input(UserInput value, UserInput flag) noexcept {
	return (static_cast<int>(value) & static_cast<int>(flag)) != 0;
}

UserInput biv::os::get_user_input() {
	UserInput input = UserInput::NO_INPUT;

	if (GetAsyncKeyState('A') < 0) {
		input = input | UserInput::MAP_RIGHT;
	}

	if (GetAsyncKeyState('D') < 0) {
		input = input | UserInput::MAP_LEFT;
	}

	if (GetAsyncKeyState(VK_SPACE) < 0) {
		input = input | UserInput::MARIO_JUMP;
	}

	if (GetAsyncKeyState(VK_ESCAPE) < 0) {
		input = input | UserInput::EXIT;
	}

	return input;
}
