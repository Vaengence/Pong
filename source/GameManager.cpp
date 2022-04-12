#include "GameManager.h"

GameManager::GameManager()
{
    this->oResources = new ResourceManager();
    this->oCurrentGameState = GameState::TITLE_SCREEN;
    
}

void GameManager::StartGame()
{

    oResources->InitialisePlayingScreen();
    oResources->ImportData();

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
    std::vector<BaseSprite*> Sprites = oResources->GetSprites();

    for (std::vector<BaseSprite*>::iterator iter = Sprites.begin(); iter != Sprites.end(); iter++)
    {
        (*iter)->Update();
    }
}

void GameManager::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    std::vector<BaseSprite*> Sprites = oResources->GetSprites();

    for (std::vector<BaseSprite*>::iterator iter = Sprites.begin(); iter != Sprites.end(); iter++)
    {
        (*iter)->Draw();
    }

    EndDrawing();
}

bool GameManager::CollissionCheck()
{
    return false;
}



GameManager::~GameManager()
{
    delete this->oResources;
}