//    Sarah Pham
//    UserID: slp0042
//    Filename: project1_slp0042.cpp
//    How to compile: type in g++ [projectname.cpp] -o [projectname] 
//    		      type in ./[projectname]
//    No help was used in the making of this program.

#include <iostream>
#include <iomanip>

using namespace std;

void PrintAsterisk(){

	for(int i = 0; i < 54; i++){
		cout << "*";
	}
	cout << endl;

}

void PrintMoney(double money){
	
	cout << "$" << money << "\t";
}

int main()
{

	cout << fixed << showpoint << setprecision(2);

	double loan = 0.0;
	double interestPerYr = 0.0;
	double monthlys = 0.0;
	double monthRate = 0.0;

	cout << "Loan Amount: ";
	cin >> loan;

	cout << "\nInterest Rate (% per year): ";
	cin >> interestPerYr;

	cout << "\n Monthly Payments: ";
	cin >> monthlys;
	cout << endl;

	monthRate = interestPerYr / 1200;

	if(monthlys > loan * monthRate){

		PrintAsterisk();
		
		cout << "\tAmortization Table" << endl;

		PrintAsterisk();

		cout << "Month\t\t" << "Balance\t\t" << "Payment\t\t" << "Rate\t" << "Interest\t" << "Principal" << endl;
		cout << "0\t\t$" << loan << "\t" << "N/A\t\t" << "N/A\t" << "N/A\t\t" << "N/A\t\t" << endl;

		int month = 1;
		double payment = 0;
		double rate = interestPerYr / 12;
		double interest = loan * monthRate;
		double total = 0;

		while((monthlys - interest) < loan){

			loan -= (monthlys - interest);
			total += interest;
			
			cout << month++ << "\t\t";
			PrintMoney(loan);

		if(loan < 1000){
			cout << "\t";

		}
			PrintMoney(monthlys);
			cout << "\t" << rate << "\t";
		
			PrintMoney(interest);
			cout << "\t";
			PrintMoney(monthlys - interest);

			cout << "\t";
			cout << endl;
			interest = loan * monthRate;
		}

		total += interest;
		cout << month << "\t\t";

		PrintMoney(0);
		cout << "\t";
		PrintMoney(loan);
		cout << "\t";
		cout << rate << "\t";

		PrintMoney(interest);

		cout << "\t";
		PrintMoney(interest + loan);

		cout << endl;

		PrintAsterisk();

		cout << endl << "It takes " << month << " months to pay off the loan.";
		cout << endl << "Total interest paid is: ";
		
		PrintMoney(total);

		cout << endl;

	}

	else{

		cout << "Payments are not larger than monthly interest. \nUnable to calculate the table!" << endl;
	}


return 0;
}
