# Dynamic-Stack-LIFO
A simple dynamic Stack. A Stack follows the LIFO pattern's rules.

Dynamic Stack - LIFO
====================

A stack is a simple data structure that follows the simple rule: Last In - First Out
The last item inserted (push) into the stack is the first that comes out (pop).

Dynamic stack is not limited in size. You can add all the items you want. The only limit is the memory of your system.

You can create a new stack with:
```C
Stack *my_lifo = stack_new();
```

I have created an item to push into the stack called Article. It's only an example.
```C
Article *art = new_article(1, "title of art", 12.55, 5);

stack_push(my_lifo, art);
```
NB: stack_push creates a own copy (deep copy) of Article. It's your responsibility delete all the articles created,
when they are not more useful, with:
```C
delete_article(art)
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

In main.c ther is a simple demo of the stack usage.

See the .h files to read the descriptions of all the functions.


Author
======
Alberto Todde <alberto.tdd@gmail.com>



