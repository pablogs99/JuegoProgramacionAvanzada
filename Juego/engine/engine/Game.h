#pragma once
#include "Scene.h"

class Game
{
private:
	float time;
	float deltaTime;

	Scene* activeScene;
	vector<Scene*> scenes;

public:

	Game() : time(0.0), deltaTime(0.25), activeScene(nullptr) {}

	void Create();
	void Render();
	void Update();
	void ProcessMouseMovement(const int& xPosition, const int& yPosition);
	void ProcessKeyPressed(const unsigned char& key, const int& xPosition, const int& yPosition);
	void ProcessMouseClick(const int& button, const int& state, const int& xPosition, const int& yPosition);
};