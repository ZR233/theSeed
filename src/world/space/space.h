#pragma once
#include <memory>
#include "../define/location.h"
#include "..//item/item.h"
#include <map>



namespace world {
	namespace space {

		using axisZ = std::map< int64_t, std::shared_ptr < world::item::Item>>;
		using axisYZ = std::map< int64_t, std::shared_ptr <axisZ>>;
		using axisXYZ = std::map< int64_t, std::shared_ptr <axisYZ>>;
		using axis =std::shared_ptr<axisXYZ>;

		class Space:public std::enable_shared_from_this<Space>
		{
		public:
			Space();
			~Space()=default;


			void addItem(std::shared_ptr<world::item::Item> itemPtr, world::define::Location location);
			void setItem(std::shared_ptr<world::item::Item> itemPtr, world::define::Location location);
			std::weak_ptr<world::item::Item> getItemByLocation(world::define::Location location);
			void moveItem(std::shared_ptr<world::item::Item> itemPtr, world::define::Location location);


		protected:
			

			axis quadrant_ = std::make_shared<axisXYZ>();

			void quadrantSetItem(std::weak_ptr<axisXYZ> quadrantPtr, world::define::Location location, std::shared_ptr<world::item::Item>);
			
			//std::weak_ptr<axisXYZ> getQuadrantBy(world::define::Location &location);
		};
	}
}