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


#ifndef _ARTICLE_H_
#define _ARTICLE_H_

#ifdef __cplusplus
extern "C" {
#endif


#include <stdbool.h>


// Early declaration of the struct. See article.c
typedef struct article_t Article;


/**
 * @brief Creates a new filled struct of Article
 *
 * @param id The identifier of the article
 * @param title The title of the article (use dynamic memory)
 * @param price The price of the article
 * @param quantity The quantity stocked
 *
 * @return A pointer to the struct Article created or NULL on error
 *
 * @note You must use this function before any other action on an Article 
 *       You must free memory area with article_delete after the use
 */
Article* article_new(const unsigned id, const char *title,
                    const float price, const unsigned quantity);

/**
 * @brief Frees memory allocate by an Article
 *
 * @param article The pointer to the memory area to be freed
 *
 * @return nothing
 *
 * @note The param should be not set to zero after use
 * @note No crash if param is NULL
 *       Undefined behavior if param is an invalid pointer
 */
 void article_delete(Article *article);


/**
 * @brief Creates a deep copy of an Article
 *
 * @param article The pointer to the memory area to be copied
 *
 * @return The pointer to the copy
 *
 * @note You must free memory with article_delete after the use
 * @note No crash if param is NULL, returns NULL
 *       Undefined behavior if param is an invalid pointer
 */
Article* article_copy(const Article *article);


/**
 * @brief Gets the id of an article
 *
 * @param article The pointer to the article
 *
 * @return The id (-1 on error)
 *
 * @see article_set_id
 *
 * @note No crash if param is NULL, returns 0
 *       Undefined behavior if param is an invalid pointer
 */
unsigned article_get_id(const Article *article);


/**
 * @brief Gets the title of an article
 *
 * @param article The pointer to the article
 *
 * @return A const pointer to the title or NULL on error
 *
 * @see article_set_title
 *
 * @note No crash if param is NULL, returns NULL
 *       Undefined behavior if param is an invalid pointer
 */
const char* article_get_title(const Article *article);


/**
 * @brief Gets the price of an article
 *
 * @param article The pointer to the article
 *
 * @return The price
 *
 * @see article_set_price
 *
 * @note No crash if param is NULL, returns -1.0f
 *       Undefined behavior if param is an invalid pointer
 */
float article_get_price(const Article *article);


/**
 * @brief Gets the quantity of an article
 *
 * @param article The pointer to the artcile
 *
 * @return The quantity
 *
 * @note No crash if param is NULL, returns false
 *       Undefined behavior if param is an invalid pointer
 */
unsigned article_get_quantity(const Article *article);


/**
 * @brief Sets the quantity of an article
 *
 * @param article The pointer to the artcile
 * @param id The new id
 *
 * @return true if sets, false on error
 *
 * @note No crash if param is NULL, returns false
 *       Undefined behavior if param is an invalid pointer
 */
bool article_set_id(Article *article, unsigned id);


/**
 * @brief Sets the title of an article
 *
 * @param article The pointer to the artcile
 * @param id The new title
 *
 * @return true if sets, false on error
 *
 * @note No crash if param is NULL, returns false
 *       Undefined behavior if param is an invalid pointer
 */
bool article_set_title(Article *article, const char *title);


/**
 * @brief Sets the price of an article
 *
 * @param article The pointer to the artcile
 * @param id The new price
 *
 * @return true if sets, false on error
 *
 * @note No crash if param is NULL, returns false
 *       Undefined behavior if param is an invalid pointer
 */
bool article_set_price(Article *article, float price);


/**
 * @brief Sets the quantity of an article
 *
 * @param article The pointer to the artcile
 * @param id The new quantity
 *
 * @return true if sets, false on error
 *
 * @note No crash if param is NULL, returns false
 *       Undefined behavior if param is an invalid pointer
 */
bool article_set_quantity(Article *article, unsigned quantity);


/**
 * @brief Simple prints of an article.
 *
 * @param article The pointer to the artcile
 *
 * @return nothing 
 *
 * @note No crash if param is NULL
 *       Undefined behavior if param is an invalid pointer
 */
void article_print(const Article *article);


#ifdef __cplusplus
}
#endif


#endif // _ARTICLE_H_
