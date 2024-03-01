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
    
    virtual void initialize();
    virtual void run();
    virtual void Update(float deltaTime);

private:
    VertexBuffer* VBO = nullptr;
    ElementBuffer* EBO = nullptr;
};
