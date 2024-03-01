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
    
    virtual void initialize();
    virtual void create();
    virtual void run();
    virtual void Update(float deltaTime);

    virtual ~Backend();

private:
    VertexBuffer* VBO = nullptr;
    ElementBuffer* EBO = nullptr;
};
