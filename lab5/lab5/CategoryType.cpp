#include "CategoryType.h"

CategoryType GetCategoryType(const int numCategory)
{
	const int minCategoryNum = 0;
	const int maxCategoryNum = 6;
	ValueValidator::AssertValueInRange(numCategory, 
		minCategoryNum, maxCategoryNum,
		NotInRange, "категорию товара");
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
			return "ноутбук";
		}
		case Smartphones:
		{
			return "смартфон";
		}
		case TV:
		{
			return "телефизор";
		}
		case Camcorders:
		{
			return "видеокамера";
		}
		case Appliances:
		{
			return "бытовая техника";
		}
		case Smartwatch:
		{
			return "умные часы";
		}
		case Acoustics:
		{
			return "акустика";
		}
	}
}