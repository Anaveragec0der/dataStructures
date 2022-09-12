#include <iostream>
#include <cstring>

using namespace std;

// driver code
int main()
{
	// assigning value to string s
	string s = "aquickbrownfoxjumpedoveralazydog";

	int n = s.length();

	// declaring character array
	char char_array[n + 1];

	// copying the contents of the
	// string to char array
	strcpy(char_array, s.c_str());

	for (int i = 0; i < n; i++)
	{

		cout << char_array[i];
	}
	cout << endl;
	cout << char_array << endl;

	return 0;
}
