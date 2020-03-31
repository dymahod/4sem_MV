/*МЕТОД ЗЕЙДЕЛЯ!*//*ЛИТВИНОВ ВАРИАНТ 7*/
#include<iostream>
#include<Windows.h>
#include<math.h>
using namespace std;
int main() {
        setlocale(LC_ALL, "rus");
    
        double A[3][3] = {{ 3.7, -2.5, 0.7 },
                          { 0.5, 3.3, 1.7  },
                          { 1.6, 2.3, -7.5 }};
        double F[] = { 6.5, -0.24, 4.3 };
        double eps = 0.001;
        double X[3];
        for (int i = 0; i < 3; i++) {
            X[i] = F[i] / A[i][i];
        }
        //итерации, на каждом шаге находим решение с точностью, 
        //переопределяем max = разница между прошлыми значениями и получившимися и сравниваем с точностью
        //если max > eps , то переходим к следующей итерации
        //идея в том, чтобы найти ответ приближенным значением к нашей точности
        //по сути это улучшенный метод итераций
        //разница в формуле xn[i] он равер СУММАМ умноженным на множители
        double max = eps + 1;
        int k = 0;
        double Xn[3];
        while (max > eps) {
            for (int i = 0; i < 3; i++) {
                double sum1 = 0;
                for (int j = 0; j <= i - 1; j++) {
                    if (j != i)
                        sum1 -= A[i][j] * (Xn[j]) / A[i][i];
                    
                }
                double sum2 = 0;
                for (int j = i; j < 3; j++) {
                    if (j != i)
                        sum1 -= A[i][j] * (X[j]) / A[i][i];
                }
                Xn[i] = sum1 + sum2 + F[i] / A[i][i];
            }
            max = abs(Xn[0] - X[0]);
            for (int i = 1; i < 3; i++) {
                if (abs(Xn[i] - X[i]) > max) {
                    max = abs(Xn[i] - X[i]);
                }
            }
            if (max < eps) {
                for (int i = 0; i < 3; i++) {
                    cout << "X" << (i + 1) << ": " << X[i] << endl;
                }
                cout<<"Количество итераций: "<< k <<endl;
                exit(1);
            }
            for (int i = 0; i < 3; i++) {
                X[i] = Xn[i];
            }
            k++;
        
    }
}
