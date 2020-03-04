 #include <iostream>
using namespace std;
// ����� ������� ���������
void vivod(double** a, double* y, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "*x" << j;
            if (j < n - 1)
                cout << " + ";
        }
        cout << " = " << y[i] << endl;
    }
    return;
}
double* gauss(double** a, double* y, int n)
{
    double* x, max;
    int k, index;
    const double to4nostb = 0.001;  // ��������
    x = new double[n];
    k = 0;
    while (k < n)
    {
        // ����� ������ � ������������ a[i][k]
        max = abs(a[k][k]);
        index = k;
        for (int i = k + 1; i < n; i++)
        {
            if (abs(a[i][k]) > max)
            {
                max = abs(a[i][k]);
                index = i;
            }
        }
        //����� ��� ������������ ������� � ������������ ������
        //���� ����� ������ �����������, �� ������ ��� 0 � ������ � ����� ������� �� �������
        if (max < to4nostb)
        {
            // ��� ��������� ������������ ���������
            cout << "������� �������� ���������� ��-�� �������� ������� ";
            cout << index << " ������� A" << endl;
            return 0;
        }
        for (int j = 0; j < n; j++)
        {
            double temp = a[k][j];
            a[k][j] = a[index][j];
            a[index][j] = temp;
        }
        //����������� ������������ ��� x , ������ ���������� y-��
        double temp = y[k];
        y[k] = y[index];
        y[index] = temp;
        //����������� ������
        // ������������ ���������
        for (int i = k; i < n; i++)
        {
            double temp = a[i][k];//����� ������������ �������

            if (abs(temp) < to4nostb) continue; // ��� �������� ������������ ����������



            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] / temp;//������� ����� ����� �� ����� � ��������� ������� [i][j] when i==j
            y[i] = y[i] / temp;//y ���� �����

            if (i == k)  continue; // ��������� �� �������� ���� �� ����
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] - a[k][j];
            y[i] = y[i] - y[k];

            cout << "/////qqqqqqqqqqqqqqqqqqqqqqqqqqqqq///////////////" << endl;
            vivod(a, y, n);
            cout<< "/////qqqqqqqqqqqqqqqqqqqqqqqqqqqqq///////////////" << endl;
        }
        k++;
        cout << endl << endl;
        vivod(a, y, n);
    }
    // �������� �����������
    cout << endl << endl <<
        "�������� �����������!" << endl << endl;
    for (k = n - 1; k >= 0; k--)
    {
        x[k] = y[k];
        for (int i = 0; i < k; i++)
            y[i] = y[i] - a[i][k] * x[k];

        cout <<"///////////////////////////////////////////////////////////"<< endl << endl;
        vivod(a, y, n);
    }
    return x;
}
int main()
{
    double** a, * y, * x;
    int n;
    system("chcp 1251");
    int Variable;
    cout << "������� ������ �����(1 - ������ , 0 - ������������� �� ������ �������� " << endl;
    cin >> Variable;
    if (Variable == 1) {
        cout << "������� ���������� ���������: ";
        cin >> n;
        a = new double* [n];
        y = new double  [n];

        for (int i = 0; i < n; i++)
        {
            a[i] = new double[n];
            for (int j = 0; j < n; j++)
            {
                cout << "a[" << i << "][" << j << "]= ";
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << "y[" << i << "]= ";
            cin >> y[i];
        }
    }
    else {
        n = 3;
        a = new double* [n];
        y = new double  [n];
        a[0] = new double[n];
        a[0][0] = 1.24; a[0][1] = -0.87;  a[0][2] = -3.17;   y[0] = 0.46;
        a[1] = new double[n];
        a[1][0] = 2.11; a[1][1] = -0.45;  a[1][2] = 1.44;    y[1] = 1.5;
        a[2] = new double[n];
        a[2][0] = 0.48;  a[2][1] = 1.25; a[2][2] = -0.63;    y[2] = 0.35;
        
    }
    vivod(a, y, n);
    x = gauss(a, y, n);
    for (int i = 0; i < n; i++)
        cout << "x[" << i << "]=" << x[i] << endl;
    cin.get();
    return 0;
}