

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void proccessInput(GLFWwindow* window);

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

int main() 
{
	//Inits
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	//Create window
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Im a Bee", NULL, NULL);
	//Error if window didn't create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	//Init for GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Faild to initialize GLAD" << std::endl;
		return -1;
	}

	//Render loop so program runs till told to stop
	while (!glfwWindowShouldClose(window))
	{
		//input
		processInput(window);

		//Rendering commands here...
			//sets color state
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			//Uses color state
		glClear(GL_COLOR_BUFFER_BIT);

		//Check and call events and swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

//For resizing screen when it is editied
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

//For checking input
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
