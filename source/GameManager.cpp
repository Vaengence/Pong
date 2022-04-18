#include "GameManager.h"

GameManager::GameManager()
{
    this->oResources = new ResourceManager();
    this->oBallManager = new BallManager();
    this->oCurrentGameState = GameState::TITLE_SCREEN;
    
}

void GameManager::StartGame()
{
    
    oResources->InitialisePlayingScreen();
    oResources->ImportData(&vPlayerSpriteArray, oBallManager);
    oResources->ImportSounds();

    GameLoop();

    CloseAudioDevice();
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

    oBallManager->Update();

}

void GameManager::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    for (std::vector<PlayerSprite*>::iterator iter = vPlayerSpriteArray.begin(); iter != vPlayerSpriteArray.end(); iter++)
    {
        (*iter)->Draw();
    }

    oBallManager->Draw();

    EndDrawing();
}

void GameManager::RunCollisions()
{
    std::vector<BallSprite*> *balls = oBallManager->GetBalls();

    for (std::vector<BallSprite*>::iterator ballIterator = balls->begin(); ballIterator != balls->end(); ballIterator++)
    {

        for (std::vector<PlayerSprite*>::iterator playerIterator = vPlayerSpriteArray.begin(); playerIterator != vPlayerSpriteArray.end(); playerIterator++)
        {

            if (CollisionCheck(*playerIterator, *ballIterator))
            {
                oBallManager->HasCollided(ballIterator);
                oResources->PlayGameSound(GameSoundType::BALL_BOUNCE);
            }
        }

        if (Goal(*ballIterator))
        {
            oBallManager->HasScored(ballIterator);
            oResources->PlayGameSound(GameSoundType::GOAL);
            break;
        }
    }
}

bool GameManager::CollisionCheck(PlayerSprite* oCurrentPlayer, BallSprite* oCurrentBall)
{

    if ((oCurrentPlayer->GetPosition().getXPos() + oCurrentPlayer->GetTexture().width >= oCurrentBall->GetPosition().getXPos()) &&
        (oCurrentPlayer->GetPosition().getXPos() <= oCurrentBall->GetPosition().getXPos() + oCurrentBall->GetTexture().width) &&
        (oCurrentPlayer->GetPosition().getYPos() + oCurrentPlayer->GetTexture().height >= oCurrentBall->GetPosition().getYPos()) &&
        (oCurrentPlayer->GetPosition().getYPos() <= oCurrentBall->GetPosition().getYPos() + oCurrentBall->GetTexture().height))
    {
        return true;
    }


    return false;
}

bool GameManager::Goal(BallSprite* oCurrentBall)
{
    if (oCurrentBall->GetPosition().getYPos() > (float)GetScreenHeight() || oCurrentBall->GetPosition().getYPos() < 0)
    {
        return true;
    }

    return false;
}


GameManager::~GameManager()
{
    delete this->oResources;
    delete this->oBallManager;
}