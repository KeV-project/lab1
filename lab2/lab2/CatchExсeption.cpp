#include <iostream>
#include "CatchExсeption.h"
#include "Output.h"

using namespace std;

//TODO: int to const?
// Сортирует массив вещественных чисел
void Sort(double* values, int valuesCount)
{
    if (valuesCount < 0)
    {
    	//TODO: В сообщении описывается, что исключение поймано,
    	//TODO: по факту отлов исключения должен происходить снаружи с помощью try-catch
    	//TODO: корректнее в сообщение укладывать информацию о типе ошибки для того,
    	//TODO: чтобы пользователь (программист) знал - что и где пошло не так +
        throw exception("ИСКЛЮЧЕНИЕ"
            "(Функция сортировки вещественных чисел):\n"
            "Количество элементов массива не может быть "
            "отрицательным числом");
    }
	//TODO: Нет смысла объявлять настолько заранее +
    //double swap;
    for (int i = 0; i < valuesCount; i++)
    {
        for (int j = 0; j < valuesCount; j++)
        {
            if (values[i] < values[j])
            {
                const double swap = values[i];
                values[i] = values[j];
                values[j] = swap;
            }
        }
    }
}

// Демонстрирует работу сортировки
void DemoSort()
{
    const int valuesCount = 5;
    double* values = new double[valuesCount]
    {
        100.0, 249.0, 12.0, 45.0, 23.5
    };
    try
    {
        cout << "Демонстрация работы программы без ошибок:" << endl << endl;
        Sort(values, valuesCount);
        ShowValues(values, valuesCount);
        cout << "Демонстрация обработки исключительной ситуации:";
        cout << endl << endl;
        Sort(values, -1);
        ShowValues(values, valuesCount);
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl << endl;
    }
    delete[] values;
}