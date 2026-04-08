struct ReactionData createEmptyReactionStruct();

void defineDefaultReactionData(struct DefaultReactionRatio *default_reaction);
void defineMainReactionData(struct ReactionData *main_reaction);

void recalculateFromFuelMol(struct ReactionData *main_reaction, float new_fuel_ammount_mol);
void recalculateFromOxidizerMol(struct ReactionData *main_reaction, float new_oxidizer_ammount_mol);
void recalculateOFRatio(struct ReactionData *main_reaction, struct DefaultReactionRatio *default_reaction, float new_of_ratio);

float massToMol(float mass, float uma);
float volumeToMol(float volume_L, float molarity_mol_over_L);
float molToMass(float mol, float uma);

float HClMolarityToWeightPercentage(float molarity, int round_weight);
float HClWeightPercentageToMolarity(float weight_percentage);
