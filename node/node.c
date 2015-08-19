/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2011 Alberto Todde <alberto.tdd@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 */


#include "node.h"
#include <stdlib.h>

struct node_t {
    Article *article;
    Node *next;
};


Node* node_new(const Article *article) {
    Node *node = malloc(sizeof (*node));
    if (node != 0) {
        node->article = article_copy(article);
        if (node->article != 0) {
            node->next = 0;
        } else {
            free(node);
            return 0;
        }
    }
    return node;
}


void node_delete(Node *node) {
    if (node != 0) {
        article_delete(node->article);
        free(node);
    }
}


void node_remove(Node *node) {
    free(node);
}


Article* node_get_content_copy(const Node *node) {
    return node != 0 ? article_copy(node->article) : 0;
}


const Article* node_get_const_ptr(const Node *node) {
    return node != 0 ? node->article : 0;
}


Article* node_get_ptr(const Node *node) {
    return node != 0 ? node->article : 0;
}


Node* node_get_next(const Node *node) {
    return node != 0 ? node->next : 0;
}


bool node_set_next(Node *current, Node *next) {
    if (current != 0) {
        current->next = next;
        return true;
    }
    return false;
}

