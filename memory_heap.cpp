#include<iostream>

int main() {
	int* p = new int; // c++���� malloc �� �����Ǵ� ������ �޸𸮸� �Ҵ� (new int)
	*p = 10;

	std::cout << *p << std::endl;

	delete p; // c++���� free�� �����Ǵ� ������ �޸𸮸� ����

	// �ڡ� new�� �迭 �Ҵ��ϱ� 

	int arr_size;
	std::cout << "array size : ";
	std::cin >> arr_size;
	int *list = new int[arr_size];

	for (int i = 0; i < arr_size; i++) {
		std::cin >> list[i];
	}

	for (int i = 0; i < arr_size; i++) {
		std::cout << i << "th element of list : " << list[i] << std::endl;
	}

	delete[] list;

	return 0; 
}