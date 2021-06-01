#include "Window.h"
#include <GLFW/glfw3.h>
#include "Logger.h"

	Window::Window(const char* title, int width, int height) {
		
	}

	 void Window::Up() {
		 glfwInit();

		 glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		 GLFWwindow* window = glfwCreateWindow(1280, 720, "GLFW OpenGL", NULL,  NULL);
		 glfwMakeContextCurrent(window);
		

		
		if (window) {
			Logger::Message("Window Create.", LOG_DEBUG);
		}
		else {
			Logger::Message("Error create Window", LOG_ERROR);
		
		}

		while (!glfwWindowShouldClose(window)) {
			glfwPollEvents();

			glClearColor(0.3, 0.3, 0.3, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(window);
		}
		glfwDestroyWindow(window);
		glfwTerminate();
	}


