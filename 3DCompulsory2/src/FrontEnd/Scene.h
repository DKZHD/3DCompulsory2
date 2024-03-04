#pragma once
#include "glm/vec3.hpp"


class Camera;
class Mesh;

class Scene
{
	Mesh* mesh;
	Camera* camera;
	int LastIndex = 0;
public:
	Scene(Mesh* mesh, Camera* camera) : mesh(mesh), camera(camera){}
	void Init(glm::vec3 init_cam_pos);
	void Load();
	void Destroy();
};
