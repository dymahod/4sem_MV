#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <iostream>
using namespace std;
int main()
{
   // clrscr();
    double a[11][11], b[11], t;
    int i, j, k, m, n;
    n = 3;
    a[1][1] = 1.24; a[1][2] = -0.87; a[1][3] = -3.17; b[1] = 0.46;
    a[2][1] = 2.11; a[2][2] = -0.45; a[2][3] = 1.44; b[2] = 1.5;
    a[3][1] = 0.48; a[3][2] = 1.25; a[3][3] = -0.63; b[3] = 0.35;
    cout << "\n\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << a[i][j] << "  ";
        cout << b[i] << "\n";
    }
    double eps = .001;
    double max;
    int max_i;
    double lead, a_div_lead;
    for (k = 1; k <= n; k++)
    {
        max = 0;
        max_i = -1;
        for (int i = k; i <= n; i++)
        {
            if (fabs(a[i][k]) > max)
            {
                max = fabs(a[i][k]);
                max_i = i;
            }
        }
        if (max_i == -1 || fabs(a[max_i][k]) < eps)
        {
            cout << "\n\n" << "Error: det=0" << "\n\n";
            break;
        }
        lead = a[k][k];
        for (j = k; j <= n; j++)
            a[k][j] /= lead;
        b[k] /= lead;
        for (i = 1; i <= n; i++)
        {
            a_div_lead = a[i][k] / a[k][k];
            if (i != k)
            {
                for (j = k; j <= n; j++)
                    a[i][j] -= a[k][j] * a_div_lead;
                b[i] -= b[k] * a_div_lead;
            }
        }
    }
    cout << "\n\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << a[i][j] << "  ";
        cout << b[i] << "\n";
    }
    //getch();
}