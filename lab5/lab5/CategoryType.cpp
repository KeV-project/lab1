#include "CategoryType.h"

CategoryType GetCategoryType(const int numCategory)
{
	const int minCategoryNum = 0;
	const int maxCategoryNum = 6;
	ValueValidator::AssertValueInRange(numCategory, 
		minCategoryNum, maxCategoryNum,
		NotInRange, "��������� ������");
	switch (numCategory)
	{
		case 0:
		{
			return Laptops;
		}
		case 1:
		{
			return Smartphones;
		}
		case 2:
		{
			return TV;
		}
		case 3:
		{
			return Camcorders;
		}
		case 4:
		{
			return Appliances;
		}
		case 5:
		{
			return Smartwatch;
		}
		case 6:
		{
			return 	Acoustics;
		}
	}
}

string GetCategoryForWrite(const CategoryType& category)
{
	switch (category)
	{
		case Laptops:
		{
			return "�������";
		}
		case Smartphones:
		{
			return "��������";
		}
		case TV:
		{
			return "���������";
		}
		case Camcorders:
		{
			return "�����������";
		}
		case Appliances:
		{
			return "������� �������";
		}
		case Smartwatch:
		{
			return "����� ����";
		}
		case Acoustics:
		{
			return "��������";
		}
	}
}