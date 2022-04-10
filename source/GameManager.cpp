#include "GameManager.h"
#include "ResourceManager.h"
#include <raylib.h>

GameManager::GameManager()
{

}

void GameManager::StartGame()
{
    this->oResources = new ResourceManager();
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
    
}

void GameManager::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    EndDrawing();
}

GameManager::~GameManager()
{
    delete this->oResources;
}