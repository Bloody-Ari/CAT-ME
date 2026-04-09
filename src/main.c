/*
 *  CAT-ME
 *
 *  Some day it will use the CEA library...
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef CEA_LOG_LEVEL_ENUM
#include "cea/cea.h"
#endif

#include "include/reaction_types.h"
#include "include/reaction_functions.h"
#include "include/rocket_types.h"
#include "include/rocket_functions.h"

/* should return the solution maybe??? */
/* not sure, the structs maybe should have the options required */
/*
 *
*/

/*
 * solve_with_of_ratio(initial, final, steps)
 * like from 1.2 to 3.0 in 0.2 increments
 *
 */

void ceaCreateStructrues(struct ReactionData *reaction_data, struct RocketData *rocket_data){
  cea_mixture_create(
      &reaction_data->reaction,
      reaction_data->n_reactants,
      reaction_data->reactants);

  cea_mixture_create_from_reactants(
      &reaction_data->products,
      reaction_data->n_reactants,
      reaction_data->reactants,
      0,
      reaction_data->ommited_products);

  cea_rocket_solver_create_with_reactants(
      &rocket_data->solver,
      reaction_data->products,
      reaction_data->reaction);

  cea_rocket_solution_create(
      &rocket_data->solution,
      rocket_data->solver);

  return;
}

void ceaDestroyStructures(struct ReactionData *reaction_data, struct RocketData *rocket_data){
  cea_mixture_destroy(&reaction_data->reaction);
  cea_mixture_destroy(&reaction_data->products);

  cea_rocket_solver_destroy(&rocket_data->solver);
  cea_rocket_solution_destroy(&rocket_data->solution);
}
/*
void ceaFacFromOF(struct ReactionData *reaction_data, struct RocketData *rocket_data){
  cea_real *weights = calloc(reaction_data->n_reactants, sizeof(cea_real));
  cea_real *area_ratio = calloc(reaction_data->num_pts, sizeof(cea_real));
  cea_real *cstar = calloc(reaction_data->num_pts, sizeof(cea_real));

  cea_mixture_of_ratio_to_weights(reaction_data->reaction, 3, reaction_data->oxidant_weights_percentage, reaction_data->fuel_weights_percentage, reaction_data->of_ratio, weights);

  cea_rocket_solver_solve_fac(
      rocket_data->solver,      // solver
      rocket_data->solution,    // solution
      weights,     // weights array
      rocket_data->chamber_pressure,    // chamber pressure bar
      pip,         // chamber to exit pressure ratio
      1.0,         // number or pips
      subar,       // subsonic area ratio
      0.0,         // n of subsonic
      supar,       // supersonic area ratio
      0.0,         // n of supersonic
      0.0,         // n_frz
      hc,          // hc or tc (enthalpty or temp at chamber)
      1,           // use_hc?
      ac_at,       // mdot or ac_at
      0,           // use_mdot?
      0.0,         // initial chamber temp estimate
      0);          // use_tc_est ^
    
                   
  cea_rocket_solution_get_property(solution, CEA_AE_AT, num_pts, area_ratio);
  cea_rocket_solution_get_property(solution, CEA_C_STAR, num_pts, cstar);

  printf("Ae/At:\t\t\t%12.6f\n", area_ratio[4]);
  printf("c*:\t\t\t%12.6f\n", cstar[4]);
}
*/

int main(){
  /* defines the stoichiometric ratio of the reaction */
  /*char mol_temp_input[10];*/
  int choice = -1;

  struct ReactionData main_reaction = createEmptyReactionStruct();
  struct RocketData main_rocket = createEmptyRocketData();
  struct DefaultReactionRatio default_reaction = {0,0,0};

  float temp_input = 0;
  /*
  cea_mixture reaction;
  float chamber_to_throat_area_ratio = 2.0;
  */

  /* initialize cea */
  cea_set_log_level(0); /* a compilation constant maybe... */
  cea_init();

  (void)defineDefaultReactionData(&default_reaction);
  (void)defineMainReactionData(&main_reaction);
  (void)defineDefaultRocketData(&main_rocket);



  /* Main menu!!! Should convert it to a function 
   * mainly so I can "count" iterations and limit them,
   * and also to have the chance to like return without
   * exiting the program haha
  */
  while(1){
    (void)printf("╔════════════════════════════════════════════════╗\n");
    (void)printf("║                  Current data                  ║\n");
    (void)printf("╠════════════════════════════════════════════════╣\n");
    (void)printf("║                  Reaction data:                ║\n");
    (void)printf("╠════════════════════════════════════════════════╣\n");
    (void)printf("║ Oxidizer M:          %12.3f M            ║\n", main_reaction.oxidizer_molarity);
    (void)printf("║ Oxidizer wt%%:        %12.3f wt%%          ║\n", main_reaction.oxidizer_wt_percentage);
    (void)printf("║ Note: accurate wt%% is preferable               ║\n");
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
    (void)printf("║ Chamber pressure:    %12.3f kPa          ║\n", main_rocket.chamber_pressure_pa/1000);
    (void)printf("║ Chamber pressure:    %12.3f atm          ║\n", main_rocket.chamber_pressure_atm);
    (void)printf("║ Chamber pressure:    %12.3f bar          ║\n", main_rocket.chamber_pressure_bar);
    (void)printf("║ Chamber volume:      %12.3f mL           ║\n", main_rocket.chamber_volume_L*1000);
    (void)printf("╠════════════════════════════════════════════════╣\n");
    (void)printf("║                  Rocket measures:              ║\n");
    (void)printf("╠════════════════════════════════════════════════╣\n");
    (void)printf("║ Chamber diameter:    %12.3f mm           ║\n", main_rocket.chamber_diameter_m * 1000);
    (void)printf("║ Chamber area:        %12.3f m²           ║\n", main_rocket.chamber_area_m2);
    (void)printf("║ Throat diameter:     %12.3f mm           ║\n", main_rocket.throat_diameter_m);
    (void)printf("║ Throat area:         %12.3f m²           ║\n", main_rocket.throat_area_m2);
    (void)printf("║ Exit diameter:       %12.3f mm           ║\n", main_rocket.exit_diameter_m);
    (void)printf("║ Exit area:           %12.3f m²           ║\n", main_rocket.exit_area_m2);
    (void)printf("╠════════════════════════════════════════════════╣\n");
    (void)printf("║                  Rocket ratios:                ║\n");
    (void)printf("╠════════════════════════════════════════════════╣\n");
    (void)printf("║ Ac/At:               %12.3f              ║\n", main_rocket.ac_at);
    (void)printf("║ At/Ae:               %12.3f              ║\n", main_rocket.at_ae);
    (void)printf("╚════════════════════════════════════════════════╝\n");

    (void)printf("\nWhat do you want to change?: \n");
    (void)printf("  1. Set fuel mass\n");
    (void)printf("  2. Set oxidizer volume\n");
    (void)printf("  3. Set fuel mol\n");
    (void)printf("  4. Set oxidizer mol\n");
    (void)printf("  5. Set target product mol\n");
    (void)printf("  6. Change OF ratio\n");
    (void)printf("  7. Change Oxidizer Molarity\n");
    (void)printf("  8. Change Oxidizer wt%%\n");
    (void)printf("  9. Set target chamber pressure (atm)\n");
    (void)printf(" 10. Set target chamber pressure (Pa)\n");
    (void)printf(" 11. Set chamber to throat ratio (Ac/At)\n");
    /*(void)printf("9. Set chamber to throat area ratio\n");*/
    (void)printf("\n-1. Quit\n");
    (void)printf("(No sanitization, this will be a GUI later)\n");

    (void)printf("\n\nEnter number to choose: ");
    (void)scanf("%d", &choice);

    switch(choice){
      case -1:
        (void)ceaCreateStructrues(&main_reaction, &main_rocket);
        (void)ceaDestroyStructures(&main_reaction, &main_rocket);
        return 0;
      case 1:
        (void)printf("\nInput grams of fuel: ");
        (void)scanf("%f", &temp_input); 
        temp_input /= main_reaction.fuel_uma;
        (void)recalculateFromFuelMol(&main_reaction, temp_input);
        printf("Calculating pressure\n");
        (void)chamberPressureFromMol(&main_rocket, main_reaction.main_product_mol);
        break;
      case 2:
        (void)printf("\nInput ml of oxidizer: ");
        (void)scanf("%f", &temp_input);
        temp_input *= main_reaction.oxidizer_molarity / 1000;
        (void)recalculateFromOxidizerMol(&main_reaction,  temp_input);
        (void)chamberPressureFromMol(&main_rocket, main_reaction.main_product_mol);
        break;
      case 3:
        (void)printf("\nInput moles of fuel: ");
        (void)scanf("%f", &temp_input);
        (void)recalculateFromFuelMol(&main_reaction, temp_input);
        (void)chamberPressureFromMol(&main_rocket, main_reaction.main_product_mol);
        break;
      case 4:
        (void)printf("\nInput moles of oxidizer: ");
        (void)scanf("%f", &temp_input);
        (void)recalculateFromOxidizerMol(&main_reaction, temp_input);
        (void)chamberPressureFromMol(&main_rocket, main_reaction.main_product_mol);
        break;
      case 5:
        (void)printf("\nInput target moles of main product: ");
        (void)scanf("%f", &temp_input);
        temp_input *= 2;
        (void)recalculateFromOxidizerMol(&main_reaction, temp_input);
        (void)chamberPressureFromMol(&main_rocket, main_reaction.main_product_mol);
        break;
      case 6:
        (void)printf("New OF ratio: ");
        (void)scanf("%f", &temp_input);
        (void)recalculateOFRatio(&main_reaction, &default_reaction, temp_input);
        (void)recalculateFromOxidizerMol(&main_reaction, main_reaction.oxidizer_mol);
        (void)chamberPressureFromMol(&main_rocket, main_reaction.main_product_mol);
        break;
      case 7:
        (void)printf("New oxidizer molarity: ");
        (void)scanf("%f", &temp_input);
        main_reaction.oxidizer_molarity = temp_input;
        main_reaction.oxidizer_wt_percentage = HClMolarityToWeightPercentage(temp_input, 0);
        if (main_reaction.fuel_g > 0){
          (void)recalculateFromFuelMol(&main_reaction, main_reaction.fuel_mol);
          (void)chamberPressureFromMol(&main_rocket, main_reaction.main_product_mol);
        }
        break;
      case 8:
        (void)printf("New oxidizer wt%%: ");
        (void)scanf("%f", &temp_input);
        main_reaction.oxidizer_wt_percentage = temp_input;
        main_reaction.oxidizer_molarity = HClWeightPercentageToMolarity(temp_input);
        break;
      case 9:
        (void)printf("Target chamber pressure (atm): ");
        (void)scanf("%f", &temp_input);
        main_rocket.chamber_pressure_atm = temp_input;
        main_rocket.chamber_pressure_pa = ATM_TO_PA(temp_input);
        main_rocket.chamber_pressure_bar = PA_TO_BAR(main_rocket.chamber_pressure_pa);
        main_rocket.chamber_pressure = main_rocket.chamber_pressure_bar;
        main_rocket.pressure_ratio[0] = main_rocket.chamber_pressure;
        (void)recalculateFromOxidizerMol(&main_reaction, molFromChamberPressureAndVolume(&main_rocket)*2);
        break;
      case 10:
        (void)printf("Target chamber pressure (Pa): ");
        (void)scanf("%f", &temp_input);
        main_rocket.chamber_pressure_pa = temp_input;
        main_rocket.chamber_pressure_atm = PA_TO_ATM(temp_input);
        main_rocket.chamber_pressure_bar = PA_TO_BAR(temp_input);
        main_rocket.chamber_pressure = main_rocket.chamber_pressure_bar;
        main_rocket.pressure_ratio[0] = main_rocket.chamber_pressure;
        (void)recalculateFromOxidizerMol(&main_reaction, molFromChamberPressureAndVolume(&main_rocket)*2);
        break;
      case 11:
        (void)printf("Chamber to throat ratio (Ac/At): ");
        (void)scanf("%f", &temp_input);
        main_rocket.ac_at = temp_input;
        break;
      default:
        /* I prefer to kill the program than to loop for now*/
        (void)printf("Wrong input...\n");
        (void)ceaCreateStructrues(&main_reaction, &main_rocket);
        (void)ceaDestroyStructures(&main_reaction, &main_rocket);
        return 0;
    }

  }

  (void)ceaCreateStructrues(&main_reaction, &main_rocket);
  (void)ceaDestroyStructures(&main_reaction, &main_rocket);
  return 0;
}
