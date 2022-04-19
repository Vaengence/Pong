#pragma once

class ObjectManager
{
public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Collisions() = 0;
	virtual void InitialiseLevel(int level) = 0;
};

