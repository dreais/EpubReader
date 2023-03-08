#include <string.h>
#include "reader.h"

int main(void)
{
    Core core = {0};
    HTMLNode *page;
    core.epub = prepareEpub("caughtup.epub"); // THOSE ARE HARDCODED VALUE, THIS IS FOR DEBUG PURPOSE

    core.manifest = prepareManifest(&core.epub);
    core.toc = prepareTOC(&core.epub);

    page = parseHTMLFile(read_zfile(core.epub.zipfile, core.manifest.hrefList[getIndexManifest(&core, "id267")]));
//    initRaylibFunctions();
//    while (!WindowShouldClose()) {
//        BeginDrawing();
//        ClearBackground((Color) {34, 34, 34, 255});
//        DrawTextEx(font, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", (Vector2) {0, 0}, font.baseSize, 1, WHITE);
//        EndDrawing();
//    }
//    CloseWindow();



    const int screenWidth = 800;
    const int screenHeight = 600;
    int fontSize = 40, spacingY = 2;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_MAXIMIZED);
    InitWindow(screenWidth, screenHeight, "raygui - portable window");
    Font font = LoadFontEx("C:\\Windows\\Fonts\\times.ttf", 40, NULL, 95);

    int drawnLines = GetScreenHeight() / (fontSize + spacingY);

    Vector2 initialPos = {.x = 0, .y = 0};
//    for (int i = 0; page[i].tag; i++) {

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground((Color) {34, 34, 34, 255});

        Vector2 initialPos = {.x = 0, .y = 0};
        for (int i = 0; page[i].tag; i++) {
            if (strcmp(page[i].tag, "text") == 0) {
                int count = 0, endL = 0, lineSize = 0;
                const char **words = TextSplit(page[i].content, ' ', &count);

                float len = 0;
                for (int j = 0; j < count; j++) {
                    len += MeasureTextEx(font, words[j], fontSize, 5).x;
                    if (len >= (float) GetScreenWidth()) {
                        initialPos = (Vector2) {.x = 0, .y = (float) fontSize + initialPos.y};
                        len = MeasureTextEx(font, words[j], fontSize, 5).x;
                    }
                    DrawTextEx(font, words[j], initialPos, fontSize, 0, WHITE);
                    initialPos.x = len;
                }
                initialPos = (Vector2) {.x = 0, .y = (float) fontSize + initialPos.y};
            }
        }
        EndDrawing();
//        scanf("%s\n", NULL);
    }
    CloseWindow();

    return 0;
}