#include <iostream>

#include "Engine.hpp"

int main(int argc, char* argv[])
{
    bool quit = false;

    while(!quit)
    {
        if (!Engine::Instance()->Listen())
            quit = true;

        Engine::Instance()->Update();
        Engine::Instance()->Draw();
    }

    Engine::Instance()->Quit();

    return EXIT_SUCCESS;
}

