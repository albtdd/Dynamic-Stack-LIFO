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


#ifndef _NODE_H_
#define _NODE_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __unix__
#include "../article/article.h"
#else
#include "..\article\article.h"
#endif

#include <stdbool.h>


// Early declaration of the struct. See node.c 
typedef struct node_t Node;


/**
 * @brief Creates a new node with a deep copy of Article inside
 *
 * @param article The pointer to the article
 *
 * @return The pointer to the new node created, or NULL on error
 *
 * @note You must use this function before any other action
 *       You must frees memory area allocated with node_delete
 * @note No crash if the param is NULL
 *       Undefined behavior if param is an invalid pointer
 */
Node* node_new(const Article *article);


/**
 * @brief Frees memory area allocated with node_new
 *
 * @param node The pointer to the node
 *
 * @return nothing
 *
 * @note No crash if the param is NULL
 *       Undefined behavior if param is an invalid pointer
 */
void node_delete(Node *node);


/**
 * @brief Gets the content of the node
 *
 * @param node The pointer to the node
 *
 * @return A deep copy of the content of the node, or NULL on error
 *
 * @note No crash if param is NULL
 *       Undefined behavior if param is an invalid pointer
 */
Article* node_get_content(const Node *node);


/**
 * @brief Gets a constant pointer to the content of the node
 *
 * @param node The pointer to the node
 *
 * @return A const pointer ti the content of the node
 *
 * @note No crash if the param is NULL
 *       Undefined behavior if param is an invalid pointer
 */
const Article* node_get_content_ptr(const Node *node);


/**
 * @brief Gest the pointer to the next node
 *
 * @param node The pointer to the current node
 *
 * @return The pointer to the next node
 *
 * @note No crash if the param is NULL
 *       Undefined behavior if param is an invalid pointer
 */
Node* node_get_next(const Node *node);


/**
 * @brief Sets a next-node to a node (current)
 *
 * @param current The pointer to the node to sets the next
 * #param next The pointer to the node that will be the next
 *
 * @return true on success, false otherwise
 *
 * @note No crash if any param is NULL
 *       Undefined behavior if any param is an invalid pointer
 */
bool node_set_next(Node *current, Node *next);


#ifdef __cplusplus
}
#endif

#endif // _NODE_H_
