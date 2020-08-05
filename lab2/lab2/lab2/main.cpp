#include <iostream>
using namespace std;

// ����� �������������� ������ ����� ���������
void PrintLine()
{
    cout << "___________________________";
    cout << "___________________________";
    cout << "__________________________" << endl << endl;
}

void ShowValues(double* values, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << values[i] << " ";
    }
    cout << endl << endl;
}

// ��������� ������ ������������ �����
void Sort(double* values, int valuesCount)
{
    if (valuesCount < 0)
    {
        throw exception("Exception catched!");
    }
    double swap;
    for (int i = 0; i < valuesCount; i++)
    {
        for (int j = 0; j < valuesCount; j++)
        {
            if (values[i] < values[j])
            {
                swap = values[i];
                values[i] = values[j];
                values[j] = swap;
            }
        }
    }
}

// ������������� ������ ����������
void DemoSort()
{
    const int valuesCount = 5;
    double* values = new double[valuesCount] 
    {
        100.0, 249.0, 12.0, 45.0, 23.5
    };
    try
    {
        cout << "������������ ������ ��������� ��� ������:" << endl << endl;
        Sort(values, valuesCount);
        ShowValues(values, valuesCount);
        cout << "������������ ��������� �������������� ��������:";
        cout << endl << endl;
        Sort(values, -1);
        ShowValues(values, valuesCount);
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl << endl;
    }
    delete[] values;
}

void main()
{
	setlocale(LC_ALL, "rus");

    DemoSort();
    PrintLine();

	system("pause");
}