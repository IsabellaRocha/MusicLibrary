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

struct song_node * insert_front(struct song_node *n, char Name[100], char Artist[100]) {
    struct song_node *p = malloc(sizeof(struct song_node));
    strcpy(p->name, Name);
    strcpy(p->artist, Artist);
    p->next = n;
    return p;
}

struct song_node * find_song(struct song_node * n, char Name[100], char Artist[100]) {
    while(n != NULL && (strcmp(Artist, n->artist) != 0 || strcmp(Name, n->name) != 0)) {
        n = n->next;
    }
    if(n == NULL) {
        printf("Song Not Found");
        return NULL;
    }
    return n;
}

struct song_node * find_first_song(struct song_node * n, char Artist[100]) {
    while(n != NULL && strcmp(Artist, n->artist) != 0) {
        n = n->next;
    }
    return n;
}

struct song_node * free_list(struct song_node *n) {
    struct song_node *p = n;
    while (n != NULL) {
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
    while(cur != NULL && strcmp(cur->artist, Artist) <= 0) {
        prev = cur;
        cur = cur->next;
    } //Now at right artist
    while(cur != NULL && strcmp(cur->name, Name) < 0 && strcmp(cur->artist, Artist) == 0) {
        prev = cur;
        cur = cur->next;
    } //Now at right song
    if (prev == NULL) {
        return insert_front(prev, Name, Artist);
    }
    prev->next = insert_front(cur, Name, Artist);
    return n;
}

struct song_node * remove_node(struct song_node *n,  char Name[100], char Artist[100]) {
    struct song_node *p = n;
    struct song_node *temp;
    while(p != NULL) {
        if(strcmp(p->name, Name) == 0 && strcmp(p->artist, Artist) == 0) {
            if(p == n) {
                n = p->next;
            }
            else {
                temp->next = p->next;
            }
            free(p);
            return n;
        }
        temp = n;
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
