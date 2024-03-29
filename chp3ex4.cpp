// 3-4

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cout << "문자열을 입력하시오: ";

	vector<string> words;
	string s;

	while (cin >> s)
	{
		words.push_back(s);
	}

	sort(words.begin(), words.end());

	vector<string>::size_type last = words.size() - 1;

	cout << "가장 짧은 길이: " << words[0] << endl;
	cout << "가장 긴 길이: " << words[last] << endl;

	return 0;
}