#include <iostream>

#include "Goods.h"
#include "Windows.h"
#include "Me_Error_size_memorry.h"
#include "My_Error_Range.h"

void test() throw(std::bad_exception);
void my_unexp();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {
		Goods a(5.2, 4);
		cout << a;

		++a;
		cout << a;
		--a;
		cout << a;
		a++;
		cout << a;
		a--;
		cout << a;

		cout << a.operator string();
	}
	catch (My_Error_Range* a) {
		std::cout << a->What();
	}

	try {
		Goods b(17.1, 2);

		cin >> b;
		cout << b;

		++b;
		cout << b;
		--b;
		cout << b;
		b++;
		cout << b;
		b--;
		cout << b;

		cout << b.operator string();
		cout << endl;
		b.Cost();
	}
	catch (std::out_of_range obj_1) {
		std::cout << obj_1.what();
	}

	try {
		int size(0);
		std::cout << "\n\nВведіть розмір масива: ";  std::cin >> size;

		if ((size < 0) || (size > 80'000'000))
			throw Me_Error_size_memorry("\nНевірно виділена пам’ять");		//генерування об'єкта винятка
		Goods* c = new Goods[size];
	}
	catch (Me_Error_size_memorry& obj_2) {		// зловлює помилку "Me_Error_size_memorry"
		std::cout << obj_2.What();
	}

	set_unexpected(my_unexp);

	try {	//захищений(контрольований) блок
		test();
	}
	catch (const std::bad_exception& e)		//зловлює помилку "std::bad_exception"
	{
		std::cerr << "\nCaught " << e.what() << '\n';
	}
	return 0;
}

void test() throw(std::bad_exception)
{
	throw std::bad_exception{};
}

void my_unexp() {
	throw;
}