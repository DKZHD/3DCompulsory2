#include "Backend.h"

#include "../Color.h"
#include "../Buffers/Buffer.h"
#include "../InputEvents/Input.h"
#include "../Window/Window.h"

float Backend::DeltaTime = 0.f;
Camera Backend::camera = Camera();
void Backend::initialize()
{
    window = Window::initWindow();
    camera.initCamera();

}

void Backend::run()
{
    initialize();
    float FirstFrame = 0.0f;

    VertexArray* VAO = new VertexArray;
    VAO->Bind();

    VBO = new VertexBuffer(mesh.mVertices);
    EBO = new ElementBuffer(mesh.mIndices);

    VAO->Activate();
    glm::vec3 color(Color::Maroon);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    while(!glfwWindowShouldClose(window))
    {
        const float CurrentFrame = glfwGetTime();
    	DeltaTime = CurrentFrame - FirstFrame;
        FirstFrame = CurrentFrame;
        glClearColor(color.x, color.y, color.z, 1.f);
    	glClear(GL_COLOR_BUFFER_BIT    | GL_DEPTH_BUFFER_BIT);
		glUseProgram(Shader::Program);
        KeyBoardInput::processInput(window);
        glUniformMatrix4fv(camera.viewLoc, 1, GL_FALSE, glm::value_ptr(camera.getView()));
        glUniformMatrix4fv(camera.projectionLoc, 1, GL_FALSE, glm::value_ptr(camera.getProjection(800, 600)));
        Update(DeltaTime);
        VAO->Bind();
        mesh.Draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}

void Backend::Update(float deltaTime)
{

}
