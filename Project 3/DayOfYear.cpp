
// Byron Burdette
// COP2551.001



/************************************************************************************************************************************************
*************************************************************************************************************************************************
												MEMBER FUNCTION DEFINITIONS FOR CLASS "DayOfYear"
*************************************************************************************************************************************************
*************************************************************************************************************************************************/






#include "DayOfYear.h"												//	include the header file for class "DayOfYear"







//	initializes an array with the number of days in each of the 12 months
const int DayOfYear::daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };




//	initializes an array with the names of each of the 12 months
const string DayOfYear::month[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };




/************************************************************************************************************************************************
											THIS MARKS THE BEGINNING OF THE DEFAULT CONSTRUCTOR

										The purpose of this function is to initialize "julianDate";
*************************************************************************************************************************************************/
DayOfYear::DayOfYear()
{
	julianDate = 0;
}
/************************************************************************************************************************************************
											THIS MARKS THE END OF THE DEFAULT CONSTRUCTOR
*************************************************************************************************************************************************/




/************************************************************************************************************************************************
												THIS MARKS THE BEGINNING OF THE "promptUser" FUNCTION

		The purpose of this function is to display a formatted prompt defining the purpose of the program and the user's instructions
*************************************************************************************************************************************************/
void DayOfYear::promptUser()
{
	cursor.placeCursor(screen, 12, 1);															//	place the cursor at cell (14, 1)
	cout << "*******************************************************" << endl;					//	display the top of a box

	cursor.placeCursor(screen, 12, 2);															//	place the cursor at cell (14, 2)
	cout << "* Enter a Julian date (any number between 1-365) and  *" << endl					//	display part of the prompt
		 << setw(12) << " " << "* I'll convert it to its corresponding Gregorian date *"		//	display part of the prompt
		 << endl;				

	cursor.placeCursor(screen, 12, 4);															//	place the cursor at cell (14, 4)
	cout << "*******************************************************" << endl << endl			//	display the bottom of the box
		 << setw(36) << " ";																	//	formatting

}
/************************************************************************************************************************************************
													THIS MARKS THE END OF THE "promptUser" FUNCTION
*************************************************************************************************************************************************/




/************************************************************************************************************************************************
												THIS MARKS THE BEGINNING OF THE "getInput" FUNCTION

										The purpose of this function is to read and store the user's input
*************************************************************************************************************************************************/
void DayOfYear::getInput()
{
	cin >> julianDate;												//	read the users input and store it in "julianDate"
}
/************************************************************************************************************************************************
												THIS MARKS THE END OF THE "getInput" FUNCTION
*************************************************************************************************************************************************/




/************************************************************************************************************************************************
											THIS MARKS THE BEGINNING OF THE "validateInput" FUNCTION

The purpose of this function is to validate whether the user's input falls between 1-365, ensuring that it can be converted to a Gregorian date
*************************************************************************************************************************************************/
void DayOfYear::validateInput()
{
	while (julianDate < 1 || julianDate > 365)						//	continue to loop until the user enters a number between 1-365
	{
		cout << "You have to enter a number between 1-365: ";		//	display error message	

		cin.sync();													//	clear the keyboard buffer
		cin.clear();												//	clear the iostate

		getInput();													//	jump over to "getInput" to reread the users input
	}
}
/************************************************************************************************************************************************
											THIS MARKS THE END OF THE "validateInput" FUNCTION
*************************************************************************************************************************************************/




/************************************************************************************************************************************************
											THIS MARKS THE BEGINNING OF THE "processInput" FUNCTION

The purpose of this function is to process the users Julian Date into its corresponding Gregorian date. It accomplishes this with a "for" loop
which sums up the number of days for each month until the sum is greater than the users Julian Date. The number of iterations the "for" loop
makes will coincide with the month AFTER the month which the users Julian date actually corresponds to, so subtracting one from the loop counter
gives the month for the Gregorian date. To find the specific day of that month, we subtract the sum of days in every month (except that month wich
corresponds to the Gregorian date) from the Julian date. 
*************************************************************************************************************************************************/
void DayOfYear::processInput()
{
	int m = 0;														//	a loop counter representing the month
	int sum = 0;													//	a variable to hold the sum of all the days in each month

	for (; sum < julianDate; m++)									//	loop until the sum of days is greater than the Julian date
		sum += daysInMonth[m];										//	add the number of days this month to "sum"


	gregorianDate = month[m - 1] + " " + to_string(julianDate - (sum - daysInMonth[m - 1]));	//	calculate and store the Gregorian date
}
/************************************************************************************************************************************************
												THIS MARKS THE END OF THE "validateInput" FUNCTION
*************************************************************************************************************************************************/




/************************************************************************************************************************************************
												THIS MARKS THE BEGINNING OF THE "output" FUNCTION

							The purpose of this function is to format and display the corresponding Gregorian date.
*************************************************************************************************************************************************/
void DayOfYear::output()
{
	cout << endl << setw(35) <<  " " << gregorianDate;				//	format and display the Gregorian date

	cout << endl << endl << endl;									//	blank space formatting
}
/************************************************************************************************************************************************
													THIS MARKS THE END OF THE "output" FUNCTION
*************************************************************************************************************************************************/