#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

///===== WORKING WITH FILES =====
const string FILE_PATH = "ASM4.dat";

bool isFirstTime();

void setMSCN(int* arr_in_file, ofstream& outFile);

void setSafetyDistance(int* arr_in_file, ofstream& outFile);

void readMSCNFromFile(int* arr_in_file, ifstream& FileIn);

void readSafetyDistanceFromFile(int* arr_in_file, ifstream& FileIn);

int readDataFromFile(int* arr_in_file, int* arr_inputted, char name, bool first_time);

void writeDataToFile(int* arr, int size, const string& identifier);

/// ===== SORT & COMPARE FUNCTIONS =====
void bubbleSort(int* arr, int size);

void selectionSort(int* arr, int size);

bool compareArrays(const int* arr1, const int* arr2, int size);

