#include "simulation.h"

// constructor, inits window and sets target fps
Simulation::Simulation() {
	InitWindow(WIDTH, HEIGHT, "classical mechanics simulation");
	SetTargetFPS(60);
}

// destructor
Simulation::~Simulation() {
	CloseWindow();
}

// main loop
void Simulation::Run() {
	while (!WindowShouldClose()) {
		float dt = GetFrameTime();
		Update(dt);
		Draw();
	}
}

void Simulation::Update(float dt) {

}

void Simulation::Draw() {
	BeginDrawing();
	ClearBackground(RAYWHITE);
	EndDrawing();
}
