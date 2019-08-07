#include "space.h"
#include "../item/item.h"
#include <vector>



#include "space.h"

namespace world {
	namespace space {
		Space::Space()
		{
		}


		void Space::addItem(std::shared_ptr<world::item::Item> itemPtr, world::define::Location location)
		{
			auto itemOrigin = getItemByLocation(location);
			if (itemOrigin.expired()){
				setItem(itemPtr, location);
			}
		}
		void Space::setItem(std::shared_ptr<world::item::Item> itemPtr, world::define::Location location)
		{
			auto quadrant = std::weak_ptr<axisXYZ>(quadrant_);
			quadrantSetItem(quadrant, location, itemPtr);
		}
		void Space::moveItem(std::shared_ptr<world::item::Item> itemPtr, world::define::Location location)
		{
			auto quadrant = std::weak_ptr<axisXYZ>(quadrant_);
			quadrantSetItem(quadrant, location, itemPtr);
		}



		void Space::quadrantSetItem(std::weak_ptr<axisXYZ> quadrantPtr, world::define::Location location, std::shared_ptr<world::item::Item> itemPtr)
		{
			if (!quadrantPtr.expired())
			{
				//it is getting valid shared_ptr obj now;
				auto  xyz = quadrantPtr.lock();
				std::weak_ptr<axisYZ> yzPtr;
				try
				{
					yzPtr = (xyz->at(location.x));
				}
				catch (const std::exception&)
				{
					(*xyz)[location.x] = std::make_shared<axisYZ>();
					yzPtr = (xyz->at(location.x));
				}

				if (!yzPtr.expired())
				{
					//it is getting valid shared_ptr obj now;
					auto yz = yzPtr.lock();
					std::weak_ptr<axisZ> zPtr;
					try
					{
						zPtr = (yz->at(location.y));
					}
					catch (const std::exception&)
					{
						(*yz)[location.y] = std::make_shared<axisZ>();
						zPtr = (yz->at(location.y));
					}

					if (!zPtr.expired())
					{
						//it is getting valid shared_ptr obj now;
						auto z = zPtr.lock();

						(*z)[location.z] = itemPtr;
					}
				}
			}

	
			itemPtr->location = location;
			itemPtr->space_ = shared_from_this();
			
		}
		std::weak_ptr<world::item::Item> Space::getItemByLocation(world::define::Location location)
		{
			std::weak_ptr<world::item::Item> itemPtr;
			std::weak_ptr<axisXYZ> quadrantPtr(quadrant_);
			if (!quadrantPtr.expired())
			{
				auto xyz = quadrantPtr.lock();
				try
				{
					auto yzPtr = xyz->at(location.x);
					auto zPtr = yzPtr->at(location.y);
					itemPtr = zPtr->at(location.z);
				}
				catch (const std::exception&){}
			}

			return itemPtr;
		
		}

		/*std::weak_ptr<axisXYZ> Space::getQuadrantBy(world::define::Location &location) {
			if (location.x >= 0
				&& location.y >= 0
				&& location.z >= 0) {
				return std::weak_ptr<axisXYZ>(quadrant1_);
			}
			else if (
				location.x < 0
				&& location.y > 0
				&& location.z > 0
				)
			{
				location.x = -location.x;
				return std::weak_ptr<axisXYZ>(quadrant2_);
			}
			else if (
				location.x < 0
				&& location.y < 0
				&& location.z > 0
				)
			{
				location.x = -location.x;
				location.y = -location.y;

				return std::weak_ptr<axisXYZ>(quadrant3_);
			}
			else if (
				location.x > 0
				&& location.y < 0
				&& location.z > 0
				)
			{
				location.y = -location.y;
				return std::weak_ptr<axisXYZ>(quadrant4_);
			}
			else if (
				location.x > 0
				&& location.y > 0
				&& location.z < 0
				)
			{
				location.z = -location.z;
				return std::weak_ptr<axisXYZ>(quadrant5_);
			}
			else if (
				location.x < 0
				&& location.y > 0
				&& location.z < 0
				)
			{
				location.x = -location.x;
				location.z = -location.z;
				return std::weak_ptr<axisXYZ>(quadrant6_);
			}
			else if (
				location.x < 0
				&& location.y < 0
				&& location.z < 0
				)
			{
				location.x = -location.x;
				location.y = -location.y;
				location.z = -location.z;
				return std::weak_ptr<axisXYZ>(quadrant7_);
			}
			else if (
				location.x > 0
				&& location.y < 0
				&& location.z < 0
				)
			{
				location.y = -location.y;
				location.z = -location.z;
				return std::weak_ptr<axisXYZ>(quadrant8_);
			}
			else {
				throw std::exception();
			}
		}*/
	}
}



