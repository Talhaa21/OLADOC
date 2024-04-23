#include<iostream>
#include<fstream>
#include"DOCTOR.h"
#include"User.h"
#include"Admin.h"
#include"Patient.h"
#include"neurosergoen.h"
#include"Appointments.h"
#include"Feedback.h"


using namespace std;


void DocWrite(doctor D1, string D)
{
	ofstream Doc(D, ios::binary | ios::app);
	Doc.write((char*)&D1, sizeof(D1));
	Doc.close();
}

void DocRead(string str)
{
	doctor D2;
	ifstream Doc(str, ios::binary | ios::app);

	while (Doc.read((char*)&D2 , sizeof(D2)))
	{
		D2.viewProf();
	}
	Doc.close();
}

void AdminWrite(admin D1, string D)
{
	ofstream Doc(D, ios::binary | ios::app);
	Doc.write((char*)&D1, sizeof(D1));
	Doc.close();
}

void AdminRead(string str)
{
	admin D;
	ifstream Doc(str, ios::binary | ios::app);

	while (Doc.read((char*)&D, sizeof(D)))
	{
		//D2.viewProf();
	}
	Doc.close();
}

void PatientWrite(patient P, string str)
{
	ofstream f(str, ios::binary | ios::app);
	f.write((char*)&P, sizeof(P));
	f.close();
}

void PatientRead(string str)
{
	patient P;
	ifstream f(str, ios::binary | ios::app);

	while (f.read((char*)&P, sizeof(P)))
	{
		P.viewProf();
	}
	f.close();
}

void AppointmentWrite(Appointment P, string str)
{
	ofstream f(str, ios::binary | ios::app);
	f.write((char*)&P, sizeof(P));
	f.close();
}

void AppointmentRead(string str)
{
	Appointment P;
	ifstream f(str, ios::binary | ios::app);

	while (f.read((char*)&P, sizeof(P)))
	{
		//P.viewProf();
	}
	f.close();
}






int main()
{
	user U;
	doctor D;
	neurosergoen n;
	admin A;
	patient p;
	Appointment Ap;
	Feedback F;
	int choice = 0;
	int cho = 0;
	string name;
	string email;
	string pass;
	string CNIC;
	int exp = 0;
	string field;
	string hosp;
	int whours = 0;
	int whors = 0;
	int fee = 0;
	string cit;
	int st = 0;
	char j;
	char as;
	do
	{

		/*cout << "\n\n							<========== Welcome to Oladoc ==========> " << endl;*/
		cout << "\n\n\n";

			
			cout << "                                             *********   *           *********   *           *********   *********     " << endl;
			cout << "                                             *       *   *           *       *   * *         *       *   *             " << endl;
			cout << "                                             *       *   *           *       *   *  *        *       *   *             " << endl;
			cout << "                                             *       *   *           *       *   *   *       *       *   *             " << endl;
			cout << "                                             *       *   *           *       *   *    *      *       *   *             " << endl;
			cout << "                                             *       *   *           *       *   *     *     *       *   *             " << endl;
			cout << "                                             *       *   *           *       *   *      *    *       *   *             " << endl;
			cout << "                                             *       *   *           *********   *       *   *       *   *             " << endl;
			cout << "                                             *       *   *           *       *   *      *    *       *   *             " << endl;
			cout << "                                             *       *   *           *       *   *     *     *       *   *             " << endl;
			cout << "                                             *       *   *           *       *   *    *      *       *   *             " << endl;
			cout << "                                             *       *   *           *       *   *   *       *       *   *             " << endl;
			cout << "                                             *       *   *           *       *   *  *        *       *   *             " << endl;
			cout << "                                             *       *   *           *       *   * *         *       *   *             " << endl;
			cout << "                                             *********   *********   *       *   *           *********   *********     " << endl;
			
		
		cout << "\n\n\n\n\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\n\n							<------------------- M E N U ------------------->" << endl;
		cout << "\n ======================================================================================================================================================================" << endl;
		cout << "| \n| \n| --> Press 1 for Doctor " << endl;
		cout << "| \n| --> Press 2 for Admin " << endl;
		cout << "| \n| --> Press 3 for Patient " << endl;
		cout << "| \n ======================================================================================================================================================================" << endl;
		cout << "\n\nPlease enter your choice: ";
		cin >> choice;
		
		system("CLS");

		//------------------------------ D O C T O R -----------------------------------
		if (choice == 1)
		{
			int cho;
			cout << "\n								<-------- D O C T O R --------->" << endl;
			cout << "\n======================================================================================================================================================================" << endl;
			cout << "\n\n--> Press 1 for login " << endl;
			cout << "\n--> Press 2 for Sign Up " << endl;
			cout << "\n========================================================================================================================================================================" << endl;
			cout << "\n\n\n Select your option: ";
			cin >> cho;
			system("CLS");

			if (cho == 1)
			{
				int counter = 0;
				string a;
				string b;
				//doctor d;

				bool b1 = false;
				int counter2 = 0;
				cout << "\n\n							<----------------- L O G I N   P A N E L -----------------> " << endl;
				do
				{

					cout << "\n\n\n========================================================================================================================================================================" << endl;
					cout << "\n---> Enter your Name: ";
					cin >> a;
					do
					{
						cout << "\n---> Enter your Password (Must be 8 digit long including 1 special letter) :";
						cin >> b;

						if (!D.CheckPass(b))
						{
							cout << "\nPassword not Correct: ";

						}
						else
						{
							counter = b.size();
						}
						
						cout << "\n========================================================================================================================================================================" << endl;

					} while (counter != 8);

					b1 = D.login(a, b);

					if (b1)
					{
						counter2++;
					}
				} while (!b1);


				//if (D.login(a, b) == true)
				//{
					system("CLS");
					cout << "\n\n\n									<---------- Successfully Logged In ----------->";
					char x;
					do
					{
						int op;
						cout << "\n\n========================================================================================================================================================================" << endl;
						cout << "\n\n----> Press 1 to edit profile : " << endl;
						cout << "\n----> Press 2 to see appointment data:  " << endl;
						cout << "\n----> Press 3 to check appointment patient's detail : " << endl;
						cout << "\n----> Press 4 to check specialization area : " << endl;
						cout << "\n----> Press 5 to change appointments status : " << endl;
						cout << "\n----> Press 6 to check schedule : " << endl;
						cout << "\n----> Press 7 to view profile : " << endl;
						cout << "\n----> Press 8 to view feedback : " << endl;
						cout << "\n----> Press 9 to logout : " << endl;
						cout << "\n========================================================================================================================================================================" << endl;
						cout << "\n\n\nSelect any option: ";
						cin >> op;
						system("CLS");

						if (op == 1)
						{
							int op1;
							cout << "\n\n 							<---------- E D I T     P R O F I L E ------------->" << endl;
							cout << "\n========================================================================================================================================================================" << endl;
							cout << "\n\n----> Press 1 to change Name :" << endl;
							cout << "\n----> Press 2 to change Password :" << endl;
							cout << "\n----> Press 3 to edit Availability Time :" << endl;
							cout << "\n----> Press 4 to edit Hourly charge :" << endl;
							cout << "\n----> Press 5 to edit Hospital  :" << endl;
							cout << "\n----> Press 6 to edit City  :" << endl;
							cout << "\n\n========================================================================================================================================================================" << endl;
							cout << "\n\n\nSelect any option: ";
							cin >> op1;
							system("CLS");

							if (op1 == 1)
							{
								string oldname;
								string newname;
								cout << "\n\n 				    		<---------- E D I T     N A M E ------------->" << endl;
								cout << "\n\n========================================================================================================================================================================" << endl;
								cout << "\n--> Enter Old name : ";
								cin >> oldname;
								cout << "\n--> Enter New name : ";
								cin >> newname;
								cout << "\n\n========================================================================================================================================================================" << endl;

								//if (D.login(a, b) == true)
								//{
								D.editName(oldname, newname);
								//}
								cout << "\n\n				  	<------------------ Your Username has been updated --------------->";
							}

							if (op1 == 2)
							{
								string oldpass;
								string newpassword;
								cout << "\n\n 			   			<---------- E D I T     P A S S W O R D ------------->" << endl;
								cout << "\n\n========================================================================================================================================================================" << endl;
								cout << "\n--> Enter old password: ";
								cin >> oldpass;

								cout << "\n--> Enter new password: ";
								cin >> newpassword;
								cout << "\n\n========================================================================================================================================================================" << endl;

								//doctor D;
								//if (D.login(a, b) == true)
								//{
								D.editPass(oldpass, newpassword);
								//}
								cout << "\n				<----------------------- Your Password has been updated ------------------------>";
							}

							if (op1 == 3)
							{
								int st, et;
								int nst, net;

								cout << "\n\n 				    		<---------- E D I T     A V A I L A B I L I T Y     T I M E ------------->" << endl;
								cout << "\n\n========================================================================================================================================================================" << endl;
								cout << "\n\n--> Enter old Starting Availability Time: ";
								cin >> st;
								cout << "\n--> Enter the Updated Starting Availability Time : ";
								cin >> nst;
								cout << "\n--> Enter old ending Availability Time: ";
								cin >> et;
								cout << "\n--> Enter the Updated Ending Availability Time : ";
								cin >> net;
								cout << "\n\n========================================================================================================================================================================" << endl;

								D.editTime(st, nst, et, net);
								cout << "\n\n					<------------------ The Availability Time Of Doctor Updated -------------------->" << endl << endl;

							}


							if (op1 == 4)
							{
								int ht, uht;

								cout << "\n\n 				    		<---------- E D I T     H O U R L Y     C H A R G E ------------->" << endl;
								cout << "\n\n========================================================================================================================================================================" << endl;
								cout << "\n\n--> Enter Old Hourly Charge: ";
								cin >> ht;
								cout << "\n--> Enter the Updated Hourly Charge: ";
								cin >> uht;
								cout << "\n\n========================================================================================================================================================================" << endl;

								D.editFee(ht, uht);
								cout << "\n\n					<------------------ The Hourly Time Charge Of Doctor Updated -------------------->" << endl << endl;

							}

							if (op1 == 5)
							{
								string hn, uhn;

								cout << "\n\n 				    		<---------- E D I T    H O S P I T A L ------------->" << endl;
								cout << "\n\n========================================================================================================================================================================" << endl;
								cout << "\n\n--> Enter Old Hospital Name: ";
								cin >> hn;
								cout << "\n--> Enter the Updated Hospital Name: ";
								cin >> uhn;
								cout << "\n\n========================================================================================================================================================================" << endl;

								D.editHosp(hn, uhn);
								cout << "\n\n					<------------------ The Hospital Of Doctor Updated -------------------->" << endl << endl;

							}

							if (op1 == 6)
							{
								string hn, uhn;

								cout << "\n\n 				    		<---------- E D I T    C I T Y ------------->" << endl;
								cout << "\n\n========================================================================================================================================================================" << endl;
								cout << "\n\n--> Enter Old City Name: ";
								cin >> hn;
								cout << "\n--> Enter the Updated City Name: ";
								cin >> uhn;
								cout << "\n\n========================================================================================================================================================================" << endl;

								D.editCity(hn, uhn);
								cout << "\n\n					<------------------ The City name Of Doctor Updated -------------------->" << endl << endl;

							}
						}

						if (op == 2)
						{
							string x;
							cout << "\n========================================================================================================================================================================" << endl;
							cout << "\n\n--> Patients Name: ";
							cin >> x;
							Ap.viewProf1(x);
						}

						if (op == 3)
						{
							string x;
							cout << "\n\n========================================================================================================================================================================" << endl;
							cout << "\n\n---> Enter name of Patient: ";
							cin >> x;
							p.AppointmentPatientProf(x);
							cout << "\n\n========================================================================================================================================================================" << endl;
							
						}

						if (op == 5)
						{
							Appointment* Ap = new Appointment;
							string s, n;
							string a = "APPROVED";
							string ab = "CANCELLED";
							int cho;

							cout << "\n\n						<---------------- E D I T      A P P O I N T M E N T ------------------------>";
							cout << "\n\n========================================================================================================================================================================" << endl;
							cout << "\n\n---> Approve Appointment: ";
							cout << "\n\n---> Ignore Appointment: ";
							cout << "\n\n========================================================================================================================================================================" << endl;
							cout << "\n\nSelect any Option: ";
							cin >> cho;

							if (cho == 1)
							{

								cout << "\n\n						<---------------- A P P R O V E      A P P O I N T M E N T------------------------>";
								cout << "\n\n========================================================================================================================================================================" << endl;
								cout << "\n\n---> Enter Name of Patient: ";
								cin >> n;
								cout << "\n\n---> Enter Day: ";
								cin >> s;
								(*Ap).AproveAppointmentt(n, a, s);
								cout << "\n\n					<-------------- Appointmemt Approved --------------->";
								cout << "\n\n========================================================================================================================================================================" << endl;
							}

							if (cho == 2)
							{

								cout << "\n\n						<---------------- I G N O R E      A P P O I N T M E N T------------------------>";
								cout << "\n\n========================================================================================================================================================================" << endl;
								cout << "\n\n---> Enter Name of Patient: ";
								cin >> n;
								cout << "\n\n---> Enter Day: ";
								cin >> s;
								(*Ap).AproveAppointmentt(n, ab, s);
								cout << "\n\n					<-------------- Appointmemt Declined --------------->";
								cout << "\n\n========================================================================================================================================================================" << endl;
							}
						}


						if (op == 7)
						{
							D.DocsProf(a, b);
						}
						if (op == 8)
						{
							cout << "\n\n\n									<---------- F E E D B A C K S ----------->";
							cout << "\n========================================================================================================================================================================" << endl;
							string c;
							cout << "\n--> Enter CNIC: ";
							cin >> c;
							F.Read(c);
							cout << "\n========================================================================================================================================================================" << endl;
						}

						if (op == 9)
						{
							D.logout();
						}

						



						cout << "\n\n\n--> Do you want to change anything else:  \n";
						cout << "--> Press Y/y for yess N/n for no  : ";
						cin >> x;
						system("CLS");
					} while (x == 'y' || x == 'Y');
				//}

			}
			if (cho == 2)
			{
				cout << "\n\n						<<<------------------------- Registration Panel --------------------->>> " << endl;
				cout << "\n\n========================================================================================================================================================================" << endl;
				cout << "\n\n---> Enter your Name: ";
				cin >> name;
				cout << "---> Enter your Email: ";
				cin >> email;

				int counter = 0;
				do
				{
					cout << "--> Enter your Password (Must be 8 digit long including 1 special letter) :";
					cin >> pass;

					if (!D.CheckPass(pass))
					{
						cout << "\nPassword not Correct: ";

					}
					else
					{
						counter = pass.size();
					}

				} while (counter != 8);

				int counter1 = 0;
				do
				{
					cout << "---> Enter your CNIC (must be 13 digit) : ";
					cin >> CNIC;

					if (D.checkCNIC(CNIC))
					{
						cout << "\n---> CNIC Already in Use: " << endl;
						while (D.checkCNIC(CNIC))
						{
							cout << "\n---> Enter CNIC Again : ";
							cin >> CNIC;
						}
					}
					else
					{

					}
					counter1 = CNIC.size();

				} while (counter1 != 13);

				cout << "\n				<-------------- You are successfully registered -------------->" << endl;

				cout << "\n\n---> Enter the furthur Information to proceed " << endl;

				cout << "\n---> Enter Years of Experience: ";
				cin >> exp;
				cout << "---> Enter Field: ";
				cin >> field;
				cout << "---> Enter Starting Time: ";
				cin >> whours;
				cout << "---> Enter Ending Time: ";
				cin >> whors;
				cout << "---> Enter hospital: ";
				cin >> hosp;
				cout << "---> Enter Fee: ";
				cin >> fee;
				cout << "---> Enter Star ratings : ";
				cin >> st;
				cout << "---> Enter city: ";
				cin >> cit;

				D.setValues(name, pass, CNIC, email, exp, field, whours, whors, hosp, fee, st, cit);
				D.addDoc(D, "DocData.dat");
				cout << "\n\n							<------------ Doctor Added ----------->" << endl;
				cout << "\n\n========================================================================================================================================================================" << endl;


			}
		}


		//---------------------------------------------------------------- A D M I N -----------------------------------------------------------------------------
		if (choice == 2)
		{
			string n;
			string p;
			admin A;

			cout << "\n\n								<------------------ A D M I N ----------------------->";

			cout << "\n ======================================================================================================================================================================" << endl;
			cout << "\n\n--> Enter your Name: ";
			cin >> n;
			cout << "\n--->Enter your Password: ";
			cin >> p;

			system("CLS");
			//if(A.checkLogin(n, p)==true)
			if(n == "talha" && p == "Talha@11")
			{

				int op;
				cout << "\n\n								<------------------ Logged In Successfully ------------------->" << endl;
				cout << "\n\n========================================================================================================================================================================" << endl;
				cout << "\n--> Press 1 to add doctor: " << endl;
				cout << "\n--> Press 2 to view doctor's profile: " << endl;
				cout << "\n--> Press 3 to delete doctor's profile: " << endl;
				cout << "\n--> Press 4 to update doctor's profile: " << endl;
				cout << "\n--> Press 5 to update doctor's appointment: " << endl;
				cout << "\n--> Press 6 to logout" << endl;
				cout << "\n\n========================================================================================================================================================================" << endl;
				cout << "\n\nSelect any Option: ";
				cin >> op;
				system("CLS");

				if (op == 1)
				{
					cout << "\n\n						<<<------------------------- Registration Panel --------------------->>> " << endl;
					cout << "\n\n========================================================================================================================================================================" << endl;
					cout << "\n\n---> Enter your Name: ";
					cin >> name;
					cout << "---> Enter your Email: ";
					cin >> email;

					int counter = 0;
					do
					{
						cout << "---> Enter your Password (Must be 8 digit long including 1 special letter) :";
						cin >> pass;

						counter = pass.size();

					} while (counter != 8);

					int counter1 = 0;
					do
					{
						cout << "---> Enter your CNIC (must be 13 digit) : ";
						cin >> CNIC;

						if (D.checkCNIC(CNIC))
						{
							cout << "\n---> CNIC Already in Use: " << endl;
							while (D.checkCNIC(CNIC))
							{
								cout << "\n---> Enter CNIC Again : ";
								cin >> CNIC;
							}
						}
						else
						{

						}
						counter1 = CNIC.size();

					} while (counter1 != 13);

					cout << "\n				<-------------- You are successfully registered -------------->" << endl;

					cout << "\n\n---> Enter the furthur Information to proceed " << endl;

					cout << "\n---> Enter Years of Experience: ";
					cin >> exp;
					cout << "---> Enter Field: ";
					cin >> field;
					cout << "---> Enter Starting Time: ";
					cin >> whours;
					cout << "---> Enter Ending Time: ";
					cin >> whors;
					cout << "---> Enter hospital: ";
					cin >> hosp;
					cout << "---> Enter Fee: ";
					cin >> fee;
					cout << "---> Enter Star ratings : ";
					cin >> st;
					cout << "---> Enter city: ";
					cin >> cit;

					D.setValues(name, pass, CNIC, email, exp, field, whours, whors, hosp, fee, st, cit);
					D.addDoc(D, "DocData.dat");
					cout << "\n\n							<------------ Doctor Added ----------->" << endl;
					cout << "\n\n========================================================================================================================================================================" << endl;
					//system("CLS");

				}

				if (op == 2)
				{
					admin A;
					string x;
					string y;
					cout << "\n\n========================================================================================================================================================================" << endl;
					cout << "\n\n---> Enter name of doctor you want to search: ";
					cin >> x;
					cout << "---> Enter their CNIC: ";
					cin >> y;
					A.searchDoc(x, y);
					cout << "\n\n========================================================================================================================================================================" << endl;
					//system("CLS");

				}

				if (op == 3)
				{
					string dlt;
					cout << "\n\n						<<<----------------- DELETE DOCTOR ------------>>>" << endl;
					cout << "\n\n========================================================================================================================================================================" << endl;
					cout << "\n--> Enter CNIC Of Doctor: " ;
					cin >> dlt;
					A.DltDoc(dlt);
					cout << "\n\n						<<<----------------- Doctor Deleted ------------>>>" << endl;
					cout << "\n\n========================================================================================================================================================================" << endl;
					
					system("CLS");

				}

				if (op == 4)
				{
					char na;
					do
					{
						int x;
						cout << "\n\n					<--------------- EDIT DOCTORS DATA--------------->";
						cout << "\n\n========================================================================================================================================================================" << endl;
						cout << "\n\n---> Edit Name: ";
						cout << "\n\n---> Edit Password: ";
						cout << "\n\n---> Edit City: ";
						cout << "\n\n---> Edit Hospital: ";
						cout << "\n\n---> Edit Fee: ";
						cout << "\n\n---> Edit Availability Time: ";
						cout << "\n\n========================================================================================================================================================================" << endl;
						cout << "\n\n---->Select your option: ";
						cin >> x;
						system("CLS");

						if (x == 1)
						{
							string n, s;
							cout << "\n\n						<---------------- E D I T      N A M E------------------------>";
							cout << "\n\n========================================================================================================================================================================" << endl;
							cout << "\n\n---> Enter old name: ";
							cin >> n;
							cout << "\n\n---> Enter new name: ";
							cin >> s;
							A.editName(n, s);
							cout << "\n\n========================================================================================================================================================================" << endl;
						}


						if (x == 2)
						{
							string n, s;
							cout << "\n\n						<---------------- E D I T      P A S S W O R D ------------------------>";
							cout << "\n\n========================================================================================================================================================================" << endl;
							cout << "\n\n---> Enter old password: ";
							cin >> n;
							cout << "\n\n---> Enter new password: ";
							cin >> s;
							A.editPass(n, s);
							cout << "\n\n========================================================================================================================================================================" << endl;
						}

						if (x == 3)
						{
							string n, s;
							cout << "\n\n						<---------------- E D I T      C I T Y ------------------------>";
							cout << "\n\n========================================================================================================================================================================" << endl;
							cout << "\n\n---> Enter old City: ";
							cin >> n;
							cout << "\n\n---> Enter new City: ";
							cin >> s;
							A.editCity(n, s);
							cout << "\n\n========================================================================================================================================================================" << endl;
						}

						if (x == 4)
						{
							string n, s;
							cout << "\n\n						<---------------- E D I T      H O S P I T A L ------------------------>";
							cout << "\n\n========================================================================================================================================================================" << endl;
							cout << "\n\n---> Enter old Hospital: ";
							cin >> n;
							cout << "\n\n---> Enter new Hospital: ";
							cin >> s;
							A.editHosp(n, s);
							cout << "\n\n========================================================================================================================================================================" << endl;
						}

						if (x == 5)
						{
							int n, s;
							cout << "\n\n						<---------------- E D I T      F E E ------------------------>";
							cout << "\n\n========================================================================================================================================================================" << endl;
							cout << "\n\n---> Enter old Fee: ";
							cin >> n;
							cout << "\n\n---> Enter new Fee: ";
							cin >> s;
							A.editFee(n, s);
							cout << "\n\n========================================================================================================================================================================" << endl;
						}

						if (x == 6)
						{
							int st, et;
							int nst, net;

							cout << "\n\n 				    		<---------- E D I T     A V A I L A B I L I T Y     T I M E ------------->" << endl;
							cout << "\n\n========================================================================================================================================================================" << endl;
							cout << "\n\n--> Enter old Starting Availability Time: ";
							cin >> st;
							cout << "\n--> Enter the Updated Starting Availability Time : ";
							cin >> nst;
							cout << "\n--> Enter old ending Availability Time: ";
							cin >> et;
							cout << "\n--> Enter the Updated Ending Availability Time : ";
							cin >> net;
							cout << "\n\n========================================================================================================================================================================" << endl;

							A.editTime(st, nst, et, net);
							cout << "\n\n					<------------------ The Availability Time Of Doctor Updated -------------------->" << endl << endl;

						}

						cout << "\n\n\n--> Do you want to change anything else:  \n";
						cout << "--> Press Y/y for yess N/n for no  : ";
						cin >> na;
						
						system("CLS");
					}while (na == 'Y' || na == 'y');




				}

				if (op == 5)
				{
					int opp;
					cout << "\n\n						<<<----------------- Edit Doctors Appointment ------------>>>" << endl;
					cout << "\n\n========================================================================================================================================================================" << endl;
					cout << "\n--> Press 1 to Approve Appointments: " << endl;
					cout << "\n--> Press 2 to Cancel Appointments: " << endl;
					cout << "\n\n========================================================================================================================================================================" << endl;
					cout << "\n\n\nSelect any option : ";
					cin >> opp;
					system("CLS");

					if (opp == 1)
					{
						Appointment* Ap = new Appointment;
						string s;
						string d;
						string a = "APPROVED";

						cout << "\n\n						<<<----------------- APPROVE APPOINTMENTS ------------>>>" << endl;
						cout << "\n\n========================================================================================================================================================================" << endl;
						cout << "\n--> Enter Name of Patient: ";
						cin >> s;
						cout << "\n--> Enter Day of Appointment: ";
						cin >> d;
						(*Ap).AproveAppointmentt(s, a, d);
						cout << "\n\n					<-------------- Appointmemt Approved --------------->";
						cout << "\n\n========================================================================================================================================================================" << endl;
						

					}

					if (opp == 2)
					{
						Appointment* Ap = new Appointment;
						string s;
						string d;
						string a = "CANCELLED";

						cout << "\n\n						<<<----------------- CANCEL APPOINTMENTS ------------>>>" << endl;
						cout << "\n\n========================================================================================================================================================================" << endl;
						cout << "\n--> Enter Name of Patient: ";
						cin >> s;
						cout << "\n--> Enter Day of Appointment: ";
						cin >> d;
						(*Ap).AproveAppointmentt(s, a, d);
						cout << "\n\n						<-------------- Appointmemt Cancelled --------------->";
						cout << "\n\n========================================================================================================================================================================" << endl;


					}

				}

				if (op == 6)
				{
					A.logout();
				}
			}
		}

			//------------------------------------------------- P A T I E N T ------------------------------------------------------------------------------
			if (choice == 3)
			{
				int op;

				cout << "\n\n						<<<----------------- PATIENT ------------>>>" << endl;
				cout << "\n\n========================================================================================================================================================================" << endl;
				cout << "\n--> Press 1 for Sign Up " << endl;
				cout << "\n--> Press 2 for login " << endl;
				cout << "\n\n========================================================================================================================================================================" << endl;
				cout << "\n\n\nSelect any option : ";
				cin >> op;
				system("CLS");

				if (op == 1)
				{
					cout << "\n							<-------------------- Registration Panel ------------------> " << endl;
					cout << "\n\n========================================================================================================================================================================" << endl;
					cout << "\n---> Enter your Name: ";
					cin >> name;
					cout << "\n---> Enter your Email: ";
					cin >> email;

					int counter = 0;
					do
					{
						cout << "\n--> Enter your Password (Must be 8 digit long including 1 special letter) :";
						cin >> pass;

						if (!D.CheckPass(pass))
						{
							cout << "\nPassword not Correct: ";

						}
						else
						{
							counter = pass.size();
						}

					} while (counter != 8);

					int counter1 = 0;
					do
					{
						cout << "\n---> Enter your CNIC (must be 13 digit) : ";
						cin >> CNIC;

						if (p.checkCNIC(CNIC))
						{
							cout << "\n---> CNIC Already in Use: " << endl;
							while (p.checkCNIC(CNIC))
							{
								cout << "\n---> Enter CNIC Again : ";
								cin >> CNIC;
							}
						}
						else
						
						counter1 = CNIC.size();

					} while (counter1 != 13);

					cout << "\n---> Enter city: ";
					cin >> cit;
					p.setpatientValues(name, pass, CNIC, email, cit, 3500);
					p.addPatient(p, "Patient.dat");

					cout << "\n						<------------- You are successfully registered --------------->" << endl;
					cout << "\n\n========================================================================================================================================================================" << endl;
					
				}

				if (op == 2)
				{
					int counter = 0;
					string a;
					string b;
					//patient p;

					bool b1 = false;
					int counter2 = 0;
					cout << "\n							<-------------------- Login  Panel ------------------> " << endl;
					cout << "\n\n========================================================================================================================================================================" << endl;
					do
					{
						cout << "\n---> Enter your Name: ";
						cin >> a;
						
						do
						{
							cout << "\n--> Enter your Password (Must be 8 digit long including 1 special letter) :";
							cin >> b;

							if (!D.CheckPass(b))
							{
								cout << "\nPassword not Correct: ";

							}
							else
							{
								counter = b.size();
							}

						} while (counter != 8);

						b1 = p.login(a, b);

						if (b1)
						{
							counter2++;
						}
					} while (!b1);
					system("CLS");

					if (p.login(a, b) == true)
					{
						cout << "\n\n				<-------------------- Logged In Successfully -------------------->\n\n" << endl;
						int x1;
						char x;
						cout << "\n\n========================================================================================================================================================================" << endl;
						do
						{
							cout << "\n--> Press 1 to reset Password: " << endl;
							cout << "\n--> Press 2 to see doctors profile: " << endl;
							cout << "\n--> Press 3 to logout " << endl;
							cout << "\n--> Press 4 to search doctor " << endl;
							cout << "\n--> Press 5 to book or cancel appointment " << endl;
							cout << "\n--> Press 6 to see appointment details " << endl;
							cout << "\n--> Press 7 to change profile details" << endl;
							cout << "\n--> Press 8 to check schedule " << endl;
							cout << "\n--> Press 9 to recharge account " << endl;
							cout << "\n--> Press 10 to see your own profile: " << endl;
							cout << "\n--> Press 11 to give Feedback: " << endl;

							cout << "\n========================================================================================================================================================================" << endl;
							cout << "\n\n\nSelect any option: ";
							cin >> x1;
							system("CLS");

							if (x1 == 1)
							{
								string oldpass;
								string newpassword;
								patient p;

								cout << "\n\n							<----------------- Reset Password----------------->";
								cout << "\n\n========================================================================================================================================================================" << endl;
								cout << "\n--> Enter old password: ";
								cin >> oldpass;

								cout << "\n--> Enter new password: ";
								cin >> newpassword;

								p.editPass(oldpass, newpassword);
								
								cout << "Your Password has been updated";
								cout << "\n\n========================================================================================================================================================================" << endl;
							}

							if (x1 == 2)
							{
								Appointment A;
								cout << "\n\n								<---------All Doctors Profiles-----------> " << endl;
								A.readDoc("DocData.dat");
							}

							if (x1 == 3)
							{
								U.logout();
							}

							if (x1 == 4)
							{
								string s;
								int x;
								cout << "\n\n								<----------------- Search Doctor----------------->";
								cout << "\n\n========================================================================================================================================================================" << endl;
								cout << "\n\n---> 1) Search by name : ";
								cout << "\n\n---> 2) Search by Field : ";
								cout << "\n\n---> 3) Search by City : ";
								cout << "\n\n---> 4) Search by Hospital : ";
								cout << "\n\n========================================================================================================================================================================" << endl;
								cout << "\n\n--> Select any option: ";
								cin >> x;
								system("CLS");

								if (x == 1)
								{
									cout << "\n\n								<----------------- Search Doctor----------------->";
									cout << "\n\n========================================================================================================================================================================" << endl;
									cout << "\n\n--> Enter the Name of doctor: ";
									cin >> s;
									n.DocsProf(s);
									cout << "\n========================================================================================================================================================================" << endl;
								}

								if (x == 2)
								{
									cout << "\n\n								<----------------- Search Doctor----------------->";
									cout << "\n\n========================================================================================================================================================================" << endl;
									cout << "\n\n--> Enter the Field of doctor: ";
									cin >> s;
									n.DocsProf(s);
									cout << "\n========================================================================================================================================================================" << endl;
								}

								if (x == 3)
								{
									cout << "\n\n								<----------------- Search Doctor----------------->";
									cout << "\n\n========================================================================================================================================================================" << endl;
									cout << "\n\n--> Enter the City of doctor: ";
									cin >> s;
									n.DocsProf(s);
									cout << "\n========================================================================================================================================================================" << endl;
								}

								if (x == 4)
								{
									cout << "\n\n								<----------------- Search Doctor----------------->";
									cout << "\n\n========================================================================================================================================================================" << endl;
									cout << "\n\n--> Enter the Hospital of doctor: ";
									cin >> s;
									n.DocsProf(s);
									cout << "\n========================================================================================================================================================================" << endl;
								}
							}

							if (x1 == 5)
							{
								int s;
								cout << "\n\n							<----------------- A P P O I N T M E N T S----------------->";
								cout << "\n\n========================================================================================================================================================================" << endl;
								cout << "\n\n--> Book Appointment: ";
								cout << "\n\n--> Cancel Appointment: ";
								cout << "\n\n========================================================================================================================================================================" << endl;
								
								cout << "\n\n\nEnter Your choice: ";
								cin >> s;
								system("CLS");
								
								if (s == 1)
								{
									string x;
									string an;
									string pname;
									string pcnic;
									int y;
									int y1;
									
									cout << "\n\n							<----------------- B O O K      A P P O I N T M E N T S----------------->";
									cout << "\n\n========================================================================================================================================================================" << endl;
									cout << "\n\n--> Enter the name of doctor: ";
									cin >> x;
									cout << "\n\n--> Enter your Name: ";
									cin >> pname;
									cout << "\n\n--> Enter your CNIC: ";
									cin >> pcnic;
									D.Prof(x);
									cout << "\n\n							<----------------- A V A I L A B L E      S L O T S----------------->";
									//cout << "\n========================================================================================================================================================================" << endl;
									Ap.slots(x);
									cout << "\n========================================================================================================================================================================" << endl;
									int sn;

									cin >> sn;

									char cha;
									cout << "\n\n---> Type Day: ";
									cin >> an;

									cout << "\n\n---> Select Starting slot: ";
									cin >> y;
									cout << "\n\n---> Select Ending slot: ";
									cin >> y1;

									string st = "PENDING";
									int count = 0;


									while (!Ap.docAvailability(an, y))
									{
										cout << "\n\nNo Doctor Available.\n Book another Slot";
										cout << "\n\nEnter Slot Number: ";
										cin >> sn;

										char cha;
										//do
										//{
										cout << "\n\n---> Type Day: ";
										cin >> an;

										cout << "\n\n---> Select Starting slot: ";
										cin >> y;
										cout << "\n\n---> Select Ending slot: ";
										cin >> y1;
									}

									Ap.setAppointment(x, pname, pcnic, y, y1, an, st);
								}

							}

							if (x1 == 6)
							{
								string x;
								cout << "\n\n-->Enter Patient Name: ";
								cin >> x;
								Ap.viewProf1(x);
							}

							if (x1 == 7)
							{
								int d;
								cout << "\n\n						<---------------- E D I T      P R O F IL E ------------------------>";
								cout << "\n\n========================================================================================================================================================================" << endl;
								cout << "\n\n---> Edit Name: ";
								cout << "\n\n---> Edit Password: ";
								cout << "\n\n---> Edit City: ";
								cout << "\n\n========================================================================================================================================================================" << endl;
								cout << "\n\nSelect your option: ";
								cin >> d;
								system("CLS");
								char na;
								do
								{
									if (d == 1)
									{
										string n, s;
										cout << "\n\n						<---------------- E D I T      N A M E------------------------>";
										cout << "\n\n========================================================================================================================================================================" << endl;
										cout << "\n\n---> Enter old name: ";
										cin >> n;
										cout << "\n\n---> Enter new name: ";
										cin >> s;
										p.editName(n, s);
										cout << "\n\n========================================================================================================================================================================" << endl;
									}


									if (d == 2)
									{
										string n, s;
										cout << "\n\n						<---------------- E D I T      P A S S W O R D ------------------------>";
										cout << "\n\n========================================================================================================================================================================" << endl;
										cout << "\n\n---> Enter old password: ";
										cin >> n;
										cout << "\n\n---> Enter new password: ";
										cin >> s;
										p.editPass(n, s);
										cout << "\n\n========================================================================================================================================================================" << endl;
									}

									if (d == 3)
									{
										string n, s;
										cout << "\n\n						<---------------- E D I T      C I T Y ------------------------>";
										cout << "\n\n========================================================================================================================================================================" << endl;
										cout << "\n\n---> Enter old City: ";
										cin >> n;
										cout << "\n\n---> Enter new City: ";
										cin >> s;
										p.editCity(n, s);
										cout << "\n\n========================================================================================================================================================================" << endl;
									}


									cout << "\n\n\n--> Do you want to change anything else:  \n";
									cout << "--> Press Y/y for yess N/n for no  : ";
									cin >> na;

									system("CLS");
								} while (na == 'Y' || na == 'y');

							}

							if (x1 == 8)
							{
								string s;
								cout << "Enter Name: ";
								cin >> s;
								p.AppointmentPatientProf(s);
							}

							if (x1 == 9)
							{
								int s;
								string na;
								string pa;
								cout << "\n\n========================================================================================================================================================================" << endl;
								
								cout << "\n\n--> Enter Name: ";
								cin >> na;
								cout << "\n\n--> Enter password: ";
								cin >> pa;
								cout << "\n\n--> Enter the Amount to be recharged: ";
								cin >> s;
								p.Recharge(na, pa, s);
								cout << "\n\n								<----------------- Your account has been Recharged ----------------->";
								cout << "\n========================================================================================================================================================================" << endl;
							}

							if (x1 == 10)
							{
								patient p;
								string x, y;
								cout << "\n\n								<----------------- P R O F I L E----------------->";
								cout << "\n\n========================================================================================================================================================================" << endl;
								cout << "\n--> Enter your name: ";
								cin >> x;
								cout << "\n--> Enter your password: ";
								cin >> y;
								p.searchPatient(x,y);
								cout << "\n\n========================================================================================================================================================================" << endl;
							}

							if (x1 == 11)
							{
								patient p;
								string x;
								string y = "APPROVED";
								cout << "\n\n								<-----------------A P P R O V E D    P R O F I L E----------------->";
								cout << "\n\n========================================================================================================================================================================" << endl;
								cout << "\n--> Enter Patient name: ";
								cin >> x;
								Ap.doneAppointment(x, y);
								cout << "\n\n========================================================================================================================================================================" << endl;

								{
									Appointment* A = new Appointment;
									string day, id;
									int slot;

									cout << "---> Enter Day Of Appointment : ";
									cin >> day;

									string a = "APPROVED";
									bool ac = A->viewstatus(id, day,a);

									if (ac)
									{
										bool a = A->updatestatus(id, "COMPLETED", day);

										string f;
										int r;

										cout << "\n---> Rate your Doctor : ";
										cin >> r;
										cout << "\n---> Enter your Review (Good or Bad) :  ";
										cin >> f;

										p.writefeedback(f, id, r);

										cout << "\n\n		<---------- THANKYOU! FOR YOU FEED-BACK ----------->\n";
									}
									else

										cout << "\n\n			<-------- Appointment Not Approved ---------->";

								}
							}

							cout << "\n\n\n--> Do you want to change anything else:  \n";
							cout << "--> Press Y/y for yess N/n for no : ";
							cin >> x;
						} while (x == 'y' || x == 'Y');
					}
				}
			}

			cout << "\n\n---> Do you want to see menu again? " << endl;
			cout << "\n---> Y/y for yess  N/n for no" << endl;
			cin >> as;
			system("CLS");
		}while (as == 'y' || as == 'Y');
		

	}
	



