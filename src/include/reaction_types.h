/* [ [ Molarity ], [ Weight% ] ]*/

#ifndef CEA_LOG_LEVEL_ENUM
#include "../cea/cea.h"
#endif

#define LEN(x) (sizeof(x) / sizeof((x)[0]))

/* yeaaa it's not the best, but I don't want to change ansi for now 
 * honestly I am thiking about c23 or C++
 */
#define N_REACTANTS 3

extern const float HCL_WEIGHT_AND_MOLARITY_TABLE[24][24];
        
struct ReactionData {
  /*tons of things should move to arrays haha*/
  float fuel_g;
  float fuel_mol;
  float fuel_uma; /* g/mol */
  float fuel_molarity; /* M = m/L, for liquids! */
  float fuel_density_g_cm3; /* *1000 for kg/m^3 haha */
  float fuel_volume; /* g/cm^3 or mL */
  float fuel_ratio;
  float oxidizer_g;
  float oxidizer_volume; 
  float oxidizer_mol;
  float oxidizer_uma;
  float oxidizer_molarity;
  float oxidizer_wt_percentage;
  float oxidizer_density_g_cm3;
  float oxidizer_ratio;
 
  float fuel_residue_mol;
  float fuel_residue_g;
  float oxidizer_residue_mol;
  float oxidizer_residue_g;

  float main_product_g;
  float main_product_mol;
  float main_product_volume;
  float main_product_uma;
  float main_product_density_g_cm3;

  float of_ratio;

  cea_int n_reactants;
  cea_mixture reaction;
  cea_mixture products;
  cea_real *weights;
  cea_real hc;
  cea_string reactants[N_REACTANTS];
  cea_real reactant_temps_k[N_REACTANTS];
  cea_real fuel_weights_percentage[N_REACTANTS];
  cea_real oxidant_weights_percentage[N_REACTANTS];
  cea_string ommited_products[1];
};

struct DefaultReactionRatio {
  float fuel_mol;
  float oxidizer_mol;
  float of_ratio;
};
/* I should make the defualt reaction data a read from a file */
