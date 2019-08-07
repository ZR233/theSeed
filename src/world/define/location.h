#pragma once
#include <stdint.h>

namespace world {
	namespace define {
		class Location
		{
		public:
			Location() = default;

			Location(uint64_t x, uint64_t y, uint64_t z) {
				this->x = x;
				this->y = y;
				this->z = z;
			}
			uint64_t x = 0;
			uint64_t y = 0;
			uint64_t z = 0;
		};
	}
}

