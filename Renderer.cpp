#include <GLFW/glfw3.h>
#include "Renderer.h"
#include "Scene.h"

Renderer::Renderer(int fps) {


    Scene scene = Scene();

	framerate = fps;

	timerLimit = 1000 / fps;
	timerCurrent = 0;

}


void Renderer::render(GLFWwindow& window) {

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(0.5, 0.5, 0.5);
    glShadeModel(GL_SMOOTH);

    //gluLookAt(0.0f, 1.0f, -5.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f);

    float lightDiffuse[] = { 1.0f, 1.0f, 0.0f, 1.0f };
    float lightAmbient[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    float lightPosition[] = { 1.0f, 1.0f, -1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);


    //Render 


    scene.drawContent();


    //------

    glfwSwapBuffers(&window);

    glfwPollEvents();
}

bool Renderer::timerGet() { return timerCurrent == timerLimit; }

void Renderer::timerRun() {
    timerCurrent++;
    if (timerCurrent > timerLimit) timerCurrent = 0;
}