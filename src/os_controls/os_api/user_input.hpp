#pragma once

namespace biv {
	namespace os {
		enum class UserInput {
			NO_INPUT = 0,
			EXIT = 1,
			MAP_LEFT = 2,
			MAP_RIGHT = 4,
			MARIO_JUMP = 8
		};

		UserInput operator|(UserInput lhs, UserInput rhs) noexcept;
		bool has_input(UserInput value, UserInput flag) noexcept;
	
		UserInput get_user_input();
	}
}
