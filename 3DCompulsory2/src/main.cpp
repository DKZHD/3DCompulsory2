#include "Backend/Backend.h"
#include "FrontEnd/FrontEnd.h"
#include "Window/Window.h"

int main()
{
    Backend backend;
    FrontEnd frontend;
    frontend.initialize();
    return 0;
}