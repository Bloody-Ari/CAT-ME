/* not sure if it should be split into
 * RocketStructureData
 * RocketPerformanceData
 *
 */
#define AMBIENT_TEMP_K 298.15
#define R_IN_LITERS 8314.46261815324
#define ATM_TO_PA(P) (P * 101325)
#define PA_TO_ATM(P) (P / 101325)

struct RocketData{
  /* ratios      */
  float ac_at; /* chamber to throat area ratio Ac/At */
  float at_ae; /* throat to exit area ratio Ac/At */

  /* pressures   */
  float chamber_pressure_atm; /* kind of just for show */
  float chamber_pressure_pa;
  float exit_pressure_atm;
  float exit_pressure_pa;

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
};
