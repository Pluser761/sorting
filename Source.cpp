#include <locale.h> 
#include <windows.h> 
#include <math.h> 
#include <iostream> 
#include <stdio.h>
#include <time.h>
#include <fstream>

//unicode fix

using namespace std;

#define mPROGRAMM1 "\n [1] - Об Авторе\n" 
#define mPROGRAMM2 "\n [2] - Получить входные данные\n" 
#define mPROGRAMM3 "\n [3] - Сравнение эффективности\n" 
#define mEXIT "\n [0] - Выход\n" 
#define mCHOOSE "\n --> Ваш выбор: " 

#define mPROGRAMM2_1 "    [1] - Автогенерация массива\n"
#define mPROGRAMM2_2 "\n    [2] - Считать из файла\n"

struct sorting
{
	int ischange, ismem;
	unsigned int istime;
};

void printarray(int arg[], int length) {
	for (int index = 0; index < length; index++)
		arg[index] = rand() % 100;
	for (int index = 0; index < length; index++)
		cout << ' ' << arg[index];
	cout << endl;
}


sorting func1(int arg[], int size) {
	int n = 0;
	sorting ret;

	unsigned int start_time = clock();

	for (int i = 1; i < size; i++)
	{
		int value = arg[i];
		int index = i;
		while ((index > 0) && (arg[index - 1] > value))
		{
			arg[index] = arg[index - 1];
			index--;
			n++;
		}
		arg[index] = value;
	}

	ret.istime = clock() - start_time;
	ret.ischange = n;
	ret.ismem = 0;
	return ret;
}

sorting func2(int arg[], int size) {
	int n = 0, min;
	sorting ret;

	unsigned int start_time = clock();

	for (int i = 0; i < size - 1; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (arg[j] < arg[min]) min = j;
			n++;
		}
		swap(arg[i], arg[min]);
	}

	ret.istime = clock() - start_time;
	ret.ischange = n;
	ret.ismem = 0;
	return ret;
}

sorting func3(int arg[], int size) {
	int n = 0;
	sorting ret;

	unsigned int start_time = clock();

	for (int i = 0; i < size - 1; i++)
		for (int j = size - 1; j > i; j--) 
			if (arg[j - 1] > arg[j])
			{
				swap(arg[j - 1], arg[j]);
				n++;
			}

	ret.istime = clock() - start_time;
	ret.ischange = n;
	ret.ismem = 0;
	return ret;
}

int *t_arr(int arr[], int size) {
	int *res = new int[100000];
	memcpy(res, arr, 100000 * sizeof(int));
	return res;
}

void the_best(sorting arr[])
{
	int t = 0, m = 0, n = 0;

	for (int i = 1; i < 3; i++) {
		if (arr[i].istime < arr[t].istime) t = i;
		if (arr[i].ismem < arr[m].ismem) m = i;
		if (arr[i].ischange < arr[n].ischange) n = i;
	}

	cout << "Самый быстрый алгоритм - ";
	switch (t)
	{
	case 0:
		cout << "сортировка методом прямого включения." << endl;
		break;
	case 1:
		cout << "сортировка методом прямого выбора." << endl;
		break;
	case 2:
		cout << "сортировка методом прямого обмена." << endl;
		break;
	default:
		break;
	}

	cout << "Самый короткий алгоритм - ";
	switch (n)
	{
	case 0:
		cout << "сортировка методом прямого включения." << endl;
		break;
	case 1:
		cout << "сортировка методом прямого выбора." << endl;
		break;
	case 2:
		cout << "сортировка методом прямого обмена." << endl;
		break;
	default:
		break;
	}

	cout << "Самый экономный алгоритм - ";
	switch (m)
	{
	case 0:
		cout << "сортировка методом прямого включения." << endl;
		break;
	case 1:
		cout << "сортировка методом прямого выбора." << endl;
		break;
	case 2:
		cout << "сортировка методом прямого обмена." << endl;
		break;
	default:
		break;
	}
}

int main() {
	srand(time(0));

	setlocale(LC_ALL, "Russian");
	int choose = 0, choose1 = 0, n = 0, ik = 0, im = 0;
	int mas[100000], *tempmas;
	sorting arr[3];
	ifstream ifs("mas.txt");

	cout << mPROGRAMM1;
	cout << mPROGRAMM2;
	cout << mPROGRAMM3;
	cout << mEXIT;
	cout << mCHOOSE;
	cin >> choose;
	cout << endl;

	while (choose != 0) {
		switch (choose) {

		case 1: {
			cout << " Студент : Коткова Диана Романовна " << endl;
			cout << " Группа  : 121171" << endl;
			cout << " Курс    : 2 " << endl;
			break; }

		case 2: {
			cout << mPROGRAMM2_1;
			cout << mPROGRAMM2_2;
			cout << ' ' << mCHOOSE;
			cin >> choose1;
			switch (choose1) {

			case 1: {
				cout << " Введите размер массива : ";
				cin >> n;
				cout << " Сгенерированный массив :";
				printarray(mas, n);
				break; }

			case 2: {
				n = 0;
				int i = 0;
				int temp = 0;
				int count = 0;
				while (ifs >> mas[i])
				{
					n++;
					i++;
				}
				cout << endl;
				cout << " Полученный массив :";
				for (int i = 0; i < n; i++) cout << ' ' << mas[i];
				cout << endl;
				break; }
			}

			break; }

		case 3: {
			cout << "\n" << endl;

			cout << "*Сортировка методом прямого включения " << endl;
			tempmas = t_arr(mas, n);
			arr[0] = func1(tempmas, n);
			cout << " Время выполнения,c: " << arr[0].istime << endl;
			cout << " Количество обменов: " << arr[0].ischange << endl;
			cout << " Затраченное ОЗУ   : " << arr[0].ismem << endl;
			cout << "\n" << endl;

			cout << "*Сортировка методом прямого выбора " << endl;
			tempmas = t_arr(mas, n);
			arr[1] = func2(tempmas, n);
			cout << " Время выполнения,c: " << arr[1].istime << endl;
			cout << " Количество обменов: " << arr[1].ischange << endl;
			cout << " Затраченное ОЗУ   : " << arr[1].ismem << endl;
			cout << "\n" << endl;

			cout << "*Сортировка методом прямого обмена " << endl;
			//tempmas = t_arr(mas, n);
			arr[2] = func3(mas, n);
			cout << " Время выполнения,c: " << arr[2].istime << endl;
			cout << " Количество обменов: " << arr[2].ischange << endl;
			cout << " Затраченное ОЗУ   : " << arr[2].ismem << endl;
			cout << "\n" << endl;

			cout << " Отсортированный массив :";
			for (int i = 0; i < n; i++) cout << ' ' << mas[i];
			cout << endl;

			the_best(arr);
			break; }
		}
		cout << mCHOOSE;
		cin >> choose;
		cout << endl;

	}

	cout << "\n";
	cout << "   Вы вышли из программы " << endl;
	Sleep(750);
	//cout << "\n";
	//system("pause");
	return 0;
}