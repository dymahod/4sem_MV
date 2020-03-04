#include<iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int i, j, n, m;
    setlocale(LC_ALL, "ru");
    //создаем массив
    cout << "введи число уравнений: ";
    cin >> n;
    cout << "введи число неизвестных: ";
    cin >> m;
    m = 4;
    m += 1;
    double** matrix = new double* [n];
    for (i = 0; i < n; i++)
        matrix[i] = new double[m];

    //инициализируем

    for (i = 0; i < n; i++)

        for (j = 0; j < m; j++)
        {
            cout << "Элемент " << "[" << i + 1 << " , " << j + 1 << "]: ";

            cin >> matrix[i][j];
        }

    //выводим массив
    cout << "matrix: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    //Метод Гаусса
    //Прямой ход, приведение к верхнетреугольному виду
    double  tmp, xx[5];
    int k;

    for (i = 0; i < n; i++)
    {
        tmp = matrix[i][i];
        for (j = n; j >= i; j--)//делим столбцы чтобы на главной диагонали получились единицы
            matrix[i][j] /= tmp;
        for (j = i + 1; j < n; j++)//здесь делаем ноль в первом столбце для i =0 и т д 
            //грубо говоря мы нашу единицу в [0][0] умножаем на [1][0] и отнимаем от [1][0] в [1][0] имеем нуль
            //и соответственно изменится и вся вторая стока)
            //когда добавляем i++ то переходим к другой строке и там тоже самое
            //вместе с этим дальше измениться и первый столбик на нули изза изменения j
        {
            tmp = matrix[j][i];
            for (k = n; k >= i; k--)
                matrix[j][k] -= tmp * matrix[i][k];
        }
    }
    //когда получили верхнетреугольную матрицу
    //начинаем получать наши иксы
    xx[n - 1] = matrix[n - 1][n];//x3 равен тому, что получилось в y3
    for (i = n - 2; i >= 0; i--)
    {
        xx[i] = matrix[i][n]; //присвоим x 2 тому что в y 2
        for (j = i + 1; j < n; j++) xx[i] -= matrix[i][j] * xx[j]; //минус x3*значение в [2][3] и получим реальное x2 и так с каждым
    }

    //Выводим решения
    for (i = 0; i < n; i++)
        cout << xx[i] << " ";
    cout << endl;

    delete[] matrix;

    return 0;
}