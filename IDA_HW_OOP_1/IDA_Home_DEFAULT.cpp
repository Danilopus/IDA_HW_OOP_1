#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <conio.h>
//#include <array>
//My own headers
#include "Service functions.h"
#include "classes.h"



// Homework OOP_01 ----------------------------------------------------	

//std::vector<Fraction*> Available_fractions;

//Task 1 Fraction class demo
void Task_1()
{
	//Вариант хранения объектов класса Fraction в векторе объектов вне класса (из точки вызова, с передачей указателя на этот вектор)
	std::vector<Fraction*> Available_fractions;
	//static std::vector<Fraction*> Available_fractions;
	Fraction fraction_1(5, 7, Available_fractions), fraction_2(7,19, Available_fractions);
	
	do
	{	
		system("cls");
		std::cout << "***\tFraction class demo\n";
		fraction_1.ShowAvailableFractions(Available_fractions);
		std::cout << "\n";
		fraction_1.ShowMethods();
		std::cout << "choose a method: ";
		int action = Get_Int_Positive();

		//fraction_1.ShowAvailableFractions();
		//fraction_1.ShowAvailableFractions(Available_fractions);

		std::cout << "\nchoose operands:";
		std::cout << "\nchoose fraction 1: ";
		int fraction_index_1 = Get_Int_Positive();
		std::cout << "choose fraction 2: ";
		int fraction_index_2 = Get_Int_Positive();

		fraction_index_1--;
		fraction_index_2--;
		switch (action)
		{
		case 1: Available_fractions[fraction_index_1]->Add(*Available_fractions[fraction_index_2], Available_fractions); break;
		case 2: Available_fractions[fraction_index_1]->Subtract(*Available_fractions[fraction_index_2], Available_fractions); break;
		case 3: Available_fractions[fraction_index_1]->Multiply(*Available_fractions[fraction_index_2], Available_fractions); break;
		case 4: Available_fractions[fraction_index_1]->Divide(*Available_fractions[fraction_index_2], Available_fractions); break;
		}
		std::cout << "\nresult - > ";
		//Available_fractions[Available_fractions.size() - 1]->ShowValues();
		Available_fractions[Available_fractions.size() - 1]->ShowValues();
		std::cout << "\n\nEsc - for exit, any key to continue";
	} while (_getch() != 27);
}

//Task 2 PhoneBook class demo
void Task_2()
{
	PhoneBook PhoneBook_1;
	PhoneBook_1.AddEntry("Ishutinov Daniil", "+3432152525", "+3433257799", "+79122824444", "Vilonova 8-125");
	PhoneBook_1.AddEntry("Makarova Irina", "(343)2152525", "3257799", "+791228255555", "Lenina 99-85");
	PhoneBook_1.AddEntry("Michael Jackson", "+49(10)2152525", "777799", "+1001755555", "New-York");

	do
	{
		system("cls");
		std::cout << "***\tPhoneBook class demo\n";
		PhoneBook_1.ShowMethods();
		PhoneBook_1.User_Choice_Handle();
		std::cout << "\n\nEsc - for exit, any key to continue";
	} while (_getch() != 27);
}

//Task 3
void Task_3() {}


// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	//setlocale(LC_CTYPE, "Russian");
	//system("mode con cols=60 lines=40"); 

	const int menu_elements_number = 2;
	Main_menu MainMenu;	
	MainMenu.AddElement("OOP Home Work 01: Intro");	// Homework name
	MainMenu.AddElement("Fractions");				// Menu element 1
	MainMenu.AddElement("Phonebook");				// Menu element 2
	//MainMenu.AddElement("XXX");

	do 
	{		
		MainMenu.Show_menu();
		if (!MainMenu.User_Choice_Handle())	break;
	} while (true);
	return 0;
}

