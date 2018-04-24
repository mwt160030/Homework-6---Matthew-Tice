// Name: Matthew Tice
// E-mail: mwt160030@utdallas.edu
// Class: CS 3377.502

// This program reads from a binary file and then fills a matrix with data from the binary file

#include "Program6.h"

// Global array to store matrix data
string matrixData[5][3];

int main()
{
  // Creating binary file record
  ifstream binInfile ("cs3377.bin", ios::in | ios::binary);
  
  // Creater instance of a BinaryFileHeader
  BinaryFileHeader *header = new BinaryFileHeader();

  // Reading header
  binInfile.read((char *) header, sizeof(BinaryFileHeader));

  // Creating a string stream and creating the magic number field for the matrix
  stringstream magicNumber;
  magicNumber << "Magic: 0x" << std::hex << std::uppercase << header->magicNumber;
  matrixData[0][0] = magicNumber.str();

  // Creatring a string stream and creating the version number field for the matrix
  stringstream versionNumber;
  versionNumber << "Version: " << header->versionNumber;
  matrixData[0][1] = versionNumber.str();

  // Creatring a string stream and creating the number of records field for the matrix 
  stringstream numberOfRecords;
  numberOfRecords << "NumRecords: " << header->numRecords;  
  matrixData[0][2] = numberOfRecords.str();

  // Reading numRecords records from the binary file and adding them to the global array
  for (unsigned int i = 1; i <= header->numRecords; i++)
    {
      addRecord(binInfile, i);
    }

  // Creatring the matrix
  createMatrix();
 
  return 0;
}
