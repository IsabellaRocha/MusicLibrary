#include "musiclibrary.h"

int place(char Artist[100]) {
    int letter = Artist[0];
    if (letter >= 97 && letter <= 122) return letter % 97;
    return 26;
}

void add_song(struct song_node *lib[27], char Name[100], char Artist[100]) {
    lib[place(Artist)] = insert_alph(lib[place(Artist)], Name, Artist);
}

struct song_node * find(struct song_node *lib[27], char Name[100], char Artist[100]) {
    return find_song(lib[place(Artist)], Name, Artist);
}

struct song_node * find_artist(struct song_node *lib[27], char Artist[100]) {
    return find_first_song(lib[place(Artist)], Artist);
}

void print_letter(struct song_node *lib[27], char letter) {
    int idx;
    if(letter >= 97 && letter <= 122) {
        idx = letter % 97;
    }
    else {
        idx = 26;
    }
    print_list(lib[idx]);
}

void print_artist(struct song_node *lib[27], char Artist[100]) {
    struct song_node *p = find_artist(lib, Artist);
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
    lib[place(Artist)] = remove_node(lib[place(Artist)], Name, Artist);
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
