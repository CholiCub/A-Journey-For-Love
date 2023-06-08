#include<string>
using namespace std;

const int NUM_OF_BODY_TYPES = 5;
enum EBodyType {
	Thin = 1,
	Athletic,
	Average,
	AFewExtra,
	BigTallOrBBW
};
string BodyTypeToString(EBodyType b);
