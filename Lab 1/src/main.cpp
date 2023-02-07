// 24 January, 2023 Tuesday (1st week)

#include "glad.h"
#include "glfw3.h"
// glfw3.h --- glfw library of openGl and version 3
#include <iostream>
#include <cmath>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
// here window width and height can be changed
const unsigned int SCR_WIDTH = 400;
const unsigned int SCR_HEIGHT = 300;

int main() // run starts from here
{
    // glfw: initialize and configure
    glfwInit();                                    // initialize opengl
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // specify openGl version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // specify openGl version
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // openGl profile defining --- core porfile means we will use basic functions of openGl

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation using glfwCreateWindow() function
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Lab-1 24 January,2023", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window Samiha" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); // single thread
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // framebuffer_size_callback is a function that is used as a parameter of glfwSetFramebufferSizeCallback() function

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents(); // indicate events such as mouse movement
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate(); // for free allocated resources
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
