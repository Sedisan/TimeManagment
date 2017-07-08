#include "stdafx.h"
#include <map>
#include <string>
class DateFile
{

public:

	virtual void act(std::string nameOfFile) = 0;

};
class SaveToFile :public DateFile
{

public:

	virtual void act(std::string nameOfFile);
	void act(std::string nameOfFile, std::string textToWrite);

};
class NewOpenFile :public DateFile
{

public:
	virtual void act(std::string nameOfFile);


};
class DumpFile :public DateFile
{

public:
	bool static checkDumpFile(std::string nameOfFile);
	virtual void act(std::string nameOfFile);
	static void copyRealFile(std::string nameOfFile, bool statusOfFile);

};
class SearchFileForBadSaved :public DateFile
{

public:
	virtual void act(std::string nameOfFile);


};
class RealFile :public DateFile
{
public:
	virtual void act(std::string nameOfFile);


};
class TestManipulateOfDate
{


public:
	static bool testValid(const unsigned int &firstHours, const unsigned int &firstMinutes, const unsigned int &secondHour, const unsigned int &secondMinutes, const unsigned int timeOfMinute, const unsigned int timeOfMidNight);

};


class ActualData
{

public:
	static std::string returnActualDate();

};
class LoadData;
class ManipulateOfDate
{
	int hour
		, minutes;
public:
	void setHour(int h)
	{
		hour = h;
	}

	void setMinutes(int m)
	{
		minutes = m;
	}

	static void convertOfDate(int &hours, int &minutes, int position, const std::string &data);
	static void dealWithIt(int position, std::string &data, int &hours, int &minutes);
	static std::string countSpendTime(const unsigned int &hours, const unsigned int &minutes, const unsigned int &secondHour, const unsigned int &secondMinutes, const unsigned int timeOfMinute, const unsigned int timeOfMidNight);



	friend class LoadData;

};

class LoadData
{
	std::string firstPartOfDate;
	std::string secondPartOfDate;
public:

	LoadData() :firstPartOfDate(""), secondPartOfDate("")
	{

	}

	std::string validOfDate(std::string &spendTime);
	std::string returnFirstPartOfDate()
	{
		return firstPartOfDate;
	}
	std::string returnSecondPartOfDate()
	{
		return secondPartOfDate;
	}
};

class RemoveDate
{
public:

	static void removeSpaceWithStringDate(std::string &textToRemoveString);
};
class ConvertStandardTime
{

public:
	static time_t changeToSecondsMinutes(int minutes);
	static time_t changeToSecondsHour(int hours);
	static void changeToHoursAndMinutes(time_t secondsHour, time_t secondsMinutes);

};
class Test
{
public:
	static  bool testOfInsertedData(std::string);

};
