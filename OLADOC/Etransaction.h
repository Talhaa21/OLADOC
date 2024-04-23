#pragma once

#include<iostream>
#include<fstream>
#include"Appointments.h"

using namespace std;

class E
{

private:
	int BankBal;

private:

	E()
	{
		BankBal = 0;
	}

	E(int x)
	{
		BankBal = x;
	}

	void setValue(int x)
	{
		BankBal = x;
	}

	int getValue()
	{
		return BankBal;
	}


	~E()
	{

	}



};