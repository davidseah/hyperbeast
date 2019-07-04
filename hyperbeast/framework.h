#pragma once

#include "source/camera.h"
#include <GLFW/glfw3.h>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

class framework 
{
 public:
  framework(Camera inputcamera);
  ~framework();
  bool vInit();

  void framebuffer_size_callback(GLFWwindow* window, int width, int height);

  void mouse_callback(GLFWwindow* window, double xpos, double ypos);

  void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);


  private: 
	  Camera frameworkCamera;
	  bool boFirstMouse;
	  float lastX;
	  float lastY;

};
