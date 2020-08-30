#include "Product.h"

void Product::SetName(const string& name)
{
	this->_name = name;
}

void Product::SetCategory(const CategoryType& category)
{
	this->_category = category;
}

void Product::SetCost(const double cost)
{
	if (cost < 0 || cost > 100000)
	{
		string message = "����� " + to_string(cost)
			+ " �� ������ � ���������� �������� [0, 100000]"
			+ "\n� �� ����� ���������� ��������� ������";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_cost = cost;
}

string Product::GetName()
{
	return _name;
}

CategoryType Product::GetCategory()
{
	return _category;
}

float Product::GetCost()
{
	return _cost;
}

Product::Product()
{
	SetName("");
	SetCategory(TV);
	SetCost(0.0);
}

Product::Product(const string& name, 
	const CategoryType& category, const double cost)
{
	SetName(name);
	SetCategory(category);
	SetCost(cost);
}
