#pragma once
#include <string>
#include <vector>
#include<iostream>
#include<fstream>
#include<stdlib.h>


using namespace std;

struct App
{
	string name;
	int rating;
	float price;
	string platform;
	string category;
};

class Store
{
public:
	void addApp();
	void saveAllApps();
	void deleteApp(int appNumber);
	void displayApp(int appNumber);
	void displayApp(App app);
	void displayAllApps();
	void displayAllApps(vector<App> appList);
	vector<App> searchByCategory(string category);
	vector<App> searchByName(string name);
	vector<App> searchByPlatform(string platform);
	vector<App> searchByPrice(float minPrice, float maxPrice);
	void loadFromFile();
private:
	vector<App> appList; 
	int getListSize();
	void createAppAddToList(vector<string> values);
	int static const noOfAppFields = 4;
	bool searchForStringInString(string searchString, string targetString);
};
