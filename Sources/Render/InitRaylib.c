//
// Created by Valentin on 07/12/2021.
//

#include "reader.h"
#include "raylib.h"

void initRaylibFunctions(void)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1280, 720, "E-books reader");
    SetTargetFPS(30);
}
