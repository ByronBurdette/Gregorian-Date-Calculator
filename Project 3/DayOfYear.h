
// Byron Burdette
// COP2551.001



/*************************************************************************************************************************************************
**************************************************************************************************************************************************
												CLASS SPECIFICATION FILE FOR THE CLASS "DayOfYear"
**************************************************************************************************************************************************
*************************************************************************************************************************************************/






/**********************************************					 PREPROCESSOR DIRECTIVES				*****************************************/
#ifndef DAYOFYEAR_H									//	include guard checks if "DAYOFYEAR_H" has already been defined in the program
#define DAYOFYEAR_H									//	defines "DAYOFYEAR_H" if it's not already

#include<iostream>									//	includes the library for standard i/o stream objects
#include<string>									//	includes the library for string types
#include<sstream>									//	includes the library for stringstream objets
#include<iomanip>									//	includes the library for manipulating i/o stream objects
#include "Cursor.h"									//	include the header file for manipulating the cursor's position
/************************************************************************************************************************************************/


using namespace std;											//	lifts all entities in the standard namespace into the global namespace




class DayOfYear
{
	private: int julianDate;										//	stores the user's input
			 string gregorianDate;									//	stores the processed input as a string containing a date
			 static const int daysInMonth[12];						//	stores the number of days in each of the 12 months
			 static const string month[12];							//	stores the name of each of the 12 months
			 Cursor cursor;											//	creates a cursor object for manipulating the cursor
			 HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);		//	initializes a handle to the std output
			

	public: DayOfYear();
			void promptUser();										//	prompts the user for input
			void getInput();										//	reads and stores the user's input
			void validateInput();									//	validates the user's input
			void processInput();									//	processes the user's input into a month and day
			void output();											//	displays formatted output
};
#endif

/************************************************************************************************************************************************
*************************************************************************************************************************************************
											THIS MARKS THE END OF THE CLASS SPECIFICATION FILE
*************************************************************************************************************************************************
*************************************************************************************************************************************************/