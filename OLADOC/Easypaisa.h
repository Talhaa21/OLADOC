#pragma once


#include<iostream>
#include<fstream>
#include"Appointments.h"

using namespace std;

class Easypaisa
{

private:
	int mobBal;

private:

	Easypaisa()
	{
		mobBal = 0;
	}

	Easypaisa(int x)
	{
		mobBal = x;
	}

	void setValue(int x)
	{
		mobBal = x;
	}

	int getValue()
	{
		return mobBal;
	}


	~Easypaisa()
	{

	}



};