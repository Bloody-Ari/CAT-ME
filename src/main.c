/*
 *  CAT-ME
 *
 *  Some day it will use the CEA library...
 */

#include <stdio.h>

#include "include/reaction_types.h"
#include "include/reaction_functions.h"

int main(){
  /* defines the stoichiometric ratio of the reaction */
  /*char mol_input[10];*/
  int choice = -1;

  struct ReactionData main_reaction = createEmptyReactionStruct();

  (void)defineMainReactionData(&main_reaction);

  /* Main menu!!! May convert it to a function */
  while(1){
    (void)printf("Current data: \n");
    (void)printf("Oxidizer mol: %.3f\n", main_reaction.oxidizer_mol);
    (void)printf("Fuel mol: %.3f\n", main_reaction.fuel_mol);
    (void)printf("OF: %.3f\n", main_reaction.fuel_g);

    (void)printf("\nWhat do you want to change?: \n");
    (void)printf("1. Set fuel mass\n");
    (void)printf("2. Set oxidizer volume\n");
    (void)printf("3. Set fuel mol\n");
    (void)printf("4. Set oxidizer mol\n");
    (void)printf("5. Set target product mass\n");
    (void)printf("6. Set target product mol\n");
    (void)printf("7. Change OF ratio\n");

    (void)printf("\n\nEnter number to choose: ");
    (void)scanf("%d", &choice);

    switch(choice){
      case -1:
        return 0; /* just quits haha */
      case 1:
        (void)printf("Recalculating from fuel mass...\n");
        break;
      case 2:
        (void)printf("Recalculating from oxidizer volume...\n");
        break;
      case 3:
        (void)printf("Recalculating from fuel mol...\n");
        break;
      case 4:
        (void)printf("Recalculating from oxidizer mol...\n");
        break;
      case 5:
        (void)printf("Recalculating from target product mass...");
        break;
      case 6:
        (void)printf("Recalculating from target product mol...");
        break;
      case 7:
        (void)printf("Recalculating from OF ratio...");
        break;
      default:
        (void)printf("Wrong input make");
        break;
    }

  }

  
  return 0;
}
