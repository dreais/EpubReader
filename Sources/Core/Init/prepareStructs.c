//
// Created by Valentin on 06/12/2021.
//

#include "reader.h"

Manifest prepareManifest(struct epub_t *epub)
{
    Manifest manifest = {0};
    xmlNodePtr node = get_root_node(epub->doc);
    int count = 0, i = 0;

    node = get_node(node, "manifest");
    node = node->children;

    while (node) {
        if (node->type == XML_TEXT_NODE)
            count++;
        node = node->next;
    }
    manifest.size = count;
    manifest.hrefList = malloc(sizeof(unsigned char *) * manifest.size);
    manifest.idList = malloc(sizeof(unsigned char *) * manifest.size);
//    manifest.isImg = malloc(sizeof(bool) * manifest.size);

    node = get_root_node(epub->doc);
    node = get_node(node, "manifest");
    node = node->children;
    while (node) {
        unsigned char *href = get_node_prop(node, "href");
        if (href) {
            manifest.hrefList[i] = href;
        }
        unsigned char *id = get_node_prop(node, "id");
        if (id) {
            manifest.idList[i] = id;
        }
        if (href && id) {
            i++;
        }
        node = node->next;
    }
    return manifest;
}

TOC prepareTOC(struct epub_t *epub)
{
    TOC toc;
    xmlNodePtr node = get_root_node(epub->doc);
    int count = 0, i = 0;

    node = get_node(get_node(node, "spine"), "itemref");
    while (node) {
        if (node->type == XML_TEXT_NODE)
            count++;
        node = node->next;
    }
    node = get_root_node(epub->doc);
    node = get_node(get_node(node, "spine"), "itemref");
    toc.size = count;
    toc.spine = malloc(sizeof(unsigned char *) * toc.size);
    while (node) {
        unsigned char *id = get_node_prop(node, "idref");
        if (id) {
            toc.spine[i] = id;
            i++;
        }
        node = node->next;
    }
    return toc;
}