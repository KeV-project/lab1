#include "CertificateDiscount.h"

void CertificateDiscount::SetAmount(const float amount)
{
	const float minAmount = 0;
	const float maxAmount = 10000;
	ValueValidator::AssertValueInRange(amount, 
		minAmount, maxAmount, "размер сертификата");
	this->_amount = amount;
}

double CertificateDiscount::GetAmount()
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
	if (product->GetCategory() == this->GetCategory())
	{
		if (_amount >= product->GetCost())
		{
			_amount = 0;
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