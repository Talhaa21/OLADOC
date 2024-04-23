#pragma once
#include<iostream>
#include<fstream>
#include"DOCTOR.h"
#include<cstring>
using namespace std;

class Feedback
{
private:
	char arr[100];
	char ID[100];
	int rating;
	char Feedbackk[100];

public:

	
	Feedback()
	{
		arr[0] = '\0';
		ID[0] = '\0';
		rating = 0;
		Feedbackk[0] = '\0';
	}


	void setValues(string a, string b, int c, string d)
	{
		strcpy_s(arr, a.c_str());
		strcpy_s(ID, b.c_str());
		rating = c;
		strcpy_s(Feedbackk, d.c_str());
	}

	string getf()
	{
		return ID;
	}

	string getr()
	{
		return arr;
	}

	void setID(string a)
	{
		strcpy_s(ID, a.c_str());
	}

	void setCNIC(string a)
	{
		strcpy_s(arr, a.c_str());
	}


	void Write(Feedback A)
	{
		ofstream f("Feedback.dat", ios::binary | ios::app);
		f.write((char*)&A, sizeof(A));
		f.close();
	}

	void setrating(int r)
	{
		rating = r;
	}
	int getrating()
	{
		return rating;
	}

	void Read(string x)
	{
		Feedback A;
		ifstream fb("Feedback.dat", ios::binary | ios::app);
		while (!fb.eof())
		{
			while (fb.read((char*)&A, sizeof(A)))
			{
				//if (A.getf() == x)
				//{
					cout << "\n========================================================================================================================================================================" << endl;
					cout << "\n\n";
					cout << "--->    FEEDBACK : " << "Good" << "     RATINGS: " << A.getrating() << endl;
					cout << "\n========================================================================================================================================================================" << endl;
				//}
			}
		}
		fb.close();
	}

	void setfeed(string d)
	{
		strcpy_s(Feedbackk, d.c_str());
	}

	string getfeed()
	{
		return Feedbackk;
	}


	bool writefeedback(string a, string b, int c)
	{
		Feedback A;

		A.setID(b);
		A.setfeed(a);
		A.setrating(c);

		Write(A);
		return true;

	}
};