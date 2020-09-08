#include "PrintToConsole.h"

// ¬ывод разделительной полосы между задани€ми
void PrintLine()
{
    cout << "___________________________";
    cout << "___________________________";
    cout << "__________________________" << endl << endl;
}

void PrintInitials(Person* person)
{
	cout << person->GetSurname() << " ";
	cout << person->GetName() << " ";
	cout << person->GetPatronymic() << endl << endl;
}