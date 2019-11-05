#include "musiclibrary.h"

int main(){
  struct song_node * songlist;

  printf("Empty List:");
  print_list(songlist);

  printf("Inserting: doing time\n");
  songlist = insert_alph(songlist, "doin time", "lana del rey");
  printf("Inserting: panini\n");
  songlist = insert_alph(songlist, "panini", "lil nas x");
  printf("Inserting: tighten up\n");
  songlist = insert_alph(songlist, "tighten up", "the black keys");
  printf("Inserting: carolina\n");
  songlist = insert_alph(songlist, "carolina", "harry styles");
  printf("Inserting: selah\n");
  songlist = insert_alph(songlist, "selah", "kanye west");
  printf("Inserting: runaway\n");
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
  printf("\n");
  print_node(rando(songlist));
  printf("\n");
  print_node(rando(songlist));
  printf("\n");

  printf("\n");
  printf("Testing remove_node:\n");
  printf("Removing [harry styles: carolina:\n");
  songlist = remove_node(songlist, "carolina", "harry styles");
  print_list(songlist);
  printf("Removing [kanye west : selah]\n");
  songlist = remove_node(songlist, "selah", "kanye west");
  print_list(songlist);
  printf("Removing [lil nas x: old town road]\n");
  songlist = remove_node(songlist, "old town road", "lil nas x");
  print_list(songlist);

  printf("\n");
  printf("Testing free_list\n");
  songlist = free_list(songlist);
  printf("List after freeing:\n");
  print_list(songlist);


  printf("-----------Testing Musiclibrary------------");
  struct song_node * library [27];
  int idx;
  for (idx = 0; idx < 27; idx++) {
      library[idx] = NULL;
  }
  add_song(library, "arabella", "arctic monkeys");
  add_song(library, "flourescent adolescent", "arctic monkeys");
  add_song(library, "doo wop", "lauryn hill");
  add_song(library, "gameshow", "two door cinema club");
  add_song(library, "a day in the life", "the beatles");
  add_song(library, "take me home country roads", "john denver");
  add_song(library, "never going to give you up", "rick astley");
  add_song(library, "set fire to the rain", "adele");

  printf("\n");
  printf("Testing print_lib\n");
  print_lib(library);

  printf("\n");
  printf("Testing print_letter\n");
  print_letter(library, 'a');

  printf("\n");
  printf("Testing print_artist\n");
  print_artist(library, "lauryn hill");
  print_artist(library, "arctic monkeys");

  printf("\n");
  printf("Testing find\n");
  printf("Finding [two door cinema club: gameshow]\n");
  print_node(find(library, "gameshow", "two door cinema club"));
  printf("\n");
  printf("Finding [adele: set fire to the rain]\n");
  print_node(find(library, "set fire to the rain", "adele"));
  printf("\n");
  printf("Finding [the beatles: here comes the sun]\n");
  print_node(find(library, "here comes the sun", "the beatles"));

  printf("\n");
  printf("Testing find_artist\n");
  printf("Finding [arctic monkeys]\n");
  print_list(find_artist(library, "arctic monkeys"));
  printf("Finding [the beatles]\n");
  print_list(find_artist(library, "the beatles"));
  printf("Finding [nas]\n");
  print_list(find_artist(library, "nas"));

  printf("\n");
  printf("Testing shuffle\n");
  shuffle(library);

  /*printf("\n");
  printf("Testing remove\n");
  printf("Removing [john denver: take me home country roads]\n");
  delete_song(library, "take me home country roads", "john denver");
  print_lib(library);
  printf("Removing [arctic monkeys: arabella]\n");
  delete_song(library, "arabella", "arctic monkeys");
  print_lib(library);
  printf("Removing [cranes in the sky: solange]\n");
  delete_song(library, "cranes in the sky", "solange");
  print_lib(library);

  printf("\n");
  printf("Testing clear library\n");
  clear_lib(library);
  printf("Library after clearing:\n");
  print_lib(library);*/
  return 0;
}
