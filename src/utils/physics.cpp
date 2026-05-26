#include "physics.h"

bool checkCollision(object &a, object &b) {
	return a.x < b.x + b.width  &&
		   a.x + a.width > b.x  &&
		   a.y < b.y + b.height &&
		   a.y + a.height > b.y;
}

void resolveCollision(object& a, object& b) {
    // find the overlap on each axis
    double overlapX = std::min(a.x + a.width, b.x + b.width) - std::max(a.x, b.x);
    double overlapY = std::min(a.y + a.height, b.y + b.height) - std::max(a.y, b.y);

    // push out along the axis of least overlap
    if (overlapX < overlapY) {
        // push horizontally
        if (a.x < b.x)
            a.x -= overlapX;
        else
            a.x += overlapX;
        a.velocity.x = 0;
    } else {
        // push vertically
        if (a.y < b.y)
            a.y -= overlapY;
        else
            a.y += overlapY;
        a.velocity.y = 0;
    }
}
