#include "simulation.h"

// constructor, inits window and sets target fps
Simulation::Simulation() {
	InitWindow(WIDTH, HEIGHT, "classical mechanics simulation");
	SetTargetFPS(60);
	AddObject(50, 50, 100, 100, 20, BLACK);
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
	for (object& obj : objects) {
		obj.update(dt);
	}
}

void Simulation::Draw() {
	BeginDrawing();
	ClearBackground(RAYWHITE);

	// draw each object

	for (object& obj : objects) {
		obj.draw();
	}

	EndDrawing();
}

void Simulation::AddObject(uint8 width, uint8 height, double x, double y, double mass, Color color) {
	object obj;
	obj.x = x;
	obj.y = y;
	obj.width = width;
	obj.height = height;
	obj.mass = mass;
	obj.color = color;
	
	objects.push_back(obj);
}
