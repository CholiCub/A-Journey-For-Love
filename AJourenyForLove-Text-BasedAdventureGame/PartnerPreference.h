#pragma once
#include<string>
using namespace std;
const int NUM_OF_PARTNER_PREFERENCE = 3;
enum class PartnerPreference {
	male = 1,
	female,
	both
};
string PartnerPreferenceToString(PartnerPreference pp);


