#include <iostream>
#include <cmath>

using namespace std;

void gaussFilter2(double gk[][5])
{
    double sigma = 1.0;
    double r;
    double s = 2.0 * sigma * sigma;
    double sum = 0.0;

    for(int x = -2; x <= 2; x++)
    {
        for(int y = -2; y <= 2; y++)
        {
            r= sqrt(x *x + y * y);
            gk[x + 2][y + 2] = (exp(-(r * r)/s)) / (M_PI * s);
            sum += gk[x+ 2][y + 2];
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            gk[i][j] /= sum;
        }
    }
}

void gaussFilter(double gk[])
{
    double sigma = 1.0;
    double s = 2.0 * sigma * sigma;
    double sum = 0.0;

    for(int x = -2; x <= 2; x++)
    {
        gk[x + 2] = (exp(-(x * x) / s)) / sqrt(M_PI * s);
        sum += gk[x + 2];
    }

    cout << "sum = " << sum << endl;

    for(int i = 0; i < 5; i++)
    {
        gk[i] /= sum;
    }
}

int main(int argc, char* arv[])
{
    /*
    double gk[5][5];
    gaussFilter2(gk);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << gk[i][j] << "\t";
        }
        cout << endl;
    }
    */
    double gk[5];
    gaussFilter(gk);

    for(int i = 0; i < 5; i++)
    {
        cout << gk[i] << "\t";
    }
    cout << endl;

}