//
// Created by Valentin on 06/12/2021.
//

#include "reader.h"

struct epub_t prepareEpub(const char *filename)
{
    struct epub_t epub;
    char *content;

    epub_init(&epub, filename);
    get_root_file(&epub);
    content = read_zfile(epub.zipfile, epub.rfpath);
    epub.doc = prepare_doc(content);
    return epub;
}