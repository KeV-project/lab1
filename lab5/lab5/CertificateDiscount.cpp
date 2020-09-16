#include "CertificateDiscount.h"

void CertificateDiscount::SetAmount(const float amount)
{
	const float minAmount = 0.00;
	const float maxAmount = 40000.00;
	ValueValidator::AssertValueInRange(amount, 
		minAmount, maxAmount,
		NotInRange, "размер сертификата");
	this->_amount = amount;
}

float CertificateDiscount::GetAmount()
{
	return _amount;
}

CertificateDiscount::CertificateDiscount(const float amount,
	const CategoryType& category) : DiscountBase(category)
{
	SetAmount(amount);
}

double CertificateDiscount::Calculate(Product* product)
{
	if (product->GetCategory() == GetCategory())
	{
		if (_amount >= product->GetCost())
		{
			_amount -= product->GetCost();
			return 0;
		}
		else if (_amount < product->GetCost())
		{
			float newCost = product->GetCost() - _amount;
			_amount = 0;
			return newCost;
		}
	}
	return product->GetCost();
}