#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Person
{
public:
	Person();
	Person (string p);
	void befriend(Person p);
	void unfriend(Person& p);
	string getFriendNames();
	int getFriendCount();
private:
	string name;
	string friends;
};

Person::Person() {};
Person::Person(string p)
{
	name = p;
}
void Person::befriend(Person p)
{
	string newFriend = p.name;
	friends = newFriend + " " + friends;
	return;
}

void Person::unfriend(Person& p)
{
	istringstream str(friends);
	string temp;
	string newstr;
	while (str >> temp)
	{
		if (temp != p.name)
		{
			newstr = newstr + temp;
		}
	}
	friends = newstr;
	return;
}

string Person::getFriendNames()
{
	string outFriend = friends;
	return outFriend;
}

int Person::getFriendCount()
{	
	int friendCount = 0;
	istringstream str(friends);
	string temp;
	while (str >> temp) {friendCount++;}
	return friendCount;
}


int main()
{
	string outputFriend;
	Person john("john");
	Person joey("joey");
	Person sam("sam");
	john.befriend(joey);
	john.befriend(sam);
	joey.befriend(john);
	outputFriend = john.getFriendNames();
	cout << outputFriend << endl;
	outputFriend = joey.getFriendNames();
	cout << outputFriend << endl;
	john.unfriend(joey);
	outputFriend = john.getFriendNames();
	cout << outputFriend << endl;
	cout << john.getFriendCount() << " " << joey.getFriendCount() << endl;


	return 0;
}