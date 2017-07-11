#include "stdafx.h"
#include <iostream>
#include "Header.h"
#include <vector>
#include <ctime>
#include <cctype>
#include <string>
#include <cstdlib>
#include <mutex>
#include <map>
#include <fstream>
#include <regex>
#include <string>
#include <thread>
#include "Header/Header.h"
#include "Header/Date.h"
#include "Header/Browse.h"
#define BASEALLRECORDWITHTXT "BASE.txt"
#define SETTINGSWITHTXT "SETTINGS.txt"

std::string getNameOfBASEWITHALLRECORD()
{
	return BASEALLRECORDWITHTXT;
}
void throwFunction()
{
	try {
		
	}
	catch(std::string w)
	{
	
	}
}

namespace FileOpenAndStreamNamespace
{
	void saveFileWithAppend(std::string nameOfFile, std::string textToSave);

}


std::string ActualTime::returnActualDate()
{



	std::this_thread::yield();

	struct tm tm;
	__time64_t tt = _time64(&tt);
	
	char buff[26];
	

	
	errno_t err = _localtime64_s(&tm, &tt);
	if (err)exit(-1);
	 err = asctime_s(buff, sizeof buff, &tm);
	if (err) exit(-1);

	//std::cout << "Today is: " << tm.tm_mday << " " << tm.tm_mon + 1 << " " << tm.tm_year + 1900 << '\n';

	std::string StringToReturn=std::to_string(tm.tm_mday)+"-"+ std::to_string(tm.tm_mon+1)+"-"+std::to_string(tm.tm_year+1900);
	
	Settings::writeOnTheScreenText(StringToReturn);

	//std::logic_error("THIS IS AN ERROR");

	return StringToReturn;

}
 
std::mutex g_i_mutex;


template class File <int>;
template class File<double>;
template class OpenFile<int>;
template class OpenFile<double>;
template class RemoveActivity <std::vector<std::string>, int>;
template class SaveFile<std::vector<std::string>>;
template class SaveFile<std::string>;
template<typename T>
T OpenFile<T>::getIng(T t)
{
	/*
	if (t == 1) {


		File *fileToDestroy = fopen(BASEWITHALLRECORD, "w"); if (!fileToDestroy) { perror("Error while destroy"); }
		else fputs("", fileToDestroy);

		std::ofstream iss(BASEWITHALLRECORD,std::ios::out | std::ios::trunc);
		_fcloseall();

	}
	*/
	std::lock_guard<std::mutex> m(g_i_mutex);
	FILE * fp;
	errno_t err =fopen_s(&fp, BASEALLRECORDWITHTXT, "r");


	if (!fp) {
	
		std::perror("Error while reading");
		return EXIT_FAILURE;

	}
	std::string concatenateStringToMapFirstArgument="";
	char* _cdecl c;
	int num = 1;

	char table[100];

	while ((c = std::fgets(table, sizeof table, fp)) != NULL) {
		
		concatenateStringToMapFirstArgument = std::string(table);
		std::cout <<num<<"."<< table;

		num++;
	}
	std::cout << '\n';
//	std::cout << concatenateStringToMapFirstArgument << '\n';

	if (std::ferror(fp))std::puts("Error IO while reading file");
	else if (std::feof(fp))std::puts("Read Success");
	
	_fcloseall();

	//std::fclose(fp);


	return t;
}


template<typename T>
T SaveFile<T>::saveFile(T t)
{

	FILE * fp;
	std::lock_guard <std::mutex> lck(g_i_mutex);
	char *flag = "a";
	if (t.empty())flag = "w";
	std::cout << "Flag equal: " << flag << '\n';
	errno_t err = fopen_s(&fp,BASEALLRECORDWITHTXT,flag);
	
	
	std::string text ="";
	for (auto n : t)
	{
		text += n;
	}

	if (!err)
	{
		
		char * pTextChar=new char[text.length()];


		for (unsigned int i=0;i<strlen(pTextChar);i++)
		{
			pTextChar[i] = text[i];
		}


		fputs(pTextChar, fp);
	}
	
	fclose(fp);
	_fcloseall();
	
	return t;
}
template<typename T,typename N>
int RemoveActivity<T,N>::act(T t,N n)
{
///Works in progress
	bool good=true;
	if(good){}
	else {}
	return 10;


}


void PatternOfFile::filePattern(FILE *&fp,char *nameOfFile)
{
	
	errno_t err = fopen_s(&fp, nameOfFile, "w+");

	
	if (err) { std::perror("Error while writing"); }
//	char * pTextChar = new char[text.length()+1];
	


	//std::cout << "PtextChar: " << pTextChar << '\n';


	//fputs(pTextChar, fp);
	//delete[] pTextChar;
	//fclose(fp);
	//FILE * filePointer;
	//errno_t errNO = fopen_s(&filePointer, SLOW_WRITING, "r");
	/*
	int _cdecl c;
	while ((c = std::fgetc(filePointer)) != EOF) {


	std::putchar(c);


	}

	_fcloseall();


	*/
	
}


bool PatternOfFile::findPattern(std::string pattern, std::string file)
{
	if (file == "")file = BASEALLRECORDWITHTXT;

	std::regex reg(pattern,
		std::regex_constants::ECMAScript |
		std::regex_constants::icase);

	std::ifstream iFstream(BASEALLRECORDWITHTXT);
	std::string line = "";

	if (iFstream.is_open())
	{
		while (iFstream.good())
		{
			std::getline(iFstream, line);
			std::smatch smt;
		
			if (std::regex_match(line, reg)) {  iFstream.close(); return true; }
			if (line.find(pattern) != std::string::npos) { iFstream.close(); return true; }

			

		}

	}
	else return false;
	iFstream.close();
	return false;
}

void Settings::setting()
{
	std::string slowWriting;
	std::cout << "Turn on - 0\n Turn off - 1\n";
	//std::cout << "Turn" << slowWriting ? "off" : "on";
	std::cout << " slow writing";
	std::cin >> slowWriting;
	if (!std::cin)throw("Bad inserter value");
	//FileOpenAndStreamNamespace::saveFile()

	std::cout << "Slow Writing: " << slowWriting << '\n';

	//if ((slowWriting != true) || (slowWriting != false) || (slowWriting != 1) || (slowWriting != 0))throw("Bad inserter data");
	
	std::ofstream ff(SETTINGSWITHTXT);
	ff << slowWriting;
	ff.close();

	
}
bool Settings::SlowWriting()
{
	
	std::ifstream ff(SETTINGSWITHTXT);
	std::string line;
	if (ff.is_open())
	{
		if(ff.good())
		std::getline(ff,line);
		ff.close();
		bool result = std::atoi(line.c_str());
		if (result == true || result == 1)  return true; 
		else return false; 
	}
	else return false;
	
}
void Settings::writeOnTheScreenText(std::string textToWrite)
{
	if (!Settings::SlowWriting())
		for (auto n : textToWrite) {
			std::cout << n;
			std::this_thread::yield();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));

		}
	else std::cout << textToWrite;

	std::cout << '\n';

}