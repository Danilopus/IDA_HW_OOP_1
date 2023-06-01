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



// Homework XXX ----------------------------------------------------	

//Task 1
static void Task_1()
{
	std::vector<Fraction*> Available_fractions;
	Fraction fraction_1(5, 7, Available_fractions), fraction_2(7,19, Available_fractions);
	//std::vector<Fraction*> Available_fractions(&fraction_1, &fraction_2);
	
	fraction_1.ShowMethods();	
	std::cout << "choose a method: ";
	int action = Get_Int_Positive();	
	fraction_1.ShowAvailableFractions(Available_fractions);
	std::cout << "\n\nchoose fraction 1: ";
	int fraction_index_1 = Get_Int_Positive();
	std::cout << "\n\nchoose fraction 2: ";
	int fraction_index_2 = Get_Int_Positive();
	
	fraction_index_1--;
	fraction_index_2--;
	switch (action)
	{
	case 1: Available_fractions[fraction_index_1]->Add(*Available_fractions[fraction_index_2]); break;
	case 2: Available_fractions[fraction_index_1]->Subtract(*Available_fractions[fraction_index_2]); break;
	case 3: Available_fractions[fraction_index_1]->Multiply(*Available_fractions[fraction_index_2]); break;
	case 4: Available_fractions[fraction_index_1]->Divide(*Available_fractions[fraction_index_2]); break;
	}
	
		
	std::cout << "\nresult - > ";
	//Available_fractions[Available_fractions.size() - 1]->ShowValues();
	Available_fractions[Available_fractions.size()-1]->ShowValues();
}
//Task 2
void Task_2(){}
//Task 3
void Task_3() {}


// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	//setlocale(LC_CTYPE, "Russian");
	//system("mode con cols=110 lines=40"); 

	const int menu_elements_number = 2;
	//Main_menu MainMenu(menu_elements_number);
	Main_menu MainMenu;	
	MainMenu.AddElement("OOP Home Work 01: Intro");	// Homework name
	MainMenu.AddElement("Fractions");						// Menu element 1
	MainMenu.AddElement("XXX");						// Menu element 2
	MainMenu.AddElement("XXX");

	do 
	{		
		MainMenu.Show_menu();
		//MainMenu.User_Choice_Handle(_getch());
		if (!MainMenu.User_Choice_Handle())	break;
				
		_getch();	
		//std::cout << "\n\n";
		//system("pause");
	} while (true);
	return 0;
}

