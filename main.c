/**
 * 
 *  A simple demo of dynamic stack
 *
 *  Alberto Todde <alberto.tdd@gmail.com>
 *
 */

#include "stack.h"  // Only include this header.
#include <stdio.h>


int main(void) {
    Stack *lifo = stack_new(INF);
    if (lifo) {

        printf("\nStack is empty: %s\n",
                stack_isempty(lifo) ? "Yes" : "No");

        puts("\nPress any key to continue...");
        getchar();

        for (int i = 1; i < 11; i++) {
            Article *tmp = article_new(i, "A title here", 12.3 * i, i * 2);
            if (tmp != 0) {
                stack_push(lifo, tmp);
                article_delete(tmp);    // Remember this
                printf("\nAritcle %d pushed", i);
            } else {
                printf("\nArticle error %d\n", i);
                return 1;
            }
        }
    }

    printf("\nStack:\n");
    stack_iterator_const(lifo, article_print);
    
    printf("\n\nStack is empty: %s\n",
            stack_isempty(lifo) ? "Yes" : "No");

    printf("Stack size is: %zu", stack_size(lifo));

    puts("\nPress any key to continue...");
    getchar();

    printf("\n*** Peek from stack ***\n");
    for (int i = 0; i < 5; i++) {
        const Article *pop = stack_peek(lifo);
        article_print(pop);
        //NB don't use article_delete(pop);
    }
    printf("\n\nStack size is: %zu", stack_size(lifo));


    puts("\nPress any key to continue...");
    getchar();

    printf("\n*** Pop from stack ***\n");
    for (int i = 0; i < 5; i++) {
        Article *pop = stack_pop(lifo);
        article_print(pop);
        // ... 
        article_delete(pop);    // Remeber this
    }
    printf("\nStack size is: %zu", stack_size(lifo));

    puts("\nPress any key to continue...");
    getchar();

    printf("\nStack delete.\n\n");
    stack_delete(lifo);
    lifo = 0;   // Optional statement.
                // lifo should be not set to zero after stack_delete

    return 0;
}
