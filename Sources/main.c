#include "reader.h"
#include <string.h>

int main(void)
{
    struct epub_t epub = prepareEpub("caughtup.epub");
    Manifest manifest;
    TOC toc;

    manifest = prepareManifest(&epub);
    toc = prepareTOC(&epub);
//    printf("%s\n", manifest.idList[5]);
//    printf("%s\n", read_zfile(epub.zipfile, (const char*) manifest.hrefList[50]));

    for (int i = 0; i < toc.size; i++) {
//        printf("ITEMREF IS:\t%s\n", toc.spine[i]);
        for (int j = 0; j < manifest.size; j++) {
            if (strcmp(toc.spine[i], manifest.idList[j]) == 0) {
//                printf("%s\n", manifest.hrefList[j]);
                printf("%s\n", read_zfile(epub.zipfile, manifest.hrefList[j]));
            }
        }
    }

    scanf("%s\n", NULL);
    return 0;
}