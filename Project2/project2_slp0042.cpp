// Sarah Pham
// slp0042
// project2_slp0042.cpp
// How to compile: g++ project2_slp0042.cpp -o project2_slp0042
// 		   ./project2_slp0042
// No help was received for this project
// It was mentioned by an instructor in Piazza that "assert" is not required in testing void shooting methods

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>

using namespace std;

void test_two_alive(void);
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void test_aaron_shoots1(void);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void test_bob_shoots(void);
void Bob_shoots(bool& A_alive, bool& C_alive);
void test_charlie_shoots(void);
void Charlie_shoots(bool& B_alive, bool& C_alive);
void test_aaron_shoots2(void);
void Aaron_shoots2(bool& B_alive, bool& C_alive);


bool A_alive = true, B_alive = true, C_alive = true;
bool stratTwoBetter = false;

int main(){

	int aaron = 0, bob = 0, charlie = 0;
	double strat1 = 0, strat2 = 0;
	
	cout << "*** Welcome to Sarah's Duel Simulator ***" << fixed << endl;
	
	srand(time(0));

	test_two_alive();
	test_aaron_shoots1();
	test_bob_shoots();
	test_charlie_shoots();
	test_aaron_shoots2();

	cout.precision(2);

	cout << "Ready to test strategy 1 (run 10000 times):\n";
	cout << "Press any key to continue...";
	cin.get();

	cout << "\n";
	
	for(int i = 0; i < 10000; i++){

	A_alive = true;
	B_alive = true;
	C_alive = true;

	while( at_least_two_alive(A_alive, B_alive, C_alive)){
		if(A_alive) { Aaron_shoots1(B_alive, C_alive); }
		if(at_least_two_alive(A_alive, B_alive, C_alive) && B_alive) { Bob_shoots(A_alive, C_alive); }
		if(at_least_two_alive(A_alive, B_alive, C_alive) && C_alive) { Charlie_shoots(A_alive, B_alive); }
	}
	
	if(A_alive) {aaron++;}
	if(B_alive) {bob++;}
	if(C_alive) {charlie++;}	

	}

	strat1 = ((double) aaron / 100.0);

	cout << "Aaron won " << aaron << "/10000 duels or " << strat1 << "%\n";
	cout << "Bob won " << bob << "/10000 duels or " << (((double) bob)/100.0) << "%\n";
	cout << "Charlie won " << charlie << "/10000 duels or " << (((double) charlie)/100.0) << "%\n\n";

	cout << "Ready to test strategy 2 (run 10000 times): \n";
	cout << "Press any key to continue...";
	cin.get();

	cout << "\n";

	aaron = 0;
	bob = 0;
	charlie = 0;

	for(int i = 0; i < 10000; i++){

		A_alive = true;
		B_alive = true;
		C_alive = true;

		while( at_least_two_alive(A_alive, B_alive, C_alive)){
			if(A_alive) { Aaron_shoots2(B_alive, C_alive); }
			if(at_least_two_alive(A_alive, B_alive, C_alive) && B_alive) { Bob_shoots(A_alive, C_alive); }
			if(at_least_two_alive(A_alive, B_alive, C_alive) && C_alive) { Charlie_shoots(A_alive, B_alive); }
		}

		if(A_alive) {aaron++;}
		if(B_alive) {bob++;}
		if(C_alive) {charlie++;}

	}

	strat2 = ((double) aaron / 100.0);
			
	cout << "Aaron won " << aaron << "/10000 duels or " << strat2 << "%\n";
	cout << "Bob won " << bob << "/10000 duels or " << (((double) bob)/100.0) << "%\n";
	cout << "Charlie won " << charlie << "/10000 duels or " << (((double) charlie)/100.0) << "%\n";
	
	if(strat2 > strat1) { cout << "\nStrategy 2 is better than strategy 1.\n";}
	else { cout << "\n Strategy 1 is better than strategy 2.\n";}

}

void test_two_alive(void){

	cout << "Unit Testing 1: Function - at_least_two_alive()\n";
	cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(true, true, true));
	cout << "\t Case passed ...\n";
	
	cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(false, true, true));
	cout << "\t Case passed ...\n";

	cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
	cout << "\t Case passed ...\n";

	cout << "\t Case 4: Aaron alive, Bob alive, Charlie dead\n";
	assert(true == at_least_two_alive(true, true, false));
	cout << "\tCase passed ...\n";

	cout << "\t Case 5: Aaron dead, Bob dead, Charlie alive\n";
	assert(false == at_least_two_alive(false, false, true));
	cout << "\tCase passed ...\n";

	cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
	assert(false == at_least_two_alive(false, true, false));
	cout << "\tCase passed ...\n";

	cout << "\t Case 7: Aaron alive, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(true, false, false));
	cout << "\tCase passed ...\n";

	cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(false, false, false));
	cout << "\tCase passed ...\n";

	cout << "Press any key to continue...\n";
	cin.get();
}

void test_aaron_shoots1(void){

	B_alive = true;
	C_alive = true;

	cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
	cout <<"\tCase 1: Bob alive, Charlie alive\n";
	Aaron_shoots1(B_alive, C_alive);
	cout << "\t\tAaron is shooting at Charlie\n";

	cout << "\tCase 2: Bob dead, Charlie alive\n";
	B_alive = false;
	Aaron_shoots1(B_alive, C_alive);
	cout << "\t\tAaron is shooting at Charlie\n";

	cout << "\tCase 3: Bob alive, Charlie dead\n";
	B_alive = true;
	C_alive = false;
	Aaron_shoots1(B_alive, C_alive);
	cout << "\t\tAaron is shooting at Bob\n";

	cout << "Press any key to continue...\n";
	cin.get();
}

void test_bob_shoots(void){

 	A_alive = true;
	C_alive = true;

	cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
	cout << "\tCase 1: Aaron alive, Charlie alive\n";
	Bob_shoots(A_alive,C_alive);
	cout << "\t\tBob is shooting at Charlie\n";
	
	cout << "\tCase 2: Aaron dead, Charlie alive\n";
	A_alive = false;
	Bob_shoots(A_alive, C_alive);
	cout << "\t\tBob is shooting at Charlie\n";

	cout << "\tCase 3: Aaron alive, Charlie dead\n";
	A_alive = true;
	C_alive = false;
	Bob_shoots(A_alive, C_alive);
	cout << "\t\tBob is shooting at Aaron\n";


	cout << "Press any key to continue...\n";
	cin.get();
}

void test_charlie_shoots(void){

	A_alive = true;
	B_alive = true;

	cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
	cout << "\tCase 1: Aaron alive, Bob alive\n";
	Charlie_shoots(A_alive, B_alive);
	cout << "\t\tCharlie is shooting at Bob\n";

	cout << "\tCase 2: Aaron dead, Bob alive\n";
	A_alive = false;
	Charlie_shoots(A_alive, B_alive);
	cout << "\t\tCharlie is shooting at Bob\n";

	cout << "\tCase 3: Aaron alive, Bob dead\n";
	A_alive = true;
	B_alive = false;
	Charlie_shoots(A_alive, B_alive);
	cout << "\t\tCharlie is shooting at Aaron\n";	

	cout << "Press any key to continue...\n";
	cin.get();
}

void test_aaron_shoots2(void){

	B_alive = true;
	C_alive = true;

	cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
	cout << "\tCase 1: Bob alive, Charlie alive\n";
	Aaron_shoots2(B_alive, C_alive);
	cout << "\t\tAaron intentionally misses his first shot\n\t\tBoth Bob and Charlie are alive\n";

	cout << "\tCase 2: Bob dead, Charlie alive\n";
	B_alive = false;
	Aaron_shoots2(B_alive, C_alive);
	cout << "\t\tAaron is shooting at Charlie\n";

	cout << "\tCase 3: Bob alive, Charlie dead\n";
	B_alive = true;
	C_alive = false;
	Aaron_shoots2(B_alive, C_alive);
	cout << "\t\tAaron is shooting at Bob\n";

	cout << "Press any key to continue...\n";
	cin.get();

}

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive){

	if(A_alive){
		if(B_alive){ return true; }
		if(C_alive){ return true; }
	}
	if(B_alive && C_alive) {return true;}

	return false;
}

void Aaron_shoots1(bool& B_alive, bool& C_alive){

	int shoot_target_result = rand()%100;
	
	if(shoot_target_result <= 33){
	
		if(C_alive){ C_alive = false; }
		else{ B_alive = false; }
	}

}

void Bob_shoots(bool& A_alive, bool& C_alive){


	int shoot_target_result = rand()%100;

	if(shoot_target_result <= 50) {

		if(C_alive) {C_alive = false;}
		else {A_alive = false;}
	}
}

void Charlie_shoots(bool& A_alive, bool& B_alive){

	if(B_alive) {B_alive = false;}
	else {A_alive = false;}
}


void Aaron_shoots2(bool& B_alive, bool& C_alive){

	if((B_alive && C_alive) == false){

		int shoot_target_result = rand()%100;

		if(shoot_target_result <= 33){

			if(C_alive) {C_alive = false;}
			else {B_alive = false;}
		}
	}
}
