#pragma once

#include "space/space.h"
#include "define/location.h"
#include "item/item.h"

namespace world {
	class World
	{
	public:
		World();
		~World()=default;

		std::shared_ptr<world::space::Space> getSpace();

	private:
		std::shared_ptr<world::space::Space> space_;
	};

}
