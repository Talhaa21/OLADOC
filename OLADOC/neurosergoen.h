#pragma once


#include<iostream>
#include<fstream>
#include"User.h"
#include"DOCTOR.h"

using namespace std;

class neurosergoen //: public user
{
private:
	doctor A;


public:
	void DocsProf(string a)
	{
		//neurosergoen A;
		//doctor A;
		//user A;
		ifstream f("DocData.dat", ios::binary | ios::app);
		while (!f.eof())
		{
			while (f.read((char*)&A, sizeof(A)))
			{
				if (A.getField() == a)
				{
					cout << "\n\n======================================================================================================================================================================" << endl;
					cout << "\n--> NAME : "          << A.getName()      << endl;
					cout << "\n--> CNIC: "           << A.getCnic()      << endl;
					cout << "\n--> Email: "          << A.getmail()      << endl;
					cout << "\n--> Experience: "     << A.getexp()       << endl;
					cout << "\n--> Feild: "          << A.getField()     << endl;
					cout << "\n--> Starting Time: "  << A.gethours1()    << endl;
					cout << "\n--> Ending Time :  "  << A.gethours2()    << endl;
					cout << "\n--> Hospital: "       << A.getHosp()      << endl;
					cout << "\n--> Fee : "           << A.getFee()       << endl;
					cout << "\n--> Stars : "         << A.getStars()     << endl;
					cout << "\n--> City : "          << A.getCity()      << endl;
					cout << "\n\n======================================================================================================================================================================" << endl;
					break;
				}

				if (A.getName() == a)
				{
					cout << "\n\n======================================================================================================================================================================" << endl;
					cout << "\n--> NAME : " << A.getName() << endl;
					cout << "\n--> CNIC: " << A.getCnic() << endl;
					cout << "\n--> Email: " << A.getmail() << endl;
					cout << "\n--> Experience: " << A.getexp() << endl;
					cout << "\n--> Feild: " << A.getField() << endl;
					cout << "\n--> Starting Time: " << A.gethours1() << endl;
					cout << "\n--> Ending Time :  " << A.gethours2() << endl;
					cout << "\n--> Hospital: " << A.getHosp() << endl;
					cout << "\n--> Fee : " << A.getFee() << endl;
					cout << "\n--> Stars : " << A.getStars() << endl;
					cout << "\n--> City : " << A.getCity() << endl;
					cout << "\n\n======================================================================================================================================================================" << endl;
					break;
				}

				if (A.getHosp() == a)
				{
					cout << "\n\n======================================================================================================================================================================" << endl;
					cout << "\n--> NAME : " << A.getName() << endl;
					cout << "\n--> CNIC: " << A.getCnic() << endl;
					cout << "\n--> Email: " << A.getmail() << endl;
					cout << "\n--> Experience: " << A.getexp() << endl;
					cout << "\n--> Feild: " << A.getField() << endl;
					cout << "\n--> Starting Time: " << A.gethours1() << endl;
					cout << "\n--> Ending Time :  " << A.gethours2() << endl;
					cout << "\n--> Hospital: " << A.getHosp() << endl;
					cout << "\n--> Fee : " << A.getFee() << endl;
					cout << "\n--> Stars : " << A.getStars() << endl;
					cout << "\n--> City : " << A.getCity() << endl;
					cout << "\n\n======================================================================================================================================================================" << endl;
					break;
				}

				if (A.getCity() == a)
				{
					cout << "\n\n======================================================================================================================================================================" << endl;
					cout << "\n--> NAME : " << A.getName() << endl;
					cout << "\n--> CNIC: " << A.getCnic() << endl;
					cout << "\n--> Email: " << A.getmail() << endl;
					cout << "\n--> Experience: " << A.getexp() << endl;
					cout << "\n--> Feild: " << A.getField() << endl;
					cout << "\n--> Starting Time: " << A.gethours1() << endl;
					cout << "\n--> Ending Time :  " << A.gethours2() << endl;
					cout << "\n--> Hospital: " << A.getHosp() << endl;
					cout << "\n--> Fee : " << A.getFee() << endl;
					cout << "\n--> Stars : " << A.getStars() << endl;
					cout << "\n--> City : " << A.getCity() << endl;
					cout << "\n\n======================================================================================================================================================================" << endl;
					break;
				}
			}
		}
		f.close();
	}
};