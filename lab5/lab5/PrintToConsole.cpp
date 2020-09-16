#include "PrintToConsole.h"

// ����� �������������� ������ ����� ���������
void PrintLine()
{
    cout << "___________________________";
    cout << "___________________________";
    cout << "__________________________" << endl << endl;
}

void PrintInitials(Person* person)
{
	cout << person->GetSurname() << " ";
	cout << person->GetName() << " ";
	cout << person->GetPatronymic() << endl << endl;
}

void ShowCheckWithDiscount(DiscountBase* discount,
	Product* products, int productsCount)
{
	for (int i = 0; i < productsCount; i++)
	{
		cout << products[i].GetName() << " ������ ����: ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << products[i].GetCost() << " ����� ����: ";
		if (products[i].GetCategory() == discount->GetCategory())
		{
			cout << discount->Calculate(&products[i]);
		}
		else
		{
			cout << products[i].GetCost();
		}
		cout << endl;
	}
	cout << endl;
}