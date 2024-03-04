#include "Scene.h"

#include "../Camera/Camera.h"
#include "../Mesh/Mesh.h"

void Scene::Init(glm::vec3 init_cam_pos)
{
	camera->cameraPos = init_cam_pos;
}

void Scene::Load()
{

}

void Scene::Destroy()
{

}
