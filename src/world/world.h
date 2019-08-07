#pragma once


#include "define/location.h"
#include "space/space.h"
#include <chrono>
#include <atomic>
#include <queue>
#include <functional>
#include <mutex>

namespace world {






	class Context
	{
	public:
		std::chrono::steady_clock::time_point lastLoopBeginTime;
		std::chrono::steady_clock::time_point lastLoopEndTime;
		std::weak_ptr<world::space::Space> space;
	};

	using Task = std::function<void(Context ctx)>;


	class World
	{
	public:
		World();
		~World()=default;

		void pushTask(Task task);

		void init();
		void run();
	private:	
		std::atomic_bool stop_ = false;
		std::shared_ptr< world::space::Space> space_;


		std::chrono::steady_clock::time_point lastLoopBeginTime_;
		std::chrono::steady_clock::time_point lastLoopEndTime_;

		std::chrono::nanoseconds loopInterval_;

		std::mutex tasksMu_;
		std::queue<Task> tasks_;
	};

}
