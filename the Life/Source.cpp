#include "Header.h"

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;
Circle A;
Platform P;
Brick R[5];
int MAX;
int BRICK_COUNTER;

int directionY = 1;
int directionX = 1;
bool bNeedMove = false;

Uint32 my_callbackfunc(Uint32 interval, void* param)
{
  SDL_Event event;

  SDL_UserEvent userevent;
  
  int i;

  /* In this example, our callback pushes an SDL_USEREVENT event
     into the queue, and causes our callback to be called again at the
     same interval: */

  if (A.pos_y < 10) // directionY = FUNK_Y(pos_x, pos_y);
    directionY = 1;

  if (A.pos_y > SCREEN_HEIGHT - 30)
    directionY = -1;

  if (A.pos_x < 10) // directionX = FUNK_X();
    directionX = 1;

  if (A.pos_x > SCREEN_WIDTH - 30)
    directionX = -1;

  if (A.pos_y < P.pos_y + P.hight && P.pos_y - P.hight < A.pos_y && A.pos_x < P.pos_x + P.weight && P.pos_x < A.pos_x)
    directionY = -1;

  for (i = 0; i < MAX; i++)
  {
    if (R[i].print == true && A.pos_y - 10 < R[i].pos_y + R[i].hight && A.pos_y + 10 > R[i].pos_y && A.pos_x > R[i].pos_x && A.pos_x < R[i].pos_x + R[i].weight)
    {
      directionY = 1;
      R[i].print = false;
      BRICK_COUNTER += 1;
    }
  }

  userevent.type = SDL_USEREVENT;
  userevent.code = 0;
  userevent.data1 = NULL;
  userevent.data2 = NULL;

  event.type = SDL_USEREVENT;
  event.user = userevent;
  bNeedMove = true;
  SDL_PushEvent(&event);
  return(interval);
}

int main(int argc, char* argv[])
{
  SDL_Window* window;                    // Declare a pointer
  SDL_Renderer* renderer;
  SDL_Event event;

  bool quit = false;
  int i;                                 // Counter

  MAX = 4;
  BRICK_COUNTER = 0;

  A.pos_x = 260;
  A.pos_y = 300;
  A.speed_x = 1;
  A.speed_y = 1;

  P.pos_x = 220;
  P.pos_y = 430;
  P.hight = 20;
  P.weight = 200;
  P.speed_x = 10;

  R[0].pos_x = 10;
  R[0].pos_y = 10;
  R[0].hight = 70;
  R[0].weight = 150;
  R[0].print = true;

  R[1].pos_x = 170;
  R[1].pos_y = 10;
  R[1].hight = 70;
  R[1].weight = 150;
  R[1].print = true;

  R[2].pos_x = 330;
  R[2].pos_y = 10;
  R[2].hight = 70;
  R[2].weight = 150;
  R[2].print = true;

  R[3].pos_x = 490;
  R[3].pos_y = 10;
  R[3].hight = 70;
  R[3].weight = 140;
  R[3].print = true;

  SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL

  Uint32 delay = (33 / 10) * 10;  /* To round it down to the nearest 10 ms */
  SDL_TimerID my_timer_id = SDL_AddTimer(delay, my_callbackfunc, 0);// my_callback_param);

  // Create a window
  window = SDL_CreateWindow(
    "Arcanoid",                  // window title
    SDL_WINDOWPOS_UNDEFINED,           // initial x position
    SDL_WINDOWPOS_UNDEFINED,           // initial y position
    SCREEN_WIDTH,                               // width, in pixels
    SCREEN_HEIGHT,                               // height, in pixels
    SDL_WINDOW_OPENGL                  // flags - see below
  );

  // Check that the window was successfully created
  if (window == NULL) {
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  // We must call SDL_CreateRenderer in order for draw calls to affect this window.
  renderer = SDL_CreateRenderer(window, -1, 0);

  // Set the color for drawing.
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

  // Clear the entire screen to our selected color.
  SDL_RenderClear(renderer);

  while (!quit)
  {
    while (SDL_PollEvent(&event))
    {
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
      SDL_RenderClear(renderer);

      for (i = 0; i < MAX; i++)
        if (R[i].print == true)
          R[i].Draw(window, renderer, 255, 0, 255, 255); // Draw the ractangle
      
      P.Draw(window, renderer, 255, 255, 255, 255); // Draw the main ractangle

      // Moving circle
      if (bNeedMove == true)
      {
        A.pos_y = A.pos_y + directionY * A.speed_y * 10;
        A.pos_x = A.pos_x + directionX * A.speed_x * 10;
        bNeedMove = false;
      }

      A.Draw(renderer);
      
      // You are loose
      if (A.pos_y > SCREEN_HEIGHT - 30)
      {
        quit = true;
        printf("\n\nYOU LOSE\n\n");
      }

      // You are win
      if (BRICK_COUNTER == 4)
      {
        quit = true;
        printf("\n\nYOU WIN\n\nCONGRADULATIONS!\n\n");
      }

// Up until now everything was drawn behind the scenes.
// This will show the new, red contents of the window.
      SDL_RenderPresent(renderer);

      if (event.type == SDL_KEYDOWN) // If the keyboard button is pressed 
      {
        switch (event.key.keysym.sym)
        {
        case SDLK_LEFT:  P.pos_x -= P.speed_x; break; // Moving the ractangle left
        case SDLK_RIGHT: P.pos_x += P.speed_x; break; // Moving the ractangle right
        }
        break;
      }

      SDL_RenderClear(renderer);

      // Closing the window
      if (event.type == SDL_QUIT)
      {
        quit = true;
        printf("\n\nYOU CLOSED THE GAME\n\n");
      }
    }
  }

  // Close and destroy the window
  SDL_DestroyWindow(window);

  // Clean up
  SDL_Quit();


  system("pause");

  return 0;
}
