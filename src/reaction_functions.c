#ifndef reaction_data
#include "include/reaction_types.h"
#endif

struct ReactionData createEmptyReactionStruct(){
  struct ReactionData empty_reaction_data;

  empty_reaction_data.fuel_g = 0; 
  empty_reaction_data.fuel_g = 0;
  empty_reaction_data.fuel_mol = 0;
  empty_reaction_data.oxidizer_g = 0;
  empty_reaction_data.oxidizer_mol = 0;

  empty_reaction_data.fuel_residue_mol = 0;
  empty_reaction_data.fuel_residue_g = 0;
  empty_reaction_data.oxidizer_residue_mol = 0;
  empty_reaction_data.oxidizer_residue_g = 0;

  empty_reaction_data.main_product_g = 0;
  empty_reaction_data.h2_mol = 0;

  empty_reaction_data.of_ratio = 0;

  return empty_reaction_data;
}

void defineMainReactionData(struct ReactionData *main_reaction){
  main_reaction->fuel_mol = 3;
}
