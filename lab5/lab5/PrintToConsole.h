#pragma once
#include <iostream>
#include "Person.h"
#include "User.h"
#include "DiscountBase.h"
#include "ValueCorrector.h"

using namespace std;

void PrintLine();

void PrintInitials(Person* person);

void PrintMessageAboutEntering(User* loginedUser);

void ShowCheckWithDiscount(DiscountBase* discount,
	Product* products, int productsCount);