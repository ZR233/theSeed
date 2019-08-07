#include "item.h"

std::weak_ptr<world::space::Space> world::item::Item::getSpace()
{
	return std::weak_ptr<world::space::Space>();
}
