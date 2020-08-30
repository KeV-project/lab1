#pragma once
#include <iostream>
#include "CategoryType.h"

using namespace std;

class Product
{
private:
	string _name;
	CategoryType _category;
	double _cost;

public:
	void SetName(const string& name);
	void SetCategory(const CategoryType& category);
	void SetCost(const double cost);

	string GetName();
	CategoryType GetCategory();
	float GetCost();

	Product();
	Product(const string& name, 
		const CategoryType& category, const double cost);
};


