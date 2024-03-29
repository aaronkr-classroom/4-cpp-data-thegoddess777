// 3-2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cout << "숫자를 입력하세요: " << endl;

    vector<int> numbers;

    int x;

    while (cin >> x) {
        numbers.push_back(x);
    }
	if (numbers.size() < 4) {
		cout << "정수의 개수가 4개 이상 필요합니다." << endl;
		return 1;
	}
    if (numbers.size() % 4 != 0) {
        cout << "정수의 개수가 4의 배수여야 합니다." << endl;
        return 1;
    }
    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < 3; i++) {
        int sum = numbers.size() / 4 * (i + 1) - 1;
        cout << i + 1 << "번째 사분위 수 : " << numbers[sum] << endl;
    }
    return 0;
}