#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
#include"User.h"
#include"DOCTOR.h"

using namespace std;

class admin : public user
{

public:
	bool checkLogin(string a , string b)
	{
		admin A;
		ifstream doc("Admin.dat", ios::binary | ios::app);

		while (!doc.eof())
		{
			while (doc.read((char*)&A, sizeof(A)))
			{
				if (A.getName() == a && A.getPass() == b)
				{
					//doc.close();
					return true;
				}
			}
		} 
		doc.close();
		return false;
	}

	void searchDoc(string s, string c)
	{
		admin A;
		doctor d;
		fstream f("DocData.dat", ios::out | ios::in | ios::binary);

		do
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.name == s && A.CNIC == c)
				{
					cout << "\n\n=============================================================================================================================================================" << endl;
					cout << "\n\n--> Name : " << A.name << endl;
					cout << "\n--> Password : " << A.pass << endl;
					cout << "\n--> CNIC : " << A.CNIC << endl;
					cout << "\n--> Email: " << A.Email << endl;
					cout << "\n--> Experience: " << A.Experience << endl;
					cout << "\n--> Feild: " << A.Feild << endl;
					cout << "\n--> Starting Time: " << A.workingHours1 << endl;
					cout << "\n--> Ending Time : " << A.workingHours1 << endl;
					cout << "\n--> Hospital: " << A.hospital << endl;
					cout << "\n--> Fee: " << A.Fee << endl;
					cout << "\n--> Stars: " << A.stars << endl;
					cout << "\n--> City: " << A.city << endl;
					cout << "\n\n==============================================================================================================================================================" << endl;
				}
			}
			
		} while (!f.eof());
		
		f.close();
	}


	void editTime(int ost, int nst, int oet, int net)
	{
		admin A;
		fstream f("DocData.dat", ios::out | ios::in | ios::binary);
		while (!f.eof())
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.workingHours1 == ost && A.workingHours2 == oet)
				{
					A.setTime1(nst);
					A.setTime2(net);

					int a = f.tellg();
					int s = sizeof(doctor);
					f.seekp(a - s, ios::beg);
					f.write((char*)&A, sizeof(A));
					break;
				}
			}
		}
		f.close();
	}



	void editFee(int a, int b)
	{
		admin A;
		fstream f("DocData.dat", ios::out | ios::in | ios::binary);
		while (!f.eof())
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.Fee == a)
				{
					A.setFee(b);

					int a = f.tellg();
					int s = sizeof(doctor);
					f.seekp(a - s, ios::beg);
					f.write((char*)&A, sizeof(A));
					break;
				}
			}
		}
		f.close();
	}


	void editHosp(string a, string b)
	{
		admin A;
		fstream f("DocData.dat", ios::out | ios::in | ios::binary);
		while (!f.eof())
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.hospital == a)
				{
					A.sethosp(b);

					int a = f.tellg();
					int s = sizeof(doctor);
					f.seekp(a - s, ios::beg);
					f.write((char*)&A, sizeof(A));
					break;
				}
			}
		}
		f.close();
	}

	void editCity(string a, string b)
	{
		admin A;
		fstream f("DocData.dat", ios::out | ios::in | ios::binary);
		while (!f.eof())
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.city == a)
				{
					A.setcity(b);

					int a = f.tellg();
					int s = sizeof(doctor);
					f.seekp(a - s, ios::beg);
					f.write((char*)&A, sizeof(A));
					break;
				}
			}
		}
		f.close();
	}

	void editPass(string oldp, string newp)
	{
		admin A;
		fstream f("DocData.dat", ios::out | ios::in | ios::binary);

		do
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.pass == oldp)
				{
					A.setPass(newp);
					int a = f.tellg();
					int s = sizeof(doctor);
					f.seekp(a - s, ios::beg);
					f.write((char*)&A, sizeof(A));
					break;
				}
			}
		} while (!f.eof());
		f.close();
	}

	void editName(string oldn, string newn)
	{
		admin A;
		fstream f("DocData.dat", ios::out | ios::in | ios::binary);

		do
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.name == oldn)
				{
					A.setname(newn);
					int a = f.tellg();
					int s = sizeof(doctor);
					f.seekp(a - s, ios::beg);
					f.write((char*)&A, sizeof(A));
					break;
				}
			}
		} while (!f.eof());
		f.close();
	}


	void DltDoc(string a)
	{

		admin A;

		ifstream f("DocData.dat", ios::in | ios::binary);

		ofstream mf("New.dat", ios::out | ios::binary);

		while (f.read((char*)&A, sizeof(A)))
		{

			if (A.CNIC != a)
			{
				mf.write((char*)&A, sizeof(A));
			}
		}

		f.close();
		mf.close();

		remove("DocData.dat");
		rename("New.dat", "DocData.dat");
		f.close();
		mf.close();
	}


};