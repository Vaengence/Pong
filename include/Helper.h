#pragma once

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
