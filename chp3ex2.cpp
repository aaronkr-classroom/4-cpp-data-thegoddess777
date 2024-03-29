// 3-2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cout << "���ڸ� �Է��ϼ���: " << endl;

    vector<int> numbers;

    int x;

    while (cin >> x) {
        numbers.push_back(x);
    }
	if (numbers.size() < 4) {
		cout << "������ ������ 4�� �̻� �ʿ��մϴ�." << endl;
		return 1;
	}
    if (numbers.size() % 4 != 0) {
        cout << "������ ������ 4�� ������� �մϴ�." << endl;
        return 1;
    }
    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < 3; i++) {
        int sum = numbers.size() / 4 * (i + 1) - 1;
        cout << i + 1 << "��° ����� �� : " << numbers[sum] << endl;
    }
    return 0;
}