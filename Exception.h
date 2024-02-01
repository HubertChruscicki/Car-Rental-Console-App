#pragma once
#include <iostream>       
#include <exception>

using namespace std;

class FileOpenErrException : public exception
{
public:
	FileOpenErrException() : exception("FOE - File Open Error")
	{
	}

};

class FileCloseErrException : public exception
{
public:
	FileCloseErrException() : exception("FCE - File Close Error")
	{
	}
};

class FileSaveErrException : public exception
{
public:
	FileSaveErrException() : exception("FSE - File Save Error")
	{
	}
};

class FileLoadErrException : public exception
{
public:
	FileLoadErrException() : exception("FLE - File Load Error")
	{
	}
};