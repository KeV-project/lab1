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
    cout << "Total sum is " << sum << endl << endl;
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
    cout << "Total sum is " << sum << endl << endl;
}

double GetPower(double base, int exponent)
{
    return pow(base, exponent);
}

void DemoGetPower(double base, int exponent)
{
    GetPower(base, exponent);

    cout << "Result: " << base << "^" << exponent << " = " << GetPower(base, exponent) << endl;
}

void RoundToTens(int& value)
{
    if (value % 10 < 5)
    {
        value = value / 10 * 10;
    }
    else if (value % 10 >= 5)
    {
        value = value / 10 * 10 + 10;
    }
}

void Foo(double x)
{
    cout << "Address of x in Foo(): " << &x << endl;
    cout << "Value of x in Foo(): " << x << endl;
    x = 15.0;
    cout << "New value of x in Foo(): " << x << endl;
}

void main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    // Task 1.1.1.1 ///////////////////////////////////////////////////////////
    Breakpoints();

    // Task 1.1.1.2 ///////////////////////////////////////////////////////////
    Breakpoints2();

    // Task 1.1.2.1 ///////////////////////////////////////////////////////////
    const int valuesIntCount = 10;
    int valuesInt[valuesIntCount];

    cout << "Source valuesChar is:" << endl;

    for (int i = 0; i < valuesIntCount; i++)
    {
        //rand() make values ​​in the range 0 - 32767
        valuesInt[i] = rand() % 10;
        cout << valuesInt[i] << " ";
    }

    cout << endl << endl;

    // Insertion sort
    for (int i = 1; i < valuesIntCount; i++)
    {
        int current = i;
        while (current != 0 && valuesInt[current] < valuesInt[current - 1])
        {
            int temp = valuesInt[current - 1];
            valuesInt[current - 1] = valuesInt[current];
            valuesInt[current] = temp;
            current--;
        }
    }

    cout << "Sorted valuesChar is:" << endl;

    for (int i = 0; i < valuesIntCount; i++)
    {
        cout << valuesInt[i] << " ";
    }

    cout << endl << endl;

    // Task 1.1.2.2 ///////////////////////////////////////////////////////////
    const int valuesDoubleCount = 12;
    float valuesDouble[valuesDoubleCount];

    cout << "Source valuesChar is:" << endl;

    for (int i = 0; i < valuesDoubleCount; i++)
    {
        valuesDouble[i] = (rand() % 10) * 0.1 + rand() % 10;
        cout << valuesDouble[i] << " ";
    }

    cout << endl << endl;

    float searchingValue = 0.0;
    cout << "Enter searching value: ";
    cin >> searchingValue;
    cout << endl;
    int count = 0;
    for (int i = 0; i < valuesDoubleCount; i++)
    {
        if (valuesDouble[i] >= searchingValue)
        {
            count++;
        }

    }
    cout << "Elements of valuesChar more than " << searchingValue << " - " << count << endl << endl;

    // Task 1.1.2.3 ///////////////////////////////////////////////////////////
    const int valuesCharCount = 8;
    char valuesChar[valuesCharCount];

    cout << "Enter array of 8 chars" << endl;

    for (int i = 0; i < valuesCharCount; i++)
    {
        cout << "Enter " << i << " element: " << endl;
        cin >> valuesChar[i];
        // Clear input buffer
        if (cin.get() != (int)'\n')
        {
            cin.clear();
            cin.ignore(32767, '\n');
        }
    }

    cout << endl << "Your array: " << endl << endl;

    for (int i = 0; i < valuesCharCount; i++)
    {
        cout << valuesChar[i] << " ";
    }

    cout << endl << endl;

    cout << "All letters in your array: " << endl << endl;

    for (int i = 0; i < valuesCharCount; i++)
    {
        if (((int)valuesChar[i] >= 65 && (int)valuesChar[i] <= 90) || ((int)valuesChar[i] >= 97 && (int)valuesChar[i] <= 122))
        {
            cout << valuesChar[i] << " ";
        }
    }
    cout << endl << endl;

    // Task 1.1.3.2 ///////////////////////////////////////////////////////////
    double base = 0.0;
    int exponent = 0;
    cout << "Enter the base: ";
    cin >> base;
    cout << endl;
    cout << "Enter exponent : ";
    cin >> exponent;
    cout << endl;
    cout << "Result: " << base << "^" << exponent << " = " << GetPower(base, exponent) << endl << endl;

    // Task 1.1.3.3 ///////////////////////////////////////////////////////////
    DemoGetPower(2.1, 5);
    DemoGetPower(5, 2);
    DemoGetPower(1, 60);
    cout << endl;

    // Task 1.1.3.4 ///////////////////////////////////////////////////////////
    int value;
    cout << "Enter value: ";
    cin >> value;
    cout << endl;
    RoundToTens(value);
    cout << "Result: " << value << endl << endl;

    // Task 1.1.4.1 ///////////////////////////////////////////////////////////
    int a = 5;
    cout << "Address of a: " << &a << endl;
    int b = 4;
    cout << "Address of b: " << &b << endl;
    double c = 13.5;
    cout << "Address of c: " << &c << endl;
    bool d = true;
    cout << "Address of d: " << &d << endl << endl;

    // Task 1.1.4.2///////////////////////////////////////////////////////////
    int numsInt[10] = { 1, 2, 7, -1, 5, 3, -1, 7, 1, 6 };
    cout << "Size of int type: " << sizeof(int) << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Address of a[" << i << "]: " << &numsInt[i] << endl;
    }
    cout << endl;
    cout << "Size of double type: " << sizeof(double) << endl;
    double numsDouble[10] = { 1.0, 2.0, 7.0, -1.0, 5.0, 3.5, -1.8, 7.2, 1.9, 6.2 };
    for (int i = 0; i < 10; i++)
    {
        cout << "Address of b[" << i << "]: " << &numsDouble[i] << endl;
    }
    cout << endl;

    // Task 1.1.4.3 ///////////////////////////////////////////////////////////
    int val = 5;
    int& valRef = val;
    cout << "Address of val: " << &val << endl;
    cout << "Address of valRef: " << &valRef << endl;
    cout << endl;
    valRef = 7;
    cout << "Value of val: " << valRef << endl << endl;

    // Task 1.1.4.4 ///////////////////////////////////////////////////////////
    double x = 5.0;
    cout << "Address of x in main: " << &x << endl;
    cout << "Value of x in main: " << x << endl;
    cout << endl;
    Foo(x);
    cout << endl;
    cout << "Value of x in main: " << x << endl << endl;

    // Task 1.1.4.6 ///////////////////////////////////////////////////////////
    int y = 5;
    int* yPtr = &y;
    cout << "Address of y: " << &y << endl;
    cout << "Address in pointer: " << yPtr << endl;
    cout << "Address of pointer: " << &yPtr << endl;
    cout << endl;
    *yPtr = 7;
    cout << "Value in y: " << y << endl;
    cout << "Value by pointer address: " << *yPtr << endl;
}

