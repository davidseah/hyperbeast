#pragma once

//Engine
#include "camera.h"

#include <imgui/imgui.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class framework
{
	public:
	
	void vInit();

	static framework& getInstance()
	{
		static framework m_instance;
		return m_instance;
	}

	GLFWwindow* window;
	Camera m_camera;
	bool boFirstMouse;
	double lastX;
	double lastY;

	framework();
	~framework();

	bool boWindowClose();
	void vUpdate();
	void vProcessInput();
	void vShutDown();

	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 600;

	private:
	framework(const framework&);
	void operator=(const framework&);
	const char* glsl_version = "#version 130";

	// timing
	double deltaTime;
	double lastFrame;
	bool show_demo_window;

};

#define  HyperbeastSystem framework::getInstance()