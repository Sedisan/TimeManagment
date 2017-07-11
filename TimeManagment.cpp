// TimeManagment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"///For Visual Studio
#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <mutex>
#include <limits>
#include <string>
#include <map>
#include <exception>
#include "Header/Header.h"
#include "Header/Date.h"
#include "Header/Browse.h"
#define SLOW_WRITINGWITHTXT "SLOW_WRITING.txt"
#define CAPABILITES 3



std::mutex mtx;
std::mutex lck;
void clearStream()
{
	
	std::cin.clear(); std::cin.sync(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void loadValidOriginalVariable(){}
template<typename T,typename ...Rest>
T loadValidOriginalVariable(T &arg,Rest&...rest)
{
	
	do {
		

	
		std::cin >> arg;
		if (std::cin)break;
		if (!std::cin) { 
			
			const std::type_info &ti = typeid(arg);
			std::cout << "You must enter type of:"<<ti.name()<<'\n'; clearStream(); 
			std::cout << "Try again" << '\n';
		}
	} while (std::cin);

	loadValidOriginalVariable(rest...);

	return arg;
}




void menu(int &decision)
{

	
	std::lock_guard <std::mutex> lock(lck);


	std::string  text= "Which option do you choose ?\n1.Add today activity\n";
	text += "2.Browse history\n";
	text += "3.Settings";

	Settings::writeOnTheScreenText(text);


	while (std::cin) {

		loadValidOriginalVariable(decision);
		if (decision > 0 && decision < CAPABILITES+1)break;


	}
	

}
void redict(DateFile *fp, std::string nameOfFile);
bool stillInserter();
int getSizeOfTable();
auto main()->int
{



	while (true) {


		
		int decision = NULL;


		Time * tAbstract;
		ActualTime tObject;
		tAbstract = &tObject;
		std::thread thrForAbstract = std::thread([&]() {


			ActualTime::returnActualDate();
			menu(decision);
		});
		thrForAbstract.join();
		mtx.lock();
		std::vector<std::string> vecString;
		
		DateFile *fp;

		std::string spendTime;
		std::string nameOfFile = ActualData::returnActualDate();
		



		SaveFile <std::vector<std::string>> fSave;
		if (decision == 1) {
			LoadData loadData;
			loadData.validOfDate(spendTime);
			std::string fullStringText = spendTime + " " + loadData.returnFirstPartOfDate() + " " + loadData.returnSecondPartOfDate();
			if (!PatternOfFile::findPattern(ActualData::returnActualDate())) {
				SaveFile<std::string> save;
				save.saveFile(ActualData::returnActualDate()+'\n');
			
			}
			std::cout << "Enter description of your activity: " << '\n';

			std::string descrOfActivity;
			
			std::getline(std::cin, descrOfActivity);
			fullStringText += " ";
			fullStringText += descrOfActivity;
			if (fullStringText.length() >= getSizeOfTable()) { std::cout << "Too length description. Program will exit\n"; exit(-1); }
			int howManySpendTime;
			int startTime;
			int endTime = 0;

			SaveToFile saveToFile;

			RealFile realFile;
			saveToFile.act(nameOfFile, fullStringText);

			
			fp = &realFile;
			auto n = [&]()
			{
				redict(fp, nameOfFile);
			};
			n();




			//loadValidOriginalVariable(startTime,endTime);
			//howManySpendTime = endTime - startTime;

			//vecString.push_back("Ala nie ma kota");
			/*
			std::thread thrForSave = std::thread(


				[&]() {fSave.saveFile(vecString); }


			);

			thrForSave.join();
		*/
		}

		if (decision == 2) {
	
			Browse *browse;
			BrowseHistory browseHistory;
			browse = &browseHistory;
			browse->decision();
		
		
		}

		if (decision == 3)
		{

			clearStream();
			std::cout << "Actual available settings: \n";
			std::cout << "1. Change slow settings\n";

			int value = 0;

			std::cout << "Which option choose? \n";
			loadValidOriginalVariable(value);
			if (value == 1) {

				
				Settings settings;

				settings.setting();

			}

		}

		mtx.unlock();
		if (!stillInserter())break;

	}

    return 0;
}

