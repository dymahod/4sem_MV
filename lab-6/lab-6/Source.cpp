#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

int main() {
	setlocale(0, "");

	double mas[3][4] = {
		{2.23,	-0.71,	0,		1.28	},
		{-0.71,	5.45,	-1.34,	0.64	},
		{0,		-1.34,	2.77,	-0.87	}
	};

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << setw(6) << mas[i][j];
		}
		cout << endl;
	}

	double A[2];
	double B[2];

	A[0] = (-1) * mas[0][1] / mas[0][0];
	B[0] = mas[0][3] / mas[0][0];

	for (int i = 1; i < 2; i++) {
		A[i] = (-1) * mas[i][i + 1] / (A[i - 1] * mas[i][i - 1] + mas[i][i]);
		B[i] = (mas[i][3] - mas[i][i - 1] * B[i - 1]) / (A[i - 1] * mas[i][i - 1] + mas[i][i]);
	}

	cout << "����������� ������������:" << endl;
	cout << "A: ";
	for (int i = 0; i < 2; i++) {
		cout << setw(10) << A[i];
	}

	cout << endl;

	cout << "����������� ������������:" << endl;
	cout << "B: ";
	for (int i = 0; i < 2; i++) {
		cout << setw(10) << B[i];
	}

	cout << endl;

	double X[3];

	X[2] = (mas[2][3] - mas[2][1] * B[1]) / (mas[2][2] + mas[2][1] * A[1]);

	for (int i = 1; i >= 0; i--) {
		X[i] = A[i] * X[i + 1] + B[i];
	}

	cout << "������� ����:" << endl;
	cout << "X: ";
	for (int i = 0; i < 3; i++) {
		printf("%10.5f", X[i]);
	}

	cout << endl;

	system("pause");
	return 0;
}