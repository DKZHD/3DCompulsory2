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
    run();
}

void Backend::create()
{
    
}

void Backend::run()
{
    create();
    float FirstFrame = 0.0f;

    VertexArray VAO;
    VAO.Bind();

    VBO = new VertexBuffer(mesh.mVertices);
    EBO = new ElementBuffer(mesh.mIndices);

    VAO.Activate();
    glm::vec3 color(Color::Teal);
    while(!glfwWindowShouldClose(window))
    {
        const auto CurrentFrame = static_cast<float>(glfwGetTime());
    	DeltaTime = CurrentFrame - FirstFrame;
        FirstFrame = CurrentFrame;
        glClearColor(color.x, color.y, color.z, 1.f);
    	glClear(GL_COLOR_BUFFER_BIT    | GL_DEPTH_BUFFER_BIT);
		glUseProgram(Shader::Program);
        glUniformMatrix4fv(camera.projectionLoc, 1, GL_FALSE, glm::value_ptr(camera.getProjection(Window::width, Window::height)));
        glUniformMatrix4fv(camera.viewLoc, 1, GL_FALSE, glm::value_ptr(camera.getView()));

        Update(DeltaTime);
        KeyBoardInput::processInput(window, mesh.Package[0].get());
        VAO.Bind();
        mesh.Draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}

void Backend::Update(float deltaTime)
{

}

Backend::~Backend()
{
    delete VBO;
    delete EBO;
}
