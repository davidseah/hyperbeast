#include "framework.h"

#include <iostream>

// settings

void framework::framebuffer_size_callback(GLFWwindow* window,
										  int width,
										  int height)
{
	glViewport(0, 0, width, height);
}

void framework::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if(boFirstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		boFirstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;

	lastX = xpos;
	lastY = ypos;


	frameworkCamera.ProcessMouseMovement(xoffset, yoffset);
}

void framework::scroll_callback(GLFWwindow* window,
								double xoffset,
								double yoffset)
{
	frameworkCamera.ProcessMouseMovement(xoffset, yoffset);

}

framework::framework(Camera inputCamera) : 
		frameworkCamera(inputCamera),
		boFirstMouse(true),
		lastX(SCR_WIDTH/2.0f),
		lastY(SCR_HEIGHT/2.0f)
{

}

framework::~framework()
{
}

bool framework::vInit()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// glfw window creation
	GLFWwindow* window =
		glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpengGL", NULL, NULL);
	if(window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

