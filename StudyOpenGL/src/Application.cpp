#include <iostream>

#include <glad/glad.h>
#include <glfw3.h>

int main()
{
	// GLFW初始化
	if (!glfwInit())
		return -1;

	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);					//主版本号
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);					//次版本号
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	//使用CORE模式

	// 宽 高 窗口名
	GLFWwindow* window = glfwCreateWindow(1280, 960, "StudyOpenGL", NULL, NULL);

	if (!window)
	{
		// 生成错误则输出错误信息
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// GLAD管理OpenGL函数指针，初始化GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		// 生成错误则输出错误信息
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// 渲染循环
	while (!glfwWindowShouldClose(window))
	{
		// 渲染指令
		glClear(GL_COLOR_BUFFER_BIT);

		// 检查并调用事件，交换缓冲
		glfwSwapBuffers(window);

		// 检查触发什么事件，更新窗口状态
		glfwPollEvents();
	}

	// 释放之前的分配的所有资源
	glfwTerminate();

	return 0;
}