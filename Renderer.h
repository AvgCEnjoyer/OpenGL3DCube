#include <GLFW/glfw3.h>
#include "Scene.h"
#pragma once


class Renderer {

public:

	Renderer(int fps);
	virtual ~Renderer() = default;

	Scene scene;

	void render(GLFWwindow& window);

private:

	int timerLimit;
	int timerCurrent;

	int framerate;

	bool timerGet();
	void timerRun();

};