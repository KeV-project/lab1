#pragma once
#include <iostream>
#include "Person.h"
#include "DiscountBase.h"
#include "ValueCorrector.h"

using namespace std;

void PrintLine();

void PrintInitials(Person* person);

void ShowCheckWithDiscount(DiscountBase* discount,
	Product* products, int productsCount);