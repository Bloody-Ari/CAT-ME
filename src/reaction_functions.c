#ifndef reaction_data
#include "include/reaction_types.h"
#endif

#ifndef printf
#include <stdio.h>
#endif

struct ReactionData createEmptyReactionStruct(){
  struct ReactionData empty_reaction_data;
  empty_reaction_data.fuel_g = 0;
  empty_reaction_data.fuel_volume = 0; /* m3 or well, L */
  empty_reaction_data.fuel_mol = 0;
  empty_reaction_data.fuel_uma = 0; /* g/mol */
  empty_reaction_data.fuel_molarity = 0; /* M = m/L, for liquids! */
  empty_reaction_data.fuel_density_g_cm3 = 0; /* *1000 for kg/m^3 haha */
  empty_reaction_data.fuel_ratio = 0;
  empty_reaction_data.oxidizer_g = 0;
  empty_reaction_data.oxidizer_volume = 0;
  empty_reaction_data.oxidizer_mol = 0;
  empty_reaction_data.oxidizer_uma = 0;
  empty_reaction_data.oxidizer_molarity = 0;
  empty_reaction_data.oxidizer_density_g_cm3 = 0;
  empty_reaction_data.oxidizer_ratio = 0;

  empty_reaction_data.fuel_residue_mol = 0;
  empty_reaction_data.fuel_residue_g = 0;
  empty_reaction_data.oxidizer_residue_mol = 0;
  empty_reaction_data.oxidizer_residue_g = 0;

  empty_reaction_data.main_product_g = 0;
  empty_reaction_data.main_product_mol = 0;
  empty_reaction_data.main_product_volume = 0;
  empty_reaction_data.main_product_uma = 0;
  empty_reaction_data.main_product_density_g_cm3 = 0;

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
  main_reaction->fuel_ratio = 2;
  main_reaction->fuel_uma = 26.98;
  main_reaction->fuel_density_g_cm3 = 2.7;

  main_reaction->oxidizer_ratio = 6;
  main_reaction->oxidizer_uma = 36.46;
  main_reaction->oxidizer_molarity =7.6;
  main_reaction->oxidizer_density_g_cm3 = 1.01; /* depends on concentration */

  main_reaction->main_product_uma = 1.008;
  main_reaction->of_ratio = 3;
}

void defineDefaultReactionData(struct DefaultReactionRatio *default_reaction){
  default_reaction->fuel_mol = 2;
  default_reaction->oxidizer_mol = 6;
  default_reaction->of_ratio = default_reaction->oxidizer_mol / default_reaction->fuel_mol;
}

/*
 * Maybe I should add a recalculate product and use that here and for the OF recalculations?
 */

/* I am hardcoding it for now...*/
void recalculateFromFuelMol(struct ReactionData *main_reaction, float new_fuel_ammount_mol){
  main_reaction->fuel_mol = new_fuel_ammount_mol;
  main_reaction->fuel_g = new_fuel_ammount_mol * main_reaction->fuel_uma;
  main_reaction->fuel_volume = main_reaction->fuel_g / main_reaction->fuel_density_g_cm3;

  main_reaction->oxidizer_mol = (new_fuel_ammount_mol * main_reaction->of_ratio);
  main_reaction->oxidizer_volume = (main_reaction->oxidizer_mol / main_reaction->oxidizer_molarity) * 1000; /* I want ml */

  main_reaction->main_product_mol = main_reaction->oxidizer_mol / 2; /*2HCl mol = 1 H2 mol*/
  main_reaction->main_product_g = main_reaction->main_product_mol * main_reaction->main_product_uma;
}

void recalculateFromOxidizerMol(struct ReactionData *main_reaction, float new_oxidizer_ammount_mol){
  main_reaction->oxidizer_mol = new_oxidizer_ammount_mol;
  main_reaction->oxidizer_volume = new_oxidizer_ammount_mol / main_reaction->oxidizer_molarity * 1000;

  main_reaction->fuel_mol = new_oxidizer_ammount_mol * 1/3;
  main_reaction->fuel_g = main_reaction->fuel_mol * main_reaction->fuel_uma;

  main_reaction->main_product_mol = main_reaction->oxidizer_mol / 2; /*2HCl mol = 1 H2 mol*/
  main_reaction->main_product_g = main_reaction->main_product_mol * main_reaction->main_product_uma;
}

void recalculateOFRatio(struct ReactionData *main_reaction, struct DefaultReactionRatio *default_reaction, float new_of_ratio){
  main_reaction->of_ratio = new_of_ratio;

  if(new_of_ratio > default_reaction->of_ratio){
    main_reaction->oxidizer_ratio = new_of_ratio * default_reaction->fuel_mol;
    main_reaction->fuel_ratio = default_reaction->fuel_mol;
  }
  if(new_of_ratio < default_reaction->of_ratio){
    main_reaction->fuel_ratio = default_reaction->oxidizer_mol / new_of_ratio;
    main_reaction->oxidizer_ratio = default_reaction->oxidizer_mol;
  }
  if(new_of_ratio == default_reaction->of_ratio){
    main_reaction->of_ratio = default_reaction->of_ratio;
    main_reaction->fuel_ratio = default_reaction->fuel_mol;
    main_reaction->oxidizer_ratio = default_reaction->oxidizer_mol;
  }
}

/*
 * Why??? I think it's more readable, I would probably add comments anyways
 * not sure if I am even using them tho lol
 */
float massToMol(float mass, float uma){
  return mass/uma;
}

float volumeToMol(float volume_L, float molarity_mol_over_L){
  return volume_L * molarity_mol_over_L;
}

float molToMass(float mol, float uma){
  return mol*uma;
}
