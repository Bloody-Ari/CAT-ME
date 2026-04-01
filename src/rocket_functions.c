#ifndef printf
  #include <stdio.h>
#endif
#ifndef AMBIENT_TEMP_K
  #include "include/rocket_types.h"
#endif

struct RocketData createEmptyRocketData(){
  struct RocketData empty_rocket_data;
  empty_rocket_data.ac_at = 0;
  empty_rocket_data.at_ae = 0;
  empty_rocket_data.chamber_pressure_atm = 0;
  empty_rocket_data.chamber_pressure_pa = 0;
  empty_rocket_data.chamber_volume_L = 0;
  empty_rocket_data.chamber_area_m2 = 0;
  empty_rocket_data.chamber_temperature_K = 0;
  empty_rocket_data.c_star = 0;

  return empty_rocket_data;
}

void defineDefaultRocketData(struct RocketData *rocket_data){
  rocket_data->ac_at = 2.0;
  rocket_data->at_ae = 0;
  rocket_data->chamber_pressure_atm = 0;
  rocket_data->chamber_pressure_pa = 0;
  rocket_data->chamber_temperature_K = AMBIENT_TEMP_K;
  /*
   * ye it's not exactly 1500mL but heh, later,
   * it should be an input anyways
   */
  rocket_data->chamber_volume_L = 0.600;
  rocket_data->chamber_area_m2 = 0.127718352;
  rocket_data->c_star = 0;

  return;
}

void chamberPressureFromMol(struct RocketData *rocket_data, float species_mol){
  rocket_data->chamber_pressure_pa = (species_mol * R_IN_LITERS * rocket_data->chamber_temperature_K) / rocket_data->chamber_volume_L;
  rocket_data->chamber_pressure_atm = PA_TO_ATM(rocket_data->chamber_pressure_pa);
  printf("Pa: %f\natm: %f\n", rocket_data->chamber_pressure_pa, rocket_data->chamber_pressure_atm);
  return;
}

float molFromChamberPressureAndVolume(struct RocketData *rocket_data){
  printf("chamber_pressure_pa: %f", rocket_data->chamber_pressure_pa);
  printf("chamber_volume_L: %f", rocket_data->chamber_volume_L);
  printf("R in liters: %f", R_IN_LITERS);
  printf("chamber temp: %f", rocket_data->chamber_temperature_K);
  return (rocket_data->chamber_pressure_pa * rocket_data->chamber_volume_L)/(R_IN_LITERS * rocket_data->chamber_temperature_K);
}
