#include<string>
using namespace std;


const int NUM_OF_IDENTITIES = 7;

enum class Identity {
	Man = 1,
	Woman,
	CisWoman,
	TransWoman,
	CisMan,
	TransMan,
	NonBinary
};
string IdentityToString(Identity i);
