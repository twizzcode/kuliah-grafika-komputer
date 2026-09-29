#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

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
        // posisi                         // warna kuning
    
        // oval tengah (0 - 6)
        -0.0825f, +0.5725f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.0675f, +0.5475f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.0225f, +0.5375f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.0675f, +0.5625f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.0625f, +0.5825f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.0275f, +0.5975f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.0375f, +0.5975f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
    
        // sayap dalam kiri (7 - 16)
        -0.3775f, +0.9375f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.5025f, +0.7725f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.5225f, +0.6425f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.4675f, +0.5175f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.1725f, +0.2125f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.1475f, -0.4375f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.0825f, -0.4125f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.0875f, +0.3575f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.1625f, +0.5025f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.3775f, +0.6975f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
    
        // sayap dalam kanan (17 - 26)
        +0.3625f, +0.9375f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.3775f, +0.7275f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.1325f, +0.4825f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.0675f, +0.3225f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.0675f, -0.4125f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.1375f, -0.4375f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.1625f, +0.2225f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.4525f, +0.5175f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.5075f, +0.6375f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.4925f, +0.7625f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
    
        // sayap tengah kiri (27 - 37)
        -0.5475f, +0.8325f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.6775f, +0.6975f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.7325f, +0.4725f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.6525f, +0.3125f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.2775f, +0.0075f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.2675f, -0.5675f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.1975f, -0.4525f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.2025f, +0.1125f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.2825f, +0.2575f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.5725f, +0.5275f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.5925f, +0.6975f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
    
        // sayap tengah kanan (38 - 48)
        +0.5325f, +0.8325f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.5775f, +0.7075f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.5625f, +0.5375f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.2725f, +0.2625f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.1875f, +0.1075f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.1825f, -0.4525f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.2525f, -0.5675f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.2625f, +0.0025f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.6425f, +0.3175f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.7175f, +0.4625f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.6875f, +0.6525f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
    
        // sayap luar kiri (49 - 58)
        -0.7625f, +0.6325f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.8925f, +0.4175f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.8975f, +0.1975f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.7775f, +0.0175f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.4025f, -0.1475f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.3825f, -0.6575f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.3125f, -0.6175f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.3125f, -0.0625f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.7625f, +0.3175f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.8025f, +0.4225f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
    
        // sayap luar kanan (59 - 68)
        +0.7475f, +0.6325f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.7875f, +0.4175f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.7425f, +0.3075f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.3025f, -0.0475f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.2975f, -0.6175f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.3675f, -0.6575f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.3825f, -0.1575f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.7625f, +0.0175f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.8775f, +0.1775f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.8775f, +0.4225f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
    
        // bagian bawah / U (69 - 93)
        -0.8725f, -0.2025f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.7575f, -0.2875f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.5075f, -0.3325f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.4975f, -0.6375f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.4375f, -0.7825f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.2875f, -0.8975f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.1175f, -0.9375f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.1975f, -0.9225f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.3725f, -0.8375f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.4775f, -0.6675f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.4925f, -0.3325f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.8075f, -0.2525f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.9225f, -0.0275f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.9175f, +0.1425f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.7725f, -0.0625f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.4325f, -0.1975f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.4075f, -0.6475f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.3075f, -0.7925f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        +0.1525f, -0.8575f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.0825f, -0.8675f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.2925f, -0.8125f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.3975f, -0.7075f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.4425f, -0.2025f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.7625f, -0.0775f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
        -0.9325f, +0.1425f, 0.0f,        0.9922f, 0.8314f, 0.2471f,
    };
    
    
    unsigned int indices[] = {
        // oval tengah
        0, 6, 5,
        0, 5, 4,
        0, 4, 3,
        0, 3, 2,
        2, 1, 0,
    
        // sayap dalam kiri
        16, 15, 14,
        14, 13, 12,
        14, 12, 11,
        16, 14, 11,
        16, 11, 10,
        7, 16, 10,
        7, 10, 9,
        9, 8, 7,
    
        // sayap dalam kanan
        17, 26, 25,
        17, 25, 24,
        23, 22, 21,
        23, 21, 20,
        24, 23, 20,
        24, 20, 19,
        24, 19, 18,
        24, 18, 17,
    
        // sayap tengah kiri
        36, 35, 34,
        34, 33, 32,
        34, 32, 31,
        36, 34, 31,
        36, 31, 30,
        37, 36, 30,
        37, 30, 29,
        27, 37, 29,
        29, 28, 27,
    
        // sayap tengah kanan
        38, 48, 47,
        47, 46, 45,
        45, 44, 43,
        45, 43, 42,
        47, 45, 42,
        47, 42, 41,
        47, 41, 40,
        47, 40, 39,
        47, 39, 38,
    
        // sayap luar kiri
        56, 55, 54,
        56, 54, 53,
        57, 56, 53,
        57, 53, 52,
        58, 57, 52,
        58, 52, 51,
        49, 58, 51,
        51, 50, 49,
    
        // sayap luar kanan
        59, 68, 67,
        67, 66, 65,
        65, 64, 63,
        65, 63, 62,
        67, 65, 62,
        67, 62, 61,
        67, 61, 60,
        67, 60, 59,
    
        // bagian bawah / U
        69, 93, 92,
        69, 92, 91,
    
        83, 82, 81,
        84, 83, 81,
        84, 81, 80,
        84, 80, 79,
        85, 84, 79,
        85, 79, 78,
        86, 85, 78,
        86, 78, 77,
        87, 86, 77,
        87, 77, 76,
        88, 87, 76,
        88, 76, 75,
        89, 88, 75,
        89, 75, 74,
        90, 89, 74,
        90, 74, 73,
        91, 90, 73,
        91, 73, 72,
        91, 72, 71,
        69, 91, 71,
        71, 70, 69,
    };

    // unsigned int indices[] = { // index dr 0
    //     0, 1, 2, // Segitiga 1
    //     0, 2, 3, // Segitiga 2
    //     0, 1, 4,
    //     1, 2, 5,
    //     2, 3, 6,
    //     0, 3, 7
    // };


    const char* vertexShaderSource = "#version 330 core\n"
     "layout(location = 0) in vec3 aPos;\n"
     "layout(location = 1) in vec3 acolor;\n"
    "out vec3 color;\n"
    "void main()\n"
    "{\n"
    " color=acolor;\n"
    " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
    
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    
    const char* fragmentShaderSource = "#version 330 core\n"
    "in vec3 color;\n"
    "out vec4 fragColor;\n"
    "void main()\n"
    "{\n"
    " fragColor = vec4(color.x,color.y,color.z, 1.0);\n"
    "}\0";
    
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

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

    glfwTerminate();
    return 0;
}