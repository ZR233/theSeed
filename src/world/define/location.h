#pragma once
#include <stdint.h>

namespace world {
	namespace define {
		class Location
		{
		public:
			Location() = default;

			Location(int64_t x, int64_t y, int64_t z) {
				this->x = x;
				this->y = y;
				this->z = z;
			}
			int64_t x = 0;
			int64_t y = 0;
			int64_t z = 0;
		};
	}
}

