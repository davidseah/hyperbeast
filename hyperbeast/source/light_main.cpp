#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "framework.h"
#include "shader.h"
#include "camera.h"
#include <iostream>

//camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

//lighting
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

int main() 
{
	FW().vInit(camera);
	while(!FW().IsWindowClose())
	{

		FW().vUpdate();
	}
}