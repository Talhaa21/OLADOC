#pragma once
#pragma once
#pragma once


#include<iostream>
#include<fstream>
#include"Appointments.h"

using namespace std;

class Paypal
{

private:
	int BankBal;

private:

	Paypal()
	{
		BankBal = 0;
	}

	Paypal(int x)
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


	~Paypal()
	{

	}



};