#include "reader.h"

int main(void)
{
    Core core = {0};
//    HTMLNode *page;
//    core.epub = prepareEpub("caughtup.epub"); // THOSE ARE HARDCODED VALUE, THIS IS FOR DEBUG PURPOSE
//
//    core.manifest = prepareManifest(&core.epub);
//    core.toc = prepareTOC(&core.epub);
//
//    page = parseHTMLFile(read_zfile(core.epub.zipfile, core.manifest.hrefList[getIndexManifest(&core, "id267")]));
    InitWindow(500, 500, "E-books reader");
    SetTargetFPS(30);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground((Color) {34, 34, 34, 255});
        EndDrawing();
    }
    CloseWindow();
    return 0;
}