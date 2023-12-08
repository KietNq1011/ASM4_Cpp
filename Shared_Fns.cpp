#include "Shared_Fns.h"

///====================================== WORKING WITH FILES =======================================
/// Check if the car is being used for the first time
bool isFirstTime() {
	ifstream FileIn(FILE_PATH);

	streampos fileSize = 0;
	FileIn.seekg(0, ios::end);
	fileSize = FileIn.tellg();
	FileIn.seekg(0, ios::beg);

	FileIn.close();
	return (fileSize == 0);
}

/// Set MSCN in file
void setMSCN(int* arr_in_file, ofstream& outFile) {
	outFile << "MSCN: ";
	for (int i = 0; i < 8; i++) {
		cout << "\nENTER NUMBER " << i + 1 << ": ";
		int temp;
		while (!(cin >> temp)) {
			cin.clear();
			cin.ignore();
			cout << "PLEASE ENTER A NUMBER!" << endl;
			cout << "ENTER NUMBER " << i + 1 << ": ";
		}
		arr_in_file[i] = temp;  // MSCN saved in file
		outFile << temp << " ";
	}
	outFile << "\n";
	outFile.close();
}

/// Set safety distance (SD) in file
void setSafetyDistance(int* arr_in_file, ofstream& outFile) {
	outFile << "Safety distance (SD): ";
	cout << "NHAP 3 MUC AN TOAN \n";
	for (int i = 0; i < 3; i++) {
		cout << "VAN TOC MUC " << i + 1 << ": ";
		int temp;
		while (!(cin >> temp)) {
			cin.clear();
			cin.ignore();
			cout << "PLEASE ENTER A NUMBER!" << endl;
			cout << "ENTER NUMBER " << i + 1 << ": ";
		}
		arr_in_file[i] = temp; // SD save in file
	}
	bubbleSort(arr_in_file, 3);
}

/// Read MSCN from file
void readMSCNFromFile(int* arr_in_file, ifstream& FileIn) {
	string line;
	while (getline(FileIn, line)) {
		if (line.find("MSCN:") != string::npos) {
			istringstream iss(line.substr(line.find(':') + 1));
			for (int i = 0; i < 8; i++) {
				iss >> arr_in_file[i];
			}
		}
	}
}

/// Read safety distance (SD) from file
void readSafetyDistanceFromFile(int* arr_in_file, ifstream& FileIn) {
	string line;
	while (getline(FileIn, line)) {
		if (line.find("(SD):") != string::npos) {
			istringstream iss(line.substr(line.find(':') + 1));
			for (int i = 0; i < 3; i++) {
				iss >> arr_in_file[i];
			}
		}
	}
}

/// Main readDataFromFile function
int readDataFromFile(int* arr_in_file, int* arr_inputted, char name, bool first_time) {
	ifstream FileIn(FILE_PATH);

	if (first_time) {
		switch (name) {
		case '1': // case call MH1
		{
			cout << "Let's set your password!\n";
			ofstream outFile(FILE_PATH);
			outFile << "Car's Infomation\n";
			setMSCN(arr_in_file, outFile);
			cout << "Set password successfully!\n";
			system("pause");
			system("cls");
			FileIn.close();
			return 2;
		}
		case '2': // case call MH2
		{
			cout << "Let's set your SD!\n";
			ofstream outFile(FILE_PATH, ios::app);
			setSafetyDistance(arr_in_file, outFile);
			for (int i = 0; i < 3; i++) {
				outFile << arr_in_file[i] << " ";
			}
			system("pause");
			system("cls");
			FileIn.close();
			return 2;
		}
		default:
			break;
		}
	}
	// if not the 1st
	else {
		switch (name) {
		case '1':
		{
			readMSCNFromFile(arr_in_file, FileIn);
			cout << "ENTER PERSONAL CODE, 8-DIGIT ARRAY" << endl;
			for (int i = 0; i < 8; i++) {
				cout << "\nENTER NUMBER " << i + 1 << ": ";
				int temp;
				while (!(cin >> temp)) {
					cin.clear();
					cin.ignore();
					cout << "PLEASE ENTER A NUMBER!" << endl;
					cout << "ENTER NUMBER " << i + 1 << ": ";
				}
				arr_inputted[i] = temp;
			}
			break;
		}
		case '2':
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
		FileIn.close();
		return 1;
	}
}

void writeDataToFile(int* arr, int size, const string& identifier) {
	fstream FileOut(FILE_PATH, ios::in | ios::out);

	if (!FileOut.is_open()) {
		cout << "Failed to open file." << endl;
		return;
	}

	// Read the whole file into a string
	string fileContent((istreambuf_iterator<char>(FileOut)), istreambuf_iterator<char>());

	// Find the position of the identifier in the file
	size_t identifierPos = fileContent.find(identifier);
	// Find the end of the line
	size_t endOfLinePos = fileContent.find("\n", identifierPos);
	if (endOfLinePos == string::npos) {
		endOfLinePos = fileContent.length();
	}

	// Get the new string
	string newContent = identifier;
	for (int i = 0; i < size; i++) {
		cout << "\nEnter number " << i + 1 << ": ";
		int temp;
		while (!(cin >> temp)) {
			cin.clear();
			cin.ignore();
			cout << "PLEASE ENTER A NUMBER!" << endl;
			cout << "Enter number " << i + 1 << ": ";
		}
		arr[i] = temp;
	}

	// Sort the array if identifier is "(SD): "
	if (identifier == "(SD): ") {
		bubbleSort(arr, size);
	}

	// Append sorted array to newContent
	for (int i = 0; i < size; i++) {
		newContent += to_string(arr[i]) + " ";
	}

	// Replace the old string with the new one
	fileContent.replace(identifierPos, endOfLinePos - identifierPos, newContent);

	// Write the new content to the file
	FileOut.seekp(0);
	FileOut << fileContent;

	FileOut.close();
}


/// ===== SORT & COMPARE FUNCTIONS =====
// Bubble sort algorithm
void bubbleSort(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = size - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			}
		}
	}
}

// Selection sort algorithm
void selectionSort(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swap(arr[i], arr[minIndex]);
		}
	}
}

// Compare two arrays
bool compareArrays(const int* arr1, const int* arr2, int size) {
	for (int i = 0; i < size; i++) {
		if (arr1[i] != arr2[i]) {
			return false;
		}
	}
	return true;
}
