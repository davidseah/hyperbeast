#include "framework.h"

#include <iostream>

// settings
void framebuffer_size_callback(GLFWwindow* window,
							   int width,
							   int height)
{
	glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if(FW().boFirstMouse)
	{
		framework::getInstance().lastX = xpos;
		FW().lastY = ypos;
		FW().boFirstMouse = false;
	}

	float xoffset = xpos - FW().lastX;
	float yoffset = FW().lastY - ypos;

	FW().lastX = xpos;
	FW().lastY = ypos;

	FW().m_camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window,
					 double xoffset,
					 double yoffset)
{
	FW().m_camera.ProcessMouseScroll(yoffset);
}

framework::framework()
{

}

framework::~framework()
{
}

bool framework::vInit(const Camera& camera)
{
	lastX = SCR_WIDTH / 2.0f;
	lastY = SCR_HEIGHT / 2.0f;
	boFirstMouse = true;

	//timing
	//deltaTime = 0.0f;
	//lastFrame = 0.0f;

	m_camera = camera;

	//init GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// glfw window creation
	window =
		glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpengGL", NULL, NULL);
	if(window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glfwSetCursorPosCallback(window, mouse_callback);

	glfwSetScrollCallback(window, scroll_callback);
	
	//tell GLFW to capture our moise
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

	//glad:load all opengl function 
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		return false;
	}


	//configure global opengl state
	glEnable(GL_DEPTH_TEST);
}


bool framework::IsWindowClose()
{
	return glfwWindowShouldClose(window);
}

void framework::vUpdate()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

