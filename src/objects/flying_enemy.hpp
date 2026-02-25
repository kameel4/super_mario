#pragma once

#include "enemy.hpp"

namespace biv {
	class FlyingEnemy : public Enemy {
		private:
			static constexpr float FLY_SPEED = 0.2f;
			static constexpr float FLY_RANGE = 8.0f;
			float left_limit;
			float right_limit;

		public:
			FlyingEnemy(const Coord& top_left, const int width, const int height);

			void move_map_left() noexcept override;
			void move_map_right() noexcept override;
			void move_horizontally() noexcept override;
			void move_vertically() noexcept override;
			void process_mario_collision(Collisionable*) noexcept override;
			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
	};
}
