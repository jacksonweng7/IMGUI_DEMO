#include "glew.h"
#include <GLFW/glfw3.h>
#define GLEW_STATIC
GLFWwindow* Windows;

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);

    Windows = glfwCreateWindow(800, 900, "IMGUI_DEMO", NULL, NULL);

    glfwMakeContextCurrent(Windows);
    glfwSwapInterval(0);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext(NULL);
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui_ImplGlfw_InitForOpenGL(Windows, true);
    ImGui_ImplOpenGL3_Init("#version 330");


    while(!glfwWindowShouldClose(Windows)){

        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();


        ImGui::ShowDemoWindow();


        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(Windows);
        glfwPollEvents();
    }
}
