#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include "ShaderManager.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

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
        //posisi                //warna                 // Texture
        -0.25f,0.25f,0.0f,      1.0f, 0.0f, 0.0f,       0.0f, 0.0f,
        0.25f,0.25f,0.0f,       0.0f, 1.0f, 0.0f,       0.0f, 1.0f,
        0.25f,-0.25f,0.0f,      0.0f, 0.0f, 1.0f,       1.0f, 1.0f,
        -0.25f,-0.25f,0.0f,     1.0f, 0.0f, 0.0f,       1.0f, 0.0f,
        0.0f, 0.75f, 0.0f,      1.0f, 0.0f, 0.0f,       0.5f, 0.5f,
        0.75f, 0.0f, 0.0f,      1.0f, 0.0f, 0.0f,       0.5f, 0.5f,
        0.0f, -0.75f, 0.0f,     1.0f, 0.0f, 0.0f,       0.5f, 0.5f,
        -0.75f, 0.0f, 0.0f,     1.0f, 0.0f, 0.0f,       0.5f, 0.5f
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
    GLuint texture;

    // Buat VAO untuk menyimpan konfigurasi attribute vertex.
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D,texture);

    //texture warping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    std::string fileTex = "resources/basecolor.png";
    unsigned char* data = stbi_load(fileTex.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    
    glBindVertexArray(VAO);

    // Aktifkan VBO posisi, lalu isi dengan data vertices.
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(3*sizeof(float)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(6*sizeof(float)));
    
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {   
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glBindTexture(GL_TEXTURE_2D, texture);
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
