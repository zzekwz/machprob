#ifndef GAMESCREEN_H
#define GAMESCREEN_H

typedef enum GameScreen
{
    MENU,
    SCORESCREEN,
    GAMEPLAY,
    GAMEOVER
} GameScreen;

void UpdateScreen(GameScreen *currentScreen);
void DrawScreen(GameScreen *currentScreen);





#endif // GAMESCREEN_H
