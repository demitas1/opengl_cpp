#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

const GLint WIDTH = 800, HEIGHT = 600;


int main() {
    if (! glfwInit()) {
        printf("error on glfwInit\n");
        glfwTerminate();
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test window", NULL, NULL);
    if (! mainWindow) {
        printf("error on glfwCreateWindow\n");
        glfwTerminate();
        return 1;
    }

    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    glfwMakeContextCurrent(mainWindow);

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        printf("error on glewInit\n");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    glViewport(0, 0, bufferWidth, bufferHeight);

    while(! glfwWindowShouldClose(mainWindow)) {
        glfwPollEvents();

        glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(mainWindow);
    }

    return 0;
}
