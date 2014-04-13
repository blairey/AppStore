#include "store.h"
void Store::addApp()
{
	App app;
	
	cout	<< "Name:\n";
	cin		>>  app.name;
	cout	<< "Rating:\n";
	cin		>>	app.rating;
	cout	<< "Price:\n";
	cin		>>  app.price;
	cout	<< "Platform:\n";
	cin		>>  app.platform;


	appList.push_back(app);	
}

void Store::saveAllApps()
{
	ofstream f ("app.dat");
	if(f.is_open())
	{
		for( int i = 0; i < appList.size(); i++)
		{
			App app = appList[i];
			f << "name:" << app.name << ",rating:" << app.rating << ",price:"<< app.price << ",platform:" << app.platform;
			f <<'\n';
		}
		f.close();
	}

}

int Store::getListSize()
{
	return appList.size();
}

void Store::displayApp(int appNumber)
{
	App app = appList[appNumber];
	displayApp(app);
	//cout << "number: "	<<	appNumber				<<	'\t';
	//cout << "name: "	<<	app.name				<<	'\t';
	//cout << "rating: "  <<	app.rating				<<	'\t';
	//cout << "price: "   <<	app.price	<<	"gbp"	<<	'\t';
	//cout << "platform: "<<	app.platform			<<	'\n';
	//cout <<"---------------------------------------------------------------------" ;
}

void Store::displayApp(App app)
{
		//cout << "number: "	<<	app.id				<<	'\t';
	cout << "name: "	<<	app.name				<<	'\t';
	cout << "rating: "  <<	app.rating				<<	'\t';
	cout << "price: "   <<	app.price	<<	"gbp"	<<	'\t';
	cout << "platform: "<<	app.platform			<<	'\n';
	cout <<"---------------------------------------------------------------------" ;
}

void Store::displayAllApps()
{
	//todo add header
	for(int i = 0; i < appList.size(); i++)
	{
		displayApp(i);
		cout<<'\n';
	}
}

void Store::displayAllApps(vector<App> appList)
{
	for(int i = 0; i < appList.size(); i++)
	{
		displayApp(appList[i]);
		cout<<'\n';
	}
}

void Store::deleteApp(int appNumber)
{
	appList.erase(appList.begin() +appNumber);

}

void Store::loadFromFile()
{
	vector<std::string> values;
	string line;
	ifstream myfile ("app.dat");
	if (myfile.is_open())
	{
		
		while (getline(myfile,line))
		{
			if(line.length() > 0)
			{
				int startPos = 0;
				for(int i = 0; i < noOfAppFields; i++)
				{
					int endPos = line.find_first_of(',', startPos);
					string subString = line.substr(startPos, (endPos - startPos));

					int sSSPos = subString.find_first_of(':') + 1;
					int sSEPos = subString.length() - sSSPos;
					string valueString = subString.substr(sSSPos, sSEPos);

					values.push_back(valueString);
					startPos = endPos + 1;
				}

				createAppAddToList(values);
				values.clear();
			}

			//for(int i = 0; i < line.length(); i++)
			//{
				
				//if(line[i]== ',')
				//{
				//	string subString = line.substr(startPos, i);
				//	startPos= subString.find_first_of(':') + 1;
				//	values[j] = subString.substr(startPos);
				//	j++;
				//	startPos= i+1;
				//}
			//}
		}

		myfile.close();
	}
}

void Store::createAppAddToList(vector<string> values)
{
	App app; 
	app.name		= values[0];
	app.rating		= atoi (values[1].c_str());
	app.price		= atof (values[2].c_str());
	app.platform	= values[3];
	appList.push_back(app);

}

vector<App> Store::searchByName(string name)
{
	vector<App> resultList;
	for(int i = 0 ; i < appList.size() ; i++)
	{
		App app = appList[i];

		if(searchForStringInString(name, app.name) == true)
		{
			resultList.push_back(app);
		}

	}
	return resultList;
}

vector<App> Store::searchByCategory(string category)
{
	vector<App> resultList;
	for(int i = 0 ; i < appList.size() ; i++)
	{
		App app = appList[i];
		
		if(searchForStringInString(category, app.category) == true)
		{
			resultList.push_back(app);
		}
	}
	return resultList;
}

vector<App> Store::searchByPlatform(string platform)
{
	vector<App> resultList;
	for(int i = 0 ; i < appList.size() ; i++)
	{
		App app = appList[i];
		
		if(searchForStringInString(platform, app.platform) == true)
		{
			resultList.push_back(app);
		}
	}
	return resultList;
}

vector<App> Store::searchByPrice(float minPrice, float maxPrice)
{
	vector<App> resultList;
	for(int i = 0; i < appList.size() ; i++)
	{
		App app = appList[i];
		if(app.price >= minPrice && app.price <= maxPrice)
			resultList.push_back(app);
	}
	return resultList;
}

bool Store::searchForStringInString(string searchString, string targetString)
{	
	int startPos = 0;
	while(startPos + searchString.length() <= targetString.length())
	{
		string subString = targetString.substr(startPos, searchString.length());
		if(subString.compare(searchString) == 0) 
		{
			return true;
		}

		startPos++;
	}

	return false;
}