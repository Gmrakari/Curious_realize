#include "iostream"
using namespace std;

/*date:September 2nd 2018 12 noon
Author:null
Project:null
*/

class Object{
public:
	Object(char girl_ = 'o', char guy_ = 'o')
	{
		girl = girl_;
		guy = guy_;
		cout << "generate object by cpp" << endl;
	}
	Object(const Object &couple)
	{
		girl = couple.girl;
		guy = couple.guy;
	}
	~Object()
	{
		cout << "Aotumatic generate Object" << endl;
	}
	char showgirl()
	{
		return girl;
	}
	char showguy()
	{
		return guy;
	}
private:
	unsigned char girl;
	unsigned char guy;
};

void get(Object o)
{
	cout << o.showgirl() << endl;
}
void complete_couple()
{
	Object girl('c', 'c');
	Object guy = girl;
	cout << "guy has been match" << endl;
	get(guy);
}

int main()
{
	complete_couple();
	system("pause");
	return 0;
	system("pause");
}
