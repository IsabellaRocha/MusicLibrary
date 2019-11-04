struct song_node{
    char *name;
    char *artist;
    struct song_node *next;
};

struct song_node * insert_front(struct song_node * n, char *Name, char *Artist);
struct song_node * insert_alph(struct song_node * n, char *Name, char *Artist);
void print_list(struct song_node * n);
struct song_node * find_song(struct song_node * n, char *Name, char *Artist);
struct song_node * find_first_song(struct song_node * n, char *Artist);
struct song_node * rando(struct song_node * n);
struct song_node *free_list(struct song_node * n);
struct song_node * remove_node(struct song_node *n,  char *Name, char *Artist);
void print_node(struct song_node *n);
