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
        Draw();
    }

}

void GameManager::Update()
{
    
}

void GameManager::Draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
}

GameManager::~GameManager()
{
    delete this->oResources;
}