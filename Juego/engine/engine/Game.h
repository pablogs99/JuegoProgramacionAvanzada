#pragma once
#include "Scene.h"
#include <chrono>
using namespace std::chrono;

class Game
{
private:
	const double TIME_INCREMENT = 0.4; //ms tiempo en el juego
	const long UPDATE_PERIOD = 10; //ms tiempo en el mundo real

	milliseconds initialMilliseconds;
	long lastUpdatedTime;

	Scene* activeScene;
	vector<Scene*> scenes;

public:

	//Game() : time(0.0), deltaTime(0.25), activeScene(nullptr) {}
	Game() : activeScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0) {}
	void Create();
	void Render();
	void Update();
	void ProcessMouseMovement(const int& xPosition, const int& yPosition);
	void ProcessKeyPressed(const unsigned char& key, const int& xPosition, const int& yPosition);
	void ProcessMouseClick(const int& button, const int& state, const int& xPosition, const int& yPosition);
};