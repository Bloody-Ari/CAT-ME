#ifndef AMBIENT_TEMP_K
  #include "include/rocket_types.h"
#endif

struct RocketData createDefaultRocketData(){
  struct RocketData empty_rocket_data;
  empty_rocket_data.ac_at = 2.0;
  empty_rocket_data.at_ae = 0;
  empty_rocket_data.chamber_pressure_atm = 0;
  empty_rocket_data.chamber_pressure_pa = 0;
  /*
   * ye it's not exactly 1500mL but heh, later,
   * it should be an input anyways
   */
  empty_rocket_data.chamber_volume_mL = 600;
  empty_rocket_data.chamber_area_m2 = 0.127718352;
  empty_rocket_data.c_star = 0;

  return empty_rocket_data;
}

float chamberPressureFromMolAndVolume(float species_mol, float volume_L, float temp_k){
  return (species_mol * R_IN_LITERS * temp_k) / volume_L;
}

float molFromChamberPressureAndVolume(float pressure_pa, float volume_L, float temp_k){
  return (pressure_pa * volume_L)/(R_IN_LITERS * temp_k);
}
