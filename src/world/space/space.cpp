#include "space.h"
#include "../item/item.h"
#include <vector>



#include "space.h"

namespace world {
	namespace space {
		void Space::addItem(world::define::Location location, std::shared_ptr<world::item::Item> itemPtr)
		{
			if (location.x >= 0
				&& location.y >= 0
				&& location.z >= 0) {
				quadrantSetItem(quadrant1_, location, itemPtr);
			}
			else if (
				location.x < 0
				&& location.y > 0
				&& location.z > 0
				)
			{
				quadrantSetItem(quadrant2_, location, itemPtr);
			}
			else if (
				location.x < 0
				&& location.y < 0
				&& location.z > 0
				)
			{
				quadrantSetItem(quadrant3_, location, itemPtr);
			}
			else if (
				location.x > 0
				&& location.y < 0
				&& location.z > 0
				)
			{
				quadrantSetItem(quadrant4_, location, itemPtr);
			}
			else if (
				location.x > 0
				&& location.y > 0
				&& location.z < 0
				)
			{
				quadrantSetItem(quadrant5_, location, itemPtr);
			}
			else if (
				location.x < 0
				&& location.y > 0
				&& location.z < 0
				)
			{
				quadrantSetItem(quadrant6_, location, itemPtr);
			}
			else if (
				location.x < 0
				&& location.y < 0
				&& location.z < 0
				)
			{
				quadrantSetItem(quadrant7_, location, itemPtr);
			}
			else if (
				location.x > 0
				&& location.y < 0
				&& location.z < 0
				)
			{
				quadrantSetItem(quadrant8_, location, itemPtr);
			}
			else {
				throw std::exception();
			}
		}
		void Space::quadrantSetItem(axis& quadrant, world::define::Location location, std::shared_ptr<world::item::Item> itemPtr)
		{
			if (quadrant.find(location.x) == quadrant.end())
				quadrant[location.x] = std::map<uint64_t, std::map<uint64_t, std::shared_ptr<world::item::Item>>>();

			if (quadrant[location.x].find(location.y) == quadrant[location.x].end())
				quadrant[location.x][location.y] = std::map<uint64_t, std::shared_ptr<world::item::Item>>();

			quadrant[location.x][location.y][location.z] = itemPtr;

		}
	}
}



