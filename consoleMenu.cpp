#pragma once
#include "store.h"
#include "consoleMenu.h"
#include "consoleColours.h"

#include<conio.h>
#include<string>
#include<iostream>
#include<fstream>


#define TXTFILE "Libraries\\Documents\\Visual Studio 2010\\Projects\\Appstore\\app.dat"

int main()
{
	Store store;
	int option = 0;
	int selectedApp = 0;
	string name;
	store.loadFromFile();
	do
	{
		option = displayMainMenu();
		switch(option) {
			case 0:	
				clearScreen();
				cout<<'\n'<<"please enter app information\n";
				store.addApp();
				store.saveAllApps();
				clearScreen();
				break;
			case 1:
				clearScreen();	
				cout<<'\n'<<"select an app ID to delete record\n";
				store.displayAllApps();
				cin >> selectedApp;
				store.deleteApp(selectedApp);
				store.saveAllApps();
				clearScreen();
				break;
			case 2: 
				clearScreen();
				cout<<'\n'<<"select an app ID\n";
				store.displayAllApps();
				cin >> selectedApp;
				clearScreen();
				store.displayApp(selectedApp);
				system("pause");
				clearScreen();
				break;
			case 3:
				searchMenu(store);
				break;
			case 4:
				clearScreen();
				cout<<"case 4";
				break;
			case 5:
				cout<<'\n'<<"please enter app information\n";
				store.displayAllApps();
				break;
		}
	}while(option != 6);
	
}

int displayMainMenu()
{
	char key;
	int activeMenuLine=0;
	
	Console::gotoXY(25,3);
	std::cout << "    DISCOVERY MOBILE  M A I N    M E N U     ";
	Console::gotoXY(15,22);
	std::cout << "please use the up/down arrows to pick and option";
	Console::gotoXY(23,23);
	std::cout << "press enter to proceed";

	while(true)
	{
		for(int i = MIN_MENU_LINE; i <= MAX_MENU_LINE ; i++)
		{
			if(i != activeMenuLine)
			{
				Console::gotoXY(menuPosX,menuPosY[i]);
				Console::setColour(Console::WHITE, Console::BLACK);
				std::cout<< menu_items[i];
			}
			else
			{
				Console::gotoXY(menuPosX,menuPosY[i]);
				Console::setColour(Console::DARKPINK, Console::CYAN);
				std::cout<< menu_items_high[i];
			}
		}
		Console::gotoXY(48,23);

		key = _getch();
		if(key != RETURN) 
			activeMenuLine = changeLineBasedOnInput(key, activeMenuLine); 
		else
			return activeMenuLine;
	}
	return 0;
}

int changeLineBasedOnInput(char key, int activeMenuLine)
{
	if(char(key) == ARROW_UP)
	{
		activeMenuLine--;
		if(activeMenuLine < MIN_MENU_LINE)
			activeMenuLine = MAX_MENU_LINE;
	}
	else if(char(key) == ARROW_DOWN)
	{
		activeMenuLine++;
		if(activeMenuLine > MAX_MENU_LINE)
			activeMenuLine = MIN_MENU_LINE;
	}
	return activeMenuLine;
}

void clearScreen()
{
	system("cls");
}

void searchMenu(Store store)
{
	clearScreen();
	cout<<'\n'<<"1. search by category";
	cout<<'\n'<<"2. search by platform";
	cout<<'\n'<<"3. search by price";
	cout<<'\n'<<"4. search by name \n";
	int subMenuSelection;
	string searchString;
	cin>>subMenuSelection;
	switch(subMenuSelection)
	{	
		case 1:
		{
			cout <<"please enter Category: \n";
			cin>>searchString;
			store.displayAllApps(store.searchByCategory(searchString));
			system("pause");
			clearScreen();
			break;
		}
		case 2:
		{
			cout <<"please enter platform: \n";
			cin>>searchString;
			store.displayAllApps(store.searchByPlatform(searchString));
			system("pause");
			clearScreen();
			break;
		}
		case 3:
		{
			string minPrice;
			string maxPrice;
			cout <<"please enter min price: \n";
			cin>> minPrice;
			cout <<"please enter max price: \n";
			cin>> maxPrice;
			store.displayAllApps(store.searchByPrice(atof(minPrice.c_str()), atof(maxPrice.c_str())));
			system("pause");
			clearScreen();
			break;
		}
		case 4:
		{
			cout << "please enter Name to search for:\n";
			cin>>searchString;
			store.displayAllApps(store.searchByName(searchString));
			system("pause");
			clearScreen();
			break;
		}
	}
}