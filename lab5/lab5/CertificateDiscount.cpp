#include "CertificateDiscount.h"

void CertificateDiscount::SetAmount(double amount)
{
	if (amount < 0 || amount > 10000)
	{
		string message = "����� " + to_string(amount)
			+ " �� ������ � ���������� �������� [0, 10000]"
			+ "\n� �� ����� ���������� ������ �����������";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_amount = amount;
}

double CertificateDiscount::GetAmount()
{
	return _amount;
}

CertificateDiscount::CertificateDiscount(const double amount,
	const CategoryType& category) : DiscountBase(category)
{
	SetAmount(amount);
}

double CertificateDiscount::Calculate(Product* product)
{
	if (product->GetCategory() == this->GetCategory())
	{
		if (_amount >= product->GetCost())
		{
			_amount = 0;
			return 0;
		}
		else if (_amount < product->GetCost())
		{
			float newCost = product->GetCost() - _amount;
			_amount = 0;
			return newCost;
		}
	}
	return product->GetCost();
}