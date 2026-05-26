#include "simulation.h"
#include "utils/physics.h"

// constructor, inits window and sets target fps
Simulation::Simulation() {
	InitWindow(WIDTH, HEIGHT, "classical mechanics simulation");
	SetTargetFPS(60);
	AddObject(50, 50, 100, 100, 20, BLACK);
	AddStaticObject(1040, 50, 0, HEIGHT-50, BLUE);
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
		if (obj.isStatic) continue;
		obj.update(dt);
	}

	// check for collisions
	for (int i = 0; i < objects.size(); ++i) {
		for (int j = i + 1; j < objects.size(); ++j) {
			if (checkCollision(objects[i], objects[j])) {
				if (!objects[i].isStatic) {
					resolveCollision(objects[i], objects[j]);
				}
				else if (!objects[j].isStatic) {
					resolveCollision(objects[j], objects[i]);
				}
			}
		}
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

void Simulation::AddStaticObject(uint16 width, uint16 height, double x, double y, Color color) {
	object obj;
	obj.x = x;
	obj.y = y;
	obj.width = width;
	obj.height = height;
	obj.color = color;
	obj.isStatic = true;
	
	objects.push_back(obj);
}
