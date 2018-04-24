// Name: Matthew Tice
// E-mail: mwt160030@utdallas.edu
// Class: CS 3377.502

#include "Program6.h"

// This is a file that contains support functions for Program6

// Function that reads a BinaryFileRecord from the binary file and stores the results in the global array
void addRecord(ifstream& binInfile, int index)
{
  // Creating a binary file record
  BinaryFileRecord *record = new BinaryFileRecord();

  // Reading record from the file
  binInfile.read((char *) record, sizeof(BinaryFileRecord));

  // Finding the length of the string 
  string temp = record->stringBuffer;
  int length = temp.length();

  // Creatring a string stream and adding the string length field to the matrix array
  stringstream strLen;
  strLen << "strlen: " << length;
  matrixData[index][0] = strLen.str();

  // Adding the string from the binary file to the matrix array
  matrixData[index][1] = record->stringBuffer;
}

// Function that creates a CDK matrix and prints it to screen
void createMatrix()
{
  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;     

  // Intializing size of matrix and data types that are accpeted in the fields of the matrix
  const char 		*rowTitles[] = {"0", "a", "b", "c", "d", "e"};
  const char 		*columnTitles[] = {"0", "a", "b", "c"};
  int		boxWidths[] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[] = {vMIXED, vMIXED, vMIXED, vMIXED,  vMIXED,  vMIXED};

  // Initialize the Cdk screen
  window = initscr();
  cdkscreen = initCDKScreen(window);

  // Start CDK Colors 
  initCDKColor();
  
  // Create the matrix.  Need to manually cast (const char**) to (char **)
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,
			  MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  // Check for errors in creating the matrix
  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  // Display the Matrix 
  drawCDKMatrix(myMatrix, true);

  // Displaying cells of data in the matrix
  setCDKMatrixCell(myMatrix, 1, 1, matrixData[0][0].c_str());
  drawCDKMatrix(myMatrix, true);
  setCDKMatrixCell(myMatrix, 1, 2, matrixData[0][1].c_str());
  drawCDKMatrix(myMatrix, true);
  setCDKMatrixCell(myMatrix, 1, 3, matrixData[0][2].c_str());
  drawCDKMatrix(myMatrix, true);
  setCDKMatrixCell(myMatrix, 2, 1, matrixData[1][0].c_str());
  drawCDKMatrix(myMatrix, true);
  setCDKMatrixCell(myMatrix, 2, 2, matrixData[1][1].c_str());
  drawCDKMatrix(myMatrix, true);
  setCDKMatrixCell(myMatrix, 3, 1, matrixData[2][0].c_str());
  drawCDKMatrix(myMatrix, true);
  setCDKMatrixCell(myMatrix, 3, 2, matrixData[2][1].c_str());
  drawCDKMatrix(myMatrix, true);
  setCDKMatrixCell(myMatrix, 4, 1, matrixData[3][0].c_str());
  drawCDKMatrix(myMatrix, true);
  setCDKMatrixCell(myMatrix, 4, 2, matrixData[3][1].c_str());
  drawCDKMatrix(myMatrix, true);
  setCDKMatrixCell(myMatrix, 5, 1, matrixData[4][0].c_str());
  drawCDKMatrix(myMatrix, true);
  setCDKMatrixCell(myMatrix, 5, 2, matrixData[4][1].c_str());
  drawCDKMatrix(myMatrix, true);

  // Blocking call to view the matrix
  unsigned char x;
  cin >> x;

  // Cleanup screen
  endCDK();
}
