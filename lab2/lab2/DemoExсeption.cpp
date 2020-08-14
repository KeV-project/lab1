#include <iostream>
#include "DemoEx�eption.h"
#include "Output.h"

using namespace std;

// ��������� ������ ������������ �����
void Sort(double* values, const int valuesCount)
{
    if (valuesCount <= 0)
    {
        string message = "����� " + to_string(valuesCount) + 
            " �� �������� ������������� � �� ����� ���������� "
            "���������� ��������� � �������";
        char buf[255];
        strcpy_s(buf, message.c_str());
        throw exception(buf);
    }
	
    for (int i = 0; i < valuesCount; i++)
    {
        for (int j = 0; j < valuesCount; j++)
        {
            if (values[i] < values[j])
            {
                const double swap = values[i];
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