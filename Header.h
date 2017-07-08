#pragma once
#include "stdafx.h"
#include <string>



class Time
{

public:

	
	virtual void getTime()=0;

};


class ActualTime:public Time
{

public:
static std::string returnActualDate();
void getTime()
{}

};
template<typename T>
class File
{

public:
	virtual T getIng(T t)=0;
	virtual T saveFile(T t)=0;
	virtual T getName()=0;
	virtual T setName()=0;
};


template<typename T>
class OpenFile:public File<T>
{
public:
	T getIng(T t);
	virtual T saveFile(T t) { return t; }
	virtual T getName() {  return 1; };
	virtual T setName() { return 1; }
};
template<typename T>
class SaveFile
{
public:
	T saveFile(T t);
	


};
std::string getNameOfBASEWITHALLRECORD();
class PatternOfFile
{

public:
	void filePattern(FILE *&fp,char *nameOfFile);
	static bool findPattern(std::string pattern,std::string=getNameOfBASEWITHALLRECORD());
	
};

class Activity
{

public:
	virtual int act() = 0;
	

};

class AddSingleActivity : Activity
{

public:
	int act();


};
class AddQuickActivity : Activity
{

public:
	int act();

};
template<typename T, typename N>
class RemoveActivity
{
public: 
	
	int act(T t,N n);

};
class Valid
{
public:
	

};
class StreamValid
{


};
class Settings
{
	bool slowWriting;
	
public:
	Settings() :slowWriting(true) {}
	void setting();
	static bool Settings::SlowWriting();
	static void writeOnTheScreenText(std::string textToWrite);
};