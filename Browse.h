#pragma once
#include "stdafx.h"
#include <string>
#include <map>
class Browse
{
public:
	virtual void actOnFile() = 0;
	virtual void show() = 0;
	virtual void decision() = 0;
};

class BrowseHistory :public Browse
{
	int countOfLine = 1;
	std::map<int, std::string> mapWithFile;
	void actOnFile();
	void show();
public:
	BrowseHistory() :countOfLine(1) {};
	void decision();
	
};