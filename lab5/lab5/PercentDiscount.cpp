#include "PercentDiscount.h"

void PercentDiscount::SetPercent(const int percent)
{
	if (percent < 0 || percent > 100)
	{
		string message = "����� " + to_string(percent)
			+ " �� ������ � ���������� �������� [0, 100]"
			+ "\n� �� ����� ���������� ������ ������ � ���������";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_percent = percent;
}

int PercentDiscount::GetPercent()
{
	return _percent;
}

PercentDiscount::PercentDiscount(const int percent,
	const CategoryType& category) : DiscountBase(category)
{
	SetPercent(percent);
}

double PercentDiscount::Calculate(Product* product)
{
	if (product->GetCategory() == this->GetCategory())
	{
		return product->GetCost() - product->GetCost() 
			* this->GetPercent() / 100;
	}
	return product->GetCost();
}
