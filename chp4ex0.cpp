// 3-01

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


//중간,기말,과제 점수에서 학생의 조합 점수를 구함
double grade(double mt, double ft, double hw) {
	return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}

	//vector<double>의 중앙값을 구함
	//함수를 호출하면 인수로 제공된 벡터를 통째로 복사
double median(vector<double> vec) {
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();

	if (size == 0) {
		throw domain_error("Median of empty vector");
	}

	//점수를 정렬
	sort(vec.begin(), vec.end());

	//과제 점수의 중앙값을 구함
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid - 1]) / 2 : vec[mid];
}

//중간, 기말, 과제 점수의 벡터로 학생의 종합 점수를 구함
//이 함수는 인수를 복사하지 않고 median 함수가 해당 작업을 실행
double grade(double mt, double ft, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("No homework!");
	return grade(mt, ft, median(hw));
}

// 입력 스트림에서 과제 점수를 읽어서 vector<double>에 넣음.
istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		//이전 내용을 제거
		hw.clear();

		//입력을 위한 변수
		double x;

		while (in >> x) {
			hw.push_back(x);
		}
		//다음 학생의 점수 입력 작업을 고려해 스트림을 지움
		in.clear();
	}
	return in;
}

int main()
{
	//학생의 이름을 묻고 읽음
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// 중간시험과 기말시험의 점수를 묻고 읽음
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	// 과제 점수를 물음.
	cout << "Enter all your homework grades, "
		"followed by end-of-file: ";

	vector<double> homework;
	
	// 과제 점수를 읽음.
	read_hw(cin, homework);

	// 종합 점수를 계산해 생성.
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