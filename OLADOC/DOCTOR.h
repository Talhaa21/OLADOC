#pragma once
#include<iostream>
#include<fstream>
#include"User.h"
#include<string>
#include<cstring>

using namespace std;

class doctor;
void DocWrite(doctor, string);
void DocRead(string);

class doctor : public user
{
protected:
	/*char CNIC[20];
	int Experience;
	char Feild[20];
	char Email[20];
	int workingHours1;
	int workingHours2;
	char hospital[20];
	int Fee;
	int stars;
	char city[20];*/

public:

	doctor()
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
	}


	/*doctor(string n, string p, string cn, string em, int e, string f, int w, int w1, string h, int fd, int s, string c)
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
	}*/

	
	void addDoc(doctor D, string s)
	{
		DocWrite(D, s);
	}

	void readDoc(string s)
	{
		DocRead(s);
	}

	bool login(string n, string p)
	{
		doctor A;
		ifstream f("DocData.dat", ios::binary | ios :: app);

		while (!f.eof())
		{
			do
			{
				if (A.name == n && A.pass == p)
				{
					return true;
				}
				
			}while (f.read((char*)&A, sizeof(A)));
		}
		f.close();
		return false;
	}

	void editTime(int ost , int nst , int oet, int net)
	{
		doctor A;
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
		doctor A;
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
		doctor A;
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
		doctor A;
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

	void editPass(string oldp,string newp)
	{
		doctor A;
		fstream f("DocData.dat", ios :: out | ios:: in | ios::binary);

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
		doctor A;
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

	bool checkCNIC(string ID)
	{
		doctor A;
		ifstream f("DocData.dat", ios::binary | ios::app);

		while (!f.eof())
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.getCnic() == ID)
				{
					f.close();
					return true;
				}
			}
		} 
		f.close();
		return false;
	}

	void DocsProf(string a, string b)
	{
		doctor A;
		ifstream f("DocData.dat", ios::binary | ios::app);
		while (!f.eof())
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.name == a && A.pass == b)
				{
					cout << "\n\n\n\n							<---------------- Y O U R      P R O F I L E ------------------>";
					cout << "\n\n\n========================================================================================================================================================================" << endl;
					cout << "\n\n--> NAME : " << A.name << endl;
					cout << "\n--> CNIC: " << A.CNIC << endl;
					cout << "\n--> Email: " << A.Email << endl;
					cout << "\n--> Experience: " << A.Experience << endl;
					cout << "\n--> Feild: " << A.Feild << endl;
					cout << "\n--> Starting Time: " << A.workingHours1 << endl;
					cout << "\n--> Ending Time : " << A.workingHours2 << endl;
					cout << "\n--> Hospital: " << A.hospital << endl;
					cout << "\n--> Fee: " << A.Fee << endl;
					cout << "\n--> Stars: " << A.stars << endl;
					cout << "\n--> City: " << A.city << endl;
					cout << "\n\n=======================================================================================================================================================================" << endl;
					break;
				}
			}
		}
		f.close();
	}


	void Prof(string a)
	{
		doctor A;
		ifstream f("DocData.dat", ios::binary | ios::app);
		while (!f.eof())
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.name == a)
				{
					cout << "\n\n\n\n							<---------------- D O C T O R S      P R O F I L E ------------------>";
					cout << "\n\n\n========================================================================================================================================================================" << endl;
					cout << "\n\n--> NAME : " << A.name << endl;
					cout << "\n--> CNIC: " << A.CNIC << endl;
					cout << "\n--> Email: " << A.Email << endl;
					cout << "\n--> Experience: " << A.Experience << endl;
					cout << "\n--> Feild: " << A.Feild << endl;
					cout << "\n--> Starting Time: " << A.workingHours1 << endl;
					cout << "\n--> Ending Time : " << A.workingHours2 << endl;
					cout << "\n--> Hospital: " << A.hospital << endl;
					cout << "\n--> Fee: " << A.Fee << endl;
					cout << "\n--> Stars: " << A.stars << endl;
					cout << "\n--> City: " << A.city << endl;
					cout << "\n\n=======================================================================================================================================================================" << endl;
					break;
				}
			}
		}
		f.close();
	}

	void viewProf()
	{
		cout << "\n\n\n\n							<----------------  P R O F I L E S------------------>";
		cout << "\n\n==============================================================" << endl;
		cout << "\n--> Name: " << name << endl;
		cout << "--> CNIC: " << CNIC << endl;
		cout << "--> Email: " << Email << endl;
		cout << "--> Experience: " << Experience << endl;
		cout << "--> Feild: " << Feild << endl;
		cout << "--> Starting Time: " << workingHours1 << endl;
		cout << "--> Ending Time : " << workingHours2 << endl;
		cout << "--> Hospital: " << hospital << endl;
		cout << "--> Fee: " << Fee << endl;
		cout << "--> Stars: " << stars << endl;
		cout << "--> City: " << city << endl;
		cout << "==============================================================" << endl;
	}



	
};