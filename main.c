#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songlist.h"

int main(){
  struct song_node * songlist;
  songlist = insert_alph(songlist, "doin time", "lana del rey");
  songlist = insert_alph(songlist, "panini", "lil nas x");
  songlist = insert_alph(songlist, "tighten up", "the black keys");
  songlist = insert_alph(songlist, "carolina", "harry styles");
  songlist = insert_alph(songlist, "selah", "kanye west");
  songlist = insert_alph(songlist, "runaway", "kanye west");
  printf("Testing print_list:\n");
  print_list(songlist);
  printf("Testing print_node:\n");
  print_node(songlist);
  printf("Testing find_node:\n");
  printf("Looking for [panini, lil nas x]:\n");
  print_list(find_song(songlist, "panini", "lil nas x"));
  printf("Looking for [old town road, lil nas x]:\n");
  print_list(find_song(songlist, "old town road", "lil nas x"));
  printf("Testing find_artist\n");
  printf("Looking for [lana del rey]\n");
  print_list(find_first_song(songlist, "lana del rey"));
  printf("Looking for [kanye west]\n");
  print_list(find_first_song(songlist, "kanye west"));
  printf("Looking for [wolfgang amadeus mozart]\n");
  print_list(find_first_song(songlist, "wolfgang amadeus mozart"));
  printf("Testing random:\n");
  srand(time(NULL));
  print_node(rando(songlist));
  print_node(rando(songlist));
  print_node(rando(songlist));
  return 0;
}
