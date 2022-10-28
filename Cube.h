#pragma once

class Cube {

public:

	Cube(float w, float h, float centerX, float centerY, float centerZ);
	Cube() = default;
	virtual ~Cube() = default;

	float width;
	float height;
	float coord[8][3];
	float center[3];
	float a;

	void draw();



};