/*
 *  necesito un buen nombre!
 */

#include <stdio.h>

#include "include/reaction_types.h"
#include "include/reaction_functions.h"

int main(){
  /* defines the stoichiometric ratio of the reaction */
  struct ReactionData main_reaction = createEmptyReactionStruct();
  (void)defineMainReactionData(&main_reaction);

  (void)printf("Main reaction data: ");
  (void)printf("Oxidizer mol: %.3f\n", main_reaction.oxidizer_mol);
  (void)printf("Fuel mol: %.3f\n", main_reaction.fuel_mol);
  (void)printf("Fuel g: %.3f\n", main_reaction.fuel_g);


  return 0;
}
