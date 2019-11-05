#include "songlist.h"


int songcmp(struct song_node *a, char b_name[100], char b_artist[100]){
  int ans = strcmp(a->artist, b_artist);
  if (ans != 0){
    return ans;
  }
  return strcmp(a->name, b_name);
}

void print_list(struct song_node *n) {
    while(n != NULL) {
        print_node(n);
        printf("|");
        n = n->next;
    }
    printf("\n");
}


void print_node(struct song_node *n){
    if(n != NULL) {
        printf(" %s: %s", n->name, n->artist);
    }
}

struct song_node * insert_front(struct song_node *n, char Name[100], char Artist[100]) {
    struct song_node *p = malloc(sizeof(struct song_node));
    strcpy(p->name, Name);
    strcpy(p->artist, Artist);
    p->next = n;
    return p;
}

struct song_node * find_song(struct song_node * n, char Name[100], char Artist[100]) {
    while(n != NULL) {
        if (songcmp(n, Name, Artist) == 0) {
            return n;
        }
        n = n->next;
    }
    return NULL;
}

struct song_node * find_first_song(struct song_node * n, char Artist[100]) {
    while(n != NULL) {
        if(strcmp(n->artist, Artist) == 0) {
            return n;
        }
        n = n->next;
    }
    return NULL;
}

struct song_node * free_list(struct song_node *n) {
    struct song_node *p = n;
    while (n != NULL) {
        printf("Freeing song %s\n", n->name);
        p = n->next;
        free(n);
        n = p;
    }
    return n;
}

struct song_node * insert_alph(struct song_node * n, char Name[100], char Artist[100]) {
    if (n == NULL) {
        n = insert_front(n, Name, Artist);
        return n;
    }
    struct song_node *cur = n;
    struct song_node *prev = NULL;
    while(cur != NULL && strcmp(cur->artist, Artist) < 0) {
       prev = cur;
       cur = cur->next;
   } //Now at right artist
   while(cur != NULL && strcmp(cur->name, Name) < 0 && strcmp(cur->artist, Artist) == 0) {
       prev = cur;
       cur = cur->next;
   } //Now at right song
   if (prev != NULL) {
       prev->next = insert_front(cur, Name, Artist);
       return n;
   }
   return insert_front(cur, Name, Artist); //Will only run if adding to front
}

struct song_node * remove_node(struct song_node *n,  char Name[100], char Artist[100]) {
    struct song_node *p = n;
    struct song_node *temp;
    while(p != NULL) {
        if(songcmp(n, Name, Artist) == 0) {
            if(p == n) {
                n = p->next;
            }
            else {
                temp->next = p->next;
            }
            free(p);
            return n;
        }
        temp = p;
        p = p->next;
    }
    return n;
}

struct song_node * rando(struct song_node * n){
  struct song_node * start = n;
  int counter;
  counter = 0;
  while (n != NULL){
    counter++;
    n = n->next;
  }
  int node;
  node = rand() % counter;
  while (node >= 0 && start != NULL){
      if(start->next == NULL) {
          return start;
      }
      start = start->next;
      node--;
  }
  return start;
}
