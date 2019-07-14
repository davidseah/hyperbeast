#include "framework.h"
#include "shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>


int main()
{
	HyperbeastSystem.vInit();

	while(!HyperbeastSystem.boWindowClose())
	{
		HyperbeastSystem.vProcessInput();
		glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		HyperbeastSystem.vUpdate();
	}

	HyperbeastSystem.vShutDown();
}