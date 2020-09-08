#pragma once
#include "ValueValidator.h"
#include "DiscountBase.h"

class PercentDiscount : public DiscountBase
{
private:
	int _percent;

public:
	void SetPercent(const int percent);

	int GetPercent();

	PercentDiscount(const int percent, const CategoryType& category);

	double Calculate(Product* product) override;
};


