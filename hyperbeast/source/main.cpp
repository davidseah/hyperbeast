#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Hyperbeast ", NULL, NULL);
    
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW Window " << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD " << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{

}