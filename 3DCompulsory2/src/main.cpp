#include "Backend/Backend.h"
#include "Window/Window.h"

int main()
{
    Window window;
    Backend backend;
    backend.initialize(&window);
    backend.run();
    return 0;
}