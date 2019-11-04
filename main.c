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

  printf("\n");
  printf("Testing print_list:\n");
  print_list(songlist);

  printf("\n");
  printf("Testing print_node:\n");
  print_node(songlist);

  printf("\n");
  printf("Testing find_node:\n");
  printf("Looking for [lil nas x: panini]:\n");
  print_list(find_song(songlist, "panini", "lil nas x"));
  printf("Looking for [lil nas x: old town road]:\n");
  print_list(find_song(songlist, "old town road", "lil nas x"));

  printf("\n");
  printf("Testing find_artist\n");
  printf("Looking for [lana del rey]\n");
  print_list(find_first_song(songlist, "lana del rey"));
  printf("Looking for [kanye west]\n");
  print_list(find_first_song(songlist, "kanye west"));
  printf("Looking for [wolfgang amadeus mozart]\n");
  print_list(find_first_song(songlist, "wolfgang amadeus mozart"));

  printf("\n");
  printf("Testing random:\n");
  srand(time(NULL));
  print_node(rando(songlist));
  print_node(rando(songlist));
  print_node(rando(songlist));

  printf("\n");
  printf("Testing remove_node:\n");
  //printf("Removing [harry styles: carolina:\n");
 // remove_node(songlist, "carolina", "harry styles");
  //print_list(songlist);
  printf("Removing [lil nas x: panini]");
  remove_node(songlist, "panini", "lil nas x\n");
  print_list(songlist);
  printf("Removing [lil nas x: old town road]\n");
  remove_node(songlist, "old town road", "lil nas x");
  print_list(songlist);
  /*printf("Testing free_list\n");
  free_list(songlist);
  printf("List after freeing:\n");
  print_list(songlist); */
  return 0;
}
