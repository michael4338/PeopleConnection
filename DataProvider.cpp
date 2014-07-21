#include <string>
#include <sstream>
#include <iostream>
#include <assert.h>
#include <math.h>
#include "DataProvider.hpp"

FileDataProvider::FileDataProvider(const char* fileName):m_fileName(fileName){
	m_inFile.open(fileName, ifstream::in);
	if(!m_inFile.is_open()) {
		cerr<<"ERROR: failed to open csv file: "<<fileName<<endl;
	}
}

/*
IN:
	size: number of data to get

OUT:
	data: data array got from file

RETURN:
	0 if succeeded, others if failed
*/
int FileDataProvider::getData(unsigned long data[], int size){
	if(! m_inFile.good()) return -1;

	string line;
	getline(m_inFile, line);
	
	//input validation
	assert(size >= 2);
	int matchingNumber = sscanf(line.c_str(), "calling #%lu, called #%lu", &data[0], &data[1]);
	if(size != matchingNumber) return 1;

	unsigned long max = (unsigned long)pow(10, 15);
	if(max <= data[0] || max <= data[1]) return 1;

/*
	stringstream ss(line);
	string field;
	int counter = 0;
	while(getline(ss, field, ',')){
		stringstream fs(field);
		fs >> data[counter];
		counter++;
	}
	
	return counter!=size;
*/
	return 0;
}
