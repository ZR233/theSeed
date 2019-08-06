#pragma once
#include "../define/location.h"



namespace world {
	namespace item {
		class Item
		{
		public:
			Item(){};
			~Item() {};

		protected:
			uint32_t type_id;
			world::define::Location location;
		};
	}
}



