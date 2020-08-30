#include "DiscountBase.h"

void DiscountBase::SetCategory(const CategoryType& category)
{
	this->_category = category;
}

CategoryType DiscountBase::GetCategory()
{
	return _category;
}

DiscountBase::DiscountBase(const CategoryType& category)
{
	SetCategory(category);
}

void ShowCheckWithDiscount(DiscountBase* discount, 
	Product* products, int productsCount)
{
	for (int i = 0; i < productsCount; i++)
	{
		cout << products[i].GetName() << " Старая цена: " << products[i].GetCost() << " Новая цена: ";
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