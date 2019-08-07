#pragma once
#include <memory>
#include "../define/location.h"
#include "..//item/item.h"
#include <map>



namespace world {
	namespace space {

		using axisZ = std::map< uint64_t, std::shared_ptr < world::item::Item>>;
		using axisYZ = std::map< uint64_t, std::shared_ptr <axisZ>>;
		using axisXYZ = std::map< uint64_t, std::shared_ptr <axisYZ>>;
		using axis =std::shared_ptr<axisXYZ>;

		class Space:public std::enable_shared_from_this<Space>
		{
		public:
			Space();
			~Space()=default;


			void addItem(world::define::Location location, std::shared_ptr<world::item::Item>);
			void setItem(world::define::Location location, std::shared_ptr<world::item::Item>);
			std::weak_ptr<world::item::Item> getItemByLocation(world::define::Location location);

		protected:
			

			axis quadrant1_ = std::make_shared<axisXYZ>();
			axis quadrant2_ = std::make_shared<axisXYZ>();
			axis quadrant3_ = std::make_shared<axisXYZ>();
			axis quadrant4_ = std::make_shared<axisXYZ>();
			axis quadrant5_ = std::make_shared<axisXYZ>();
			axis quadrant6_ = std::make_shared<axisXYZ>();
			axis quadrant7_ = std::make_shared<axisXYZ>();
			axis quadrant8_ = std::make_shared<axisXYZ>();

			void quadrantSetItem(std::weak_ptr<axisXYZ> quadrantPtr, world::define::Location location, std::shared_ptr<world::item::Item>);
			
			std::weak_ptr<axisXYZ> getQuadrantBy(world::define::Location location);
		};
	}
}