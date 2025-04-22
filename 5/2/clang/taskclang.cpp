#include<iostream>
#include<vector>

int more(std::vector<int> arr, int num) {
	int num1 = 0;
	for (int i = 0; i < 9; i++) {
		if (arr[i] > num) {
			num1 += 1;
		}
		else {
			continue;
		}
	}
	return num1;
}

int main(){
	setlocale(LC_ALL, "Russian");


	std::vector<int> arr = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };

	int num;
	std::cout << "Введите точку отсчёта: ";
	std::cin >> num;

	std::cout << "Количество элементов в массиве больших, чем " << num << ": " << more(arr, num);
	return 0;
}