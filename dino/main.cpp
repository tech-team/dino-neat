#include "platform.h"
#include "game.h"

int main() {
    int time_scale = 20;

    Game game(time_scale);
    game.startEventLoop();
}

