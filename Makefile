CC=gcc
CFLAGS=-g -Wall -pedantic -std=c99 -Werror

all:
	$(CC) $(CFLAGS) -I./include/ -o lr ./src/list_ranking.c