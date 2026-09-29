#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include "ShaderManager.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void framebuffer_size_callback(GLFWwindow* window, int width, int height) { 
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
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Initialize GLAD */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        fprintf(stderr,"Failed to initialize GLAD\n");
        return -1;
    }

    // /*Perlu ditekankan tempat menggambar*/ 
    glViewport(0, 0, 640, 480);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    float vertices[] = { 
        //posisi           //warna 
        0.0f,-0.5f,0.0f,   1.0f, 0.0f, 0.0f,
        0.0f,0.5f,0.0f,    0.0f, 1.0f, 0.0f, 
        0.5f,-0.5f,0.0f,   0.0f,  0.0f, 1.0f,  
        0.5f,0.5f,0.0f,    1.0f,  0.0f, 0.0f 
    }; 

    unsigned int indices[] = {  // index dr 0 
        0, 1, 2,   // Segitiga 1 
        1, 2, 3,   // Segitiga 2 
    };

    // float colors[] = { 
    //     1.0f, 0.0f, 0.0f,
    //     0.0f, 1.0f, 0.0f, 
    //     0.0f, 0.0f, 1.0f,
    //     1.0f, 0.0f, 0.0f 
    // }; ga efisien

    ShaderManager::GetInstance()->compileAndLink("resources/sample.vsl", "resources/sample.fsl");
    unsigned int shaderProgram = ShaderManager::GetInstance()->getShaderProgram();
    
    GLuint VBO;
    GLuint VAO;
    GLuint EBO;

    // bangkitkan buffers. kita butuh 1 id buffer. 
    glGenBuffers(1, &VBO);  
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &EBO); 
     
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); 

    // glVertexAttribPointer. 
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (GLfloat)0, (GLvoid*)0); 
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0); 
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); 
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    while (!glfwWindowShouldClose(window)) { 
        glClear(GL_COLOR_BUFFER_BIT); 
        glUseProgram(shaderProgram);
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
        //animasi blink
        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;
        int vertexColorLocation = glGetUniformLocation(shaderProgram, "mycolor");
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
        glBindVertexArray(VAO); 
        glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window); 
        glfwPollEvents(); 
    } 

    // Deleting the used resources 
    glDeleteVertexArrays(1, &VAO); 
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    ShaderManager::GetInstance()->destroy();

    glfwTerminate();
    return 0;
}