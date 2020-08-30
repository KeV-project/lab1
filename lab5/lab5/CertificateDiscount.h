#pragma once
#include "DiscountBase.h"

class CertificateDiscount : public DiscountBase
{
private:
	double _amount;
public:
	void SetAmount(const double amount);

	double GetAmount();

	CertificateDiscount(const double amount, const CategoryType& category);

	double Calculate(Product* product) override;
};