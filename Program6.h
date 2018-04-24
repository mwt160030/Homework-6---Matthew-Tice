// Name: Matthew Tice
// E-mail: mwt160030@utdallas.edu
// Class: CS 3377.502

// Header file that contains includes, funcrion prototypes, global variables, and class definitions for Program6

// Creating include guard
#ifndef _PROGRAM6_H_
#define _PROGRAM6_H_

using namespace std;

// Include statements
#include <iostream> 
#include <fstream>
#include <iomanip>
#include <stdint.h>
#include <string>
#include <sstream>
#include "cdk.h"

// Defining constants for CDK
#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"

// Class for the header of the binary file (magic number, version, and number of records)
class BinaryFileHeader
{
 public:
  uint32_t magicNumber; /* Should be 0xFEEDFACE */
  uint32_t versionNumber;
  uint64_t numRecords;
};

// Size of fixed buffer
const int maxRecordStringLength = 25;

// Class for the records in the binary file (string length and record string)
class BinaryFileRecord
{
 public:
  uint8_t strLength;
  char stringBuffer[maxRecordStringLength];
};

// Array used to store the data from the binary file
extern string matrixData[5][3];

// Function prototypes
void addRecord(ifstream&, int);
void createMatrix();

#endif //_PROGRAM6_H_
