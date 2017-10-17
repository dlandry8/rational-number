//----------------------------------------------------------------------------
//	File:		CRational.cpp
//
//	functions:	
//			CRational CRational::operator+
//				(const CRational & rationalNumber) const
//			CRational CRational::operator-
//				(const CRational & rationalNumber) const
//			CRational CRational::operator*
//				(const CRational & rationalNumber) const
//			CRational CRational::operator/
//				(const CRational & rationalNumber) const
//			CRational CRational::operator+=(const CRational & rationalNumber)
//			CRational CRational::operator-=(const CRational & rationalNumber)
//			CRational CRational::operator*=(const CRational & rationalNumber)
//			CRational CRational::operator/=(const CRational & rationalNumber)
//			CRational CRational::toThePower(int exponent) const
//			CRational CRational::operator++()
//			CRational CRational::operator--()
//			CRational CRational::operator++(int)
//			CRational CRational::operator--(int)
//			CRational CRational::operator~() const
//			long CRational::compareTo(const CRational & rationalNumber) const
//			bool CRational::operator <(const CRational & rationalNumber) const
//			bool CRational::operator >(const CRational & rationalNumber) const
//			bool CRational::operator <=(const CRational & rationalNumber) const
//			bool CRational::operator >=(const CRational & rationalNumber) const
//          CRational::operator string() const
//			void CRational::print(ostream & sout = cout) const
//			long greatestCommonFactor(const long number1, const long number2)
//			void CRational::setProperForm(long numerator, long denominator)
//			void CRational::setProperForm(double decimal)
//			long CRational::leastCommonDenominator
//              (const CRational & comlexNumber) const
//			ostream& operator<<(ostream& sout,
//				const CRational &rationalNumber)
//			istream& operator>>(istream& sin,
//				CRational& rationalNumber)
//			
//----------------------------------------------------------------------------
#include "CRational.h"
#include <cctype>
using namespace std;

namespace DL_RATIONAL
{
	const char CRational::ERROR_MESSAGE[45] = "Domain error:\nDivision by 0 is not allowed.";
	const double CRational::ROUND_ERROR_HIGH = .99999999;
	const double CRational::ROUND_ERROR_LOW = .00000001;
	const short CRational::MAX_PRECISION = 8;

	//-----------------------------------------------------------------------------
	//	Class:          CRational
	//
	//	Title:          Rational Number Class
	//
	//	Description:    Definitions for CRational methods and related functions
	//
	//	Programmer:     David Landry
	//   
	//	Date:           2/29/2016
	// 
	//	Version:        1.0
	//  
	//	Environment:	PC 
	//				Software:   MS Windows 10
	//				Compiles under Microsoft Visual C++ Community 2013
	// 
	//	class: CRational
	//
	//	Properties:
	//	               double m_numerator -- the real part of the number
	//	               double m_denominator -- the imaginary part of the number
	//
	//	History Log:
	//                	2/29/2016- DL completed version 1.0.
	//------------------------------------------------------------------------

	// -----------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			CRational CRational::operator+
	//						(const CRational & rationalNumber) const
	//	Description:	Addition operator overload.
	//	Input:			None
	//	Output:			None
	//	Calls:			leastCommonDenominator(), getNumerator(),
	//						getDenominator(), default constructor
	//	Called by:		None
	//	Parameters:		const CRational & rationalNumber
	//						A constant reference to a CRational object.
	//	Returns:		A CRational object: the sum of two CRationals
	//	History log:	2/23/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	CRational CRational::operator+(const CRational &rationalNumber) const
	{
		long LCD = leastCommonDenominator(rationalNumber);
		long thisFactor = LCD / m_denominator;
		long thatFactor = LCD / rationalNumber.getDenominator();
		long thisNumerator = m_numerator * thisFactor;
		long thisDenominator = m_denominator * thisFactor;
		long numerator = thatFactor * rationalNumber.getNumerator();
		long denominator = thatFactor * rationalNumber.getDenominator();
		return CRational(thisNumerator + numerator, denominator);
	}

	// -----------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			CRational CRational::operator-
	//						(const CRational & rationalNumber) const
	//	Description:	Subtraction operator overload.
	//	Input:			None
	//	Output:			None
	//	Calls:			leastCommonDenominator(), getNumerator(),
	//						getDenominator(), default constructor
	//	Called by:		None
	//	Parameters:		const CRational & rationalNumber
	//						A constant reference to a CRational object.
	//	Returns:		A CRational object: the difference of two CRationals
	//	History log:	2/23/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	CRational CRational::operator-(const CRational & rationalNumber) const
	{
		long LCD = leastCommonDenominator(rationalNumber);
		long thisFactor = LCD / m_denominator;
		long thatFactor = LCD / rationalNumber.getDenominator();
		long thisNumerator = m_numerator * thisFactor;
		long thisDenominator = m_denominator * thisFactor;
		long numerator = thatFactor * rationalNumber.getNumerator();
		long denominator = thatFactor * rationalNumber.getDenominator();
		return CRational(thisNumerator - numerator, denominator);
	}

	// -----------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			CRational CRational::operator*
	//						(const CRational & rationalNumber) const
	//	Description:	Multiplication operator overload.
	//	Input:			None
	//	Output:			None
	//	Calls:			leastCommonDenominator(), getNumerator(),
	//						getDenominator(), default constructor
	//	Called by:		None
	//	Parameters:		const CRational & rationalNumber
	//						A constant reference to a CRational object.
	//	Returns:		A CRational object: the product of two CRationals
	//	History log:	2/23/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	CRational CRational::operator*(const CRational &rationalNumber) const
	{
		long thisNumerator = m_numerator;
		long thisDenominator = m_denominator;
		long numerator = rationalNumber.getNumerator();
		long denominator = rationalNumber.getDenominator();
		long GCFExtremes = greatestCommonFactor(thisNumerator, denominator);
		long GCFMeans = greatestCommonFactor(thisDenominator, numerator);
		thisNumerator /= GCFExtremes;
		thisDenominator /= GCFMeans;
		numerator /= GCFMeans;
		denominator /= GCFExtremes;
		numerator *= thisNumerator;
		denominator *= thisDenominator;
		//CRational product = { numerator, denominator };
		return CRational(numerator, denominator);
	}

	// -----------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			CRational CRational::operator/
	//						(const CRational & rationalNumber) const
	//	Description:	Division operator overload.
	//	Input:			None
	//	Output:			None
	//	Calls:			leastCommonDenominator(), getNumerator(),
	//						getDenominator(), default constructor
	//	Called by:		None
	//	Parameters:		const CRational & rationalNumber
	//						A constant reference to a CRational object.
	//	Returns:		A CRational object: the quotient of two CRationals
	//	History log:	2/23/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	CRational CRational::operator/(const CRational & rationalNumber) const
	{
		CRational quotient = ~rationalNumber;
		long thisNumerator = m_numerator;
		long thisDenominator = m_denominator;
		long numerator = quotient.getNumerator();
		long denominator = quotient.getDenominator();
		long GCFExtremes = greatestCommonFactor(thisNumerator, denominator);
		long GCFMeans = greatestCommonFactor(thisDenominator, numerator);
		thisNumerator /= GCFExtremes;
		thisDenominator /= GCFMeans;
		numerator /= GCFMeans;
		denominator /= GCFExtremes;
		numerator *= thisNumerator;
		denominator *= thisDenominator;
		//CRational product = { numerator, denominator };
		return CRational(numerator, denominator);
	}

	// -----------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			CRational CRational::toThePower(int exponent) const
	//	Description:	Exponentiation of rational numbers.
	//	Input:			None
	//	Output:			None
	//	Calls:			greatestCommonFactor(), default constructor
	//	Called by:		None
	//	Parameters:		int exponent
	//						The exponent.
	//	Returns:		A CRational object: the CRational raised to a power.
	//	History log:	2/23/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	CRational CRational::toThePower(int exponent) const
	{
		if (exponent == 0)
			return 1;
		else
		{
			long numerator = m_numerator;
			long denominator = m_denominator;
			long long newNumerator = numerator;
			long long newDenominator = denominator;
			long GCF = 0;
			for (int p = 1; p < abs(exponent); p++)
			{
				long GCFExtremes = greatestCommonFactor(numerator, newDenominator);
				long GCFMeans = greatestCommonFactor(denominator, newNumerator);
				numerator /= GCFExtremes;
				denominator /= GCFMeans;
				newNumerator /= GCFMeans;
				newDenominator /= GCFExtremes;
				newNumerator *= numerator;
				newDenominator *= denominator;
				GCF = greatestCommonFactor(newNumerator, newDenominator);
				newNumerator /= GCF;
				newDenominator /= GCF;
			}
			if (exponent > 0)
				return CRational((long)newNumerator, (long)newDenominator);
			else
			{
				return CRational((long)newDenominator, (long)newNumerator);
			}	
		}
	}

	// -----------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			CRational CRational::operator++()
	//	Description:	Prefix incrementer.
	//	Input:			None
	//	Output:			None
	//	Calls:			default constructor
	//	Called by:		None
	//	Parameters:		None
	//	Returns:		A CRational object: the CRational + 1.
	//	History log:	2/24/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	CRational CRational::operator++()
	{
		CRational addOne = { 1, 1 };
		*this += addOne;
		return *this;
	}

	// -----------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			CRational CRational::operator--()
	//	Description:	Prefix decrementer.
	//	Input:			None
	//	Output:			None
	//	Calls:			default constructor
	//	Called by:		None
	//	Parameters:		None
	//	Returns:		A CRational object: the CRational - 1.
	//	History log:	2/24/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	CRational CRational::operator--()
	{
		CRational subtractOne = { 1, 1 };
		*this -= subtractOne;
		return *this;
	}

	// -----------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			CRational CRational::operator++()
	//	Description:	Postfix incrementer.
	//	Input:			None
	//	Output:			None
	//	Calls:			default constructor
	//	Called by:		None
	//	Parameters:		An unused int.
	//	Returns:		A CRational object: this CRational before adding 1.
	//	History log:	2/24/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	CRational CRational::operator++(int)
	{
		CRational temp = *this;
		CRational addOne = { 1, 1 };
		*this += addOne;
		return temp;
	}

	// -----------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			CRational CRational::operator--()
	//	Description:	Postfix decrementer.
	//	Input:			None
	//	Output:			None
	//	Calls:			default constructor
	//	Called by:		None
	//	Parameters:		An unused int.
	//	Returns:		A CRational object: this CRational before subtracting
	//						1.
	//	History log:	2/24/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	CRational CRational::operator--(int)
	{
		CRational temp = *this;
		CRational subtractOne = { 1, 1 };
		*this -= subtractOne;
		return temp;
	}

	// -----------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			CRational CRational::operator~()
	//	Description:	Multiplicative inverse operator.
	//	Input:			None
	//	Output:			None
	//	Calls:			default constructor
	//	Called by:		None
	//	Parameters:		None.
	//	Returns:		A CRational object: the inverse of this CRational
	//						(e.g., 3/2 if 2/3).
	//	History log:	2/24/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	CRational CRational::operator~() const
	{
		long numerator = 0;
		long denominator = 0;
		numerator = this->m_denominator;
		denominator = this->m_numerator;
		CRational multInverse(numerator, denominator);
		return multInverse;
	}

	// -----------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			long CRational::compareTo
	//						(const CRational & rationalNumber) const
	//	Description:	Comparison method.
	//	Input:			None
	//	Output:			None
	//	Calls:			getNumerator(), getDenominator()
	//	Called by:		Overloaded operators ==, !=, <, <=, >, >=
	//	Parameters:		const CRational & rationalNumber, a constant reference
	//						to a CRational object.
	//	Returns:		A long integer.  If it's negative then this CRational
	//						object is less than the parameter.  If it's 0,
	//						they're identical.  If it's positive then this
	//						CRational object is greater than the parameter.
	//	History log:	2/25/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	long CRational::compareTo(const CRational & rationalNumber) const
	{
		long a = this->m_numerator;
		long b = this->m_denominator;
		long c = rationalNumber.getNumerator();
		long d = rationalNumber.getDenominator();
		long  extremes = a * d;
		long  means = b * c;
		//return log(extremes - means);
		//return static_cast<long>(log(extremes - means));
		return (extremes - means);
	}

	// -----------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			bool CRational::operator<
	//						(constCRational & rationalNumber) const
	//	Description:	Overloaded < operator.
	//	Input:			None
	//	Output:			None
	//	Calls:			compareTo()
	//	Called by:		None
	//	Parameters:		const CRational & rationalNumber, a constant reference
	//						to a CRational object.
	//	Returns:		A boolean that is true if this object is less than
	//						the parameter or false if not.
	//	History log:	2/25/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	bool CRational::operator<(const CRational & rationalNumber) const
	{
		long comparison = compareTo(rationalNumber);
		if (comparison < 0)
			return true;
		else
			return false;
	}

	// -----------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			bool CRational::operator>
	//						(constCRational & rationalNumber) const
	//	Description:	Overloaded > operator.
	//	Input:			None
	//	Output:			None
	//	Calls:			compareTo()
	//	Called by:		None
	//	Parameters:		const CRational & rationalNumber, a constant reference
	//						to a CRational object.
	//	Returns:		A boolean that is true if this object is greater than
	//						the parameter or false if not.
	//	History log:	2/25/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	bool CRational::operator>(const CRational & rationalNumber) const
	{
		long comparison = compareTo(rationalNumber);
		if (comparison > 0)
			return true;
		else
			return false;
	}

	// -----------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			bool CRational::operator<=
	//						(constCRational & rationalNumber) const
	//	Description:	Overloaded <= operator.
	//	Input:			None
	//	Output:			None
	//	Calls:			compareTo()
	//	Called by:		None
	//	Parameters:		const CRational & rationalNumber, a constant reference
	//						to a CRational object.
	//	Returns:		A boolean that is true if this object is less than
	//						or equal to the parameter, or false if not.
	//	History log:	2/25/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	bool CRational::operator<=(const CRational & rationalNumber) const
	{
		long comparison = compareTo(rationalNumber);
		if (comparison <= 0)
			return true;
		else
			return false;
	}

	// -----------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			bool CRational::operator>=
	//						(constCRational & rationalNumber) const
	//	Description:	Overloaded < operator.
	//	Input:			None
	//	Output:			None
	//	Calls:			compareTo()
	//	Called by:		None
	//	Parameters:		const CRational & rationalNumber, a constant reference
	//						to a CRational object.
	//	Returns:		A boolean that is true if this object is greater than
	//						or equal to the parameter, or false if not.
	//	History log:	2/25/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	bool CRational::operator>=(const CRational & rationalNumber) const
	{
		long comparison = compareTo(rationalNumber);
		if (comparison >= 0)
			return true;
		else
			return false;
	}

	//------------------------------------------------------------------------
	//  Class:          CRational
	//  Method:         CRational::operator string() const
	//	Description:	Overloaded string typecast operator.
	//	Input:			None
	//	Output:			This CRational object to a string stream.
	//	Calls:			None
	//	Called by:		None
	//	Parameters:		None
	//	Returns:		A string representation of this CRational object.
	//	History log:	2/26/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	CRational::operator string() const
	{
		string myFraction;
		stringstream sout;
		sout << *this;
		sout >> myFraction;
		return myFraction;
	}

	//------------------------------------------------------------------------
	//	Class:			CRational
	//	method:			void print(ostream & sout = cout)const;
	//	Description:	Overloaded string typecast operator.
	//	Input:			None
	//	Output:			This CRational object to an indicated output stream.
	//	Calls:			None
	//	Called by:		None
	//	Parameters:		sout (default cout), an output stream.
	//	Returns:		None.
	//	History log:	2/26/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	void CRational::print(ostream & sout = cout) const
	{
		sout << m_numerator;
		if (m_denominator > 1)
			sout << "/" << m_denominator;
	}

	//------------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			long greatestCommonFactor(const long number1,
	//						const long number2)
	//	Description:	A static method that finds the greatest common factor
	//						of two numbers.
	//	Input:			None
	//	Output:			None
	//	Calls:			greatestCommonFactor()
	//	Called by:		setProperForm(long numerator, long denominator),
	//						greatestCommonFactor(), leastCommonDenominator(),
	//						operator*(), operator/(), toThePower()
	//	Parameters:		None
	//	Returns:		The long integer that is the greatest common factor of
	//						the two numbers.
	//	History log:	2/24/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	long CRational::greatestCommonFactor(const long number1, const long number2)
	{
		if (number1 == 0 && number2 == 0)
			return 0;
		else if (number1 == 0)
			//return abs(number2);
			return number2;
		else if (number2 == 0)
			//return abs(number1);
			return number1;
		else
		{
			long absolute1 = abs(number1);
			long absolute2 = abs(number2);
			//long quotient = 0;
			long remainder = 0;
			if (absolute1 > absolute2)
			{
				//quotient = absolute1 / absolute2;
				remainder = absolute1 % absolute2;
				if (greatestCommonFactor(remainder, absolute2) == 0)
					return remainder;
			}
			else
			{
				//quotient = absolute2 / absolute1;
				remainder = absolute2 % absolute1;
				if (greatestCommonFactor(remainder, absolute1) == 0)
					return remainder;
			}
		}
	}

    //------------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			void CRational::setProperForm(long numerator,
	//						long denominator)
	//	Description:	Method that sets the proper form of a numerator and a
	//						denominator by finding their greatest common
	//						factor and properly handling negatives.
	//	Input:			None
	//	Output:			None
	//	Calls:			greatestCommonFactor()
	//	Called by:		The constructor
	//						CRational(long numerator, long denominator)
	//	Parameters:		long numerator and long denominator, two long
	//						integers.
	//	Returns:		None
	//	History log:	2/24/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	void CRational::setProperForm(long numerator, long denominator)
	{
		if (denominator == 0)
		{
			throw invalid_argument(ERROR_MESSAGE);
		}

		if (denominator < 0)
		{
			numerator *= -1; denominator *= -1;
		}
		if (numerator == 0)
		{
			m_numerator = 0;
			m_denominator = 1;
		}
		else
		{
			long GCF = greatestCommonFactor(numerator, denominator);
			m_numerator = numerator / GCF;
			m_denominator = denominator / GCF;
		}
	}

	//------------------------------------------------------------------------
	//	Class:			CRational
	//	Method:			void CRational::setProperForm(double decimal)
	//	Description:	Method that sets the proper form of a numerator and a
	//						denominator given a floating-point decimal input.
	//	Input:			None
	//	Output:			None
	//	Calls:			setProperForm(long numerator, long denominator)
	//	Called by:		The constructor CRational(double decimal)
	//	Parameters:		double decimal, a floating-point decimal number.
	//	Returns:		None
	//	History log:	2/24/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	void CRational::setProperForm(double decimal)
	{
		long numerator = 0;
		long denominator = 0;
		int multiplier = 10;
		short count = 0;
		// Separate the part >= 1 from the part that's 0 < decimal < 1.
		double overOnePart = floor(decimal);
		double decimalPart = decimal - overOnePart;
		if (decimalPart >= ROUND_ERROR_HIGH)
		{
			decimalPart += ROUND_ERROR_LOW -1;
			overOnePart += 1;
		}

		// Set up a loop to come to either a fraction or an estimated fraction
		while (decimalPart >= ROUND_ERROR_LOW && count <= MAX_PRECISION)
		{
			count += 1;
			decimal *= multiplier;
			overOnePart = floor(decimal);
			decimalPart = decimal - overOnePart;
			if (decimalPart >= ROUND_ERROR_HIGH)
			{
				decimalPart += ROUND_ERROR_LOW - 1;
				overOnePart += 1;
			}
		}
		multiplier *= pow(10, count - 1);
		numerator = overOnePart;
		denominator = multiplier;
		setProperForm(numerator, denominator);
	}

	//------------------------------------------------------------------------
    //  Class:          CRational
    //  Method:         long CRational::leastCommonDenominator
	//						(const CRational & rationalNumber)
	//	Description:	This private method finds the least common denominator
	//						of two rational numbers.
	//	Input:			None
	//	Output:			None
	//	Calls:			getNumerator(), getDenominator(),
	//						greatestCommonFactor()
	//	Called by:		Overloaded operators +, -, +=, -=
	//	Parameters:		const CRational & rationalNumber, a const reference
	//						to a CRational object.
	//	Returns:		a long; the least common denominator of the two
	//						fractions.
	//	History log:	2/24/16- DL completed version 1.0
	// -----------------------------------------------------------------------
	long CRational::leastCommonDenominator(const CRational & rationalNumber)
		const
	{
		long otherDenominator = rationalNumber.getDenominator();
		long GCF = greatestCommonFactor(m_denominator, otherDenominator);
		long quotient = m_denominator / GCF;
		return (quotient * otherDenominator);
	}

	// -----------------------------------------------------------------------
	//	method:         ostream& operator<<(ostream& sout,
	//						const CRational &rationalNumber)
	//	description:    prints out the c object to the stream
	//	Input:          None
	//	Output:         Screen display of complex number
	//	Calls:          None
	//	Called By:      n/a
	//	Parameters:     ostream & sout  -- the stream used for output
	//	                const CRational &rationalNumber -- the object to print
	//	Returns:        a reference to sout 
	//	History Log:
	//	                2/7/02  PB  completed version 1.0 for CComplex.
	//					2/16/16 DL incorporated function into the CRational
	//								class.
	//					2/26/16 DL competed version 1.0.
	// -----------------------------------------------------------------------
	ostream& operator<<(ostream& sout, const CRational &rationalNumber)
	{
		rationalNumber.print(sout);
		return sout;
	}

	// -----------------------------------------------------------------------
	//	function:        istream& operator>>(istream& sin, 
	//						CRational& rationalNumber)
	//	description:     inputs the rationalNumber object from the stream
	//	Input:           a rational number from the sin stream
	//	Output:          None
	//	Calls:           None
	//	Called By:       n/a 
	//	Parameters:      ostream & sin  -- the stream used for input
	//	                 CRational& rationalNumber -- the number to read into
	//	Returns:         a reference to sin 
	//	History Log:
	//	                 2/7/02   PB  completed version 1.0
	//	                 6/10/06  PB  completed version 1.01
	//					2/15/16		DL incorporated function into the
	//									CRational class.
	//					2/26/16		DL completed version 1.02, allowing
	//									complete compatibility with the
	//									CRational class.
	//------------------------------------------------------------------------
	istream& operator>>(istream& sin, CRational& rationalNumber)
	{
		long numerator = 0;
		long denominator = 0;
		double decimal = 0.0;
		char inputChar = ' ';
		string inputString;
		short signum = 1;
		unsigned index = 0;
		bool hasint = false;
		char test = ' ';

		// Check for whitespace.
		while (isspace(inputChar = sin.peek()) &&
			((inputChar = sin.peek()) != '\n'))
			sin.get();

		// Check for positive/negative.
		if ((test = sin.peek()) == '-')
		{
			signum = -1;
			sin.get();
		}
		else if (sin.peek() == '+')
		{
			signum = 1;
			sin.get();
		}

		// Is it a floating-point decimal with just a decimal input
		// (e.g., .5)?
		if ((test = sin.peek()) == '.')
		{
			sin >> decimal;
			decimal *= signum;
			test = sin.peek();
			rationalNumber = CRational(decimal);
			//sin.get();
			return sin;
		}
		// Get number and handle improper input
		if (!(sin >> numerator))
			return sin;

		// Ignore whitespace after first number and before the slash
		// (assuming there is a slash, that is):
		while (isspace(inputChar = sin.peek()) && inputChar != '\n')
			sin.get();

		// Check if there's a decimal (e.g., user inputs 3.2):
		if (inputChar == '.')
		{
			sin >> decimal;
			decimal += static_cast<double>(numerator);
			decimal *= signum;
			rationalNumber = CRational(decimal);
			//sin.get();
			return sin;
		}
		else if (inputChar == '\n' || isdigit(inputChar) || inputChar == '-'
			|| inputChar == '+')
		{
			numerator *= signum;
			rationalNumber = CRational(numerator, 1);
			return sin;
		}
		else if (inputChar == '/')
		{
			inputChar = sin.get();
			if (!(sin >> denominator))
			{
				return sin;
			}
			else
			{
				rationalNumber = CRational(signum * numerator, denominator);
				//sin.get();
			}
		}
		else sin.clear(ios::failbit);
		return sin;
	}
}