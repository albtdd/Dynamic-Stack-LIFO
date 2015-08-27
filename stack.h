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


#ifndef _STACK_H_
#define _STACK_H_

#ifdef __cplusplus
extern "C" {
#endif

ifdef __unix__
#include "node/node.h"
#else
#include "node\node.h"
#endif

#include <stdlib.h>


// Early declaration of the struct. See stack.c    
typedef struct stack_t Stack;


// Defines pointer to a function that returns void and 
// gets const Article* as a parameter.
//
// Usefull for the const iterator's functions defined below
typedef void (*const_iter_action)(const Article *);

// Usefull for the iterator's functions defined below
typedef void (*iter_action)(Article *);


// Infinity 
#define INF 0


/**
 * @brief Creates a new empty Stack
 *
 * @param nothing
 *
 * @return The Stack pointer or NULL on error
 *
 * @note You must use this function before any other action
 *       You must free memory allocated with stack_delete
 */
Stack* stack_new(size_t max_size);


/**
 * @brief Frees memory area allocated with stack_new
 *
 * @param stack The pointer to the Stack
 *
 * @return nothing
 *
 * @note No crash if param is NULL, returns 0
 *       Undefined behavior if param is an invalid pointer
 */
void stack_delete(Stack *stack);


/**
 * @brief Gets the actual size of the stack
 *
 * @param stack The pointer to the stack
 *
 * @return The size of the stack
 *
 * @note No crash if param is NULL, returns 0
 *       Undefined behavior if param is an invalid pointer
 */
size_t stack_size(const Stack *stack);


/**
 * @brief Checks if the stack is empty or no
 *
 * @param stack The pointer to the stack
 *
 * @return true if the stack is empty, false otherwise
 *
 * @note No crash if param is NULL, returns false (empty)
 *       Undefined behavior if param is an invalid pointer
 */
bool stack_isempty(const Stack *stack);


/**
 * @brief Checks if the stack is full or no
 *
 * @param stack The pointer to the stack
 *
 * @return true if the stack is full, false otherwise
 *
 * @note No crash if param is NULL, returns true (full)
 *       Undefined behavior if param is an invalid pointer
 */
bool stack_isfull(const Stack *stack);


/**
 * @brief Inserts an Article to the top of the stack
 *
 * @param stack The stack pointer
 * @param article The article pointer
 *
 * @see article_new, article_delete
 *
 * @return bool if the insertion had success, false otherwise
 *
 * @note A deep copy af the *article is inserted to the stack
 * @note No crash if param is NULL, returns false
 *       Undefined behavior if param is an invalid pointer
 */
bool stack_push(Stack *stack, const Article *article);


/**
 * @brief Pop the last article inserted.
 *        Gets a pointer to the article in the node. The node is deleted
 *        but not the article in the node.
 *
 * @param stack The stack pointer
 *
 * @return The const pointer to the article
 *
 * @note You must use article_delete with this pointer after the use
 * @note No crash if param is NULL, returns 0
 *       Undefined behavior if param is an invalid pointer
 */
Article* stack_pop(Stack *stack);


/**
 * @brief Pop the last article inserted.
 *        Gets a pointer to the article in the node. The node is not deleted
 *
 * @param stack The stack pointer
 *
 * @return The const pointer to the article
 *
 * @note Don't use article_delete with this pointer
 * @note No crash if the param is NULL, returns 0
 *       Undefined behavior if param is an invalid pointer
 */
const Article* stack_peek(const Stack *stack);


/**
 * @brief A const Iter from top to bottom of the stack
 *
 * @param stack The stack pointer
 * @param action Pointer to the const function that acts on every item
 *
 * @return nothing
 *
 * @note You can't modify any items of the stack
 * @note No crash if any param is NULL
 *       Undefined behavior any param is an invalid pointer
 */
void stack_iterator_const(const Stack *stack, const_iter_action action);

/**
 * @brief A Iter from top to bottom of the stack
 *
 * @param queue The stack pointer
 * @param action Pointer to the function that acts on every item
 *
 * @return nothing
 *
 * @note You can modify all the items of the stack
 * @note No crash if any param is NULL
 *       Undefined behavior any param is an invalid pointer
 */
void stack_iterator(Stack *stack, iter_action action);


#ifdef __cplusplus
}
#endif

#endif // _STACK_H_
