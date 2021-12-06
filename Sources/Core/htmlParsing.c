//
// Created by Valentin on 06/12/2021.
//

#include "reader.h"
#include <libxml2/libxml/HTMLparser.h>
#include <string.h>

// TODO: check if we can just use xmlDocPtr and xmlReadDoc instead of the html versions
// it could save some lines and headaches due to the parameters
HTMLNode *parseHTMLFile(const unsigned char *fileContent)
{
    HTMLNode *page;
    htmlDocPtr html = htmlReadDoc(fileContent, "/", "UTF-8", 0);
    htmlNodePtr n = get_node(get_root_node(html), "body");
    int count = 0, i = 0;

    n = n->children;//get_node(n, "p");
    while (n) {
        if (n->type == XML_ELEMENT_NODE) {
            count++;
        }
        n = n->next;
    }
    page = malloc(sizeof(HTMLNode) * count + 1);
    page[count].tag = NULL;
    n = get_node(get_node(get_root_node(html), "body"), "p");
    while (n) {
        if (n->type == XML_ELEMENT_NODE) {
            if (n->children) {
                n = n->children;
                if (n->content) {
                    page[i].content = n->content;
                    page[i].tag = n->name;
//                    printf("%s\n", n->content);
                } else if (strcmp(n->name, "img") == 0) {
                    page[i].prop.src = get_node_prop(n, "src");
                    page[i].tag = n->name;
                    page[i].content = NULL;
//                    printf("%s\n", get_node_prop(n, "src"));
                }
                i++;
                n = n->parent;
            }
        }
        n = n->next;
    }
    return page;
}