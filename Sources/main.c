#include "reader.h"

int main(void)
{
    Core core = {0};
    HTMLNode *page;
    core.epub = prepareEpub("caughtup.epub");

    core.manifest = prepareManifest(&core.epub);
    core.toc = prepareTOC(&core.epub);

    page = parseHTMLFile(read_zfile(core.epub.zipfile, core.manifest.hrefList[getIndexManifest(&core, "id267")]));

    for (int i = 0; page[i].tag; i++) {
        if (page[i].content) {
            printf("%s\n", page[i].content);
        }
    }

    scanf("%s\n", NULL);
    return 0;
}