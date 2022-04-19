#pragma once
#include <random>

enum class Object
{
	PLAYER_ONE_SPRITE = 0,
	PLAYER_TWO_SPRITE = 1,
	BALL = 2
};

enum class GameState
{
	TITLE_SCREEN = 0,
	PLAYING = 1,
	GAME_OVER = 2,
	HIGH_SCORES = 3,
	EXIT = 4
};

enum class GameSoundType
{
	BALL_BOUNCE = 0,
	GOAL = 1,
	END_GAME = 2
};

enum class CollisionType
{
	NO_COLLISION = 0,
	STANDARD = 1,
	PLAYER_LEFT_SIDE = 2,
	PLAYER_RIGHT_SIDE = 3,
};
