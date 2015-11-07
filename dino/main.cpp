#include "game.h"

int main(int argc, char* argv[]) {
    int fps = 1;
    Game game(fps);
    game.startEventLoop();
}

