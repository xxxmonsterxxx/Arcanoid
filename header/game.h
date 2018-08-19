#pragma once
#include <glew.h>
#include <glfw3.h>
#include <vector>
#include "game_level.h"


// Represents the current state of the game
enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class Game
{
public:
	// Game state
	GameState              State;
	GLboolean              Keys[1024];
	GLuint                 Width, Height;
	// Levels
	std::vector<GameLevel> Levels;
	GLuint                 Level;
	// Constructor/Destructor
	Game(GLuint width, GLuint height);
	~Game();
	// Initialize game state (load all shaders/textures/levels)
	void Init();
	// GameLoop
	void DoCollisions();
	// Reset
	void ResetLevel();
	void ResetPlayer();
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Render();
};
