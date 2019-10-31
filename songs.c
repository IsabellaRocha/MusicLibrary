#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        if(strcmp(Artist, n->artist) == 0 || strcmp(Name, n->name) == 0) {
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
        if(strcmp(Artist, n->artist) == 0) {
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

struct song_node * insert_alph(struct song_node * n, char Name[100], char Artist[100]){
  struct song_node *start = n;
  struct song_node *prev = n;
  struct song_node *s = malloc(sizeof(struct song_node));
  s->name = Name;
  s->artist = Artist;
  if (strcmp(s->artist, n->artist) < 0){
    s->next = n;
    return s;
  }
  if (strcmp(s->artist, n->artist) == 0 && strcmp(s->song, n->song) == 0){
    s->next = n;
    return s;
  }
  while (n != NULL) {
    if (strcmp(s->artist, n->artist) == 0){
      if (strcmp(s->song, n->song) <= 0){
        prev->next = s;
        s->next = n;
        return start;
      }
    }
    if (strcmp(s->artist, n->artist) <= 0){
      prev->next = s;
      s->next = n;
      return start;
    }
    prev = n;
    n = n->next;
  }
  prev->next = s;
  s->next = n;
  return start;
}

struct song_node * remove_node(struct song_node *n,  char Name[100], char Artist[100]) {
    struct song_node *p;
    struct song_node *temp;
    p = n;
    if (strcmp(n->name, Name) == 0 && strcmp(n->artist, Artist) == 0) {
        p = p->next;
        free(n);
        return p;
    }
    while (p->next != NULL) {
        if(strcmp(p->next->name, Name) == 0 && strcmp(p->next->artist, Artist) == 0) {
            temp = p->next;
            p->next = p->next->next;
            free(temp);
            return front;
        }
        else {
            p = p->next;
        }
    }
    return n;
}
