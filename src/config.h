#pragma once

#include "raylib.h"

#include <cstdint>
#include <iostream>

#define WIDTH 1280
#define HEIGHT 720

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
};
