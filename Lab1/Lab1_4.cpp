#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#define MAX 100
using namespace std;

//집합A와 B를 오름차순으로 sort시키기 위하여 quicksort를 사용
void quickSort(int *arr, int start, int last) {
	if (start >= last) {
		return;
	}
	int p = start;
	int i = start + 1;
	int j = last;
	int temp;
	while (i <= j) {
		while (i <= last && arr[i] < arr[p]) {
			i++;
		}
		while (j >= start + 1 && arr[j] > arr[p]) {
			j--;
		}
		if (i > j) {
			temp = arr[j];
			arr[j] = arr[p];
			arr[p] = temp;
		}
		else {
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	quickSort(arr, start, j - 1);
	quickSort(arr, j + 1, last);

}

//집합 A와 B를 출력하기 위한 메소드
void printArray(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

//random함수를 이용하고, goes를 통해 무작위로 입력받은 숫자들이 중복이 되지 않도록 처리함
void makeArray(int *arr1, int *arr2, int size1, int size2) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size1; i++) {
	make1:
		int num = rand() % MAX + 1;
		for (int j = 0; j < i; j++) {
			if (num == arr1[j]) {
				goto make1;
			}
		}
		arr1[i] = num;
	}

	for (int i = 0; i < size2; i++) {
	make2:
		int num = rand() % MAX + 1;
		for (int j = 0; j < i; j++) {
			if (num == arr2[j]) {
				goto make2;
			}
		}
		arr2[i] = num;
	}
}

//합집합과 교집합을 한번에 구하는 함수 합집합과 교집합은 배열추가의 편의를 위해 vector를 사용함
void makeUnion_intersection(int *arr1, int *arr2, int size1, int size2, vector<int> &arr3, vector<int> &arr4) {
	int index1 = 0;
	int index2 = 0;
	while (index1 < size1 && index2 < size2) {
		if (arr1[index1] < arr2[index2]) {
			arr3.push_back(arr1[index1]);
			index1++;
		}
		else if (arr1[index1] > arr2[index2]) {
			arr3.push_back(arr2[index2]);
			index2++;
		}
		else {
			arr3.push_back(arr1[index1]);
			arr4.push_back(arr1[index1]);
			index1++;
			index2++;
		}
	}
	if (index1 >= size1) {
		while (index2 < size2) {
			arr3.push_back(arr2[index2]);
			index2++;
		}
	}
	if (index2 >= size2) {
		while (index1 < size1) {
			arr3.push_back(arr1[index1]);
			index1++;
		}
	}
}


int main() {
	int N;
	int M;

	cin >> N;
	cin >> M;

	int *A = new int[N];
	int *B = new int[M];

	vector<int> U;
	vector<int> I;

	makeArray(A, B, N, M);
	cout << "집합 A- ";
	quickSort(A, 0, N-1);
	printArray(A, N);

	cout << "집합 B- ";
	quickSort(B, 0, M-1);
	printArray(B, M);

	makeUnion_intersection(A, B, N, M, U, I);

	cout << "합집합- ";
	for (int i = 0; i < U.size(); i++) {
		cout << U[i] << " ";
	}
	cout << "\n";

	cout << "교집합- ";
	for (int i = 0; i < I.size(); i++) {
		cout << I[i] << " ";
	}
	cout << "\n";
	
	return 0;
}