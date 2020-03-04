#include<iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int i, j, n, m;
    setlocale(LC_ALL, "ru");
    //������� ������
    cout << "����� ����� ���������: ";
    cin >> n;
    cout << "����� ����� �����������: ";
    cin >> m;
    m = 4;
    m += 1;
    double** matrix = new double* [n];
    for (i = 0; i < n; i++)
        matrix[i] = new double[m];

    //��������������

    for (i = 0; i < n; i++)

        for (j = 0; j < m; j++)
        {
            cout << "������� " << "[" << i + 1 << " , " << j + 1 << "]: ";

            cin >> matrix[i][j];
        }

    //������� ������
    cout << "matrix: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    //����� ������
    //������ ���, ���������� � ������������������ ����
    double  tmp, xx[5];
    int k;

    for (i = 0; i < n; i++)
    {
        tmp = matrix[i][i];
        for (j = n; j >= i; j--)//����� ������� ����� �� ������� ��������� ���������� �������
            matrix[i][j] /= tmp;
        for (j = i + 1; j < n; j++)//����� ������ ���� � ������ ������� ��� i =0 � � � 
            //����� ������ �� ���� ������� � [0][0] �������� �� [1][0] � �������� �� [1][0] � [1][0] ����� ����
            //� �������������� ��������� � ��� ������ �����)
            //����� ��������� i++ �� ��������� � ������ ������ � ��� ���� �����
            //������ � ���� ������ ���������� � ������ ������� �� ���� ���� ��������� j
        {
            tmp = matrix[j][i];
            for (k = n; k >= i; k--)
                matrix[j][k] -= tmp * matrix[i][k];
        }
    }
    //����� �������� ����������������� �������
    //�������� �������� ���� ����
    xx[n - 1] = matrix[n - 1][n];//x3 ����� ����, ��� ���������� � y3
    for (i = n - 2; i >= 0; i--)
    {
        xx[i] = matrix[i][n]; //�������� x 2 ���� ��� � y 2
        for (j = i + 1; j < n; j++) xx[i] -= matrix[i][j] * xx[j]; //����� x3*�������� � [2][3] � ������� �������� x2 � ��� � ������
    }

    //������� �������
    for (i = 0; i < n; i++)
        cout << xx[i] << " ";
    cout << endl;

    delete[] matrix;

    return 0;
}