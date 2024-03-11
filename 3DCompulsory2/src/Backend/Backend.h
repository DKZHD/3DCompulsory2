#pragma once
#include "../Camera/Camera.h"
#include "glm/gtc/type_ptr.inl"
#include "../Mesh/Mesh.h"

class ElementBuffer;
class VertexBuffer;
struct GLFWwindow;

class Backend
{
public:
    GLFWwindow *window;
    static Camera camera;
    static float DeltaTime;
    Mesh mesh;

    Backend() = default;

    // Initialize all default functions, called at program start
    virtual void initialize();
    // Create objects
    virtual void create();
    // Main Loop
    virtual void run();
    // Change variables before draw call
    virtual void Update(float deltaTime);

    virtual ~Backend();

private:
    VertexBuffer* VBO = nullptr;
    ElementBuffer* EBO = nullptr;
};
