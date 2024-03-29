// 3-01

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


//�߰�,�⸻,���� �������� �л��� ���� ������ ����
double grade(double mt, double ft, double hw) {
	return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}

	//vector<double>�� �߾Ӱ��� ����
	//�Լ��� ȣ���ϸ� �μ��� ������ ���͸� ��°�� ����
double median(vector<double> vec) {
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();

	if (size == 0) {
		throw domain_error("Median of empty vector");
	}

	//������ ����
	sort(vec.begin(), vec.end());

	//���� ������ �߾Ӱ��� ����
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid - 1]) / 2 : vec[mid];
}

//�߰�, �⸻, ���� ������ ���ͷ� �л��� ���� ������ ����
//�� �Լ��� �μ��� �������� �ʰ� median �Լ��� �ش� �۾��� ����
double grade(double mt, double ft, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("No homework!");
	return grade(mt, ft, median(hw));
}

// �Է� ��Ʈ������ ���� ������ �о vector<double>�� ����.
istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		//���� ������ ����
		hw.clear();

		//�Է��� ���� ����
		double x;

		while (in >> x) {
			hw.push_back(x);
		}
		//���� �л��� ���� �Է� �۾��� ����� ��Ʈ���� ����
		in.clear();
	}
	return in;
}

int main()
{
	//�л��� �̸��� ���� ����
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// �߰������ �⸻������ ������ ���� ����
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	// ���� ������ ����.
	cout << "Enter all your homework grades, "
		"followed by end-of-file: ";

	vector<double> homework;
	
	// ���� ������ ����.
	read_hw(cin, homework);

	// ���� ������ ����� ����.
	try {
		double final_grade = grade(midterm, final, homework);
		streamsize prec = cout.precision();
		cout << "Your final grade is " << setprecision(3)
			<< final_grade << setprecision(prec) << endl;
	}
	catch (domain_error) {
		cout << endl << "You nust enter your grades. "
			"Please try again. " << endl;
		return 1;
	}
	return 0;
}