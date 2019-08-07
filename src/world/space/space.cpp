#include "space.h"
#include "../item/item.h"
#include <vector>



#include "space.h"

namespace world {
	namespace space {
		Space::Space()
		{
		}


		void Space::addItem(world::define::Location location, std::shared_ptr<world::item::Item> itemPtr)
		{
			auto itemOrigin = getItemByLocation(location);
			if (itemOrigin.expired()){
				auto quadrant = getQuadrantBy(location);
				quadrantSetItem(quadrant, location, itemPtr);
			}
		}
		void Space::setItem(world::define::Location location, std::shared_ptr<world::item::Item> itemPtr)
		{
			auto quadrant = getQuadrantBy(location);
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

		

			//if (quadrant.find(location.x) == quadrant.end())
			//	quadrant[location.x] = std::map<uint64_t, std::map<uint64_t, std::shared_ptr<world::item::Item>>>();

			//if (quadrant[location.x].find(location.y) == quadrant[location.x].end())
			//	quadrant[location.x][location.y] = std::map<uint64_t, std::shared_ptr<world::item::Item>>();

			//quadrant[location.x][location.y][location.z] = itemPtr;
			itemPtr->location = location;
			itemPtr->space_ = shared_from_this();
			
		}
		std::weak_ptr<world::item::Item> Space::getItemByLocation(world::define::Location location)
		{
			std::weak_ptr<world::item::Item> itemPtr;
			auto quadrantPtr = getQuadrantBy(location);
			if (!quadrantPtr.expired())
			{
				//it is getting valid shared_ptr obj now;
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

		std::weak_ptr<axisXYZ> Space::getQuadrantBy(world::define::Location location) {
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
				return std::weak_ptr<axisXYZ>(quadrant2_);
			}
			else if (
				location.x < 0
				&& location.y < 0
				&& location.z > 0
				)
			{
				return std::weak_ptr<axisXYZ>(quadrant3_);
			}
			else if (
				location.x > 0
				&& location.y < 0
				&& location.z > 0
				)
			{
				return std::weak_ptr<axisXYZ>(quadrant4_);
			}
			else if (
				location.x > 0
				&& location.y > 0
				&& location.z < 0
				)
			{
				return std::weak_ptr<axisXYZ>(quadrant5_);
			}
			else if (
				location.x < 0
				&& location.y > 0
				&& location.z < 0
				)
			{
				return std::weak_ptr<axisXYZ>(quadrant6_);
			}
			else if (
				location.x < 0
				&& location.y < 0
				&& location.z < 0
				)
			{
				return std::weak_ptr<axisXYZ>(quadrant7_);
			}
			else if (
				location.x > 0
				&& location.y < 0
				&& location.z < 0
				)
			{
				return std::weak_ptr<axisXYZ>(quadrant8_);
			}
			else {
				throw std::exception();
			}
		}
	}
}



