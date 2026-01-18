#include "Windows.h"
#include <iostream>
#include <vector>
#include "math.h"
#include <thread>

//std::vector<int>& the & makes it a reference to our object so it modifies that directly. COOL
//we learned something

void draw(std::vector<int>& arr, int j, int j1) {
	system("cls");
	for (const int value : arr) {
		for (int i = 0; i < value; i++) {

			std::cout << "*";
			
		}
		std::cout << "\n";
	}
}

void bubblesort(std::vector<int>& arr) {
	int size = arr.size();

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				draw(arr, j, j + 1);
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
		}
	}
}

void insertionsort(std::vector<int>& arr) {
	int size = arr.size();
	for (int i = 1; i < size; i++) {
		int key = arr[i]; //element to insert
		int j = i - 1; //index of last sorted element

		//shift elements to the right
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			draw(arr, j, j + 1);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			j--;
		}

		//insert key in correct position
		arr[j + 1] = key;
		draw(arr, j + 1, i);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}


void main() {
	std::vector<int> sort_these;
	for (int i = 0; i <= 10; i++) {
		int randomized = rand() % (100 + 1) + 1;
		sort_these.push_back(randomized);
	}
	insertionsort(sort_these);

	std::this_thread::sleep_for(std::chrono::seconds(10));
	exit(0);
}