#pragma once

#include "config.h"
#include "./utils/physics.h"

class Simulation {
	public:
		Simulation();
		~Simulation();
		void Run();

		std::vector<object> objects;
	
	private:
		void Update(float dt);
		void Draw();

		void AddObject(uint8 width, uint8 height, double x, double y, double mass, Color color);
		void AddStaticObject(uint16 width, uint16 height, double x, double y, Color color);
};
