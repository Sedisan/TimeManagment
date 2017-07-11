// StandardOfData.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>
#include <fstream>
#include <cstdio>
#include <cctype>
#include <ctime>
#include "Header/Header.h"
#include "Header/Date.h"
#include "Header/Browse.h"

#define DUMP "DUMP"
#define TEMP "TEMP"
#define SIZEOFTABLEINFOPEN 2000 ///Protect from stackOverflow
#define TEXTSUFFIX ".txt"

int getSizeOfTable()
{
	return SIZEOFTABLEINFOPEN;

}

namespace Suffix
{
	void addOrNonAddSuffix(std::string &name)
	{
		int where = name.find(TEXTSUFFIX);

		if (where != std::string::npos) {



		}
		else {
			name += TEXTSUFFIX;
		}
	}
}
namespace FileOpenAndStreamNamespace
{
	void saveFileWithAppend(std::string nameOfFile, std::string textToSave) {

		Suffix::addOrNonAddSuffix(nameOfFile);

		std::ofstream ff(nameOfFile, std::ios::app);

		ff << textToSave + '\n';

		ff.close();
	}

}


///Method
[[deprecated]]
std::string ActualData::returnActualDate()
{

	struct tm tm;
	__time64_t tt = _time64(&tt);

	char buff[26];



	errno_t err = _localtime64_s(&tm, &tt);
	if (err)exit(-1);
	err = asctime_s(buff, sizeof buff, &tm);
	if (err) exit(-1);


	//std::cout << "Today is: " << tm.tm_mday << " " << tm.tm_mon + 1 << " " << tm.tm_year + 1900 << '\n';

	std::string StringToReturn = std::to_string(tm.tm_mday) + "-" + std::to_string(tm.tm_mon + 1) + "-" + std::to_string(tm.tm_year + 1900);
	return StringToReturn;
}
bool TestManipulateOfDate::testValid(const unsigned int &firstHours, const unsigned int &firstMinutes, const unsigned int &secondHour, const unsigned int &secondMinutes, const unsigned int timeOfMinute = 60, const unsigned int timeOfMidNight = 24)
{
	if (firstHours >= timeOfMidNight || secondHour >= timeOfMidNight || firstMinutes >= timeOfMinute || secondMinutes >= timeOfMinute)
	{

		throw std::exception("Hours or minutes is higher than should be, or you write a negative number. Program will exit");
		return false;
		//exit(-1);
	}
	return true;
}

void SaveToFile::act(std::string nameOfFile)
{

	std::string tempCin;
	std::cout << "Insert your text: " << '\n';
	std::getline(std::cin, tempCin);
	FileOpenAndStreamNamespace::saveFileWithAppend(nameOfFile, tempCin);
	/**
	std::ofstream ff(nameOfFile);
	ff << tempCin;
	ff.close();
	*/
}
void SaveToFile::act(std::string nameOfFile, std::string textToWrite)
{

	FileOpenAndStreamNamespace::saveFileWithAppend(nameOfFile, textToWrite);


}
void PROTECT_FROM_STACK_OVERFLOW(std::string);
void NewOpenFile::act(std::string nameOfFile)
{


	///TEST
	Suffix::addOrNonAddSuffix(nameOfFile);
	PROTECT_FROM_STACK_OVERFLOW(nameOfFile);
	char buffer[SIZEOFTABLEINFOPEN];///This is dangerous and can simple stack overflow
	FILE * fp;
	fopen_s(&fp, nameOfFile.c_str(), "r");
	if (!fp)
	{
		std::perror("Failed while opened file...");
		std::_Exit(EXIT_FAILURE);
	}


	int lineCounter = 0;
	while ((std::fgets(buffer, sizeof buffer, fp) != NULL))
	{
		lineCounter++;
		std::cout << lineCounter << ". " << buffer;


		std::string tempValue = std::string(buffer);

	}

	fclose(fp);



	std::string temp;

	std::ifstream ff(nameOfFile);
	while (std::getline(ff, temp))
	{
		//std::cout << temp << '\n';
	}


	ff.close();


}

void RealFile::act(std::string nameOfFile)
{
	DumpFile dumpFile;
	dumpFile.act(nameOfFile);
	///Next

}
bool DumpFile::checkDumpFile(std::string nameOfFile)
{

	FILE *file;
	std::string tempToFOpen = DUMP + nameOfFile;
	fopen_s(&file, tempToFOpen.c_str(), "r");
	if (file) {


		fclose(file);
		return true;
	}
	else return false;



	///if Dump File exist, replace file with it

	return true;
}
void DumpFile::act(std::string nameOfFile)
{

	if (checkDumpFile(nameOfFile)) {

		DumpFile::copyRealFile(nameOfFile, false);

		std::cout << "Restore file..." << '\n';
	}
	else {
		DumpFile::copyRealFile(nameOfFile, true);

	}

}
void DumpFile::copyRealFile(std::string nameOfFile, bool statusOfFile = true)
{
	std::string StringDump = DUMP + nameOfFile;
	std::string StringTemp = std::string("TEMP") + DUMP + nameOfFile;
	/*auto remFile = [](std::string& name) {

	return [](std::string& name) {
	std::remove(name.c_str());


	};
	};*/





	if (std::remove((StringTemp.c_str())) == 0) {
		std::perror("Previous Running was bad");

	}
	if (statusOfFile) {
		std::ifstream src(nameOfFile, std::ios::binary);
		std::ofstream dst(StringTemp, std::ios::binary);
		dst << src.rdbuf();

		src.close();
		dst.close();
		std::rename(StringTemp.c_str(), StringDump.c_str());
	}
	else
	{

		std::cout << "Your save restore before last modification" << '\n';

		std::ifstream src(StringDump, std::ios::binary);
		std::ofstream dst(nameOfFile, std::ios::binary);
		dst << src.rdbuf();
		dst.close();



	}

	//    std::this_thread::sleep_for(std::chrono::seconds(15));
	if (std::remove((StringDump.c_str())) != 0)std::perror("Error while delete");

}




void SearchFileForBadSaved::act(std::string nameOfFile)
{

	if (DumpFile::checkDumpFile(nameOfFile))
	{
		DumpFile::copyRealFile(nameOfFile, false);
	}

}

///END OF METHOD
void redict(DateFile *fp, std::string nameOfFile)
{
	PROTECT_FROM_STACK_OVERFLOW(nameOfFile);

	fp->act(nameOfFile);
}



bool Test::testOfInsertedData(std::string test)
{

	///std::regex;

	for (auto n : test) {
		if ((int)(n)>59) { std::cout << "Try again!" << '\n'; return false; }

	}
	return true;
}

void loadValue()
{

}
template<typename T, typename ...Rest>
void loadValue(T &d, Rest&...r)
{

	std::getline(std::cin, d);
	while (!Test::testOfInsertedData(d))loadValue(d);

	loadValue(r...);
	//return;
}


[[deprecated("Better idea is loadValue")]]
void testLoadValue(std::string &d)
{
	std::cin.clear();
	std::cin.sync();

	std::getline(std::cin, d);
}

[[deprecated("Can cause problem")]]
void RemoveDate::removeSpaceWithStringDate(std::string &textToRemoveString)
{

	textToRemoveString.erase(std::remove_if(textToRemoveString.begin(), textToRemoveString.end(), [](char x)
	{
		return std::isspace(x);
	}), textToRemoveString.end());

}


time_t ConvertStandardTime::changeToSecondsMinutes(int minutes)
{


	minutes *= 60;
	time_t secondsMinutes = minutes;



	return secondsMinutes;

}
time_t ConvertStandardTime::changeToSecondsHour(int hours)
{
	hours *= 3600;

	time_t secondsHour = hours;



	return secondsHour;

}
[[deprecated("It is not necessary")]]
void ConvertStandardTime::changeToHoursAndMinutes(time_t secondsHour, time_t secondsMinutes)
{


	time_t hours = secondsHour / 3600;


	time_t minutes = secondsMinutes / 60;




}
int main();
void ManipulateOfDate::convertOfDate(int &hours, int &minutes, int position, const std::string &data)
{


	//charToHour[0]=;
	//  charToHour[1]=);
	std::string hourToString;
	hourToString.resize(3);

	hourToString[0] = data.at(0);
	hourToString[1] = data.at(1);

	// while(Test::testOfInsertedData(hourToString))loadValue(data);
	if ((int)hourToString[0]>57 || (int)hourToString[0]<48 ||
		(int)hourToString[1]>57 || (int)hourToString[1]<48
		) {
		std::cout << "Bad format of hours. Try again" << '\n';

		main();
		return;
	}

	hours = std::atoi(hourToString.c_str());

	std::string minuteToString;
	minuteToString.resize(3);

	minuteToString[0] = data.at(3);

	minuteToString[1] = data.at(4);




	if ((int)minuteToString[0]>57 || (int)minuteToString[0]<48 ||
		(int)minuteToString[1]>57 || (int)minuteToString[1]<48
		) {
		std::cout << "Bad format of minutes. Try again" << '\n';
		main();
		return;

	}

	minutes = std::atoi(minuteToString.c_str());

}
void ManipulateOfDate::dealWithIt(int position, std::string &data, int &hours, int &minutes)
{

	convertOfDate(hours, minutes, position, data);



	time_t secondsMinutes = ConvertStandardTime::changeToSecondsMinutes(minutes);
	time_t secondsHours = ConvertStandardTime::changeToSecondsHour(hours);

	//ConvertStandardTime::changeToHoursAndMinutes(secondsHours, secondsMinutes);///Change for seconds, unused
}

std::string ManipulateOfDate::countSpendTime(const unsigned int &firstHours, const unsigned int &firstMinutes, const unsigned int &secondHour, const unsigned int &secondMinutes, const unsigned int timeOfMinute = 60, const unsigned int timeOfMidNight = 24)
{

	unsigned int hour
		, minute;

	try {

		TestManipulateOfDate::testValid(firstHours, firstMinutes, secondHour, secondMinutes, timeOfMinute, timeOfMidNight);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << '\n';
		throw;
	}

	bool issetFirstValue = 0;
	if (secondHour<firstHours)
	{
		issetFirstValue = 1;
		hour = timeOfMidNight - firstHours + secondHour;

		minute = firstMinutes - secondMinutes;

		if (minute<0)minute = (minute*(-1));

		minute = timeOfMinute - minute;
	}
	if (secondHour == firstHours&& secondMinutes<firstMinutes)
	{

		issetFirstValue = 1;
		hour = timeOfMidNight - firstHours + secondHour - 1;

		minute = firstMinutes - secondMinutes;

		if (minute<0)minute = (minute*(-1));

		minute = timeOfMinute - minute;

	}

	if (secondMinutes<firstMinutes)
	{


		if (!issetFirstValue)hour = secondHour - firstHours - 1;

		minute = firstMinutes - secondMinutes;

		if (minute<0)minute = (minute*(-1));



		minute = timeOfMinute - minute;

	}
	else
	{

		minute = secondMinutes - firstMinutes;
		if (!issetFirstValue)	hour = secondHour - firstHours;
	}
	if (hour<0)hour = (hour*(-1));
	if (minute == timeOfMinute)hour += 1;


	return std::to_string(hour) + " " + std::to_string(minute);
}

void clearStream();
std::string LoadData::validOfDate(std::string &spendTime)//Spending Time will changing to spendingOfTime in format Hour Minutes
{
jump:///GOTO
	std::cout << "Insert date in format hours:minutes or hours minutes.\nValid format: hh:min or hh min. Insert start.\nAfter it, insert end time, as the start.\nFor example valid form is:\n10:20 10:30 or\n10 20 10 30\nWhere 10:20 is start, and 10:30 is end.\nIf number is lower than 10, 0 needs to be add\nExample:\n09:07 09:09 or\n09 07 09 09\n";


	clearStream();

	loadValue(firstPartOfDate, secondPartOfDate);



	if (firstPartOfDate.length()>5 || firstPartOfDate.length() <= 4 || secondPartOfDate.length()>5 || secondPartOfDate.length() <= 4)
	{
		std::cout << "Value is too short, or too long.Try again..." << '\n';

		goto jump;///JUMP TO START OF FUNCTION

	}


	///Space

	int position = 0;

	int firstDataHours = 0;
	int secondDataHours = 0;
	int firstDataminutes = 0;
	int secondDataminutes = 0;

	if (firstPartOfDate.find(':') != firstPartOfDate.npos&&secondPartOfDate.find(':') != secondPartOfDate.npos)
	{
		//RemoveDate::removeSpaceWithStringDate(firstPartOfDate);
		//RemoveDate::removeSpaceWithStringDate(secondPartOfDate);

		position = firstPartOfDate.find_first_of(':');
	}

	else if (firstPartOfDate.find_first_of(' ') != firstPartOfDate.npos&&secondPartOfDate.find(' ') != secondPartOfDate.npos)
	{

		position = firstPartOfDate.find_first_of(' ');
	}
	else
	{

		std::cout << "Unrecognized Separator.Try again..." << '\n';
		//loadValue(firstPartOfDate, secondPartOfDate);
		goto jump;///JUMP TO START OF FUNCTION
	}





	ManipulateOfDate::dealWithIt(position, firstPartOfDate, firstDataHours, firstDataminutes);

	ManipulateOfDate::dealWithIt(position, secondPartOfDate, secondDataHours, secondDataminutes);



	std::string fullFormatDataToReturn = std::to_string(firstDataHours) + " " + std::to_string(firstDataminutes) + " " + std::to_string(secondDataHours) + " " + std::to_string(secondDataminutes);

	spendTime = ManipulateOfDate::countSpendTime(firstDataHours, firstDataminutes, secondDataHours, secondDataminutes, 60, 24);

	return firstPartOfDate;

	//return ;

}


void PROTECT_FROM_STACK_OVERFLOW(std::string fname)
{
	std::ifstream ff(fname);
	std::string checkStackOverflowLength = "";
	int counterLine = 0;
	while (std::getline(ff, checkStackOverflowLength))
	{
		counterLine++;
		if (checkStackOverflowLength.length() > SIZEOFTABLEINFOPEN - 1)
		{

			std::cout << "This can be dangerous and cause stack overflow\n Check your file, that don't have line with text length lengther than 29. Problem is in: " << counterLine << "Line" << '\n';
			std::cout << "Program will exit" << '\n';

			std::_Exit(EXIT_FAILURE);
		}
	}
	ff.close();
}

bool stillInserter()
{
	bool stillInterter = 0;
	std::cout << "Is program should still works ? Press 1 to accept. 0 to exit" << '\n';
	std::cin >> stillInterter;
	if (stillInterter == 0)return false;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.sync();
	return true;

}
