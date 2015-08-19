@echo "Dynamic Stack - Alberto Todde <alberto.tdd@gmail.com>"
OS := $(shell uname)
ifeq ($(OS), Linux)
    ARTICLE_DIR = ../article/
    NODE_DIR = ../node/
    CLEAN = rm -f
else # Windows
    ARTICLE_DIR ..\article\
    NODE_DIR = ..\node\
    CLEAN = del
endif

CC = gcc

CFLAGS = -std=c11 -Wall -Wpointer-arith -fstrict-aliasing -pedantic -Werror
DFLAGS = -DDEBUG -gO0
RFLAGS = -DNDEBUG -O3 -funroll-loops

LIBS =

SOURCES = $(ARTICLE_DIR)article.c $(NODE_DIR)node.c queue.c main.c

OBJECTS = $(SOURCES:.c=.o)

EXECUTABLE = queue

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $(OBJECTS) -o $@
	@echo " "
	@echo "[*]Done"
	@echo " "

.PHONY clean:
	$(CLEAN) $(OBJECTS)

#.c.o:
#	$(CC) $(CFLAGS) $< -o $@

