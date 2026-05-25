#pragma once

#include "config.h"

class Simulation {
	public:
		Simulation();
		~Simulation();
		void Run();
	
	private:
		void Update(float dt);
		void Draw();
};
