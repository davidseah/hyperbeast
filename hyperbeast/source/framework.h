#pragma once


//settings
#include "camera.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

class framework
{
	public:
	
	bool vInit(const Camera& camera);

	static framework& getInstance()
	{
		static framework m_instance;
		return m_instance;
	}

	GLFWwindow* window;
	Camera m_camera;
	bool boFirstMouse;
	float lastX;
	float lastY;

	framework();
	~framework();

	bool IsWindowClose();
	void vUpdate();


	private:

	framework(const framework&);
	void operator=(const framework&);
	
	

};

#define FW() framework::getInstance()