#pragma once

#include <iostream>
#include <SDL.h>
#include <math.h>
#include <time.h>

class Circle 
{
public:
  int pos_x;
  int pos_y;
  int speed_x;
  int speed_y;

  Circle();

  void Draw(SDL_Renderer* renderer)
  {
    int i, j, k;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for (i = -10; i < 10; i++)
      for (j = -10; j < 10; j++)
        if (i * i + j * j <= 100)
          SDL_RenderDrawPoint(renderer, pos_x + 10 + i, pos_y + 10 + j);
  }

  ~Circle();

private:

};

class Platform
{
public:
  int pos_x;
  int pos_y;
  int hight;
  int weight;
  int speed_x;

  Platform();

  void Draw(SDL_Window* window, SDL_Renderer* renderer,
            int color1, int color2, int color3, int color4)
  {
    SDL_Rect rect;
    rect.x = pos_x;
    rect.y = pos_y;
    rect.w = weight;
    rect.h = hight;

    SDL_SetRenderDrawColor(renderer, color1, color2, color3, color4);
    SDL_RenderFillRect(renderer, &rect);
  }

  ~Platform();

private:
 
};

class Brick
{
public:
  Brick();
  
  int pos_x;
  int pos_y;
  int hight;
  int weight;

  bool print;  // Draw the brick or no

  void Draw(SDL_Window* window, SDL_Renderer* renderer,
            int color1, int color2, int color3, int color4)
  {
    SDL_Rect rect;
    rect.x = pos_x;
    rect.y = pos_y;
    rect.w = weight;
    rect.h = hight;

    SDL_SetRenderDrawColor(renderer, color1, color2, color3, color4);
    SDL_RenderFillRect(renderer, &rect);
  }

  ~Brick();

private:

};
