#include "Product.h"

void Product::SetName(const string& name)
{
	this->_name = name;
}

void Product::SetCategory(const CategoryType& category)
{
	this->_category = category;
}

void Product::SetCost(const float cost)
{
	const float minCost = 0;
	const float maxCost = 100000;
	ValueValidator::AssertValueInRange(cost, 
		minCost, maxCost, 
		NotInRange, "стоимость товара");
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
	const CategoryType& category, const float cost)
{
	SetName(name);
	SetCategory(category);
	SetCost(cost);
}
