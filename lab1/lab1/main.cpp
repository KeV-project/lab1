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
    cout << "Result: " << base << "^" << exponent;
    cout << " = " << GetPower(base, exponent) << endl;
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

void FooPtr(double* z)
{
    cout << "Address in pointer: " << z << endl;
    cout << "Address of pointer: " << &z << endl;
    cout << "Value in pointer address: " << *z << endl;
    *z = 15.0;
    cout << "New z in pointer address: " << *z << endl << endl;
}

void Sort(float* numsFloat, const int numsFloatCount)
{
    for (int i = 1; i < numsFloatCount; i++)
    {
        int current = i;
        while (current != 0 && numsFloat[current] < numsFloat[current - 1])
        {
            float temp = numsFloat[current - 1];
            numsFloat[current - 1] = numsFloat[current];
            numsFloat[current] = temp;
            current--;
        }
    }
}

bool Search(int* numbers, int numsCount, int& searchingValue, int& index)
{
    for (int i = 0; i < numsCount; i++)
    {
        if (numbers[i] == searchingValue)
        {
            index = i;
            return true;
        }
    }
    return false;
}

void SearchLetters(char* characters, const int charactersCount)
{
    for (int i = 0; i < charactersCount; i++)
    {
    	 if ((characters[i] >= 'A' && characters[i] <= 'Z') 
            || (characters[i] >= 'a' && characters[i] <= 'z'))
        {
            cout << characters[i] << " ";
        }
    }
}

int* MakeRandomArray(int arraySize)
{
    int* array = new int[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = rand() % 100;
    }
    return array;
}

int* ReadArray(int count)
{
    int* values = new int[count];
    for (int i = 0; i < count; i++)
    {
        cout << "Enter " << i << " element: ";
        cin >> values[i];
    }
    cout << endl;
    return values;
}

int CountPositiveValues(int* values, int count)
{
    int result = 0;
    for (int i = 0; i < count; i++)

    {
        if (values[i] > 0)
        {
            result++;
        }
    }
    return result;
}

void PrintRandomArray(int arrayCount)
{
    int* tmpArray = MakeRandomArray(arrayCount);
    cout << "Random array of " << arrayCount << " : ";
    for (int j = 0; j < arrayCount; j++)
    {
        cout << tmpArray[j] << " ";
    }
    cout << endl << endl;
    delete[] tmpArray;
}

void PrintEnterArrayCounts(int valuesCount)
{
    int* values = ReadArray(valuesCount);
    cout << "Count is: " << CountPositiveValues(values, valuesCount) << endl << endl;
    delete[] values;
}

void main()
{
    setlocale(LC_ALL, "rus");
    srand(time(nullptr));
   
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
        //rand() make values ​​range 0 - 32767
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
	
    cout << "Elements of valuesChar more than ";
    cout << searchingValue << " - " << count << endl << endl;

    // Task 1.1.2.3 ///////////////////////////////////////////////////////////
    const int valuesCharCount = 8;
    char valuesChar[valuesCharCount];

    cout << "Enter array of 8 chars" << endl;

    for (int i = 0; i < valuesCharCount; i++)
    {
        cout << "Enter " << i << " element: " << endl;
        cin >> valuesChar[i];
        // Clear input buffer
        // Исключает ввод более одного символа в переменную типа char
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
    SearchLetters(valuesChar, valuesCharCount);
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
    cout << "Result: " << base << "^" << exponent;
    cout << " = " << GetPower(base, exponent) << endl << endl;

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
    double numsDouble[10] = 
    { 
        1.0, 2.0, 7.0, -1.0, 5.0,
        3.5, -1.8, 7.2, 1.9, 6.2 
    };
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
    cout << "Value by pointer address: " << *yPtr << endl << endl;

    // Task 1.1.4.8 ///////////////////////////////////////////////////////////
    double z = 5.0;
    double* zPtr = &z;
    cout << "Address of z in main(): " << &z << endl;
    cout << "Address in pointer in main(): " << zPtr << endl;
    cout << "Address of pointer in main(): " << &zPtr << endl;
    cout << "Value of a in main(): " << z << endl << endl;
    
    FooPtr(zPtr);
    
    cout << "Value of z in main(): " << z << endl << endl;

    // Task 1.1.5.1 ///////////////////////////////////////////////////////////
    int valuesFloatCount = 5;
    float* valuesFloat = new float[valuesFloatCount] {1.2, 2.6, 7.1, 6.3, 2.4};
    cout << "Array of float: ";
    for (int i = 0; i < valuesFloatCount; i++)
    {
        cout << valuesFloat[i] << " ";
    }
    cout << endl << endl;
    delete[] valuesFloat;

    // Task 1.1.5.2 ///////////////////////////////////////////////////////////
    int valuesBoolCount = 5;
    bool* valuesBool = new bool[valuesFloatCount] {true, true, false, true, false};
    cout << "Array of bool: ";
    for (int i = 0; i < valuesBoolCount; i++)
    {
        if (valuesBool[i])
        {
            cout << "true" << " ";
        }
        else
        {
            cout << "false" << " ";
        }
    }
    cout << endl << endl;
    delete[] valuesBool;

    // Task 1.1.5.3 ///////////////////////////////////////////////////////////
    int symbolsCount = 0;
    cout << "Enter char array size: ";
    cin >> symbolsCount;
    cout << endl;
    char* symbols = new char[symbolsCount];
    for (int i = 0; i < symbolsCount; i++)
    {
        cout << "Enter symbol[" << i << "]: ";
        cin >> symbols[i];
    }
    cout << endl;
    cout << "Your char array is: ";
    for (int i = 0; i < symbolsCount; i++)
    {
        cout << symbols[i] << " ";
    }
    cout << endl << endl;
    delete[] symbols;

    // Task 1.1.5.4 ///////////////////////////////////////////////////////////
	const int numsFloatCount = 10;
    float* numsFloat = new float[numsFloatCount] 
    {
        1.2, 6.2, 1.7, 3.8, 7.3,
        9.2, 0.5, -9.2, 2.5, 4.6
    };
    cout << "Array of float: ";
    for (int i = 0; i < numsFloatCount; i++)
    {
        cout << numsFloat[i] << " ";
    }
    cout << endl << endl;
    Sort(numsFloat, numsFloatCount);
    cout << "Sorted array of float: ";
    for (int i = 0; i < numsFloatCount; i++)
    {
        cout << numsFloat[i] << " ";
    }
    cout << endl << endl;
    delete[] numsFloat;

    // Task 1.1.5.5 ///////////////////////////////////////////////////////////
    const int numsCount = 10;
    int* numbers = new int[numsCount] {1, 5, -9, 0, 4, 5, 6, 2, 3, 7};
    cout << "Array of int: ";
    for (int i = 0; i < numsCount; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl << endl;
    int index = 0;
    int searchingElement = 0;
    cout << "Enter searching value: ";
    cin >> searchingElement;
    cout << endl;
    if (Search(numbers, numsCount, searchingElement, index))
    {
        cout << "Index of searching value " << index;
        cout << " is: " << searchingElement << endl << endl;
    }
    else
    {
        cout << searchingElement << " not floun in array" << endl << endl;
    }
    delete[] numbers;

    // Task 1.1.5.6 ///////////////////////////////////////////////////////////
    const int charactersCount = 15;
    char* characters = new char[charactersCount] 
    {
        '1', 'h', '!', '6', 'l',
        '#', '(', 'y', '*', '5',
        'x', '0', '=', 'p', '+'
    };
    cout << "Array of char: ";
    for (int i = 0; i < charactersCount; i++)
    {
        cout << characters[i] << " ";
    }
    cout << endl << endl;
    cout << "All letters in your array: " << endl << endl;
    SearchLetters(valuesChar, valuesCharCount);
    cout << endl << endl;
    delete[] characters;

    // Task 1.1.5.7 ///////////////////////////////////////////////////////////
    const int arraysCount = 3;
    int* arraysCounts = new int[arraysCount] { 5, 8, 13 };
    for (int i = 0; i < arraysCount; i++)
    {
        PrintRandomArray(arraysCounts[i]);
    }
    delete[] arraysCounts;
    
    // Task 1.1.5.8 ///////////////////////////////////////////////////////////
    PrintEnterArrayCounts(15);
    PrintEnterArrayCounts(20);

    system("pause");
} 