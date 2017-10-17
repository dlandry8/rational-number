// ---------------------------------------------------------------------------
//	File:			rationalDriver.cpp
//
//	Functions:		int main()
//					char setGetTest()
//					char GCFTest()
//					char binaryArithemeticTest()
//					char incrementDecrementTest()
//					char plusNegateTest()
//					char powerTest()
//					char logicTest()
//					char typecastTest()
//					char IOTest()
//					char fractionGame()
//					char prompt(char(*thisFunction)())
// ---------------------------------------------------------------------------

#include "CRational.h"
#include <fstream>
#include <ctime>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;
using namespace DL_RATIONAL;

char setGetTest();
char GCFTest();
char binaryArithemeticTest();
char incrementDecrementTest();
char plusNegateTest();
char powerTest();
char logicTest();
char typecastTest();
char IOTest();
char fractionGame();
char prompt(char(*thisFunction)());

//----------------------------------------------------------------------------
//	Function:		main()
//
//	Title:			Main menu for the Rational Number Driver
//
//	Description:	This function presents a menu of testing options for the
//						Rational Number class.
//
//	Programmer:		David Landry
//   
//	Date:			2/29/2016
// 
//	Version:		1.02
//  
//	Environment:	PC 
//						Software:   MS Windows 10
//						Compiles under Microsoft Visual C++ Community 2013
// 
//	Input:			A character from the console
// 
//	Output:			The menu
// 
//	Calls:			The various test functions:
//					char setGetTest(), char GCFTest(), 
//					char binaryArithemeticTest(), 
//					char incrementDecrementTest(), char plusNegateTest(),
//					char powerTest(), char logicTest(), char typecastTest(),
//					char IOTest(), and char fractionGame()
// 
//	Called By:		None
// 
//	Parameters:		None
// 
//	Returns:		EXIT_SUCCESS  = successful 
//
//	History Log:
//					2/25/16		DL completed version 0.5
//					2/28/16		DL completed version 1.0
//					2/29/16		DL completed version 1.02
//----------------------------------------------------------------------------
int main()
{
	char selection = ' ';
	do
	{
		system("CLS");
		cout << "CRational Class Tests" << endl;
		cout << "=====================" << endl;
		cout << "These test all the possible operations that can be performed"
			<< " on, to," << endl <<
			"and from the CRational class and class objects." << endl << endl;
		cout << "Main Menu:" << endl;
		cout << "==========" << endl;
		cout << "\t1. Set & get test." << endl;
		cout << "\t2. Greatest Common Factor test." << endl;
		cout << "\t3. Binary arithmetic test" << endl;
		cout << "\t\t(addition, subtraction, etc.)." << endl;
		cout << "\t4. Increment and decrement test." << endl;
		cout << "\t5. Unary operators (+  -  ~) test." << endl;
		cout << "\t6. Exponent test." << endl;
		cout << "\t7. Logic test." << endl;
		cout << "\t8. Type cast test." << endl;
		cout << "\t9. Input/output test." << endl;
		cout << "\tG. Play the fraction game." << endl << endl;
		cout << "Enter a number, or q to quit.  _\b";
		(cin >> selection).get();
		switch (selection)
		{
		case '1': selection = setGetTest();
			break;
		case '2':  selection = GCFTest();
			break;
		case '3': selection = binaryArithemeticTest();
			break;
		case '4': selection = incrementDecrementTest();
			break;
		case '5': selection = plusNegateTest();
			break;
		case '6': selection = powerTest();
			break;
		case '7': selection = logicTest();
			break;
		case '8': selection = typecastTest();
			break;
		case '9': selection = IOTest();
			break;
		case 'g':
		case'G': selection = fractionGame();
			break;
		}
	} while (selection != 'q' && selection != 'Q');
	return EXIT_SUCCESS;
}

//----------------------------------------------------------------------------
//	Function:		char prompt(char(*thisFunction)())
//
//	Title:			Prompt At the End of the Test
//
//	Description:	This function prompts the user to retest or return to the
//						main menu.
//
//	Programmer:		David Landry
//   
//	Date:			2/28/2016
// 
//	Version:		1.0
//  
//	Environment:	PC 
//						Software:   MS Windows 10
//						Compiles under Microsoft Visual C++ Community 2013
// 
//	Input:			A character from the console
// 
//	Output:			The main menu or the calling function
// 
//	Calls:			The various test functions:
//					char setGetTest(), char GCFTest(), 
//					char binaryArithemeticTest(), 
//					char incrementDecrementTest(), char plusNegateTest(),
//					char powerTest(), char logicTest(), char typecastTest(),
//					char IOTest(), and char fractionGame()
// 
//	Called by:		The various test functions:
//					char setGetTest(), char GCFTest(), 
//					char binaryArithemeticTest(), 
//					char incrementDecrementTest(), char plusNegateTest(),
//					char powerTest(), char logicTest(), char typecastTest(),
//					char IOTest(), and char fractionGame()
// 
//	Parameters:		char(*thisFunction)(), a pointer to the function that
//						called this function.
// 
//	Returns:		A character. 
//
//	History Log:
//					2/25/16		DL completed version 0.5
//					2/28/16		DL completed version 1.0
//					2/29/16		DL completed version 1.02
//----------------------------------------------------------------------------

char prompt(char(*thisFunction)())
{
	char selection = ' ';
	do
	{
		cout << endl << endl <<
			"What would you like to do?\n(R)etest or (M)ain menu?  ";
		(cin >> selection).get();
		if ((selection = tolower(selection)) == 'r')
			(*thisFunction)();
		else if ((selection = tolower(selection)) == 'm')
			return 'm';
	} while (tolower(selection) != 'r' && tolower(selection) != 'm');
}

//----------------------------------------------------------------------------
//	Function:		char getSetTest()
//
//	Title:			Constructor Test
//
//	Description:	This function tests each of the constructor including
//						how they handle input and output.
//
//	Programmer:		David Landry
//   
//	Date:			2/28/2016
// 
//	Version:		1.0
//  
//	Environment:	PC 
//						Software:   MS Windows 10
//						Compiles under Microsoft Visual C++ Community 2013
// 
//	Input:			Various numbers in various formats.
// 
//	Output:			Correctly formatted fractions
// 
//	Calls:			CRational constructors, CRational::getNumerator(),
//						CRational::getDenominator(), CRational::print via the
//						<< operator, prompt()
// 
//	Called by:		main(), prompt()
// 
//	Parameters:		None
// 
//	Returns:		A character. 
//
//	History Log:
//					2/28/16		DL completed version 1.0
//----------------------------------------------------------------------------
char setGetTest()
{
	long number1 = 0;
	long number2 = 0;
	double number3 = 0.0;
	int number4 = 0;
	double number5 = 0.0;
	int number6 = 0;
	char selection = ' ';
	system("CLS");
	cout << "Test 1: Set & Get Test" << endl;
	cout << "======================" << endl;
	// -----------------------------------------------------------------------
	// Test 1a: Testing the constructors.
	// -----------------------------------------------------------------------
	CRational defaultFraction;
	cout << "Default fraction is " << defaultFraction << " or " <<
		defaultFraction.getNumerator() << "/" << 
		defaultFraction.getDenominator() << "." << endl << endl;
	CRational myRationalNumber1;
	CRational myRationalNumber2;
	int widthsize = 0;
	cout << setw(7) << left << "a. " << setw(7) << "b. 2L" << setw(7) 
		<< "c. -3" << setw(12) << "d. 9L, -6L" << setw(12) << "e. -5L, 2L" <<
		setw(12) << "f. 2.97854511" << endl;
	cout << "a. ";
	cout << myRationalNumber1 << "   b. ";
	myRationalNumber1 = 2L;
	cout << myRationalNumber1 << "   c. ";
	myRationalNumber1 = -3;
	cout << myRationalNumber1 << "   d. ";
	myRationalNumber1 = { 9L, 6L };
	cout << myRationalNumber1 << "   e. ";
	myRationalNumber1 = { -5L, 2L };
	cout << myRationalNumber1 << "   f. ";
	myRationalNumber1 = 2.97854511;
	cout << myRationalNumber1 << endl;
	// -----------------------------------------------------------------------
	// Test 1b: converting 2 integers/longs into a fraction:
	// -----------------------------------------------------------------------
	cout << "Enter 2 integers/longs with which to build a fraction" << endl
		<< "(the first would be the numerator, and the second would" <<
		" be the denominator):" << endl;
	try
	{
		(cin >> number1 >> number2).get();
		// Calling the default constructor:
		cout << "Calling the default constructor 2 ways..." << endl;
		CRational myRationalNumber1 = { number1, number2 };
		CRational myRationalNumber2(number1, number2);
		cout << "Done!" << endl;
		// Using the .get accessors:
		cout << "Fraction printed twice, first using .getNumerator and " <<
			".getDenominator:" << endl <<
			myRationalNumber1.getNumerator() << "/" <<
			myRationalNumber1.getDenominator() << endl << "And now directly:"
			// Using the overloaded << operator:
			<< endl << myRationalNumber2 << endl << endl;
	}
	catch (invalid_argument e)
	{
		cout << "You do realize division by 0 is not allowed right?" << endl;
		cout << "Error message:" << endl << e.what() << endl << endl;
	}
	// -----------------------------------------------------------------------
	// Test 1c: converting a floating-point number into a fraction:
	// -----------------------------------------------------------------------
	cout << "Enter a floating-point decimal number:" << endl;
	(cin >> number3).get();
	// Using the decimal constructor:
	cout << "Calling the decimal constructor..." << endl;
	CRational myRationalNumber3 = { number3 };
	cout << "Done!" << endl;
	cout << number3 << " = " << myRationalNumber3 << endl;
	// Using decimal constructor on the already-existing myRationalNumber1:
	cout << "Repurposing myRationalNumber1..." << endl;
	myRationalNumber1 = { number3 };
	cout << "Done!  myRationalNumber1 now equals number3." << endl;
	cout << "myRationalNumber 1 now equals " << myRationalNumber1 << "." <<
		endl << endl;
	// -----------------------------------------------------------------------
	// Test 1d: reading in 2 decimals and assigning them each to a separate
	//		fraction directly from cin:
	// -----------------------------------------------------------------------
	cout << "Enter 2 more floating-point decimal numbers:" << endl;
	(cin >> myRationalNumber1 >> myRationalNumber2).get();
	cout << "Was the right constructor called?  Was the input formatted " <<
		"correctly?" << endl;
	cout << "The first has been assigned a fraction of " << myRationalNumber1
		<< " (" << myRationalNumber1.getNumerator() << "/" <<
		myRationalNumber1.getDenominator() << ")" << endl;
	cout << "The 2nd has been assigned a fraction of " << myRationalNumber2 <<
		" (" << myRationalNumber2.getNumerator() << "/" <<
		myRationalNumber2.getDenominator() << ")" << endl << endl;
	// -----------------------------------------------------------------------
	// Test 1e: Single integer input:
	// -----------------------------------------------------------------------
	cout << "Enter an integer:" << endl;
	(cin >> number4).get();
	// Using the integer constructor:
	cout << "Calling the integer constructor...";
	myRationalNumber1 = { number4 };
	cout << "Done!" << endl;
	cout << "myRationalNumber1 equals " << myRationalNumber1 << "." << endl;
	cout << "Using .getNumerator and .getDenominator:  " <<
		myRationalNumber1.getNumerator() << "/" <<
		myRationalNumber1.getDenominator() << endl << endl;
	// -----------------------------------------------------------------------
	// Test 1f: reading in 2 integers and assigning them each to a separate
	//		fraction directly from cin:
	// -----------------------------------------------------------------------
	cout << "Enter 2 integers:" << endl;
	(cin >> myRationalNumber1 >> myRationalNumber2).get();
	cout << "Was the integer constructor called twice?  I hope so!" << endl;
	cout << "The first: " << myRationalNumber1 << ", or using " <<
		".getNumerator() & .getDenominator(): " <<
		myRationalNumber1.getNumerator() << "/" <<
		myRationalNumber1.getDenominator() << endl;
	cout << "The second: " << myRationalNumber2 << ", or using " <<
		".getNumerator() & .getDenominator(): " <<
		myRationalNumber2.getNumerator() << "/" <<
		myRationalNumber2.getDenominator() << endl << endl;
	// -----------------------------------------------------------------------
	// Test 1g:  Read in 2 fractions directly:
	// -----------------------------------------------------------------------
	try
	{
		cout << "Enter 2 fractions in the form of #/#" << endl;
		(cin >> myRationalNumber1 >> myRationalNumber2).get();
		cout << "Fraction 1: " << myRationalNumber1 << endl;
		cout << "Fraction 2: " << myRationalNumber2 << endl;
	}
	catch (invalid_argument e)
	{
		cout << "Are you testing division by 0.  If so, congratulations!" <<
			endl << "You have successfully been caught attempting this" <<
			endl << "horrific division.  Here's the what statement:" << endl;
		cout << e.what();
	}

	return prompt(setGetTest);
}

//----------------------------------------------------------------------------
//	Function:		char GCFTest()
//
//	Title:			Greatest Common Factor Test
//
//	Description:	This function tests the greatestCommonFactor method.
//
//	Programmer:		David Landry
//   
//	Date:			2/29/2016
// 
//	Version:		1.02
//  
//	Environment:	PC 
//						Software:   MS Windows 10
//						Compiles under Microsoft Visual C++ Community 2013
// 
//	Input:			2 long integers.
// 
//	Output:			The greatest common factor of those integers.
// 
//	Calls:			CRational constructors, greatestCommonFactor(), 
//						CRational::print via the << operator, prompt()
// 
//	Called by:		main(), prompt()
// 
//	Parameters:		None
// 
//	Returns:		A character. 
//
//	History Log:
//					2/28/16		DL completed version 1.0
//					2/29/16		DL completed version 1.02
//----------------------------------------------------------------------------
char GCFTest()
{
	long number1 = 0;
	long number2 = 0;
	long GCF = 0;
	CRational myFraction;
	system("CLS");
	cout << "Test 2: Greatest Common Factor" << endl;
	cout << "==============================" << endl;
	cout << "Enter 2 integers/longs:" << endl;
	(cin >> number1 >> number2).get();
	GCF = CRational::greatestCommonFactor(number1, number2);
	cout << "Greatest common factor is " << GCF << "." << endl;
	return prompt(GCFTest);
}

//----------------------------------------------------------------------------
//	Function:		char binaryArithemeticTest()
//
//	Title:			Binary Aritmetic Test
//
//	Description:	This function tests each of the overloaded binary
//						arithmetic operators.
//
//	Programmer:		David Landry
//   
//	Date:			2/28/2016
// 
//	Version:		1.0
//  
//	Environment:	PC 
//						Software:   MS Windows 10
//						Compiles under Microsoft Visual C++ Community 2013
// 
//	Input:			Various fractions.
// 
//	Output:			Correctly formatted fractions after performing arithemetic
//						operations.
// 
//	Calls:			CRational constructors; CRational::operators 
//						+, -, *, /, +=, -=, *=, /=; CRational::print via the 
//						<< operator; prompt()
// 
//	Called by:		main(), prompt()
// 
//	Parameters:		None
// 
//	Returns:		A character. 
//
//	History Log:
//					2/28/16		DL completed version 1.0
//----------------------------------------------------------------------------
char binaryArithemeticTest()
{
	system("CLS");
	CRational myFraction1;
	CRational myFraction2;
	cout << "Test 3: Binary Arithmetic Test" << endl;
	cout << "==============================" << endl;
	try
	{
		cout << "Enter 2 fractions, decimals, or int/longs:" << endl;
		(cin >> myFraction1 >> myFraction2).get();
		cout << "myFraction1: " << myFraction1 << "\tmyFraction2: " <<
			myFraction2 << endl << endl;
		cout << myFraction1 << " + " << myFraction2 << " = " << 
			(myFraction1 + myFraction2) << endl;
		cout << myFraction1 << " - " << myFraction2 << " = " << 
			(myFraction1 - myFraction2) << endl;
		cout << myFraction1 << " * " << myFraction2 << " = " << 
			(myFraction1 * myFraction2) << endl;
		try
		{
			cout << myFraction1 << " / " << myFraction2 << " = " << 
				(myFraction1 / myFraction2) << endl << endl;
		}
		catch (invalid_argument e)
		{
			cout << "Cannot perform division:" << endl << e.what() << endl;
		}
		cout << "Input a fraction with which to perform operations on each\n"
			<< "previously inputted fraction:" << endl;
		CRational myFraction3;
		(cin >> myFraction3).get();
		cout << myFraction1 << " += " << myFraction3 << " = ";
		myFraction1 += myFraction3;
		cout << myFraction1 << endl;
		myFraction1 -= myFraction3;
		cout << myFraction1 << " -= " << myFraction3 << " = ";
		myFraction1 -= myFraction3;
		cout << myFraction1 << endl;
		myFraction1 += myFraction3;
		cout << myFraction1 << " *= " << myFraction3 << " = ";
		myFraction1 *= myFraction3;
		cout << myFraction1 << endl;
		myFraction1 /= myFraction3;
		cout << myFraction1 << " /= " << myFraction3 << " = ";
		myFraction1 /= myFraction3;
		cout << myFraction1 << endl;
		cout << myFraction2 << " += " << myFraction3 << " = ";
		myFraction2 += myFraction3;
		cout << myFraction2 << endl;
		myFraction2 -= myFraction3;
		cout << myFraction2 << " -= " << myFraction3 << " = ";
		myFraction2 -= myFraction3;
		cout << myFraction2 << endl;
		myFraction2 += myFraction3;
		cout << myFraction2 << " *= " << myFraction3 << " = ";
		myFraction2 *= myFraction3;
		cout << myFraction2 << endl;
		myFraction2 /= myFraction3;
		cout << myFraction2 << " /= " << myFraction3 << " = ";
		myFraction2 /= myFraction3;
		cout << myFraction2 << endl;
	}
	catch (invalid_argument e)
	{
		cout << "Division won't work:" << endl << e.what() << endl;
	}

	return prompt(binaryArithemeticTest); 
}

//----------------------------------------------------------------------------
//	Function:		char incrementDecrementTest()
//
//	Title:			Increment and Decrement Test
//
//	Description:	This function tests the increment and decrement operator
//						overloads for the CRational class.
//
//	Programmer:		David Landry
//   
//	Date:			2/28/2016
// 
//	Version:		1.0
//  
//	Environment:	PC 
//						Software:   MS Windows 10
//						Compiles under Microsoft Visual C++ Community 2013
// 
//	Input:			A fraction.
// 
//	Output:			Correctly formatted fractions after decrement and
//						increment.
// 
//	Calls:			CRational constructors; CRational::operator
//						++(), --(), ++(int), --(int); CRational::print via the 
//						<< operator; prompt()
// 
//	Called by:		main(), prompt()
// 
//	Parameters:		None
// 
//	Returns:		A character. 
//
//	History Log:
//					2/28/16		DL completed version 1.0
//----------------------------------------------------------------------------
char incrementDecrementTest()
{
	system("CLS");
	CRational myFraction;
	CRational tempFraction;
	CRational originalFraction;
	cout << "Test 4: Increment and Decrement" << endl;
	cout << "===============================" << endl;
	try
	{
		cout << "Enter a fraction, decimal, or integer:" << endl;
		(cin >> myFraction).get();
		originalFraction = myFraction;
		cout << "First, the postfix increment and decrement." << endl << endl;
		cout << "You entered " << (myFraction++) << "." << endl;
		cout << "This test did a postfix increment during the printout of" <<
			" the previous line." << endl;
		cout << "After postfix incrementing, it is now " << myFraction << "."
			<< endl;
		myFraction = originalFraction;
		cout << "You entered " << (myFraction--) << "." << endl;
		cout << "A postfix decrement was performed within the previous line."
			<< endl;
		cout << "After postfix decrementing, it is now " << myFraction << "."
			<< endl << endl;
		myFraction = originalFraction;
		cout << "Now, the prefix increment and decrement." << endl << endl;
		cout << "You entered " << myFraction << "." << endl;
		cout << "Prefix incrementing... it is now " << (++myFraction) << "."
			<< endl;
		cout << "Resetting..." << endl;
		myFraction = originalFraction;
		cout << "You entered " << myFraction << "." << endl;
		cout << "Prefix decrementing... it is now " << (--myFraction) << "."
			<< endl;
	}
	catch (invalid_argument e)
	{
		cout << "Could not perform this test:" << endl << e.what() << endl;
	}
	return prompt(incrementDecrementTest);
}

//----------------------------------------------------------------------------
//	Function:		char plusNegateTest()
//
//	Title:			Unary Operator Test
//
//	Description:	This function tests the overloaded unary operators from
//						the CRational Class.
//
//	Programmer:		David Landry
//   
//	Date:			2/28/2016
// 
//	Version:		1.0
//  
//	Environment:	PC 
//						Software:   MS Windows 10
//						Compiles under Microsoft Visual C++ Community 2013
// 
//	Input:			A fraction.
// 
//	Output:			Correctly formatted fractions after performing several
//						operations.
// 
//	Calls:			CRational constructors; CRational::operator
//						+, -, ~; CRational::print via the << operator;
//						prompt()
// 
//	Called by:		main(), prompt()
// 
//	Parameters:		None
// 
//	Returns:		A character. 
//
//	History Log:
//					2/28/16		DL completed version 1.0
//----------------------------------------------------------------------------
char plusNegateTest()
{
	system("CLS");
	CRational myFraction;
	cout << "Test 5: Unary operators test (+  -  ~)" << endl;
	cout << "======================================" << endl;
	try
	{
		cout << "Enter a fraction, decimal, or integer:" << endl;
		(cin >> myFraction).get();
		cout << "+" << myFraction << " = " << (+myFraction) << endl;
		cout << "-" << myFraction << " = " << (-myFraction) << endl;
		try
		{
			cout << "~" << myFraction << " = " << (~myFraction) << endl;
		}
		catch (invalid_argument e)
		{
			cout << "Could not perform the multiplicative inverse test:" <<
				endl << e.what() << endl;
		}
	}
	catch (invalid_argument e)
	{
		cout << "Could not perform this test:" << endl << e.what() << endl;
	}
	return prompt(plusNegateTest);
}

//----------------------------------------------------------------------------
//	Function:		char powerTest()
//
//	Title:			Exponent Test
//
//	Description:	This function tests the powerOf method from the CRational
//						class.
//
//	Programmer:		David Landry
//   
//	Date:			2/28/2016
// 
//	Version:		1.0
//  
//	Environment:	PC 
//						Software:   MS Windows 10
//						Compiles under Microsoft Visual C++ Community 2013
// 
//	Input:			A fraction and an integer for the exponent.
// 
//	Output:			Correctly formatted fractions after calling the powerOf
//						method
// 
//	Calls:			CRational constructors, CRational::powerOf(), 
//						CRational::print via the << operator, prompt()
// 
//	Called by:		main(), prompt()
// 
//	Parameters:		None
// 
//	Returns:		A character. 
//
//	History Log:
//					2/28/16		DL completed version 1.0
//----------------------------------------------------------------------------
char powerTest()
{
	system("CLS");
	CRational myFraction;
	CRational powerfulFraction;
	int exponent;
	cout << "Test 6: To-the-power-of test" << endl;
	cout << "============================" << endl;
	cout << "Enter a fraction, decimal, or integer:" << endl;
	try
	{
		(cin >> myFraction).get();
		cout << "Enter an integer for an exponent:" << endl;
		(cin >> exponent).get();
		powerfulFraction = myFraction.toThePower(exponent);
		cout << myFraction << " to the power of " << exponent << " = " <<
			powerfulFraction << "." << endl;
	}
	catch (invalid_argument e)
	{
		cout << "Could not proceed:" << endl << e.what() << endl;
	}
	return prompt(powerTest);
}

//----------------------------------------------------------------------------
//	Function:		char logicTest()
//
//	Title:			Logic Test
//
//	Description:	This function tests the compareTo and the overloaded
//						logic operators from the CRational class.
//
//	Programmer:		David Landry
//   
//	Date:			2/28/2016
// 
//	Version:		1.0
//  
//	Environment:	PC 
//						Software:   MS Windows 10
//						Compiles under Microsoft Visual C++ Community 2013
// 
//	Input:			Two fractions.
// 
//	Output:			The correctly formatted fractions in addition to a logical
//						combination of:
//						is equal to, is not equal to, is less than, is greater
//						than, is less than or equal to, is greater than or
//						equal to.
//					1 or 0 and true or false, depending on the result of the
//						! and bool tests.
// 
//	Calls:			CRational constructors; CRational::compareTo();
//						CRational::operator	==, !=, <, <=, >, >=, !, bool;
//						CRational::print via the << operator; prompt()
// 
//	Called by:		main(), prompt()
// 
//	Parameters:		None
// 
//	Returns:		A character. 
//
//	History Log:
//					2/28/16		DL completed version 1.0
//----------------------------------------------------------------------------
char logicTest()
{
	CRational myFraction1;
	CRational myFraction2;
	CRational myFraction3;
	system("CLS");
	cout << "Test 7:  Logic Test" << endl;
	cout << "===================" << endl;
	try
	{
		cout << "Enter a combination of 2 fractions, decimals, or integers:"
			<< endl;
		(cin >> myFraction1 >> myFraction2).get();
		cout << "compareTo: " << myFraction1.compareTo(myFraction2) << endl;
		if (myFraction1 == myFraction2)
			cout << myFraction1 << " is equal to " << myFraction2 << ".\n";
		if (myFraction1 != myFraction2)
			cout << myFraction1 << " is not equal to " << myFraction2 <<
			"." << endl;
		if (myFraction1 < myFraction2)
			cout << myFraction1 << " is less than " << myFraction2 << ".\n";
		if (myFraction1 <= myFraction2)
			cout << myFraction1 << " is less than or equal to " << myFraction2
			<< "." << endl;
		if (myFraction1 > myFraction2)
			cout << myFraction1 << " is greater than " << myFraction2 << "."
			<< endl;
		if (myFraction1 >= myFraction2)
			cout << myFraction1 << " is greater than or equal to " <<
			myFraction2 << "." << endl << endl;
		cout << "Switching the order..." << endl << endl;
		cout << "compareTo: " << myFraction2.compareTo(myFraction1) << endl;
		if (myFraction2 == myFraction1)
			cout << myFraction2 << " is equal to " << myFraction1 << ".\n";
		if (myFraction2 != myFraction1)
			cout << myFraction2 << " is not equal to " << myFraction1 << "."
			<< endl;
		if (myFraction2 < myFraction1)
			cout << myFraction2 << " is less than " << myFraction1 << ".\n";
		if (myFraction2 <= myFraction1)
			cout << myFraction2 << " is less than or equal to " << myFraction1
			<< "." << endl;
		if (myFraction2 > myFraction1)
			cout << myFraction2 << " is greater than " << myFraction1 << "."
			<< endl;
		if (myFraction2 >= myFraction1)
			cout << myFraction2 << " is greater than or equal to " <<
			myFraction1 << "." << endl << endl;
		cout << "True & false test for " << myFraction1 << ":" << endl;
		cout << "!" << myFraction1 << " = " << (!myFraction1) << "." << endl;
		cout << "(bool)" << myFraction1 << " = " << (bool(myFraction1)) << "."
			<< endl;
		if (myFraction1)
			cout << myFraction1 << " is true." << endl << endl;
		if (!myFraction1)
			cout << myFraction1 << " is false." << endl << endl;
		cout << "True & false test for " << myFraction2 << ":" << endl;
		cout << "!" << myFraction2 << " = " << (!myFraction2) << "." << endl;
		cout << "(bool)" << myFraction2 << " = " << (bool(myFraction2)) << "."
			<< endl;
		if (myFraction2)
			cout << myFraction2 << " is true." << endl;
		if (!myFraction2)
			cout << myFraction2 << " is false." << endl;
	}
	catch (invalid_argument e)
	{
		cout << "This test could not proceed:" << endl << e.what() << endl;
	}
	return prompt(logicTest);
}

//----------------------------------------------------------------------------
//	Function:		char typecastTest()
//
//	Title:			Type Cast Test
//
//	Description:	This function tests the type cast methods of the CRational
//						method.
//
//	Programmer:		David Landry
//   
//	Date:			2/28/2016
// 
//	Version:		1.0
//  
//	Environment:	PC 
//						Software:   MS Windows 10
//						Compiles under Microsoft Visual C++ Community 2013
// 
//	Input:			A fraction.
// 
//	Output:			The fraction converted to a double, a string, and a
//						boolean.
// 
//	Calls:			CRational constructors; CRational::operator
//						double, string, bool; CRational::print via the << 
//						operator; prompt()
// 
//	Called by:		main(), prompt()
// 
//	Parameters:		None
// 
//	Returns:		A character. 
//
//	History Log:
//					2/28/16		DL completed version 1.0
//----------------------------------------------------------------------------
char typecastTest()
{
	system("CLS");
	CRational myFraction;
	cout << "Test 8:  Type cast" << endl;
	cout << "==================" << endl;
	cout << "Please enter a fraction, decimal, or integer." << endl;
	try
	{
		(cin >> myFraction).get();
		cout << "Your fraction: " << myFraction << "." << endl;
		cout << "Your fraction as a decimal: " << (double(myFraction)) <<
			endl;
		cout << "Trying some string magic..." << endl;
		string string1 = "The quick brown fox jumps over ";
		string string2 = " lazy dogs.";
		string string3 = string(myFraction);
		string string4 = string1 + string3 + string2;
		cout << string4 << endl;
		bool fractionAsBool = bool(myFraction);
		cout << "Your fraction as a boolean: " << fractionAsBool << "." <<
			endl;
	}
	catch (invalid_argument e)
	{
		cout << "Could not proceed:" << endl << e.what() << endl;
	}
	return prompt(typecastTest);
}

//----------------------------------------------------------------------------
//	Function:		char IOTest()
//
//	Title:			Input/Output Test
//
//	Description:	This function tests string and file I/O when working with
//						the CRational class.
//
//	Programmer:		David Landry
//   
//	Date:			2/28/2016
// 
//	Version:		1.0
//  
//	Environment:	PC 
//						Software:   MS Windows 10
//						Compiles under Microsoft Visual C++ Community 2013
// 
//	Input:			A fraction and a string for a file name.
// 
//	Output:			The fraction to a string, to the console, and to an
//						indicated file.
// 
//	Calls:			CRational constructors; CRational::print via the << 
//						operator; prompt()
// 
//	Called by:		main(), prompt()
// 
//	Parameters:		None
// 
//	Returns:		A character. 
//
//	History Log:
//					2/28/16		DL completed version 1.0
//----------------------------------------------------------------------------
char IOTest()
{
	system("CLS");
	cout << "Test 9: IO Test" << endl;
	cout << "===============" << endl;
	ifstream ifs;
	ofstream ofs;
	string myString;
	istringstream iss;
	ostringstream oss;
	CRational myFraction;
	CRational myFraction2;
	CRational myFraction3;
	cout << "Enter a fraction, decimal, or integer: " << endl;
	try
	{
		(cin >> myFraction).get();
		cout << myFraction << endl;
		cout << "Building string..." << endl;
		for (short i = 0; i < 6; i++)
		{
			for (short j = 0; j < 10; j++)
				oss << myFraction << " ";
			oss << endl;
		}
		myString = oss.str();
			
		cout << myString << endl << endl;
		cout << "Enter a name for a file.  This program will automatically "
			<< " append the .txt,\nso don't include it." << endl;
		string filename;
		cin >> filename;
		filename += ".txt";
		try
		{
			ofs.open(filename);
			for (short i = 0; i < 6; i++)
			{
				for (short j = 0; j < 10; j++)
					ofs << myFraction << " ";
				ofs << endl;
			}
			ofs.close();
			cout << filename << " is ready to be viewed.  It should be in the"
				<< endl << "same directory as this program." << endl;
		}
		catch (exception e)
		{
			cout << "I couldn't open the file." << e.what() << endl;
		}
		
		iss.str(myString);
		iss >> myFraction2;
		cout << "Retrieving my fraction from the string:  " << myFraction2 <<
			endl;
		try
		{
			ifs.open(filename);
			ifs >> myFraction3;
			cout << "Retrieving my fraction from test file:  " << myFraction3
				<< endl;
			ifs.close();
		}
		catch (exception e)
		{
			cout << "I couldn't open the file." << e.what() << endl;
		}
		
	}
	catch (invalid_argument e)
	{
		cout << "Could not proceed with test:" << endl << e.what() << endl;
	}
	return prompt(IOTest);
}

//----------------------------------------------------------------------------
//	Function:		char fractionGame()
//
//	Title:			Fraction Game
//
//	Description:	This function has the user enter the correct reduced
//						fraction given the random decimal.  This function
//						tests several aspects of the CRational class in a
//						fun and different way.
//
//	Note:			This function incorporates some features not covered in
//						CS 132.
//
//	Programmer:		David Landry
//   
//	Date:			2/28/2016
// 
//	Version:		1.0
//  
//	Environment:	PC 
//						Software:   MS Windows 10
//						Compiles under Microsoft Visual C++ Community 2013
// 
//	Input:			Fractions.
// 
//	Output:			Decimals; then either "correct" or "incorrect", followed
//						by a properly formatted fraction.
// 
//	Calls:			CRational constructors; CRational::operator==, !=, double;
//						CRational::print via the << operator.
// 
//	Called by:		main(), prompt()
// 
//	Parameters:		None
// 
//	Returns:		A character. 
//
//	History Log:
//					2/28/16		DL completed version 1.0
//----------------------------------------------------------------------------
char fractionGame()
{
	long numerator = 0;
	long denominator = 0;
	double randomDecimal = 0;
	short score = 0;
	CRational randomFraction;
	CRational myFraction;
	system("CLS");
	cout << "Name the Fraction Game!" << endl;
	cout << "=======================" << endl;
	cout << "The purpose of this game is to enter in the correct proper\n"
		<< "fraction given the decimal provided.  The fraction must always\n"
		<< "be in the form of #/# (for example, 1.5 would be entered as\n"
		<< "3/2).  You'll get 10 decimal numbers to convert and will score\n"
		<< "1 point for each correct answer." << endl << endl;
	cout << "Press <enter> to begin!" << endl;
	cin.get();
	for (short i = 0; i < 10; i++)
	{
		system("CLS");
		unsigned seed =
			std::chrono::system_clock::now().time_since_epoch().count();
		default_random_engine generator (seed);
		uniform_int_distribution<int> distribution1(-10, 10);
		uniform_int_distribution<int> distribution2(1, 10);
		numerator = distribution1(generator);
		denominator = distribution2(generator);
		randomFraction = { numerator, denominator };
		randomDecimal = double(randomFraction);
		cout << randomDecimal << endl << "?";
		(cin >> myFraction).get();
		if (myFraction == randomFraction)
		{
			cout << "Correct!  ";
			++score;
		}
		else
			cout << "Incorrect!  ";
		cout << randomFraction << endl;
		cin.get();
	}
	system("CLS");
	cout << "GAME OVER!" << endl;
	cout << "==========" << endl;
	cout << "Your score:  " << score << endl;
	return prompt(fractionGame);
}
