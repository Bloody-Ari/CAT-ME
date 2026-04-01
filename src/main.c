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
  struct DefaultReactionRatio default_reaction = {0,0,0};

  float input = 0; /* just to have something to play around with sanitization*/
  (void)defineDefaultReactionData(&default_reaction);
  (void)defineMainReactionData(&main_reaction);


  /* Main menu!!! Should convert it to a function 
   * mainly so I can "count" iterations and limit them,
   * and also to have the chance to like return without
   * exiting the program haha
  */
  while(1){
    (void)printf("╔════════════════════════════════════════════╗\n");
    (void)printf("║                Current data:               ║\n");
    (void)printf("╠════════════════════════════════════════════╣\n");
    (void)printf("║ Oxidizer M:          %8.3f M            ║\n", main_reaction.oxidizer_molarity);
    (void)printf("╠════════════════════════════════════════════╣\n");
    (void)printf("║ Fuel mass:           %8.3f g            ║\n", main_reaction.fuel_g);
    (void)printf("║ Oxidizer volume:     %8.3f ml           ║\n", main_reaction.oxidizer_volume);
    (void)printf("╠════════════════════════════════════════════╣\n");
    (void)printf("║ Main Product mol:    %8.3f mol          ║\n", main_reaction.main_product_mol);
    (void)printf("╠════════════════════════════════════════════╣\n");
    (void)printf("║ Fuel mol:            %8.3f mol          ║\n", main_reaction.fuel_mol);
    (void)printf("║ Oxidizer mol:        %8.3f mol          ║\n", main_reaction.oxidizer_mol);
    (void)printf("╠════════════════════════════════════════════╣\n");
    (void)printf("║ Fuel ratio:          %8.3f mol          ║\n", main_reaction.fuel_ratio);
    (void)printf("║ Oxidizer ratio:      %8.3f mol          ║\n", main_reaction.oxidizer_ratio);
    (void)printf("║ OF ratio:            %8.3f mol          ║\n", main_reaction.of_ratio);
    (void)printf("╚════════════════════════════════════════════╝\n");

    (void)printf("\nWhat do you want to change?: \n");
    (void)printf("1. Set fuel mass\n");
    (void)printf("2. Set oxidizer volume\n");
    (void)printf("3. Set fuel mol\n");
    (void)printf("4. Set oxidizer mol\n");
    (void)printf("5. Set target product mol\n");
    (void)printf("6. Change OF ratio\n");
    (void)printf("7. Change Oxidizer Molarity\n");
    (void)printf("\n-1. Quit\n");
    (void)printf("(No sanitization, this will be a GUI later)\n");

    (void)printf("\n\nEnter number to choose: ");
    (void)scanf("%d", &choice);

    switch(choice){
      case -1:
        return 0; /* just quits haha */
      case 1:
        (void)printf("\nInput grams of fuel: ");
        (void)scanf("%f", &input); 
        input /= main_reaction.fuel_uma;
        (void)recalculateFromFuelMol(&main_reaction, input);
        break;
      case 2:
        (void)printf("\nInput ml of oxidizer: ");
        (void)scanf("%f", &input);
        input *= main_reaction.oxidizer_molarity / 1000;
        recalculateFromOxidizerMol(&main_reaction,  input);
        break;
      case 3:
        (void)printf("\nInput moles of fuel: ");
        (void)scanf("%f", &input);
        (void)recalculateFromFuelMol(&main_reaction, input);
        break;
      case 4:
        (void)printf("\nInput moles of oxidizer: ");
        (void)scanf("%f", &input);
        (void)recalculateFromOxidizerMol(&main_reaction, input);
        break;
      case 5:
        (void)printf("\nInput target moles of main product: ");
        (void)scanf("%f", &input);
        input *= 2;
        (void)recalculateFromOxidizerMol(&main_reaction, input);
        break;
      case 6:
        (void)printf("New OF ratio: ");
        (void)scanf("%f", &input);
        (void)recalculateOFRatio(&main_reaction, &default_reaction, input);
        (void)recalculateFromOxidizerMol(&main_reaction, main_reaction.oxidizer_mol);
        break;
      case 7:
        (void)printf("New oxidizer molarity: ");
        (void)scanf("%f", &input);
        main_reaction.oxidizer_molarity = input;
        if (main_reaction.fuel_g > 0){
          recalculateFromFuelMol(&main_reaction, main_reaction.fuel_mol);
        }
        break;
      default:
        /* I prefer to kill the program than to loop for now*/
        (void)printf("Wrong input...\n");
        return 0;
    }

  }

  
  return 0;
}
