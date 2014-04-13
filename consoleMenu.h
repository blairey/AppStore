#pragma once

#include<string>

const std::string menu_items[7] = {
	 "add apps                             "
	,"delete an app                        "
	,"display an app                       "
	,"search for an app                    "
	,"update an app                        "
	,"simple report                        "
	,"exit                                 "
};


const std::string menu_items_high[7] = {
	 "ADD  APP                            "
	,"DELETE APP                          "
	,"DISPLAY AN APP                      "
	,"SEARCH FOR AN APP                   "
	,"UPDATE AN APP                       "
	,"SIMPLE REPORT                       "
	,"EXIT                                "
};

const int MIN_MENU_LINE = 0;
const int MAX_MENU_LINE = 6;

const char RETURN = char(13);
const unsigned ARROW_UP = 72;
const unsigned ARROW_DOWN = 80;

const unsigned menuPosX = 23;
const unsigned menuPosY [7] = {7,9,11,13,15,17,19};

int displayMainMenu();
int changeLineBasedOnInput(char key, int activeMenuLine);
void clearScreen();
int AddApp();
int DeleteApp();
int DisplayApp();
int Search();
int Update();
int Simple();

void searchMenu(Store store);