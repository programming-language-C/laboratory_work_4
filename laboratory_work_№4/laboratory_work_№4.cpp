#include <iomanip>
using namespace std;
#include <iostream>
#include <string>

//В одномерном массиве найти среднее арифметическое для элементов,
//расположенных между максимальным и минимальным.Если они следуют один за
//другим, считать его равным нулю.Количество элементов в массиве не более 200.
//Формат числа цц.ц.Массив распечатывать по десять элементов на строке.

double round_value(double value, int accuracy)
{
	int rounding_to = pow(10, accuracy);
	return round(value * rounding_to) / rounding_to;

}

int main()
{
	setlocale(LC_ALL, "ru");

	int count_elements_arr = 0;

	while (true)
	{
		cout << "Введите количество элементво в массиве (не больше 200): ";
		cin >> count_elements_arr;
		if (count_elements_arr > 200)
			cout << "Ошибка: количество элементов в массиве не должно превышать 200\n";
		else
			break;
	}


	//заполнение массива и вывод значений в консоль
	const int n = count_elements_arr;
	double* arr_of_numbers = new double[n];

	srand(time(NULL)); //рандомизация - инициализация ДСЧ
	cout << "Целочисленный массив из " << n << " случайных чисел:\n";
	string str_numbers_arr;
	int BORDER_RANDOMAZER = 100;
	for (int i = 0; i < n; i++)
	{
		double random_number = (double)(((double)rand() / (double)(RAND_MAX)) * BORDER_RANDOMAZER);
		arr_of_numbers[i] = round_value(random_number, 1);
		str_numbers_arr += "a[" + std::to_string(i) + "]=" + std::to_string(arr_of_numbers[i]);

		if ((i + 1) % 10 == 0)
		{
			str_numbers_arr += "\n";
		}
		else if (n - i != 1)
		{
			str_numbers_arr += ", ";
		}
	}
	cout << str_numbers_arr << "\n";


	//поиск максимума и минимума
	int max_arr_number = arr_of_numbers[0],
		min_arr_number = arr_of_numbers[0],
		index_max_arr_number = 0,
		index_min_arr_number = index_max_arr_number;
	for (int i = 1; i < n; i++)
	{
		if (arr_of_numbers[i] > max_arr_number)
		{
			max_arr_number = arr_of_numbers[i];
			index_max_arr_number = i;
		}
		if (arr_of_numbers[i] < min_arr_number)
		{
			min_arr_number = arr_of_numbers[i];
			index_min_arr_number = i;
		}
	}


	// определение интервала
	int index_initial, index_end;
	if (index_min_arr_number < index_max_arr_number)
	{
		index_initial = index_min_arr_number;
		index_end = index_max_arr_number;
	}
	else
	{
		index_initial = index_max_arr_number;
		index_end = index_min_arr_number;
	}

	// Подсчёт avg
	int count_number_between_max_min_numbers = abs(index_initial - index_end) - 1;
	double sum_numbers_arr_between_max_min_numbers = 0,
		avg_numbers_arr;
	if (count_number_between_max_min_numbers)
	{
		for (int i = index_initial + 1; i < index_end; i++)
		{
			sum_numbers_arr_between_max_min_numbers += arr_of_numbers[i];
		}
		avg_numbers_arr = sum_numbers_arr_between_max_min_numbers / count_number_between_max_min_numbers;
	}
	else
	{
		avg_numbers_arr = count_number_between_max_min_numbers;
	}

	cout << "Максимальное значение в массиве = " << max_arr_number << "\nиндекс: " << index_max_arr_number << "\n";

	cout << "Минимальное значение в массиве = " << min_arr_number << "\nиндекс: " << index_min_arr_number << "\n";

	cout << "Среднее арифметическое между максимальным и минимальным значением = " << avg_numbers_arr << "\n";

	system("PAUSE");
	return 0;
}
