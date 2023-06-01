#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <windows.h>

extern void Task_1();

class Main_menu
{
	std::vector<std::string> _menu_elements;
	//int _menu_elements_number=0;

public:
	//Main_menu(const int menu_elements_number, std::string menu_element)
	//Main_menu(const int menu_elements_number): _menu_elements_number(menu_elements_number)
	//Main_menu(){}

	void AddElement(std::string menu_element)
	{
		//_menu_elements_number++;
		_menu_elements.push_back(menu_element);
	}

	void Show_menu()
	{
		system("cls");
		std::cout << "\n\t***\t" << _menu_elements[0] << "\t***\n\n\t\n\nChoose an option: \n";
		//for (int i=1; i< _menu_elements_number; i++)		
		for (int i = 1; i < _menu_elements.size(); i++)
		std::cout << "\n" <<i<<". " << _menu_elements[i];
		std::cout << "\n\n 0. Exit\n";
		std::cout << "\nYour choice: ";
	}

	int User_Choice_Handle()
	{
		int choice = 0;
		choice = Get_Int_Positive();
		std::cout << "\n";
		// Обработка выбора пользователя
		if (choice == 0) { std::cout << "\nGood By"; for (int j = 0; j < 50; j++) { Sleep(50 - j); std::cout << "y"; } std::cout << "e!"; Sleep(850);  return 0; }
		
		else if (choice == 1) Task_1();
		//else if (choice == 2) Power_of_number_through_pointer_demo();
		//else if (choice == 3) Sort_Array_from_N_demo();
		//else if (choice == 4) Search_First_Ordinary_in_Array_demo();

		else { std::cout << "\nSuch choice does not exist yet\n"; Sleep(1000); }
		return 1;
	}
	void User_Choice_Handle(int key_code)
		{
		switch (key_code)
		{
		case 1: break;
		//case:
		}
	}

};


class Fraction
{
//private:
	int _numerator=1;
	int _denominator=1;

	int MaxCommonDivider(int a1, int a2){}
	void Fraction_reduction() {}
public:
	// _numerator, _denominator
	//Fraction(int A1, int A2): _numerator(A1), _denominator(A2){}
	Fraction(int A1, int A2, std::vector<Fraction*>& Available_fractions) : _numerator(A1), _denominator(A2) 
	{
		Available_fractions.push_back(this);
	}
	Fraction(std::vector<Fraction*>& Available_fractions) { Available_fractions.push_back(this); }
	void Set_numerator(int numerator)
	{
		_numerator = numerator;
	}
	void Set_denominator(int denominator)
	{
		_denominator = denominator;
	}
	int Get_numerator()
	{
		return _numerator;
	}
	int Get_denominator()
	{
		return _denominator;
	}

	void ShowValues()
	{
		std::cout << this->Get_numerator() << " / " << this->Get_denominator();
	}
	int ShowMethods()
	{
		std::cout << "\nAvailable methods:";
		//std::cout << "\n1) Add\n2) Substract\n3) Multiply\n4) Divide\n";
		std::cout << "\n1) Add\t2) Substract\t3) Multiply\t4) Divide\n";
		//return Get_Int_Positive();
		return 0;
	}
	void ShowAvailableFractions(std::vector<Fraction*> Available_fractions)
	{
		std::cout << "Available fractions:";
		for (int i = 0; i < Available_fractions.size(); i++)
		{
			std::cout << "\nFraction" << i + 1 << " -> " << Available_fractions[i]->Get_numerator() << " / " << Available_fractions[i]->Get_denominator();
		}
	}
	
	Fraction* Add(Fraction another_Fraction)
	{
		Fraction* result_fraction = new Fraction;
		result_fraction->Set_numerator(_numerator * another_Fraction.Get_denominator() + another_Fraction.Get_numerator() * _denominator);
		result_fraction->Set_denominator(_denominator * another_Fraction.Get_denominator());
		Fraction_reduction();
		return result_fraction;
	}
	Fraction* Subtract(Fraction another_Fraction)
	{
		Fraction* result_fraction = new Fraction;
		result_fraction->Set_numerator(_numerator * another_Fraction.Get_denominator() - another_Fraction.Get_numerator() * _denominator);
		result_fraction->Set_denominator(_denominator * another_Fraction.Get_denominator());
		Fraction_reduction();
		return result_fraction;
	}
	Fraction* Multiply(Fraction& another_Fraction)
	{
		Fraction * result_fraction = new Fraction;
		result_fraction->Set_numerator(_numerator * another_Fraction.Get_numerator());
		result_fraction->Set_denominator(_denominator * another_Fraction.Get_denominator());
		Fraction_reduction();
		return result_fraction;
	}
	Fraction* Divide(Fraction another_Fraction)
	{
		Fraction* result_fraction = new Fraction;
		result_fraction->Set_numerator(_numerator * another_Fraction.Get_denominator());
		result_fraction->Set_denominator(_denominator * another_Fraction.Get_numerator());
		Fraction_reduction();
		return result_fraction;
	}

		
	
};

