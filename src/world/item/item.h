#pragma once
#include "../define/location.h"

#include <memory>



namespace world {
	namespace space {
		class Space;
	}
	

	namespace item {
		class Item
		{
		public:
			Item(){};
			~Item() {};

			std::weak_ptr<world::space::Space> getSpace();

		protected:
			uint32_t type_id_;
			world::define::Location location;
			std::weak_ptr<world::space::Space> space_;

			friend world::space::Space;
		};
	}
}



