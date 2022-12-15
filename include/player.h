#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>
#include <SDL2/SDL_ttf.h>
#include "ltexture.h"
#include "camera.h"

class Player
{
    public:
        Player();
        ~Player();
        void Draw(SDL_Renderer* renderer);
        void SetPos(int to_x, int to_y);
        void MoveIP(int offset_x, int offset_y);
        void HandleInput(SDL_Event event);
        void Update();
        void LoadTexture(SDL_Renderer* renderer);
        double RotateTo(double angle);

        void setRotation(double angle);
        void RenderDebugInfo(TTF_Font* font, SDL_Renderer* renderer);

        void LoadCamera(Camera* camera);

    private:
        int x;
        int y;

        int renderedX;
        int renderedY;

        SDL_Rect mRect;

        Camera* pCamera;

        void _rotateSelf();

        double rotatedAngle;
        double toRotateTo;
        double rotationSpeed = 10; // 1 degree per frame

        LTexture mTexture;

        int colour[4] = {2, 53, 53, 255};

        int basevelocity = 5;
        int xvel;
        int yvel;

        // Movement smoothing
        bool upkeydown;
        bool downkeydown;
        bool leftkeydown;
        bool rightkeydown;

        // Gravity
        int groundLevel;
        double gravitySpeed;
        bool isGrounded;


        // Mouse input
        int mouseX = 0;
        int mouseY = 0;
        
        double GetRotationTowardsMouse(double currentRotation, int x, int y, int mouseX, int mouseY);
};