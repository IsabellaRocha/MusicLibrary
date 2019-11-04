#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songlist.h"

void print_list(struct song_node *n) {
    if (n == NULL) {
        printf("|  |");
    }
    while(n != NULL) {
        printf("| %s: %s |", n->artist, n->name);
        n = n->next;
    }
    printf("\n");
}


void print_node(struct song_node *n){
    if (n == NULL) {
        printf("|  |");
    }
    else {
        printf("| %s: %s |\n", n->artist, n->name);
    }
}

struct song_node * insert_front(struct song_node *n, char *Name, char *Artist) {
    struct song_node *p = malloc(sizeof(struct song_node));
    p->name = Name;
    p->next = n;
    p->artist = Artist;
    return p;
}

struct song_node * find_song(struct song_node * n, char *Name, char *Artist) {
    while(n != NULL && (strcmp(Artist, n->artist) != 0 || strcmp(Name, n->name) != 0)) {
        n = n->next;
    }
    if(n == NULL) {
        printf("Song Not Found");
        return NULL;
    }
    return n;
}

struct song_node * find_first_song(struct song_node * n, char *Artist) {
    while(n != NULL && strcmp(Artist, n->artist) != 0) {
        n = n->next;
    }
    return n;
}

struct song_node * free_list(struct song_node *n) {
    if(n == NULL) {
        return n;
    }
    if (n->next = NULL) {
        free(n);
        n = NULL;
    }
    else {
        free_list(n->next);
        free(n);
        n = NULL;
    }
    return n;
}

struct song_node * insert_alph(struct song_node * n, char *Name, char *Artist) {
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
    if (prev != NULL) { //Take care of adding to the very front
        prev->next = insert_front(cur, Name, Artist);
        return n;
    }
    return insert_front(cur, Name, Artist); //Will only run if adding to front
}

struct song_node * remove_node(struct song_node *n,  char *Name, char *Artist) {
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
            return n;
        }
        else {
            p = p->next;
        }
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
