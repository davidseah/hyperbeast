#include "framework.h"

#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

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
	if(HyperbeastSystem.boFirstMouse)
	{
		framework::getInstance().lastX = xpos;
		HyperbeastSystem.lastY = ypos;
		HyperbeastSystem.boFirstMouse = false;
	}

	double xoffset = xpos - HyperbeastSystem.lastX;
	double yoffset = HyperbeastSystem.lastY - ypos;

	HyperbeastSystem.lastX = xpos;
	HyperbeastSystem.lastY = ypos;

	HyperbeastSystem.m_camera.ProcessMouseMovement(static_cast<float>(xoffset), static_cast<float>(yoffset));
}

void scroll_callback(GLFWwindow* window,
					 double xoffset,
					 double yoffset)
{
	HyperbeastSystem.m_camera.ProcessMouseScroll(static_cast<float>(yoffset));
}



framework::framework()
	:
	boFirstMouse(true),
	lastX(SCR_WIDTH / 2.0f),
	lastY(SCR_HEIGHT / 2.0f),
	deltaTime(0.f),
	lastFrame(0.f),
	window(nullptr),
	m_camera(glm::vec3(0.0f, 0.0f, 3.0f)),
	show_demo_window(true)
{}

framework::~framework()
{}

void framework::vInit()
{
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
	}

	//configure global opengl state
	glEnable(GL_DEPTH_TEST);

	//Setup ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();

	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);



}


bool framework::boWindowClose()
{
	return glfwWindowShouldClose(window);
}

void framework::vProcessInput()
{
	double currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}

	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		m_camera.ProcessKeyboard(FORWARD, deltaTime);
	}
	if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		m_camera.ProcessKeyboard(BACKWARD, deltaTime);
	}
	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		m_camera.ProcessKeyboard(LEFT, deltaTime);
	}
	if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		m_camera.ProcessKeyboard(RIGHT, deltaTime);
	}
}

void framework::vUpdate()
{
	glfwPollEvents();

	// Start the Dear ImGui frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();


	// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
	if(show_demo_window)
	{
		ImGui::ShowDemoWindow(&show_demo_window);
	}


	// Rendering
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	glfwSwapBuffers(window);
	
}

void framework::vShutDown()
{
	// Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

