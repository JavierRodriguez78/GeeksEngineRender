// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include "Logger.h"
#include <Windows.h>
#include "Window.h"

int main(void)
{

	Logger::Message("OpenGL functions succesfully loaded.", LOG_INIT);
	Window::Up();


}