//
// Created by Valentin on 06/12/2021.
//

#ifndef EPUBREADER_READER_H
#define EPUBREADER_READER_H

#include <stdbool.h>
#include "epub.h"
#include "raylib.h"

typedef struct {
    unsigned char **spine;
    unsigned int size;
} TOC;

typedef struct {
    unsigned char **hrefList;
    unsigned char **idList;
    bool *isImg;
    unsigned int size;
} Manifest;

typedef struct {
    Manifest manifest;
    TOC toc;
    struct epub_t epub;
} Core;

typedef struct {
    unsigned int fontSize;
    // Color color;
    // font family
    /* IF IMAGE */
    unsigned char *src; // DEFAULT: NULL
} Properties;

typedef struct {
    const unsigned char *tag;
    unsigned char *content;
    Properties prop;
} HTMLNode;

/**
 * initialize and open a given epub file
 * @param filename filename/path to the epub file
 * @return an initialized and declared struct epub_t var
 */
struct epub_t prepareEpub(const char *filename);

/**
 *
 * @param epub
 * @return
 */
Manifest prepareManifest(struct epub_t *epub);

/**
 *
 * @param epub
 * @return
 */
TOC prepareTOC(struct epub_t *epub);

HTMLNode *parseHTMLFile(const unsigned char *fileContent);

unsigned int getIndexManifest(Core *core, unsigned char *idref);

void initRaylibFunctions(void);

#endif //EPUBREADER_READER_H
