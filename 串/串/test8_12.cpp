#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <string>
#include <iostream>

using namespace std;
int match(string s1, string s2)
{
	int l1 = s1.length();
	int l2 = s2.length();
	if (l2 > l1)
	{
		return -1;
	}
	for (int i = 0; i < l1 - l2 + 1; i++)
	{
		int j = 0;
		while (s1[j+i] == s2[j]&&j<l2)
		{
			j++;
		}
		if (j == l2)
		{
			return i;
		}
	}
}

int main()
{
	string major;
	string model;
	cin >> major >> model;
	int ret = match(major, model);
	cout << ret << endl;
	return 0;
}