#pragma once
#include <iostream>
#include "ValueValidator.h"
#include "CategoryType.h"

using namespace std;

class Product
{
private:
	string _name;
	CategoryType _category;
	float _cost;

public:
	void SetName(const string& name);
	void SetCategory(const CategoryType& category);
	void SetCost(float cost);

	string GetName();
	CategoryType GetCategory();
	float GetCost();

	Product();
	Product(const string& name, 
		const CategoryType& category, const float cost);
};


