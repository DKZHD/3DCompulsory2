#include "Backend/Backend.h"
#include "FrontEnd/FrontEnd.h"
#include "Window/Window.h"

int main()
{
    Backend backend;
    FrontEnd frontend;
    frontend.run();
    return 0;
}