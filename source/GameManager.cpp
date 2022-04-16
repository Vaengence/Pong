#include "GameManager.h"

GameManager::GameManager()
{
    this->oResources = new ResourceManager();
    this->oCurrentGameState = GameState::TITLE_SCREEN;
    
}

void GameManager::StartGame()
{
    
    oResources->InitialisePlayingScreen();
    oResources->ImportData(&vPlayerSpriteArray, &vBallSpriteArray);

    GameLoop();

    CloseWindow();        // Close window and OpenGL context

}

void GameManager::GameLoop()
{
    // Main game loop
    while (this->oCurrentGameState != GameState::EXIT)    // Detect window close button or ESC key
    {
        if (WindowShouldClose())
        {
            this->oCurrentGameState = GameState::EXIT;
            break;
        }

        Update();
        Draw();
    }

}

void GameManager::Update()
{

    for (std::vector<PlayerSprite*>::iterator iter = vPlayerSpriteArray.begin(); iter != vPlayerSpriteArray.end(); iter++)
    {
        (*iter)->Update();
    }

    for (std::vector<BallSprite*>::iterator iter = vBallSpriteArray.begin(); iter != vBallSpriteArray.end(); iter++)
    {
        (*iter)->Update();
    }
}

void GameManager::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    for (std::vector<PlayerSprite*>::iterator iter = vPlayerSpriteArray.begin(); iter != vPlayerSpriteArray.end(); iter++)
    {
        (*iter)->Draw();
    }

    for (std::vector<BallSprite*>::iterator iter = vBallSpriteArray.begin(); iter != vBallSpriteArray.end(); iter++)
    {
        (*iter)->Draw();
    }

    EndDrawing();
}

bool GameManager::CollissionCheck()
{
    //std::vector<BaseSprite*> oCurrentSpriteArray = oResources->GetSprites();
    //std::vector<BaseSprite*>::iterator oCurrentBall = std::find(oCurrentSpriteArray.begin(), oCurrentSpriteArray.end(), Object::BALL);
    //std::vector<BaseSprite*>::iterator oCurrentPlayerOne = std::find(oCurrentSpriteArray.begin(), oCurrentSpriteArray.end(), Object::PLAYER_ONE_SPRITE);
    //std::vector<BaseSprite*>::iterator oCurrentPlayerTwo = std::find(oCurrentSpriteArray.begin(), oCurrentSpriteArray.end(), Object::PLAYER_TWO_SPRITE);


    return false;
}



GameManager::~GameManager()
{
    delete this->oResources;
}