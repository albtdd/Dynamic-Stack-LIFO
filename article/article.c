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


#include "article.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/**
 * A simple article
 */
struct article_t {
    unsigned id;        // Identifier (0 is for an invalid article)
    char *title;        // Article's title
    float price;        // Price of one article
    unsigned quantity;  // Quantity stored
};


Article* article_new(const unsigned id, const char *title,
                    const float price, const unsigned quantity) {
    if (title != 0) {
        Article *article = malloc(sizeof (*article));
        if (article != 0) {
            size_t len = strlen(title);
            article->title = malloc(sizeof (*article->title) * (len + 1));
            strcpy(article->title, title);
            article->id = id;
            article->price = price;
            article->quantity = quantity;
        }
        return article;
    }
    return 0;
}


void article_delete(Article *article) {
    if (article != 0) {
        free (article->title);
        free(article);
    }
}


Article* article_copy(const Article *article) {
    if (article != 0) {
        Article *copy = malloc(sizeof (*copy));
        if (copy != 0) {
            size_t len = strlen(article->title);
            copy->title = malloc(sizeof (*copy->title) * (len + 1));
            if (copy->title != 0) {
                strcpy(copy->title, article->title);
                copy->id = article->id;
                copy->price = article->price;
                copy->quantity = article->quantity;
            } else {
                free(copy);
                return 0;
            }
            return copy;
        }
    }
    return 0;
}


unsigned article_get_id(const Article *article) {
    return article != 0 ? article->id : -1;
}


const char* article_get_title(const Article *article) {
    return article != 0 ? article->title : 0;
}


float article_get_price(const Article *article) {
    return article != 0 ? article->price : -1.0f;
}


unsigned article_get_quantity(const Article *article) {
    return article != 0 ? article->quantity : 0;
}


bool article_set_id(Article *article, unsigned id) {
    if (article != 0) {
        article->id = id;
        return true;
    }
    return false;
}


bool article_set_title(Article *article, const char *title) {
    if (article != 0 && title != 0) {
        free(article->title);
        size_t len = strlen(title);
        article->title = malloc(sizeof(*article->title) * (len + 1));
        if (article->title) {
            strcpy(article->title, title);
            return true;
        }
    }
    return false;
}


bool article_set_price(Article *article, float price) {
    if (article != 0) {
        article->price = price;
        return true;
    }
    return false;
}


bool article_set_quantity(Article *article, unsigned quantity) {
    if (article != 0) {
        article->quantity = quantity;
        return true;
    }
    return false;
}


void article_print(const Article *article) {
    if (article != 0) {
        printf("\nArticle\nID\t%d\nTitle\t%s",
                article->id, article->title);

        printf("\nPrice\t€%2.2f\nQty.\t%d\n",
                article->price, article->quantity);
    } else {
        printf("[ NULL ]\n");
    }
}

