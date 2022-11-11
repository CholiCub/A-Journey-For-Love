#include<string>
using namespace std;

const int NUM_OF_BODY_TYPES = 5;
enum BodyType {
	Thin = 1,
	Athletic,
	Average,
	AFewExtra,
	BigTallOrBBW
};
string BodyTypeToString(BodyType b);
