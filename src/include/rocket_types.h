/* not sure if it should be split into
 * RocketStructureData
 * RocketPerformanceData
 *
 */

#ifndef CEA_LOG_LEVEL_ENUM
#include "../cea/cea.h"
#endif

#define AMBIENT_TEMP_K 298.15
#define R_IN_LITERS 8314.46261815324
#define ATM_TO_PA(P) (P * 101325)
#define PA_TO_ATM(P) (P / 101325)
#define PA_TO_BAR(P) (P / 100000)
#define BAR_TO_PA(P) (P * 100000)

struct RocketData{
  /* ratios      */
  float ac_at; /* chamber to throat area ratio Ac/At */
  float ae_at; /* throat to exit area ratio Ac/At */

  /* pressures   */
  float chamber_pressure_atm; /* kind of just for show */
  float chamber_pressure_pa;
  float exit_pressure_atm;
  float exit_pressure_pa;
  cea_real chamber_pressure_bar;

  /* meaures     */
  float chamber_volume_L;
  float chamber_temperature_K;
  float chamber_area_m2;
  float chamber_diameter_m;

  float throat_area_m2;
  float throat_diameter_m;

  float exit_diameter_m;
  float exit_area_m2;

  /* performance */
  float c_star_m_over_s;
  float effective_exhaust_velocity_c_m_over_s;
  float Isp_s;

  cea_rocket_solver solver;
  cea_rocket_solution solution;
  cea_real chamber_pressure;
  cea_int num_pts;
  cea_real pressure_ratio[1];
  cea_real subar[1];
  cea_real supar[1];
};
