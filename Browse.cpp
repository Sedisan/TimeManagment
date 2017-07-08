#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <thread>
#include <chrono>
#include "Browse.h"
#include "Header.h"
#define DaysLimit 20
std::string getNameOfBASEWITHALLRECORD();
void BrowseHistory::show()
{
	for (size_t i = 1; i<mapWithFile.size() + 1; i++)
	{
		std::cout << i << ".";
		std::cout << mapWithFile[i] << '\n';
	}
}
void BrowseHistory::actOnFile()
{
	countOfLine = 1;

	std::ifstream iff(getNameOfBASEWITHALLRECORD());

	if (!iff) { std::cout << "Base is empty. Program will exit\n"; exit(-1); }
	std::string line;

	while (std::getline(iff, line))
	{
		countOfLine++;
	}

	iff.close();
}



void BrowseHistory::decision()
{
	this->actOnFile();

	std::ifstream iff(getNameOfBASEWITHALLRECORD());
	if (!iff)exit(-1);
	std::string line;
	int lineInt = 0;

	auto lambdaToAllFileRecord = [&]() {

		while (std::getline(iff, line))
		{
			lineInt++;
			for (int i = 0; i<1; i++)
				mapWithFile[countOfLine - lineInt] = line;
		}


	};


	if (countOfLine>DaysLimit)
	{
		int decision;
		std::cout << "The history is higher than: " << DaysLimit << ".Show all day(press 1), or press 0 to show last 7 days\n";

		std::cin >> decision;


		if (decision == 1) lambdaToAllFileRecord();
		else
		{
			int countHowMany = 0;
			while (std::getline(iff, line))
			{
				lineInt++;

				if (countOfLine <= lineInt + 7)
					for (int i = 0; i<1; i++) {
						countHowMany++;
						mapWithFile[countHowMany] = line;
					}
			}
		}
	}
	else lambdaToAllFileRecord();



	this->show();

	int select;

	std::cout << "Enter number: " << '\n';
	std::cin >> select;
	if (!std::cin)throw "Unrecognized number\n";
	if (select>lineInt || select<0)throw "Too long, or to small number";

	std::ifstream file(mapWithFile[select]+".txt");

	if (!file) { std::cerr << "Not find the file\n"; throw "Not find File"; }

	std::string allLine="";
	if (file.is_open())
	{
		while (file.good())
		{

			std::getline(file, line);
			
				allLine += line;
				allLine += '\n';

		}
	}

	std::cout << "Your activity in: " << mapWithFile[select] << '\n';

	Settings::writeOnTheScreenText(allLine);
	
	file.close();

}
