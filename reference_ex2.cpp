#include<iostream>

int& function() { // 리턴 타입이 레퍼런스이다.
	int a = 2; // 지역변수 ( 지역변수를 리턴하지 않게 해야함 )
	return a;
}; // 레퍼런스를 리턴하는 함수 이건 오류걸림 왜냐면 function안에 정의되어 있는 a는 함수의 리턴과 함께 사라지기 때문에
   // 본체는 이미 사라졌지만 별명만 남아있는 상황이기 때문에 오류걸림
   // ★★★ 즉 레퍼런스를 리턴하는 함수에서 지역 변수의 레퍼런스를 리턴하지 않도록 조심해야한다.

int& function2(int& a) {
	a = 5;
	return a;
}

// 상수 리터럴을 참조하는 방법

int function3() {
	int a = 5;
	return a;
}

int main() {
	// 상수에 대한 참조자

	//int& ref = 4; // 상수 자체가 리터럴이기 때문에 참조 불가능 (상수리터럴)
	// 리터럴 : 변할 수 없는 값

	const int& ref = 4; // 상수 참조자 선언 -> const 타입& 해야 리터럴 선언가능
	std::cout << ref << std::endl;

	// 레퍼런스의 배열과 배열의 레퍼런스
	// C++ 규정: 레퍼런스의 레퍼런스,레퍼런스의 배열, 레퍼런스의 포인터는 존재할 수 없다.
	// 주소값이 존재한다라는 의미는 해당 원소가 메모리 상에서 존재한다 라는 의미와 같습니다.
	// 하지만 레퍼런스는 특별한 경우가 아닌 이상 메모리 상에서 공간을 차지 하지 않습니다.따라서
	// 이러한 모순 때문에 레퍼런스들의 배열을 정의하는 것은 언어 차원에서 금지가 되어 있는 것

	// ★★★ 레퍼런스의 배열은 불가능 , 배열의 레퍼런스는 가능

	int arr[3] = { 1, 2, 3 };
	int(&ref_arr)[3] = arr; // 배열의 레퍼런스
	// ★★★ 배열의 레퍼런스의 경우 참조하기 위해선 반드시 배열의 크기를 명시해야함
	// ex) int (&ref_arr)[3] <= 크기 

	ref_arr[0] = 2;
	ref_arr[1] = 3;
	ref_arr[2] = 1;

	std::cout << arr[0] << arr[1] << arr[2] << std::endl; // 2 3 1 출력

	int arr2[3][2] = {1,2,3,4,5,6};
	int(&ref_arr2)[3][2] = arr2; // 2차원 배열 레퍼런스

	std::cout << ref_arr2[0][0] << std::endl; // 1출력 

	// ★★★ 레퍼런스를 리턴하는 함수
	int b = function();
	std::cout <<"b:" << b << std::endl;

	// ★★★ 상수리터럴을 참조하는 방법 -> const
	const int& c = function3();
	std::cout << "c:" << c << std::endl;
	// ★★★ 로 상수 레퍼런스로 리턴값을 받게되면 해당 리턴값의 생명이 연장됩니다

	return 0;
}