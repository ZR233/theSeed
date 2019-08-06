// theSeed.cpp: 定义应用程序的入口点。
//

#include "theSeed.h"
#include "world/world.h"

using namespace std;

int main()
{

	auto w = world::World();

	auto s = w.getSpace();



	auto i = std::make_shared<world::item::Item>();
	world::define::Location location(1,1,3);


	s->addItem(location, i);

	cout << "Hello CMake。" << endl;
	return 0;
}
