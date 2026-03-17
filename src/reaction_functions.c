#ifndef reaction_data
#include "include/reaction_types.h"
#endif

struct ReactionData createEmptyReactionStruct(){
  struct ReactionData empty_reaction_data;

  empty_reaction_data.fuel_g = 0; 
  empty_reaction_data.fuel_mol = 0;
  empty_reaction_data.fuel_uma = 0;
  empty_reaction_data.oxidizer_g = 0;
  empty_reaction_data.oxidizer_mol = 0;
  empty_reaction_data.oxidizer_uma = 0;

  empty_reaction_data.fuel_residue_mol = 0;
  empty_reaction_data.fuel_residue_g = 0;
  empty_reaction_data.oxidizer_residue_mol = 0;
  empty_reaction_data.oxidizer_residue_g = 0;

  empty_reaction_data.main_product_g = 0;
  empty_reaction_data.main_product_mol = 0;
  empty_reaction_data.main_product_uma = 0;

  empty_reaction_data.of_ratio = 0;

  return empty_reaction_data;
}

/* 
 * Defines the main reaction, I'd like this to be a file read in the future,
 * for 2 main reasons:
 * 1. I am not a suckless dev, I don't really want to force people to change the source code
 * 2. It makes much more sense to just read a .txt file than to hard code :3
 */
void defineMainReactionData(struct ReactionData *main_reaction){
  main_reaction->fuel_mol = 2;
  main_reaction->fuel_uma = 26.981538;

  main_reaction->oxidizer_mol = 6;
  main_reaction->oxidizer_uma = 36.46;

  main_reaction->of_ratio = 3;
}

