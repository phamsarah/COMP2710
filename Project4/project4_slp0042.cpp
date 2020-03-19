// Sarah Pham
// slp0042
// project4_slp0042.cpp
// How to compile: g++ project4_slp0042.cpp -o project4_slp0042
// 		   ./project4_slp0042
// No help was received for this project

#include <iostream>
#include <assert.h>
using namespace std;

int totalPoints;

struct TriviaNode{
	string question;
	string answer;
	int points;

	TriviaNode *next;
};

void insert(struct TriviaNode** head, string question_new, string answer_new, int points_new){
	
		struct TriviaNode* new_node = new TriviaNode;
	
	struct TriviaNode *last = *head;
		
		new_node -> question = question_new;
		new_node -> answer = answer_new;
		new_node -> points = points_new;

		new_node -> next = NULL;	

		if(*head == NULL){
			*head = new_node;
			return;
		}
		
		while(last -> next != NULL){
			last = last -> next;
		}

		last -> next = new_node;
		return;
}

void display(TriviaNode *node){
	
	while(node != NULL){
		cout << node -> question <<  endl;
		node = node -> next;
	}
}

void production_version(void){

	cout  << "Enter a question: ";

	string question;
	cin >> question;

	cout << "\n"
	     << "Enter an answer: ";

	string answer;
	cin >> answer;

	cout << "\n"
	     << "Enter award points: ";

	string point;
	cin >> point;

	cout << "\n"
	     << "Continue? (Yes/No)"
}

void debug_version(void){
	
}

void checkAnswer(struct TriviaNode** head, string answer){
		
	
}



#define UNIT_TESTING
#ifdef UNIT_TESTING

int main() {
	debug_version();
}

#else
int main(){

	TriviaNode* head = new TriviaNode; 
	
// Inserting hardcoded first three trivia questions 

	string question = "How long was the shortest war on record? (Hint: how many minutes)";
	string answer = "38";
	int point = 100;
	insert(&head, question, answer, point);
	
	question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
	answer = "Bank of Italy";
	point = 50;
	insert(&head, question, answer, point);

	question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?";
	answer = "Wii Sports";
	point = 20;
	insert(&head, question, answer, point);	
	display(head);

	return 0;
}


