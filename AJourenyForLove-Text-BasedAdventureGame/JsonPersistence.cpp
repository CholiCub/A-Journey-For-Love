#include "JsonPersistence.h"

void JsonPersistence::save(Player& p) {
	ofstream ofs;
	ofs.open(DEFAULT_PLAYER_JOURNAL_SETTINGS_FILE);
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
	ofs << j;
	ofs.close();
}

Player JsonPersistence::read() {
	ifstream ifs;
	ifs.open(DEFAULT_PLAYER_JOURNAL_SETTINGS_FILE);
	json data = json::parse(ifs);

	Player p(data.at("Name").get<string>(), data.at("Age").get<int>(), 
		data.at("Identity").get<EIdentity>(), data.at("Race").get<ERace>(),
		data.at("Religion").get<EReligion>(), data.at("BodyType").get<EBodyType>(), 
		data.at("HairColor").get<EHairColor>(),data.at("EyeColor").get<EEyeColor>(),
		data.at("PartnerPreference").get<EPartnerPreference>());

	ifs.close();
	return p;
}

bool JsonPersistence::IsFileEmpty() {
	ifstream ifs;
	ifs.open(DEFAULT_PLAYER_JOURNAL_SETTINGS_FILE);
	bool empty = ifs.peek() == ifstream::traits_type::eof();
	ifs.close();
	return empty;
}
