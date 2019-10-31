#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "songlist.h"

void print_list(struct song_node *n) {
    printf("[ ");
    while(n != NULL) {
        printf("%c, %c ", n->name, n->artist);
        n = n->next;
    }
    printf("]\n");
}

struct song_node * insert_front(struct song_node * n, char Name[100], char Artist[100]);
    struct song_node *p = malloc(sizeof(struct song_node));
    p->name = Name;
    p->next = n;
    p->artist = Artist;
    return p;
}

struct song_node * find_song(struct song_node * n, char Name[100], char Artist[100]) {
    while(n != NULL) {
        if(strcmp(Artist) != strcmp(n->artist) || strcmp(Name) != strcmp(n->name)) {
            n = n->next;
        }
        else {
            return n;
        }
    }
    return NULL;
}
struct song_node * find_first_song(struct song_node * n, char Artist[100]) {
    while(n != NULL) {
        if(strcmp(Artist) != strcmp(n->artist)) {
            n = n->next;
        }
        else {
            return n;
        }
    }
    return NULL;
}
struct song_node * free_list(struct song_node *n) {
    struct song_node *p;
    while (n != NULL) {
        p = n->next;
        free(n);
        n = p;
    }
    return p;
}
