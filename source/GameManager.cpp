#include "GameManager.h"

GameManager::GameManager()
{
    this->oResources = new ResourceManager();
    this->oCurrentGameState = GameState::TITLE_SCREEN;
    oResources->ImportData();
}

void GameManager::StartGame()
{

    oResources->InitialisePlayingScreen();

    GameLoop();

    CloseWindow();        // Close window and OpenGL context

}

void GameManager::GameLoop()
{
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
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



GameManager::~GameManager()
{
    delete this->oResources;
}