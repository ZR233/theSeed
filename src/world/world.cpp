#include "world.h"
#include "item/stone.h"
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
		auto item0 = std::make_shared<world::item::Item>();
		auto item1 = std::make_shared<world::item::Stone>();
		auto item2 = std::make_shared<world::item::Item>();
		auto item3 = std::make_shared<world::item::Item>();
		auto item4 = std::make_shared<world::item::Item>();
		auto item5 = std::make_shared<world::item::Item>();
		auto item6 = std::make_shared<world::item::Item>();
		auto item7 = std::make_shared<world::item::Item>();
		auto item8 = std::make_shared<world::item::Item>();



		space_->addItem(item0, world::define::Location(0, 0, 0));
		space_->addItem(item1, world::define::Location(1, 1, 1));
		space_->addItem(item2, world::define::Location(-1, 1, 1));
		space_->addItem(item3, world::define::Location(-1, -1, 1));
		space_->addItem(item4, world::define::Location(1, -1, 1));
		space_->addItem(item5, world::define::Location(1, 1, -1));
		space_->addItem(item6, world::define::Location(-1, 1, -1));
		space_->addItem(item7, world::define::Location(-1, -1, -1));
		space_->addItem(item8, world::define::Location(1, -1, -1));
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