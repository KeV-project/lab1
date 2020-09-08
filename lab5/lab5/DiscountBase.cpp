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