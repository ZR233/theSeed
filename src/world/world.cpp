#include "world.h"


namespace world {


	World::World()
	{
		space_ = std::make_shared<world::space::Space>();
	}

	std::shared_ptr<world::space::Space> World::getSpace()
	{
		return space_;
	}

}