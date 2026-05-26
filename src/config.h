#pragma once

#include "raylib.h"

#include <cstdint>
#include <iostream>
#include <vector>

#define WIDTH 1280
#define HEIGHT 720

#define G 9.8

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

struct object {
	uint8 width;
	uint8 height;

	double x;
	double y;

	Vector2 force;
	float torque;

	Vector2 velocity;
	Vector2 acceleration;

	double mass = 0;
	double momentOfInertia;

	double roation;
	float angularVel;

	bool isStatic;

	Color color = RAYWHITE;

	void update(float dt) {

		// apply gravity F = g x m

		force.y = G * mass;

		// apply acceleration f = ma
		acceleration.y = force.y / mass;

		// apply acceleration
		velocity.x += acceleration.x;
		velocity.y += acceleration.y;

		x += velocity.x * dt;
		y += velocity.y * dt;

		// reset acceleration
		acceleration.x = 0;
		acceleration.y = 0;

	}

	void draw() {
		
		DrawRectangle((int)x, (int)y, width, height, color);

	}
};
