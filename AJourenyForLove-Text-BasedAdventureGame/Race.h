#include<string>
using namespace std;

const int NUM_OF_RACES = 10;

enum class ERace {
	AfricanAmerican = 1,
	Asian,
	Caucasian,
	Black,
	Indian,
	IndigenousOrAboriginal,
	LatinOrHispanic,
	MiddleEastern,
	Mixed,
	Other
};
string RaceToString(ERace r);
