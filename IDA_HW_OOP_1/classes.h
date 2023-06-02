#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <windows.h>

extern void Task_1();
extern void Task_2();

class Main_menu
{
	std::vector<std::string> _menu_elements;
public:
	void AddElement(std::string menu_element){	_menu_elements.push_back(menu_element);	}
	void Show_menu();
	int User_Choice_Handle();
	void User_Choice_Handle(int key_code);
};

class Fraction
{
//private:
	int _numerator=1;
	int _denominator=1;
	//Fraction* Available_fractions;
	//std::vector<Fraction*>* Available_fractions;
	int MaxCommonDivider(int a, int b);
	void Fraction_reduction();
public:	
	Fraction(int A1, int A2, std::vector<Fraction*>& Available_fractions);// : _numerator(A1), _denominator(A2){	Available_fractions.push_back(this); Fraction_reduction();	}
	Fraction(std::vector<Fraction*>& Available_fractions) {	Available_fractions.push_back(this); }
	void Set_numerator(int numerator){	_numerator = numerator;	}
	void Set_denominator(int denominator){	_denominator = denominator;	}
	int Get_numerator()	{	return _numerator;	}
	int Get_denominator(){	return _denominator;	}
	void ShowValues(){	std::cout << this->Get_numerator() << " / " << this->Get_denominator();	}
	int ShowMethods();
	void ShowAvailableFractions(std::vector<Fraction*> Available_fractions);	
	Fraction* Add(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions);
	Fraction* Subtract(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions);
	Fraction* Multiply(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions);
	Fraction* Divide(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions);	
};

class PhoneBook_logical_unit
{
	std::string _FIO;
	std::string _home_number;
	std::string _work_number;
	std::string _mobile_number;
	std::string _comments;
public:
	PhoneBook_logical_unit();
	PhoneBook_logical_unit(std::string FIO, std::string home_number, std::string work_number, std::string mobile_number, std::string comments);
	std::string GetFIO() { return _FIO; }
	void ShowInfo();
};

class PhoneBook
{
	//private:		
	std::vector<PhoneBook_logical_unit*> PhoneBook_logical_unit_list;
public:
	PhoneBook() {}	
	void AddEntry();
	void AddEntry(std::string FIO, std::string home_number, std::string work_number, std::string mobile_number, std::string comments);
	void List();
	void DeleteEntry();
	int SearchByName();
	void ShowMethods();
	void User_Choice_Handle();
};

//попробовать через наследование
//class PhoneBook : public PhoneBook_logical_unit;
