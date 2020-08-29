#include "Output.h"

// ¬ывод разделительной полосы между задани€ми
void PrintLine()
{
    cout << "___________________________";
    cout << "___________________________";
    cout << "__________________________" << endl << endl;
}

void ShowName(Person* person)
{
    cout << person->GetSurname() << " ";
    cout << person->GetName() << " ";
    cout << person->GetPatronymic() << endl << endl;
}