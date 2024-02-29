#pragma once

class Cube;

class Collision
{
public:
    void checkWorldCollision();
    void checkCollision(Cube& cube1, Cube& cube2);
};
