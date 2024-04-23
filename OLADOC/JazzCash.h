#pragma once
#pragma once


#include<iostream>
#include<fstream>
#include"Appointments.h"

using namespace std;

class JazzCash
{

private:
	int mobBal;

private:

	JazzCash()
	{
		mobBal = 0;
	}

	JazzCash(int x)
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


	~JazzCash()
	{

	}



};