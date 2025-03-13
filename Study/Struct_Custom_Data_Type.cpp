#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    struct myDataType {
        int id;
        int age;
        bool life;
    };

    myDataType person1;
    person1.id = 102;
    person1.age = 23;
    person1.life = true;

    cout << person1.id;
	
	return 0;
}