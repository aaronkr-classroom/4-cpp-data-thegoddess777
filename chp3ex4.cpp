// 3-4

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cout << "���ڿ��� �Է��Ͻÿ�: ";

	vector<string> words;
	string s;

	while (cin >> s)
	{
		words.push_back(s);
	}

	sort(words.begin(), words.end());

	vector<string>::size_type last = words.size() - 1;

	cout << "���� ª�� ����: " << words[0] << endl;
	cout << "���� �� ����: " << words[last] << endl;

	return 0;
}