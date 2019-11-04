void print_letter(struct song_node **lib, char letter);
void print_Artist(struct song_node **lib, char *Artist);
void print_lib(struct song_node **lib);
void add_lib(struct song_node **lib, char *Name, char *Artist);
struct song_node * find_lib(struct song_node **lib, char *Name, char *Artist);
struct song_node * find_Artist_lib(struct song_node **lib, char *Artist);
void delete_song(struct song_node **lib, char*Name, char*Artist);
void clear_lib(struct song_node **lib);
void shuffle(struct song_node **lib)
