#include "Scene.h"
#include "Cube.h"

Scene::Scene() {

	cubes[0] = Cube(1.0f, 1.0f, 0.0f, -1.0f, 0.0f);
	cubes[1] = Cube(1.0f, 1.0f, 0.0f, 0.0f, 0.0f);
	cubes[3] = Cube(1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
	cubes[2] = Cube(1.0f, 1.0f, 0.0f, 1.0f, 0.0f);
}


void Scene::drawContent() {

	for(int i = 0; i < 4; i++)
		cubes[i].draw();
}