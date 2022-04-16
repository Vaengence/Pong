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
        RunCollisions();
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

void GameManager::RunCollisions()
{
    for (std::vector<PlayerSprite*>::iterator playerIterator = vPlayerSpriteArray.begin(); playerIterator != vPlayerSpriteArray.end(); playerIterator++)
    {
        for (std::vector<BallSprite*>::iterator ballIterator = vBallSpriteArray.begin(); ballIterator != vBallSpriteArray.end(); ballIterator++)
        {

            if (CollisionCheck(*playerIterator, *ballIterator))
            {
                BallSprite* oTempBall = *ballIterator;

                Point2D oCurrentVelocity = oTempBall->GetVelocity();

                oCurrentVelocity.setYPos(oCurrentVelocity.getYPos() * -1);
                oTempBall->SetVelocity(oCurrentVelocity);
            }
        }
    }
}

bool GameManager::CollisionCheck(PlayerSprite* oCurrentPlayer, BallSprite* oCurrentBall)
{
    if ((oCurrentPlayer->GetPosition().getXPos() + oCurrentPlayer->GetCollisionBox().top / 2.0f)  >= (oCurrentBall->GetPosition().getXPos() - oCurrentBall->GetCollisionBox().top / 2.0f) &&
        (oCurrentPlayer->GetPosition().getXPos() - oCurrentPlayer->GetCollisionBox().bottom / 2.0f)   <= (oCurrentBall->GetPosition().getXPos() + oCurrentBall->GetCollisionBox().bottom / 2.0f) &&
        (oCurrentPlayer->GetPosition().getYPos() - oCurrentPlayer->GetCollisionBox().left / 2.0f) <= (oCurrentBall->GetPosition().getYPos() + oCurrentBall->GetCollisionBox().left / 2.0f) &&
        (oCurrentPlayer->GetPosition().getYPos() + oCurrentPlayer->GetCollisionBox().right / 2.0f)    >= (oCurrentBall->GetPosition().getYPos() - oCurrentBall->GetCollisionBox().right / 2.0f))
    {
        return true;
    }


    return false;
}




GameManager::~GameManager()
{
    delete this->oResources;
}