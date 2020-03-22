// Sarah Pham
// slp0042
// project4_slp0042.cpp
// Run this command in terminal: g++ project4_slp0042.cpp -o project4_slp0042
// Then run ./project4_slp0042
// No help used

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int totalPoints;
int lastPoints;
string lastAnswer;

struct TriviaNode {

    string question;
    string answer;
    int points;

    TriviaNode *next;

};

class linkedList {

public:

    TriviaNode *head, *tail;
    TriviaNode *index;

    int size;

    linkedList() {

        TriviaNode *t1 = new TriviaNode();
        TriviaNode *t2 = new TriviaNode();
        TriviaNode *t3 = new TriviaNode();

        t1->question = "How long was the shortest war on record? (Hint: how many minutes)";
        t1->answer = "38";
        t1->points = 100;

        t2->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
        t2->answer = "Bank of Italy";
        t2->points = 50;

        t3->question = " What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
        t3->answer = "Wii Sports";
        t3->points = 20;

        t1->next = t2;
        t2->next = t3;
        t3->next = NULL;

        head = t1;
        tail = t3;
        size = 3;

        index = NULL;

    }

    void addNode(string questionIn, string answerIn, int pointsIn) {

        TriviaNode *temp = new TriviaNode();

        temp->question = questionIn;
        temp->answer = answerIn;
        temp->points = pointsIn;

        tail->next = temp;
        tail = temp;

        size++;

    }

    TriviaNode* getNext() {

        if (index == NULL) {
            index = head;
        }

        else {
            index = index->next;
        }

        return index;

    }

};

int askQuestion(linkedList& inputList, int numofQuestions);
int case_insensitive_match(string s1, string s2);
void testAskQuestion(void);

#define UNIT_TESTING

#ifdef UNIT_TESTING

int main () {
    testAskQuestion();
}

#else

int main() {

    string questionIn;
    string answerIn;
    string repeat;
    int points;
    linkedList list;

    cout << "\n*** Welcome to Sarah's trivia quiz game ***\n";

    bool done = false;

    while (!done) {

        cout << "Enter a question: ";

        getline(cin, questionIn);

        cout << "Enter an answer: ";

        getline(cin, answerIn);

        cout << "Enter award points: ";

        cin >> points;

        list.addNode(questionIn, answerIn, points);

        cout << "Continue? (Yes/No): ";

        cin >> repeat;

        cin.ignore();

        if (repeat == "No" || repeat == "no") {
            done = true;
        }

    }

    for (int i = 0; i < list.size; i++) {
        
        askQuestion(list, 1);
        
    }

    cout << "\n\n*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
}


#endif

int askQuestion(linkedList& inputList, int numOfQuestions) {

    string answerIn;
    string correctAnswer;

    if (numOfQuestions < 1) {

        cout << "\nWarning: The number of trivia to be asked must equal or be larger than 1.\n";
        return 0;

    }

    if (numOfQuestions > inputList.size) {

        cout << "\nWarning: There are only " << inputList.size << " trivia in the list.\n";
        return 0;

    }

    for (int i = 0; i < numOfQuestions; i++) {

        TriviaNode *node = inputList.getNext();
        
        cout << "\nQuestion: " << node->question;
        cout << "\nAnswer: ";

        getline(cin, answerIn);
        correctAnswer = node->answer;

        if ((answerIn != correctAnswer) && (case_insensitive_match(answerIn, correctAnswer)) < 1) {

            cout << "Your answer is wrong. The correct answer is " << node->answer << endl;
            lastAnswer = node->answer;
            
        }

        else {

            cout << "Your answer is correct! You will receive " << node->points << " points." << endl;
            
            totalPoints += node->points;
            lastPoints = node->points;
            
        }
        
        cout << "Your total points: " << totalPoints << endl;

    }

    return 1;
}


void testAskQuestion(void) {

    linkedList list1;
    linkedList list2;
    linkedList list3;
    linkedList list4;

    cout << "*** This is a debug version ***";

    cout << "\nUnit Test Case 1: Ask no questions. The program should give a warning message.";
    askQuestion(list1, 0);
    cout << "\nCase 1 Passed\n";
    

    cout << "\nUnit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer.";
    askQuestion(list1, 1);
    cout << "\nCase 2.1 passed\n";

    totalPoints = 0;

    cout << "\nUnit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer.";
    assert(1 == askQuestion(list2, 1));
    cout << "\nCase 2.2 passed\n";
    
    totalPoints = 0;

    cout << "\nUnit Test Case 3: Ask all the questions of the last trivia in the linked list.";
    assert(1 == askQuestion(list3, 3));
    cout << "\nCase 3 passed\n";
    
    
    cout << "\nUnit Test Case 4: Ask 5 questions in the linked list.";
    assert(0 == askQuestion(list4, 5));
    cout << "\nCase 4 passed\n";


    cout << "\n*** End of the Debugging Version ***\n\n";
    
    totalPoints = 0;

    }

int case_insensitive_match(string s1, string s2){

    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    
    if(s1.compare(s2) == 0) return 1;       // the strings are the same
              
    return 0;       // the strings are not the same
}
