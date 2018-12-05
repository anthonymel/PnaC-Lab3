#include <iostream>
#include <string>
#include <map>

using namespace std;


void ChangeCapital(map<string, string>& countries, const string s1, const string s2)
{
	if (countries.count(s1) == 0) {
		cout << "Introduce new country " << s1 << " with capital " << s2 << endl;
		countries[s1] = s2;
	}
	else {
		if (countries[s1] == s2) {
			cout << "Country " << s1 << " hasn't changed its capital" << endl;
		}
		else {
			cout << "Country " << s1 << " has changed its capital from " << countries[s1] << " to " << s2 << endl;
			countries[s1] = s2;
		}
	}
}

void Rename(map<string, string>& countries, const string s1, const string s2)
{
	if (s1 == s2 || countries.count(s1) == 0 || countries.count(s2) != 0) {
		cout << "Incorrect rename, skip" << endl;
	}
	else {
		cout << "Country " << s1 << " with capital " << countries[s1] << " has been renamed to " << s2 << endl;
		countries[s2] = countries[s1];
		countries.erase(s1);
	}
}

void About(map<string, string>& countries, const string s1)
{
	if (countries.count(s1) == 0) {
		cout << "Country " << s1 << " doesn't exist" << endl;
	}
	else {
		cout << "Country " << s1 << " has capital " << countries[s1] << endl;
	}
}

void Dump(map<string, string>& countries)
{
	if (countries.empty()) {
		cout << "There are no countries in the world" << endl;
	}
	else {
		for (auto c : countries) {
			cout << c.first << "/" << c.second << " ";
		}
	}
}


int main() {
	int q;
	cin >> q;
	map<string, string> countries;
	string command, s1, s2;
	while (q>0) {
		cin >> command;
		if (command == "CHANGE_CAPITAL") {
			cin >> s1;
			cin >> s2;
			ChangeCapital(countries, s1, s2);
		}

		if (command == "RENAME") {
			cin >> s1;
			cin >> s2;
			Rename(countries, s1, s2);
		}

		if (command == "ABOUT") {
			cin >> s1;
			About(countries, s1);
		}

		if (command == "DUMP") {
			Dump(countries);
		}

		q--;
	}
	system("pause");
	return 0;
}