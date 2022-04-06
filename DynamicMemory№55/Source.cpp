//Персональный шаблон проекта С++
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define crtdarr(t, n, s) t * n = new t [s]

void fillArr(int arr[], int len, int min, int max);
template <typename T> void showArr(T arr[], int len);
template <typename T> T* addEl(T arr[], int len, int n);
template <typename T> T* delEl(T arr[], int len, int n);

int main() {
	setlocale(LC_ALL, "Russian");
	/*int* pn = new int;
	cout << pn << endl;
	*pn = 10;
	cout << *pn << endl;
	
	delete pn;
	pn = nullptr; //после очищения ячейки, нужно перенаправить указательн на нейтральную область оп

	pn = new int;
	*pn = 17;
	cout << pn << endl;
	cout << *pn << endl;*/
	/*	//Создание динамического массива
	int n;
	cout << "Введите длину массива: ";
	cin >> n;
	int* dArr = new int[n]; 
	fillArr(dArr, n, 10, 31);
	cout << "Массив длинною в " << n << ":\n";
	showArr(dArr, n);
	delete[] dArr; //Очищение указателя на динамический массив
	dArr = nullptr;
	crtdarr(int, myDArr, n);*/ // int * myDArr = new int[n];   Вызываем макрос = как работает препроцессор

	// Задача. 1. Создайте функцию, которая принимает динамический массив, длину и  число. После этого длина массива увеличивается на переданное число
	/*cout << "Задача 1.\nВведите длину массива: ";
	int size1;
	cin >> size1;
	int* z1 = new int[size1];
	fillArr(z1, size1, 10, 31);
	cout << "Изначальный массив:\n";
	showArr(z1, size1);
	z1 = addEl(z1, size1, 3);
	size1 += 3;
	cout << "Итоговый массив:\n";
	showArr(z1, size1);*/
	//Задача 2.
	cout << "Задача 2.\nВведите длину массива: ";
	int size2;
	cin >> size2;
	int* z2 = new int[size2];
	fillArr(z2, size2, 20, 41);
	cout << "Изначальный массив: ";
	showArr(z2, size2);
	z2 = delEl(z2, size2, 2);
	size2 -= 2;
	cout << "Итоговый массив:\n";
	showArr(z2, size2);

	return 0;
}
//Заполняет переданный массив случайными числами от min до max
void fillArr(int arr[], int len, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		arr[i] = rand() % (max - min) + min;
}
//Выводит массив в консоль
template <typename T> void showArr(T arr[], int len) {
	cout << "[";
	for (int i = 0; i < len; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
//Задача 1. Функция увеличивает длину массива
template <typename T> T* addEl(T arr[], int len, int n) {
	if (n <= 0)
		return arr;
	T* tmp = new T[len];
	for (int i = 0; i < len; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = new T[len + n];
	for (int i = 0; i < len; i++)
		arr[i] = tmp[i];
	delete[] tmp;
	return arr;
}
//Задача 2. Функция уменьшает длину массива 
template <typename T> T* delEl(T arr[], int len, int n) {
	if (n >= len || n <= 0)
		return arr;
	len -= n;
	T *tmp = new T[len];
	for (int i = 0; i < len; i++)
		tmp[i] = arr[i];
	delete[] arr;
	return tmp;
}
