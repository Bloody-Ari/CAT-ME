/* [ [ Molarity ], [ Weight% ] ]*/


#define LEN(x) (sizeof(x) / sizeof((x)[0]))

extern const float HCL_WEIGHT_AND_MOLARITY_TABLE[24][24];
        
struct ReactionData {
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
};

struct DefaultReactionRatio {
  float fuel_mol;
  float oxidizer_mol;
  float of_ratio;
};
/* I should make the defualt reaction data a read from a file */
