//
// Created by Valentin on 06/12/2021.
//

#include "reader.h"
#include <string.h>

unsigned int getIndexManifest(Core *core, unsigned char *idref)
{
    for (int j = 0; j < core->manifest.size; j++) {
        if (strcmp(idref, core->manifest.idList[j]) == 0) {
            return j;
        }
    }
    return -1;
}