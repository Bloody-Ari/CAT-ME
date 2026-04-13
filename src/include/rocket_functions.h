struct RocketData createEmptyRocketData();
void defineDefaultRocketData(struct RocketData *rocket_data);

void chamberPressureFromMol(struct RocketData *rocket_data, float species_mol);
float molFromChamberPressureAndVolume(struct RocketData *rocket_data);

void recalculateNozzleDiametersAndAreas(struct RocketData *rocket_data);
