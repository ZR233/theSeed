#include "world.h"
#include "world.h"
#include <thread>


namespace world {


	World::World()
	{
		space_ = std::make_shared<world::space::Space>();
	}


	void World::pushTask(Task task)
	{
		std::lock_guard<std::mutex> g(tasksMu_);
		tasks_.push(task);
	}

	void World::init() {

	}


	void World::run() {
		lastLoopBeginTime_ = std::chrono::steady_clock::now();
		lastLoopEndTime_ = lastLoopBeginTime_;

		while (!stop_)
		{
			std::this_thread::sleep_until(lastLoopBeginTime_ + loopInterval_);
			auto lastLoopBeginTime = lastLoopBeginTime_;
			lastLoopBeginTime_ = std::chrono::steady_clock::now();

			Context ctx;
			ctx.lastLoopBeginTime = lastLoopBeginTime_;
			ctx.lastLoopEndTime = lastLoopEndTime_;
			ctx.space = space_;

			std::queue<Task> tasks;

			{
				std::lock_guard<std::mutex> g(tasksMu_);
				std::swap(tasks, tasks_);
			}
			while (!tasks.empty())
			{
				auto task = tasks.front();
				tasks.pop();
				task(ctx);
			}

			lastLoopEndTime_ = std::chrono::steady_clock::now();
		}
	}

}