#include "PlayerPersistence.h"

void PlayerPersistence::save(Player& p) {
	json j;
	j["Name"] = p.getName();
	j["Age"] = p.getAge();
	j["Identity"] = p.getIdentity();
	j["Race"] = p.getRace();
	j["Religion"] = p.getReligion();
	j["BodyType"] = p.getBodyType();
	j["EyeColor"] = p.getEyeColor();
	j["HairColor"] = p.getHairColor();
	j["PartnerPreference"] = p.getPartnerPreference();
	ofstream ofs;
	ofs.open(DEFAULT_PLAYER_JOURNAL_SETTINGS_FILE);
	ofs << j;
	ofs.close();
}

Player PlayerPersistence::read() {
	ifstream ifs(DEFAULT_PLAYER_JOURNAL_SETTINGS_FILE);
	json data = json::parse(ifs);
	ifs.close();

	Player p(data.at("Name").get<string>(), data.at("Age").get<int>(), 
		data.at("Identity").get<EIdentity>(), data.at("Race").get<ERace>(),
		data.at("Religion").get<EReligion>(), data.at("BodyType").get<EBodyType>(), 
		data.at("HairColor").get<EHairColor>(),data.at("EyeColor").get<EEyeColor>(),
		data.at("PartnerPreference").get<EPartnerPreference>());

	return p;
}

bool PlayerPersistence::IsEmpty() {
	ifstream ifs(DEFAULT_PLAYER_JOURNAL_SETTINGS_FILE);
	bool empty = {};
	if (!ifs.fail()) {
		ifs.open(DEFAULT_PLAYER_JOURNAL_SETTINGS_FILE);
		empty = ifs.peek() == ifstream::traits_type::eof();
		ifs.close();
	}
	return empty;
}
