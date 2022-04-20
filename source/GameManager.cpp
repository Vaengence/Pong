#include "GameManager.h"

GameManager::GameManager()
{
    this->oResources = new ResourceManager();
    this->oBallManager = new BallManager(oResources);
    this->oPlayerManager = new PlayerManager(oResources);
    this->oCurrentGameState = GameState::TITLE_SCREEN;
    
    vObjectManagers.push_back(oBallManager);
    vObjectManagers.push_back(oPlayerManager);
}

void GameManager::StartGame()
{
    
    oResources->InitialisePlayingScreen();
    oResources->ImportData();
    oResources->ImportSounds();

    
    for (std::vector<ObjectManager*>::iterator iter = vObjectManagers.begin(); iter != vObjectManagers.end(); iter++)
    {
        (*iter)->InitialiseLevel(1); // Level 1 by default as multiple levels not yet implemented
    }

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

    for (std::vector<ObjectManager*>::iterator iter = vObjectManagers.begin(); iter != vObjectManagers.end(); iter++)
    {
        (*iter)->Update();
    }

}

void GameManager::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    for (std::vector<ObjectManager*>::iterator iter = vObjectManagers.begin(); iter != vObjectManagers.end(); iter++)
    {
        (*iter)->Draw();
    }

    EndDrawing();
}

void GameManager::RunCollisions()
{
    std::vector<BallSprite*> *balls = oBallManager->GetBalls();
    std::unordered_map<Object, PlayerSprite*> *players = oPlayerManager->GetPlayers();

    for (std::vector<BallSprite*>::iterator ballIterator = balls->begin(); ballIterator != balls->end(); ballIterator++)
    {

        for (std::unordered_map<Object, PlayerSprite*>::iterator playerIterator = players->begin(); playerIterator != players->end(); playerIterator++)
        {

            if ((*ballIterator)->GetCollisionState() == false && (*ballIterator)->GetCollidedTimer() == 0.0)
            {
                CollisionType CheckForCollision = CollisionCheck(playerIterator->second, *ballIterator);

                if (CheckForCollision != CollisionType::NO_COLLISION)
                {
                    (*ballIterator)->SetActiveCollision(true);
                    (*ballIterator)->SetCollidedTimer(GetTime() + 0.5);
                    Point2D oPlayerVelocity = playerIterator->second->GetVelocity();
                    oBallManager->HasCollided(ballIterator, CheckForCollision, oPlayerVelocity);
                    oResources->PlayGameSound(GameSoundType::BALL_BOUNCE);
                }
            }

            if (CollisionCheck(playerIterator->second, *ballIterator) == CollisionType::NO_COLLISION &&
                (*ballIterator)->GetCollisionState() == true && 
                GetTime() > (*ballIterator)->GetCollidedTimer())
            {
                (*ballIterator)->SetActiveCollision(false);
                (*ballIterator)->SetCollidedTimer(0.0);
            }
        }

        if (Goal(*ballIterator))
        {
            if ((*ballIterator)->GetPosition().getYPos() > (float)GetScreenHeight())
                oPlayerManager->PlayerScored(Object::PLAYER_TWO_SPRITE);
            else
                oPlayerManager->PlayerScored(Object::PLAYER_ONE_SPRITE);

            oBallManager->HasScored(ballIterator);
            oResources->PlayGameSound(GameSoundType::GOAL);



            break;
        }
    }

}

CollisionType GameManager::CollisionCheck(PlayerSprite* oCurrentPlayer, BallSprite* oCurrentBall)
{
    CollisionType CheckForCollision = CollisionType::NO_COLLISION;



    if ((oCurrentPlayer->GetPosition().getXPos() + oCurrentPlayer->GetTexture().width >= oCurrentBall->GetPosition().getXPos()) &&
        (oCurrentPlayer->GetPosition().getXPos() <= oCurrentBall->GetPosition().getXPos() + oCurrentBall->GetTexture().width) &&
        (oCurrentPlayer->GetPosition().getYPos() + oCurrentPlayer->GetTexture().height >= oCurrentBall->GetPosition().getYPos()) &&
        (oCurrentPlayer->GetPosition().getYPos() <= oCurrentBall->GetPosition().getYPos() + oCurrentBall->GetTexture().height))
    {

        if (oCurrentBall->GetPosition().getXPos() + oCurrentBall->GetTexture().width / 2 < oCurrentPlayer->GetPosition().getXPos())
        {
            CheckForCollision = CollisionType::PLAYER_LEFT_SIDE;
            return CheckForCollision;
        }

        if (oCurrentBall->GetPosition().getXPos() + oCurrentBall->GetTexture().width / 2 > oCurrentPlayer->GetPosition().getXPos() + oCurrentPlayer->GetTexture().width)
        {
            CheckForCollision = CollisionType::PLAYER_RIGHT_SIDE;
            return CheckForCollision;
        }

        CheckForCollision = CollisionType::STANDARD;
        return CheckForCollision;
    }

    return CheckForCollision;
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