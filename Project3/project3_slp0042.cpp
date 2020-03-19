// Sarah Pham
// Slp0042
// project3_slp0042.cpp
// How to Compile: g++ project3_slp0042.cpp -o project3_slp0042
// 	            ./project3_slop0042
// No help used except my knowledge from taking Java 2 and going through sorting algorithms

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

int convertStringToInt(string stringNumber);

int getFileSize(string fileName);

int readFile(int inputArray[], string fileName);

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);

void writeFile(int outputArray[], int outputArray_size, string outputName);

int main(){
	string input1;
	string input2;
	string outputName;

	cout << "*** Welcome to Sarah Pham's sorting program ***\n";
	cout << "Enter the first input file name: ";
	cin >> input1;

	int arr1[getFileSize(input1)];
	int arr1Size = readFile(arr1, input1);

	cout << "\nEnter the second input file name: ";
	cin >> input2;
	int arr2[getFileSize(input2)];
	int arr2Size = readFile(arr2, input2);

	int arr3[arr1Size + arr2Size];
	int arr3Size = sort(arr1, arr1Size, arr2, arr2Size, arr3);

	cout << "\nThe sorted list of " << arr3Size << " is: ";
	
	for(int i = 0; i < arr3Size; i++){
		cout << arr3[i] << " ";
	}

	cout << endl << "Enter the output file name: ";
	cin >> outputName;


	writeFile(arr3, arr3Size, outputName);

	cout << "\n*** Please check the new file - " << outputName << " ***\n";
	cout << "*** Goodbye. ***\n";

	return 0;

}


int convertStringToInt(string stringNumber){
	stringstream stream(stringNumber);
	int number;
	stream >> number;
	return number;

}

int getFileSize(string fileName){
	ifstream inFile(fileName.c_str());

	int size = 0;
	if(inFile.fail()){
		cout << "Input file opening failed!\n";
		exit(1);
	}

	if(inFile.is_open()){

		string line;
		getline(inFile, line);
		while(!inFile.eof()){
			size++;
			getline(inFile, line);
		}		
	}

	return size;
}

int readFile(int inputArray[], string fileName){
	ifstream inFile(fileName.c_str());
	int size = 0;
	if(inFile.fail()){
		cout << "Input file opening failed!\n";
		exit(1);
	}

	if(inFile.is_open()){
		string line;
		getline(inFile, line);
		while(!inFile.eof()){
			inputArray[size++] = convertStringToInt(line);
			getline(inFile, line);
		}
	}

	cout << "The list of " << size << " numbers in file " << fileName << " is: \n";

	for(int i = 0; i < size; i++){
		cout << inputArray[i] << endl;
	}
	
	return size;
}

int sort (int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]){
	int outputArray_size = inputArray1_size + inputArray2_size;

	for(int arr1Count = 0; arr1Count < inputArray1_size; arr1Count++){
		outputArray[arr1Count] = inputArray1[arr1Count];
	}

	for(int arr2Count = 0; arr2Count < inputArray2_size; arr2Count++){
		outputArray[inputArray1_size + arr2Count] = inputArray2[arr2Count];
	}

	for(int i = 0; i < outputArray_size; i++){
		int temp = outputArray[i];
		int j = i;

		while(j > 0 && temp < outputArray[j - 1]){
			outputArray[j] = outputArray[j - 1];
			j--;
		}

		outputArray[j] = temp;
	}

	cout << endl;
	return inputArray1_size + inputArray2_size;
}

void writeFile(int outputArray[], int outputArray_size, string outputName){
	ofstream outFile;

	outFile.open(outputName.c_str());	

	for(int count = 0; count < outputArray_size; count++){
		outFile << outputArray[count] << endl;
	}
	
	outFile.close();
}
