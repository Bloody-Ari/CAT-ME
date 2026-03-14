/*
 *  necesito un buen nombre!
 */

#include <stdio.h>

#include "reaction_types.h"
#include "reaction_functions.h"

int main(){
  /* defines the stoichiometric ratio of the reaction */
  struct reaction_data main_reaction = {};
  defineMainReactionData(&main_reaction);

  printf("Main reaction data: ");
  printf("Oxidizer mol: %.3f\n", main_reaction.oxidizer_mol);
  printf("Fuel mol: %.3f\n", main_reaction.fuel_mol);
  printf("Fuel g: %.3f\n", main_reaction.fuel_g);


  return 0;
}
