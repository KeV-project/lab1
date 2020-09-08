#pragma once
#include "CategoryType.h"
#include "Product.h"

class DiscountBase
{
private:
	CategoryType _category;
	void SetCategory(const CategoryType& category);

public:
	CategoryType GetCategory();
	virtual double Calculate(Product* product) = 0;

protected:
	DiscountBase(const CategoryType& category);
};

