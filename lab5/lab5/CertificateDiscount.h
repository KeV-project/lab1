#pragma once
#include "DiscountBase.h"
#include "ValueValidator.h"

class CertificateDiscount : public DiscountBase
{
private:
	float _amount;
public:
	void SetAmount(const float amount);

	double GetAmount();

	CertificateDiscount(const float amount, 
		const CategoryType& category);

	double Calculate(Product* product) override;
};