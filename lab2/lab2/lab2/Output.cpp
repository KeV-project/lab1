#include <iostream>

using namespace std;

// ����� �������������� ������ ����� ���������
void PrintLine()
{
    cout << "___________________________";
    cout << "___________________________";
    cout << "__________________________" << endl << endl;
}

void ShowValues(double* values, int valuesCount)
{
    for (int i = 0; i < valuesCount; i++)
    {
        cout << values[i] << " ";
    }
    cout << endl << endl;
}