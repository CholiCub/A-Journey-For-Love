#pragma once
#include<string>
using namespace std;
const int NUM_OF_PARTNER_PREFERENCE = 3;
enum class EPartnerPreference {
	male = 1,
	female,
	both
};
string PartnerPreferenceToString(EPartnerPreference pp);


