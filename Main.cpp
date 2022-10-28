#include <GLFW/glfw3.h>
#include <Windows.h>
#include "Entity.h"
#include <GLFW/glut.h>
#include <thread>
#include <chrono>

#include "Renderer.h"

int main(int argc, char **argv) {

    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(800, 600, "fuk u", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    Renderer rRenderer = Renderer(144);
    double lasttime = glfwGetTime();


    while (!glfwWindowShouldClose(window)) {
        rRenderer.render(*window);
        while (glfwGetTime() < lasttime + 1.0 / 144) { }
        lasttime += 1.0 / 144;
    }

    glfwTerminate();
    return 0;
}