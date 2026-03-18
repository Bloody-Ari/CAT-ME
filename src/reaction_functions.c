#ifndef reaction_data
#include "include/reaction_types.h"
#endif

#ifndef printf
#include <stdio.h>
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
  main_reaction->fuel_uma = 26.98;

  main_reaction->oxidizer_mol = 6;
  main_reaction->oxidizer_uma = 36.46;
  main_reaction->oxidizer_molarity = 6.4;

  main_reaction->main_product_uma = 1.008;
  main_reaction->of_ratio = 3;
}

void recalculateFromFuelMol(struct ReactionData *user_reaction, struct ReactionData *main_reaction, float new_fuel_ammount_mol){
  user_reaction->fuel_mol = new_fuel_ammount_mol;
  user_reaction->fuel_g = new_fuel_ammount_mol * user_reaction->fuel_uma;
  user_reaction->fuel_volume = user_reaction->fuel_g / user_reaction->fuel_density_kg_m3;

  user_reaction->oxidizer_mol = (new_fuel_ammount_mol / main_reaction->fuel_mol) * main_reaction->oxidizer_mol;
  user_reaction->oxidizer_g = user_reaction->oxidizer_mol * user_reaction->oxidizer_uma;
  user_reaction->oxidizer_volume = user_reaction->oxidizer_g / user_reaction->oxidizer_density_kg_m3;

  user_reaction->main_product_mol = main_reaction->oxidizer_mol / 2; /*2HCl mol = 1 H2 mol*/
  user_reaction->main_product_g = main_reaction->main_product_g = user_reaction->main_product_mol * user_reaction->main_product_uma;
  user_reaction->main_product_volume = user_reaction->main_product_g / user_reaction->main_product_density_kg_m3;
  /*(void)printf("\nTo react %5.2f mol of Aluminum you need %5.3f mol of HCl\n\n", new_fuel_ammount_mol, ammount_of_oxidizer_needed);*/
}

/*
 * Why??? I think it's more readable, I would probably add comments otherwise
 */
float massToMol(float mass, float uma){
  return mass/uma;
}

float molToMass(float mol, float uma){
  return mol*uma;
}
