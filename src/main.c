/*
 *  CAT-ME
 *
 *  Some day it will use the CEA library...
 */

#include <stdio.h>

#include "include/reaction_types.h"
#include "include/reaction_functions.h"
#include "include/rocket_types.h"
#include "include/rocket_functions.h"

int main(){
  /* defines the stoichiometric ratio of the reaction */
  /*char mol_temp_input[10];*/
  int choice = -1;

  struct ReactionData main_reaction = createEmptyReactionStruct();
  struct RocketData main_rocket_data = createDefaultRocketData();
  struct DefaultReactionRatio default_reaction = {0,0,0};

  float temp_input = 0;
  /*
  float chamber_to_throat_area_ratio = 2.0;
  */

  (void)defineDefaultReactionData(&default_reaction);
  (void)defineMainReactionData(&main_reaction);


  /* Main menu!!! Should convert it to a function 
   * mainly so I can "count" iterations and limit them,
   * and also to have the chance to like return without
   * exiting the program haha
  */
  while(1){
    (void)printf("╔════════════════════════════════════════════════╗\n");
    (void)printf("║                  Current data:                 ║\n");
    (void)printf("╠════════════════════════════════════════════════╣\n");
    (void)printf("║                  Reaction data:                ║\n");
    (void)printf("╠════════════════════════════════════════════════╣\n");
    (void)printf("║ Oxidizer M:          %12.3f M            ║\n", main_reaction.oxidizer_molarity);
    (void)printf("╠════════════════════════════════════════════════╣\n");
    (void)printf("║ Fuel mass:           %12.3f g            ║\n", main_reaction.fuel_g);
    (void)printf("║ Oxidizer volume:     %12.3f ml           ║\n", main_reaction.oxidizer_volume);
    (void)printf("╠════════════════════════════════════════════════╣\n");
    (void)printf("║ Main Product mol:    %12.3f mol          ║\n", main_reaction.main_product_mol);
    (void)printf("╠════════════════════════════════════════════════╣\n");
    (void)printf("║ Fuel mol:            %12.3f mol          ║\n", main_reaction.fuel_mol);
    (void)printf("║ Oxidizer mol:        %12.3f mol          ║\n", main_reaction.oxidizer_mol);
    (void)printf("╠════════════════════════════════════════════════╣\n");
    (void)printf("║ Fuel ratio:          %12.3f mol          ║\n", main_reaction.fuel_ratio);
    (void)printf("║ Oxidizer ratio:      %12.3f mol          ║\n", main_reaction.oxidizer_ratio);
    (void)printf("║ OF ratio:            %12.3f mol          ║\n", main_reaction.of_ratio);
    (void)printf("╠════════════════════════════════════════════════╣\n");
    (void)printf("║                  Rocket data:                  ║\n");
    (void)printf("╠════════════════════════════════════════════════╣\n");
    (void)printf("║ Chamber pressure:    %12.3f Pa           ║\n", main_rocket_data.chamber_pressure_pa);
    (void)printf("║ Chamber pressure:    %12.3f atm          ║\n", main_rocket_data.chamber_pressure_atm);
    (void)printf("║ Chamber volume:      %12.3f mL           ║\n", main_rocket_data.chamber_volume_mL);
    (void)printf("║ Ac/At:               %12.3f              ║\n", main_rocket_data.ac_at);
    (void)printf("║ At/Ae:               %12.3f              ║\n", main_rocket_data.at_ae);
    (void)printf("╚════════════════════════════════════════════════╝\n");

    (void)printf("\nWhat do you want to change?: \n");
    (void)printf("1. Set fuel mass\n");
    (void)printf("2. Set oxidizer volume\n");
    (void)printf("3. Set fuel mol\n");
    (void)printf("4. Set oxidizer mol\n");
    (void)printf("5. Set target product mol\n");
    (void)printf("6. Change OF ratio\n");
    (void)printf("7. Change Oxidizer Molarity\n");
    (void)printf("8. Set target chamber pressure (atm) <-- not implemented\n");
    (void)printf("9. Set target chamber pressure (Pa)  <-- not implemented\n");
    /*(void)printf("9. Set chamber to throat area ratio\n");*/
    (void)printf("\n-1. Quit\n");
    (void)printf("(No sanitization, this will be a GUI later)\n");

    (void)printf("\n\nEnter number to choose: ");
    (void)scanf("%d", &choice);

    switch(choice){
      case -1:
        return 0; /* just quits haha */
      case 1:
        (void)printf("\nInput grams of fuel: ");
        (void)scanf("%f", &temp_input); 
        temp_input /= main_reaction.fuel_uma;
        (void)recalculateFromFuelMol(&main_reaction, temp_input);
        break;
      case 2:
        (void)printf("\nInput ml of oxidizer: ");
        (void)scanf("%f", &temp_input);
        temp_input *= main_reaction.oxidizer_molarity / 1000;
        recalculateFromOxidizerMol(&main_reaction,  temp_input);
        break;
      case 3:
        (void)printf("\nInput moles of fuel: ");
        (void)scanf("%f", &temp_input);
        (void)recalculateFromFuelMol(&main_reaction, temp_input);
        break;
      case 4:
        (void)printf("\nInput moles of oxidizer: ");
        (void)scanf("%f", &temp_input);
        (void)recalculateFromOxidizerMol(&main_reaction, temp_input);
        break;
      case 5:
        (void)printf("\nInput target moles of main product: ");
        (void)scanf("%f", &temp_input);
        temp_input *= 2;
        (void)recalculateFromOxidizerMol(&main_reaction, temp_input);
        break;
      case 6:
        (void)printf("New OF ratio: ");
        (void)scanf("%f", &temp_input);
        (void)recalculateOFRatio(&main_reaction, &default_reaction, temp_input);
        (void)recalculateFromOxidizerMol(&main_reaction, main_reaction.oxidizer_mol);
        break;
      case 7:
        (void)printf("New oxidizer molarity: ");
        (void)scanf("%f", &temp_input);
        main_reaction.oxidizer_molarity = temp_input;
        if (main_reaction.fuel_g > 0){
          recalculateFromFuelMol(&main_reaction, main_reaction.fuel_mol);
        }
        break;
      case 8:
        (void)printf("Target chamber pressure (atm): ");
        (void)scanf("%f", &temp_input);
        main_rocket_data.chamber_pressure_atm = temp_input;
        main_rocket_data.chamber_pressure_pa = ATM_TO_PA(temp_input);
        recalculateFromOxidizerMol(&main_reaction, molFromChamberPressureAndVolume(main_rocket_data.chamber_pressure_pa, main_rocket_data.chamber_volume_mL/1000, AMBIENT_TEMP_K)*2);
        break;
      case 9:
        (void)printf("Target chamber pressure (Pa): ");
        (void)scanf("%f", &temp_input);
        main_rocket_data.chamber_pressure_pa = temp_input;
        main_rocket_data.chamber_pressure_atm = PA_TO_ATM(temp_input);
        recalculateFromOxidizerMol(&main_reaction, molFromChamberPressureAndVolume(main_rocket_data.chamber_pressure_pa, main_rocket_data.chamber_volume_mL/1000, AMBIENT_TEMP_K)*2);
        break;
      default:
        /* I prefer to kill the program than to loop for now*/
        (void)printf("Wrong input...\n");
        return 0;
    }

  }

  
  return 0;
}
