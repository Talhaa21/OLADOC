#pragma once
#include<iostream>
#include<fstream>
#include"DOCTOR.h"
#include"Patient.h"
#include"User.h"
using namespace std;

//class doctor;
//void DocWrite(doctor, string);
//void DocRead(string);

class Appointment
{

protected:

	int* st;
	int* et;
	char CNICC[20];
	char Day[20];
	int Availableslot;
	char pID[20];
	char status[20];
	char docName[20];
	char pName[20];
	int st1, et1;
	

public:

	void setDocName(string a)
	{
		strcpy_s(docName, a.c_str());
	}
	void setPName(string a)
	{
		strcpy_s(pName, a.c_str());
	}
	void setPcnic(string a)
	{
		strcpy_s(pID, a.c_str());
	}
	void setstatus(string a)
	{
		strcpy_s(status, a.c_str());
	}
	
	void setslot1(int a)
	{
		st1 = a;
	}

	void setslot2(int a)
	{
		et1 = a;
	}

	void setCNICC(string name)
	{
		strcpy_s(CNICC, name.c_str());
	}

	void setDay(string name)
	{
		strcpy_s(Day, name.c_str());
	}

	string getcnic()
	{
		return CNICC;
	}

	string getday()
	{
		return Day;
	}

	int gets1()
	{
		return st1;
	}

	int gete1()
	{
		return et1;
	}

	string getstatus()
	{
		return status;
	}

	string getdname()
	{
		return docName;
	}

	string getpname()
	{
		return pName;
	}

	string getPid()
	{
		return pID;
	}


	void readDoc(string s)
	{
		DocRead(s);
	}

	void slots(string a)
	{
		int temp = 0;
		int x, y;
		doctor A;
		ifstream f("DocData.dat", ios::binary | ios::app);
		while (!f.eof())
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.getName() == a)
				{
					 x = A.gethours1();
					 y = A.gethours2();
					 temp = y - x;

					st = new int[temp];
					et = new int[temp];

					for (int i = 0; i < temp; i++)
					{
						st[i] = x;
						et[i] = x + 1;
						x += 1;
					}

				}
			}
		}

		for (int j = 0; j < temp; j++)
		{
			cout << "\n---> Slot " << j + 1 << " :     " << st[j] << " : 00  -  " << et[j] <<" : 00" << endl;

		}
		f.close();
	}

	void setAppointment(string dname, string pname, string pcnic, int slot1 , int slot2 , string day, string status)
	{
		//bool flag;
		//docAvailability(day, slot);

		
			Appointment A;

			A.setDocName(dname);
			A.setPName(pname);
			A.setPcnic(pcnic);
			A.st1 = slot1;
			A.et1 = slot2;
			A.setDay(day);
			A.setstatus(status);

			A.Write(A);
			cout << "\n\n			<------------------- APPOINTMNENT BOOKED -------------------->\n";
		//}

		/*else
		{
			cout << "\n\n				<------------- No Doctor Available----------------->\n";
			return false;*/
		//}
	}


	void viewDetail(string a)
	{
		Appointment A;
		ifstream f("Appointment.dat", ios::binary | ios::app);

		while (f.read((char*)&A, sizeof(A)))
		{
			if (A.pID == a)
			{
				A.viewProf();
			}
		}
		f.close();
	}


	void viewProf()
	{
		Appointment A;

		ifstream f("Appointment.dat", ios::binary | ios::app);
		while (!f.eof())
		{
			while (f.read((char*)&A, sizeof(A)))
			{

				cout << "\n\n					<--------------- A P P O I N T M E N T        D E T A I L S ------------------->\n\n";
				cout << "\n\n========================================================================================================================================================================" << endl;
				cout << "\n\n---> Doctors Name : " << A.getdname() << endl;
				cout << "\n\n---> Patient Name : " << A.getpname() << endl;
				cout << "\n\n---> Appointment booked Day : " << A.getday() << endl;
				cout << "\n\n---> Appointment from : " << A.gets1() << "  -  "<<A.gete1() << endl;
				cout << "\n\n---> Appointment Status : " << A.getstatus() << endl;
				cout << "\n\n========================================================================================================================================================================" << endl;
			}
		}
	}

	void viewProf1(string s)
	{
		Appointment A;

		ifstream f("Appointment.dat", ios::binary | ios::app);
		while (!f.eof())
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.pName == s)
				{

					cout << "\n\n					<--------------- A P P O I N T M E N T        D E T A I L S ------------------->\n\n";
					cout << "\n\n========================================================================================================================================================================" << endl;
					cout << "\n\n---> Doctors Name : " << A.getdname() << endl;
					cout << "\n\n---> Patient Name : " << A.getpname() << endl;
					cout << "\n\n---> Appointment booked Day : " << A.getday() << endl;
					cout << "\n\n---> Appointment from : " << A.gets1() << "  -  " << A.gete1() << endl;
					cout << "\n\n---> Appointment Status : " << A.getstatus() << endl;
					cout << "\n\n========================================================================================================================================================================" << endl;
				}
			}
		}
	}

	bool docAvailability(string d,  int s)
	{
		Appointment A;
		ifstream f("Appointment.dat", ios::binary | ios::app);

		while (f.read((char*)&A, sizeof(A)))
		{
			if (A.getday() == d && A.st1 == s)
			{
				f.close();
				return false;
			}
		}
		f.close();
		return true;
	}

	void Write(Appointment A)
	{
		ofstream f("Appointment.dat", ios::binary | ios::app);
		f.write((char*)&A, sizeof(A));
		f.close();
	}


	bool AproveAppointmentt(string b, string a, string c)
	{
		Appointment A;
		fstream f("Appointment.dat", ios::out | ios::in | ios::binary);

		while (f.read((char*)&A, sizeof(A)))
		{
			if (A.getpname() == b && A.getday() == c )
			{

				A.setstatus(a);

				int a = f.tellg();
				int s = sizeof(Appointment);
				f.seekp(a - s, ios::beg);
				f.write((char*)&A, sizeof(A));
				f.close();
				return true;
			}
		}
		return false;
		f.close();

	}

	void doneAppointment(string a , string b)
	{
		Appointment A;
		fstream f("Appointment.dat", ios::out | ios::in | ios::binary);

		while (f.read((char*)&A, sizeof(A)))
		{
			if (A.getpname() == a && A.status == b)
			{
				cout << "\n\n========================================================================================================================================================================" << endl;
				cout << "\n\n---> Doctors Name : " << A.getdname() << endl;
				cout << "\n\n---> Patient Name : " << A.getpname() << endl;
				cout << "\n\n---> Appointment booked Day : " << A.getday() << endl;
				cout << "\n\n---> Appointment from : " << A.gets1() << "  -  " << A.gete1() << endl;
				cout << "\n\n---> Appointment Status : " << A.getstatus() << endl;
				cout << "\n\n========================================================================================================================================================================" << endl;

			}
		}
		f.close();
	}
	bool viewstatus(string a, string d ,string ch)
	{
		Appointment Aa;

		ifstream doc("Appointment.dat", ios::binary | ios::in | ios::out);

		while (doc.read((char*)&Aa, sizeof(Aa)))
		{
			if (/*Aa.getcnic() == a &&*/ Aa.getday() == d  && Aa.getstatus() == ch)
			{
				doc.close();
				return true;

			}
		}

		doc.close();
		return false;
	}


	bool updatestatus(string b, string a, string c)
	{
		Appointment Aa;

		fstream doc("Appointment.dat", ios::out | ios::in | ios::binary);

		while (doc.read((char*)&Aa, sizeof(Aa)))
		{
			if (Aa.getcnic() == b && Aa.getday() == c)
			{

				Aa.setstatus(a);

				int a = doc.tellg();
				int s = sizeof(Appointment);
				doc.seekp(a - s, ios::beg);
				doc.write((char*)&Aa, sizeof(Aa));
				doc.close();
				return true;

			}
		}

		return false;
		doc.close();
	}


};