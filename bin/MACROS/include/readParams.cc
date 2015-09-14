#include "readParams.h"

#include <math.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <vector>


using namespace std;

vector<double> readParams(string fileName)
	{
	vector<double> vec;
//	===============================================================================
//	read parameters from file
//	===============================================================================
	FILE * myParFile;
//	cout << fileName << endl;
	myParFile = fopen(fileName.c_str(), "r");
	if (myParFile == NULL) { cout << "File error for " << fileName << endl; return vec;}
/*
//	obtain file size:
	fseek (myParFile , 0 , SEEK_END);
	long lSize = ftell (myParFile);
	rewind (myParFile);

//	allocate memory to contain the whole file:
	char * buffer = (char*) malloc (sizeof(char)*lSize);
//	if (buffer == NULL) {fputs ("Memory error",stderr); return 0;}

//	copy the file into the buffer:
	size_t result = fread (buffer, 1, lSize, myParFile);
	string test = buffer;

	while (test.find(",") != -1)
		{
		size_t pos;
		pos = test.find(",");
		string test1 = test.substr(0, pos);
		test = test.substr(pos+1);
		vec.push_back(atof(test1.c_str()));
		}

//	if (result != lSize) {fputs ("Reading error",stderr); return 0;}
*/
	float data = 0;
	while (fscanf(myParFile, "%f", &data) != EOF)
		vec.push_back(data);

	fclose(myParFile);
//	===============================================================================
	return vec;
	}

vector<string> sreadParams(string fileName)
	{
	vector<string> vec;
//	===============================================================================
//	read parameters from file
//	===============================================================================
	FILE * myParFile;
//	cout << fileName << endl;
	myParFile = fopen(fileName.c_str(), "r");
	if (myParFile == NULL) { cout << "File error" << endl; return vec;}

	char data[20];
	while (fscanf(myParFile, "%s", &data) != EOF)
		vec.push_back(data);

	fclose(myParFile);
//	===============================================================================
	return vec;
	}
