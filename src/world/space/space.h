#pragma once
#include <memory>
#include "../define/location.h"
#include "..//item/item.h"
#include <map>



namespace world {
	namespace space {

		class Space
		{
		public:
			Space()=default;
			~Space()=default;


			void addItem(world::define::Location location, std::shared_ptr<world::item::Item>);


		protected:
			using axis = std::map<uint64_t, std::map<uint64_t ,std::map<uint64_t,std::shared_ptr<world::item::Item>>>>;

			axis quadrant1_;
			axis quadrant2_;
			axis quadrant3_;
			axis quadrant4_;
			axis quadrant5_;
			axis quadrant6_;
			axis quadrant7_;
			axis quadrant8_;

			void quadrantSetItem(axis& quadrant, world::define::Location location, std::shared_ptr<world::item::Item>);
		};
	}
}