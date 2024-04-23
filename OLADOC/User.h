#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
using namespace std;

class user {
protected:
	char name[20];
	char pass[20];
	char CNIC[20];
	int Experience;
	char Feild[20];
	char Email[20];
	int workingHours1;
	int workingHours2;
	char hospital[20];
	int Fee;
	int stars;
	char city[20];
	int Bal;
	

public:

	string getName()
	{
		return name;
	}

	string getPass()
	{
		return pass;
	}

	string getCnic()
	{
		return CNIC;
	}

	int getexp()
	{
		return Experience;
	}

	string getmail()
	{
		return Email;
	}

	string getField()
	{
		return Feild;
	}

	int gethours1()
	{
		return workingHours1;
	}

	int gethours2()
	{
		return workingHours2;
	}

	string getHosp()
	{
		return hospital;
	}

	int getFee()
	{
		return Fee;
	}

	int getStars()
	{
		return stars;
	}

	string getCity()
	{
		return city;
	}


	void setEmail(string n)
	{
		strcpy_s(Email, n.c_str());
	}

	void setTime1(int n)
	{
		workingHours1 = n;
	}

	void setTime2(int n)
	{
		workingHours2 = n;
	}

	void setID(string s)
	{
		strcpy_s(CNIC, s.c_str());
	}

	void setFee(int s)
	{
		Fee = s;
	}

	void setExp(int e)
	{
		Experience = e;
	}

	void sethosp(string e)
	{
		strcpy_s(hospital, e.c_str());
	}

	void setcity(string e)
	{
		strcpy_s(city, e.c_str());
	}

	void setFeild(string e)
	{
		strcpy_s(Feild, e.c_str());
	}

	void setPass(string e)
	{
		strcpy_s(pass, e.c_str());
	}


	void setname(string n)
	{
		strcpy_s(name, n.c_str());
	}

	user()
	{
		name[0] = '\0';
		pass[0] = '\0';
		CNIC[0] = '\0';
		Email[0] = '\0';
		Experience = 0;
		Feild[0] = '\0';
		workingHours1 = 0;
		workingHours2 = 0;
		hospital[0] = '\0';
		Fee = 0;
		stars = 0;
		city[0] = '\0';
		Bal = 0;
	}

	user(string n, string p, string cn, string em, int e, string f, int w, int w1, string h, int fd, int s, string c,int b)
	{
		strcpy_s(name, n.c_str());
		strcpy_s(pass, p.c_str());
		strcpy_s(CNIC, cn.c_str());
		strcpy_s(Email, em.c_str());
		Experience = e;
		strcpy_s(Feild, f.c_str());
		workingHours1 = w;
		workingHours2 = w1;
		strcpy_s(hospital, h.c_str());
		Fee = fd;
		stars = s;
		strcpy_s(city, c.c_str());
		Bal = b;
	}

	void setValues(string n, string p, string cn, string em, int e, string f, int w, int w1, string h, int fd, int s, string c)
	{
		strcpy_s(name, n.c_str());
		strcpy_s(pass, p.c_str());
		strcpy_s(CNIC, cn.c_str());
		strcpy_s(Email, em.c_str());
		Experience = e;
		strcpy_s(Feild, f.c_str());
		workingHours1 = w;
		workingHours2 = w1;
		strcpy_s(hospital, h.c_str());
		Fee = fd;
		stars = s;
		strcpy_s(city, c.c_str());
	}


	bool CheckPass(string p)
	{
		int up = 0;
		int low = 0;
		int num = 0;
		int spe = 0;
		for (int i = 0; i < p.length(); i++)
		{
			if (p[i] >= 'A' && p[i] <= 'Z')
			{
				up+=1;
			}
				
			else if (p[i] >= 'a' && p[i] <= 'z')
			{
				low += 1;
			}
				
			else if (p[i] >= '0' && p[i] <= '9')
			{
				num+=1;
			}
				
			else
			{
				spe+=1;
			}
				
		}
		int z = p.size();
		if (spe >= 1 && low >= 1 && num >= 1 && up >= 1 && z == 8)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	void logout()
	{
		char choice;
		cout << "\n\n========================================================================================================================================================================" << endl;
		cout << "\nAre you sure you want to logout ? " << endl;
		cout << "\n--> Y/y for yes" << endl;
		cout << "\n--> N/n for no" << endl;
		cout << "\n\n========================================================================================================================================================================" << endl;
		cout << "\n\n Enter your choice: ";
		cin >> choice;

		if (choice == 'y' || choice == 'Y')
		{
			cout << "\n\n			<--------------------- You are logged out of your account --------------------> " << endl;
		}
	}


	

};
