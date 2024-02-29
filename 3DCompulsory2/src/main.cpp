#include "Backend/Backend.h"
#include "Window/Window.h"

int main()
{
    Backend backend;
    backend.initialize();
    backend.run();
    return 0;
}