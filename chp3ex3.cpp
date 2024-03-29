// 3-3

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cout << "단어를 입력하시오: " << endl;

	vector<string> words;
	string s;

	while (cin >> s)
	{
		words.push_back(s);
	}

	sort(words.begin(), words.end());

	string tmp = words[0];
	int count = 1;

	for (int i = 1; i < words.size(); i++)
	{
		if (words[i] == tmp)
		{
			count++;
			continue;
		}

		cout << tmp << " : " << count << endl;

		tmp = words[i];
		count = 1;
	}

	cout << tmp << " : " << count << endl;

	return 0;
}