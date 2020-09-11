#include "PercentDiscount.h"

void PercentDiscount::SetPercent(const int percent)
{
	const int minPercent = 0;
	const int maxPercent = 100;
	ValueValidator::AssertValueInRange(percent, 
		minPercent, maxPercent, 
		NotInRange, "размер скидки в процентах");
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
