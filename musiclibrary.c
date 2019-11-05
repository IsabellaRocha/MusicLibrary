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

void add_song(struct song_node *lib[27], char Name[100], char Artist[100]) {
    lib[idx] = insert_alph(lib[index(Artist[0])], Name, Artist);
}

struct song_node * find(struct song_node *lib[27], char Name[100], char Artist[100]) {
    return find_song(lib[index(Artist[0])], Name, Artist);
}

struct song_node * find_Artist(struct song_node *lib[27], char Artist[100]) {
    return find_first_song(lib[index(Artist[0])], Artist);
}

void print_letter(struct song_node *lib[27], char letter) {
    int idx = index(letter);
    print_list(lib[idx]);
}

void print_artist(struct song_nod *lib[27], char Artist[100]) {
    struct node *p = find_Artist(lib, Artist);
    while(p != NULL && strcmp(p->artist, Artist) == 0) {
        print_node(p);
        printf(" ");
        p = p->next;
    }
    printf("\n");
}

void print_lib(struct song_node *lib[27]) {
    int idx = 0;
    for (idx; idx < 27; idx++) {
        print_list(lib[idx]);
    }
    printf("\n");
}

void delete_song(struct song_node *lib[27], char Name[100], char Artist[100]) {
    lib[index(Artist[0])] = remove_node(lib[index(Artist[0])], Name, Artist);
}

void clear_lib(struct song_node *lib[27]) {
    int idx = 0;
    for(idx; idx < 27; idx++) {
        lib[idx] = free_list(lib[idx]);
    }
}

void shuffle(struct song_node *lib[27]) {
    int idx;
    for(idx = 0; idx < 5; idx++) {
        int idx = rand() % 26;
        struct song_node *n = rando(lib[idx]);
        print_node(n);
        printf("\n");
    }
}
