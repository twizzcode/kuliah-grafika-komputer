#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include "ShaderManager.h"

void framebuffer_size_callback(GLFWwindow*window, int width, int height);
void framebuffer_size_callback(GLFWwindow*window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 640, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        fprintf(stderr, "fail");
        return -1;
    }

    // glViewport(0, 0, 640, 480);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    float vertices[] = {
        //posisi            //warna
        -0.25f,0.25f,0.0f,      1.0f, 0.0f, 0.0f,
        0.25f,0.25f,0.0f,       0.0f, 1.0f, 0.0f,
        0.25f,-0.25f,0.0f,      0.0f, 0.0f, 1.0f,
        -0.25f,-0.25f,0.0f,     1.0f, 0.0f, 0.0f,
        0.0f, 0.75f, 0.0f,      1.0f, 0.0f, 0.0f,
        0.75f, 0.0f, 0.0f,      1.0f, 0.0f, 0.0f,
        0.0f, -0.75f, 0.0f,     1.0f, 0.0f, 0.0f,
        -0.75, 0.0f, 0.0f,      1.0f, 0.0f, 0.0f
    };

    unsigned int indices[] = { // index dr 0
        0, 1, 2, // Segitiga 1
        0, 2, 3, // Segitiga 2
        0, 1, 4,
        1, 2, 5,
        2, 3, 6,
        0, 3, 7
    };

    ShaderManager::GetInstance()->compileAndLink("resources/sample.vsl", "resources/sample.fsl");
    unsigned int shaderProgram = ShaderManager::GetInstance()->getShaderProgram();

    GLuint VBO;
    GLuint VAO;
    GLuint EBO;

    // Buat VAO untuk menyimpan konfigurasi attribute vertex.
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    // Aktifkan VBO posisi, lalu isi dengan data vertices.
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // Aktifkan VBO warna, lalu isi dengan data colors.
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {   
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;

        int vertexColorLocation = glGetUniformLocation(shaderProgram, "mycolor");
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
        
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    ShaderManager::GetInstance()->destroy();

    glfwTerminate();
    return 0;
}