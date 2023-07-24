#include <iostream>
#include <string>

#include "raylib-cpp.hpp"

#include "Ball.h"
#include "Paddle.h"

int main()
{
    const int kScreenWidth = 1280;
    const int kScreenHeight = 720;
    raylib::Window window(kScreenWidth, kScreenHeight, "PONG");

    Ball ball(kScreenWidth / 2, kScreenHeight / 2, 7, 7, 20);
    Paddle p1(10, kScreenHeight / 2 - 60, 25, 120, 6);
    p1.setKeys(KEY_W, KEY_S);
    Paddle p2(kScreenWidth - 35, kScreenHeight / 2 - 60, 25, 120, 6);
    p2.setKeys(KEY_O, KEY_L);
    int p1Score = 0, p2Score = 0;

    // MAIN LOOP
    window.SetTargetFPS(60);
    while (!window.ShouldClose())
    {
        // EVENTS
        ball.checkCollisionWithRect(p1.getHitBox());
        ball.checkCollisionWithRect(p2.getHitBox());
        if (ball.getPosition().x < p1.getPosition().x + p1.getWidth()) {
            p2Score++;
            ball.resetPosition();
        }
        else if (ball.getPosition().x > p2.getPosition().x) {
            p1Score++;
            ball.resetPosition();
        }
        
        // UPDATE
        ball.Update();
        p1.Update();
        p2.Update();

        // DRAW
        BeginDrawing();
            window.ClearBackground(DARKGRAY);
            DrawCircle(kScreenWidth / 2, kScreenHeight / 2, 150, LIGHTGRAY);
            DrawLine(kScreenWidth / 2, 0, kScreenWidth / 2, kScreenHeight, LIGHTGRAY);
            
            ball.Draw();
            p1.Draw();
            p2.Draw();
            raylib::DrawText(std::to_string(p1Score), kScreenWidth / 4 - 20, 20, 80, YELLOW);
            raylib::DrawText(std::to_string(p2Score), 3 * kScreenWidth / 4 - 20, 20, 80, YELLOW);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}