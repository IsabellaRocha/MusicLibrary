#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct song_node{
    char name[100];
    char artist[100];
    struct song_node *next;
};

struct song_node * insert_front(struct song_node * n, char Name[100], char Artist[100]);
struct song_node * insert_alph(struct song_node * n, char Name[100], char Artist[100]);
void print_list(struct song_node * n);
struct song_node * find_song(struct song_node * n, char Name[100], char Artist[100]);
struct song_node * find_first_song(struct song_node * n, char Artist[100]);
struct song_node * rando(struct song_node * n);
struct song_node * free_list(struct song_node * n);
struct song_node * remove_node(struct song_node *n,  char Name[100], char Artist[100]);
void print_node(struct song_node *n);
