#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
#include"User.h"
#include"Appointments.h"
#include"Feedback.h"
using namespace std;

class patient;
void PatientWrite(patient, string);
void PatientRead(string);

class patient : public user
	

{

private:
	//int Bal;
public:

	patient()
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
		//Bal = 0;
	}

	patient (string n, string p, string cn, string em, int e, string f, int w, int w1, string h, int fd, int s, string c , int b)
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

	void setpatientValues(string n, string p, string c, string e, string cit , int b)
	{
		strcpy_s(name, n.c_str());
		strcpy_s(pass, p.c_str());
		strcpy_s(CNIC, c.c_str());
		strcpy_s(Email, e.c_str());
		strcpy_s(city, cit.c_str());
		Bal = b;
	}

	void setBal(int a)
	{
		Bal = a;
	}

	int getBal()
	{
		return Bal;
	}
	

	void addPatient(patient p, string s)
	{
		PatientWrite(p , s);
	}

	void readPatient(string s)
	{
		PatientRead(s);
	}

	void readDoc(string s)
	{
		DocRead(s);
	}

	bool login(string n, string p)
	{
		patient A;
		ifstream f("Patient.dat", ios::binary | ios::app);

		while (!f.eof())
		{
			do
			{
				if (A.name == n && A.pass == p)
				{
					return true;
				}

			} while (f.read((char*)&A, sizeof(A)));
		}
		f.close();
		return false;
	}

	void Recharge(string n, string p , int x)
	{
		patient A;
		int myvar = 0;
		fstream f("Patient.dat", ios ::out | ios:: in |ios::binary );

		while (!f.eof())
		{
			while (f.read((char*)&A, sizeof(A)))
			{

				if (A.name == n && A.pass == p)
				{
					myvar=A.Bal+x;

					A.setBal(myvar);
					int a = f.tellg();
					int s = sizeof(doctor);
					f.seekp(a - s, ios::beg);
					f.write((char*)&A, sizeof(A));
					break;
				}
			}
		}
		f.close();
		//return false;
	}


	void editPass(string oldp, string newp)
	{
		patient A;
		fstream f("Patient.dat", ios::out | ios::in | ios::binary);

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


	void searchPatient(string s , string x)
	{
		patient A;
		fstream f("Patient.dat", ios::out | ios::in | ios::binary);

		while (!f.eof())
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.name == s && A.pass == x)
				{
					cout << "\n\n\n\n\n\n							<----------------- SEARCHED PROFILE ----------------->";
					cout << "\n\n==============================================================================================================================================================" << endl;
					cout << "\n\nName : " << A.name << endl;
					cout << "Password : " << A.pass << endl;
					cout << "CNIC : " << A.CNIC << endl;
					cout << "Email: " << A.Email << endl;
					cout << "City: " << A.city << endl;
					cout << "Balance: " << A.Bal << endl;
					cout << "\n\n==================================================================================================================================================================" << endl;
					break;
				}
			}

		} 
		f.close();
	}


	bool writefeedback(string name, string a, int b)
	{

		Feedback* f = new Feedback;

		bool A = f->writefeedback(name, a, b);

		return A;

	}



	void AppointmentPatientProf(string s)
	{
		//Appointment A;
		patient A;
		fstream f("Patient.dat", ios::out | ios::in | ios::binary);

		while (!f.eof())
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.getName() == s)
				{
					cout << "\n\n\n\n\n\n							<----------------- APPOINTMENTS PATIENT PROFILE ----------------->";
					cout << "\n\n==============================================================================================================================================================" << endl;
					cout << "\n\nName : " << A.getName() << endl;
					cout << "Password : " << A.getPass() << endl;
					cout << "CNIC : " << A.getCnic() << endl;
					cout << "Email: " << A.getmail() << endl;
					cout << "City: " << A.getCity() << endl;
					cout << "\n\n==================================================================================================================================================================" << endl;
					break;
				}
			}

		}
		f.close();
	}

	void viewProf()
	{
		cout << "\n\n===================================================================" << endl;
		cout << "\n\n";
		cout << "Name: " << name << endl;
		cout << "CNIC: " << CNIC << endl;
		cout << "Email: " << Email << endl;
		cout << "Experience: " << Experience << endl;
		cout << "Feild: " << Feild << endl;
		cout << "Starting Time: " << workingHours1 << endl;
		cout << "Ending Time : " << workingHours2 << endl;
		cout << "Hospital: " << hospital << endl;
		cout << "Fee: " << Fee << endl;
		cout << "Stars: " << stars << endl;
		cout << "City: " << city << endl;
		cout << "Balance: " << Bal << endl;
		cout << "\n\n===================================================================" << endl;
	}


	void editName(string oldn, string newn)
	{
		patient A;
		fstream f("Patient.dat", ios::out | ios::in | ios::binary);

		do
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.getName() == oldn)
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

	void editCity(string oldn, string newn)
	{
		patient A;
		fstream f("Patient.dat", ios::out | ios::in | ios::binary);

		do
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.getCity() == oldn)
				{
					A.setcity(newn);
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

	void setx(string y)
	{
		strcpy_s(city, y.c_str());
	}

	string getx()
	{
		return city;
	}

	void x(string oldn, string newn)
	{
		patient A;
		fstream f("Patient.dat", ios::out | ios::in | ios::binary);

		do
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.getx() == oldn)
				{
					A.setx(newn);
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


	void setAppointment(string dname, string pname, string pcnic, int slots1 , int slots2 , string day, string status)
	{
		Appointment* A = new Appointment;
		bool flag;
		(*A).setAppointment(dname, pname,  pcnic,  slots1 , slots2, day, "PENDING");
		
	}

	void viewDetail(string a)
	{
		Appointment* A = new Appointment;
		(*A).viewDetail(a);
	}

};