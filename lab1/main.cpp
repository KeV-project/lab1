#include <iostream>

using namespace std;


void Breakpoints()
{
    double add = 1.0;
    double sum = 0.0;
    for (int i = 0; i < 10; i++)
    {
        // sum = 0.0, 1.1, 3.52, 7.513, 13.3, 21.42, 31.05, 45.69, 62.84, 84.06
        sum += add * i; // breakpoint
        add *= 1.1;
    }
    cout << "Total sum is " << sum << endl;
}

void Breakpoints2()
{
    double add = 1.0;
    double sum = 0.0;
    for (int i = 0; i < 1000; i++)
    {
        // At 777 iterations of the loop sum == 3.26
        sum += add * i; // breakpoint
        if (i % 3 == 0)
        {
            add *= 1.1;
        }
        else
        {
            add /= 3.0;
        }
    }
    cout << "Total sum is " << sum << endl;
}

void main()
{
	setlocale(LC_ALL, "rus");

    // Task 1.1.1.1
    Breakpoints();

    // Task 1.1.1.2
    Breakpoints2();
}

