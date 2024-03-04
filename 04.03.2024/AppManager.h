#pragma once
#include "InMemoryDb.h"
#include "XmlManager.h"
class AppManager
{
private:
	InMemoryDb inMemoryDb;
	XmlManager xmlManager;

	void updateXmlManager();
	void updateInMemoryDb();
public:
	AppManager();
	void addUser(User user);
	void removeUserById(int id);
	void showAll();
	vector<string> allElFromString(string str, char del);

};

