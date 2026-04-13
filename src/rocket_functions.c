#ifndef AMBIENT_TEMP_K
  #include "include/rocket_types.h"
#endif

#ifndef sqrt
  #include <math.h>
#endif

struct RocketData createEmptyRocketData(){
  struct RocketData empty_rocket_data;
  /* ratios      */
  empty_rocket_data.ac_at = 0; /* chamber to throat area ratio Ac/At */
  empty_rocket_data.ae_at = 0; /* throat to exit area ratio Ac/At */

  /* pressures   */
  empty_rocket_data.chamber_pressure_atm = 0; /* kind of just for show */
  empty_rocket_data.chamber_pressure_pa  = 0;
  empty_rocket_data.exit_pressure_atm    = 0;
  empty_rocket_data.exit_pressure_pa     = 0;

  /* meaures     */
  empty_rocket_data.chamber_volume_L      = 0;
  empty_rocket_data.chamber_temperature_K = 0;
  empty_rocket_data.chamber_area_m2       = 0;
  empty_rocket_data.chamber_diameter_m    = 0;

  empty_rocket_data.throat_area_m2    = 0;
  empty_rocket_data.throat_diameter_m = 0;

  empty_rocket_data.exit_diameter_m = 0;
  empty_rocket_data.exit_area_m2    = 0;

  /* performance */
  empty_rocket_data.c_star_m_over_s = 0;
  empty_rocket_data.effective_exhaust_velocity_c_m_over_s = 0;
  empty_rocket_data.Isp_s = 0;

  return empty_rocket_data;
}

void defineDefaultRocketData(struct RocketData *rocket_data){
  rocket_data->ac_at                 = 2.0;
  rocket_data->ae_at                 = 0;
  rocket_data->chamber_pressure_atm  = 5;
  rocket_data->chamber_pressure_pa   = rocket_data->chamber_pressure_atm * 101300;
  rocket_data->chamber_pressure_bar  = rocket_data->chamber_pressure_atm * 1.01325;
  rocket_data->pressure_ratio[0] = rocket_data->chamber_pressure_bar;
  rocket_data->chamber_temperature_K = AMBIENT_TEMP_K;
  rocket_data->chamber_volume_L      = 0.600;
  rocket_data->chamber_diameter_m    = 0.01275;
  rocket_data->chamber_area_m2       = pow(rocket_data->chamber_diameter_m/2, 2) * 3.14159265359;
  rocket_data->c_star_m_over_s       = 0;

  rocket_data->subar[0] = 0.0;
  rocket_data->supar[0] = 0.0;

  return;
}

void chamberPressureFromMol(struct RocketData *rocket_data, float species_mol){
  rocket_data->chamber_pressure_pa  = (species_mol * R_IN_LITERS * rocket_data->chamber_temperature_K) / rocket_data->chamber_volume_L;
  rocket_data->chamber_pressure_atm = PA_TO_ATM(rocket_data->chamber_pressure_pa);
  rocket_data->chamber_pressure_bar = PA_TO_BAR(rocket_data->chamber_pressure_pa);

  rocket_data->chamber_pressure = rocket_data->chamber_pressure_bar;
  rocket_data->pressure_ratio[0] = rocket_data->chamber_pressure_bar;
  return;
}

float molFromChamberPressureAndVolume(struct RocketData *rocket_data){
  return (rocket_data->chamber_pressure_pa * rocket_data->chamber_volume_L)/(R_IN_LITERS * rocket_data->chamber_temperature_K);
}


/* not angles yet */
void recalculateNozzleDiametersAndAreas(struct RocketData *rocket_data){
  /* tengo ac/at y ae/at */
  /* ae/at = ratio */
  /* ae = ratio * at */
  rocket_data->throat_area_m2 = rocket_data->chamber_area_m2 / rocket_data->ac_at;
  rocket_data->throat_diameter_m = 2 * sqrt(rocket_data->throat_area_m2 / 3.14159265359);

  rocket_data->exit_area_m2 = rocket_data->throat_area_m2 * rocket_data->ae_at;
  rocket_data->exit_diameter_m = 2 * sqrt(rocket_data->exit_area_m2 / 3.14159265359);
}
