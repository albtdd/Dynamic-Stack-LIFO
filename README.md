# Dynamic-Stack-LIFO
A simple dynamic Stack. A Stack follows the LIFO pattern's rules.

A stack is a simple data structure that follows the simple rule: Last In - First Out
The last item inserted (push) into the stack is the first that comes out (pop).

Dynamic stack is not limited in size. You can add all the items you want. The only limit is the memory of your system.

You can create a new stack with:
```C
Stack *my_lifo = stack_new(size_t max_size);
```
max_size defines the max item allowed into the stack.
0 means infinity size. I have defined INF for this purpose. 

I have created an item to push into the stack called Article. It's only an example.
```C
Article *art = new_article(1, "title of art", 12.55, 5);

stack_push(my_lifo, art);
```
NB: stack_push creates a own copy (deep copy) of Article. It's your responsibility delete all the articles created,
when they are not more useful, with:
```C
article_delete(art)
```

To extract an item from the stack you can simply use:
```C
Article *res = stack_pop(my_lifo);
```
See "article.h" for to know all the functions to manage it.

NB: It's again your responsibility delete all the items extracted from the stack (see above).

If you only want to know which is the top of the stack (without extract anything) you will use:
```C
Article *res_const = stack_peek(my_lifo);
```

NB: *res_const it's only a constant pointer. No memory to frees in that case.

When you have finished to using the stack:
```C
stack_delete(my_lifo):
```

To iter the Stack:
```C
void stack_iterator_const(const Stack *stack, const_iter_action action);
void stack_iterator(Stack *stack, iter_action action);
```
The functions iter, have as parameters, the stack in use and the pointer to the function to be applied to the elements of the stack. 
The const-function can only read the elements, the non-const-functions can read and write to the elements.


To know how many entries contain the stack is used:
```C
size_t stack_size(const Stack *stack);
```

To know if the stack is empty or not:
```C
bool stack_isempty(const Stack *stack);
```
returns true if the stack is empty (or NULL), false otherwise

To know if the stack is full or not:
```C
bool stack_isfull(const Stack *stack);
```
returns true if the stack is full (or NULL), false otherwise

Note
====
I added a repository (Node) with which to create the node used in this project.

Author
======
Alberto Todde <alberto.tdd@gmail.com>



