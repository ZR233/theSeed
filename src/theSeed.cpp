// theSeed.cpp: 定义应用程序的入口点。
//

#include "theSeed.h"
#include "world/world.h"

using namespace std;

int main()
{

	auto w = std::make_shared<world::World>();
	w->init();
	w->run();







	return 0;
}
