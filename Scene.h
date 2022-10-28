#pragma once
#include "Cube.h"

class Scene {

public:
	Scene();
	virtual ~Scene() = default;

	Cube cubes[12];
	void drawContent();
};