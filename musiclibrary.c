#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "songlist.h"
#include "library.h"

int index(char letter) {
    int idx;
    if (letter > 90) {
        idx = letter - 97;
    }
    else {
        idx = letter - 65;
    }
    if (idx > 26) {
        idx = 26;
    }
    return idx;
}

void add_song(struct song_node **lib, char *Name, char *Artist) {
    lib[idx] = insert_alph(lib[index(Artist[0])], Name, Artist);
}

struct song_node * find(struct song_node **lib, char *Name, char *Artist) {
    return find_song(lib[index(Artist[0])], Name, Artist);
}

struct song_node * find_Artist(struct song_node **lib, char *Artist) {
    return find_first_song(libe[index(Artist[0])], Artist);
}

void print_letter(struct song_node **lib, char letter) {
    int idx = index(letter);
    prtin_list(lib[idx]);
}

void print_artist(struct song_nod **lib, char *Artist) {
    struct node *p = find_Artist(lib, Artist);
    while(p != NULL && strcmp(p->artist, Artist) == 0) {
        print_node(p);
        printf(" ");
        p = p->next;
    }
    printf("\n");
}
