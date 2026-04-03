#ifndef AMBIENT_TEMP_K
  #include "include/rocket_types.h"
#endif

struct RocketData createEmptyRocketData(){
  struct RocketData empty_rocket_data;
  /* ratios      */
  empty_rocket_data.ac_at = 0; /* chamber to throat area ratio Ac/At */
  empty_rocket_data.at_ae = 0; /* throat to exit area ratio Ac/At */

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
  rocket_data->at_ae                 = 0;
  rocket_data->chamber_pressure_atm  = 0;
  rocket_data->chamber_pressure_pa   = 0;
  rocket_data->chamber_temperature_K = AMBIENT_TEMP_K;
  rocket_data->chamber_volume_L      = 0.600;
  rocket_data->chamber_area_m2       = 0.127718352;
  rocket_data->chamber_diameter_m    = 0.0127521;
  rocket_data->c_star_m_over_s       = 0;

  return;
}

void chamberPressureFromMol(struct RocketData *rocket_data, float species_mol){
  rocket_data->chamber_pressure_pa = (species_mol * R_IN_LITERS * rocket_data->chamber_temperature_K) / rocket_data->chamber_volume_L;
  rocket_data->chamber_pressure_atm = PA_TO_ATM(rocket_data->chamber_pressure_pa);
  return;
}

float molFromChamberPressureAndVolume(struct RocketData *rocket_data){
  return (rocket_data->chamber_pressure_pa * rocket_data->chamber_volume_L)/(R_IN_LITERS * rocket_data->chamber_temperature_K);
}
