#include "songlist.h"

void add_song(struct song_node *lib[27], char Name[100], char Artist[100]);
struct song_node * find(struct song_node *lib[27], char Name[100], char Artist[100]);
struct song_node * find_Artist(struct song_node *lib[27], char Artist[100]);
void print_letter(struct song_node *lib[27], char letter);
void print_Artist(struct song_node *lib[27], char Artist[100]);
void print_lib(struct song_node *lib[27]);
void shuffle(struct song_node *lib[27]);
void delete_song(struct song_node *lib[27], char Name[100], char Artist[100]);
void clear_lib(struct song_node *lib[27]);
int place(char Artist[100]);
