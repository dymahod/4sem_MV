#include <iostream>
#include <Windows.h>
#include <fstream>
#include <math.h>
using namespace std;
//решение СЛАУ методом итераций
double* iter(double** a, double* y, int n) {

	double* res = new double[n];
	int i, j;

	for (i = 0; i < n; i++)
	{
		res[i] = y[i] / a[i][i];
	}

	double eps = 0.001;
	double* Xn = new double[n];
	do {
		//count++
		for (i = 0; i < n; i++)
		{
			Xn[i] = y[i] / a[i][i];

			for (j = 0; j < n; j++)
			{
				if (i == j) continue;
				else {
					Xn[i] -= a[i][j] / a[i][i] * res[j];
				}
			}
		}
		bool flag = true;
		for (i = 0; i < n -1; i++)
		{
			if (abs(Xn[i] - res[i]) > eps) {
				flag = false;
				break;
			}
		}
		for (i = 0; i < n; i++)
		{
			res[i] = Xn[i];
		}
		if (flag) break;

	} while (1);
	return res;
}
int main() {
	setlocale(LC_ALL, "ru");
	double** a;
	double* y;
	double* x;
	int n = 4 , i, j;
	
	y = new double[n];
	a = new double* [n];
	for (i = 0; i < n; i++) {
		a[i] = new double[n];
	}
	cout << "Способ сам -1 , иначе дефолт будет";
	int sposob;
	cin >> sposob;
	if (sposob == 1) {
		for (i = 0; i < n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				if (j != n) {
					cin >> a[i][j];
				}
				else {
					cin >> y[i];
				}
			}
		}
	}
	else {
		a[0][0] =-0.83 ; a[0][1] =0.31 ;  a[0][2] = -0.18; a[0][3] = 0.22;  y[0] =1.71 ;
		a[1][0] = -0.21; a[1][1] =-1 ;    a[1][2] =0.33 ;  a[1][3] = 0.22;  y[1] = -0.62;
		a[2][0] = 0.32;  a[2][1] =-0.18 ; a[2][2] = -0.95; a[2][3] =-0.19 ; y[2] = 0.89;
		a[3][0] = 0.12;  a[3][1] =0.28 ;  a[3][2] =-0.14 ; a[3][3] = -1;    y[3] =-0.94 ;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (j != n) cout << a[i][j] << "\t";
			else		cout << y[i] << "\t";
		}
		cout << endl;
	}
	cout << "Теперь метод!" << endl;
	x = iter(a, y, n);
	for (i = 0; i < n; i++)
	{
		cout << x[i] << "\t";
	}
	cout << endl;
	return 0;
}