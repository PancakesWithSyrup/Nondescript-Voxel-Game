#pragma once
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>




#include "Shader.h"
#include "Camera.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class Game {
public:
	Game(const char* windowName, const int windowHeight, const int windowWidth);
	~Game();

private:
	GLFWwindow* window;

	GLFWwindow* createWindow(const char* windowName, const int windowHeight, const int windowWidth);
	void processInput(GLFWwindow* window);
	void mainLoop();
};
