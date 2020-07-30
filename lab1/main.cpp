#include <iostream>
#include <ctime>

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
    srand(time(NULL));

    // Task 1.1.1.1
    Breakpoints();

    // Task 1.1.1.2
    Breakpoints2();

    //Task 1.1.2.1
    const int valuesCount = 10;
    int values[valuesCount];

    cout << "Source array is:" << endl;

    for (int i = 0; i < valuesCount; i++)
    {
        //rand() make values ​​in the range 0 - 32767
        values[i] = rand() % 10;
        cout << values[i] << " ";
    }

    cout << endl << endl;

    // Insertion sort
    for (int i = 1; i < valuesCount; i++)
    {
        int current = i;
        while (current != 0 && values[current] < values[current - 1])
        {
            int temp = values[current - 1];
            values[current - 1] = values[current];
            values[current] = temp;
            current--;
        }
    }

    cout << "Sorted array is:" << endl;

    for (int i = 0; i < valuesCount; i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;
}

