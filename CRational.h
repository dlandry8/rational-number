//-----------------------------------------------------------------------------
//	File:           CRational.h
//
//	class:		CRational
//-----------------------------------------------------------------------------
#ifndef DL_CRATIONAL_H
#define DL_CRATIONAL_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <exception>
#include <stdexcept>
using namespace std;

namespace DL_RATIONAL
{
	//------------------------------------------------------------------------
	//	Title:          Rational Number Class
	//
	//	Description:    This file contains the class definition for CRational
	//
	//	Programmer:     David Landry
	//					Using starting code by Paul Bladek
	//   
	//	Date:           2/29/2016
	// 
	//	Version:		1.0
	//   
	//	Environment:	PC 
	//					Software:   MS Windows 10
	//					Compiles under Microsoft Visual C++ Community 2013
	//
	//	class CRational:
	//
	//	Properties:
	//					long m_numerator
	//						the numerator of the fraction
	//					long m_denominator
	//						the denominator of the fraction
	//
	//	Methods:
	//	
	//		inline:	
	//			CRational(long numerator = 0, long denominator = 0)
	//				Default constructor
	//				Intializes m_numerator and m_denominator
	//				Parameters:	
	//					long numerator: the numerator
	//					long denominator: the denominator
	//
	//			CRational(int numerator) -- constructor
	//				Initializes m_numerator and m_denominator if the user
	//					enters an integer.
    //              Parameters:
    //                  int numerator: a number that becomes the numerator.
	//
	//			CRational(double decimal)
	//				Initializes m_numerator and m_denominator based on the
	//					input of a floating-point number
    //              Parameters:
    //                  double decimal: a floating-point number to be
    //                      converted to a fraction (or a fractional estimate)
    //
	//			long getNumerator()const
	//				Accessor for the numerator.
	//				Returns:	m_numerator
	//				
	//			long getDenominator()const
	//				Accessor for the denominator.
	//				Returns:	m_denominator
	//
	//			CRational operator+=(const CRational & rationalNumber)
	//				Addition with assignment
	//				Parameter:	const CRational & rationalNumber:
	//					The fraction to add to the current fraction.
	//				Returns:	this*, the new fraction after addition.
	//
	//			CRational operator-=(const CRational & rationalNumber)
	//				subtraction with assignment
	//				Parameter:	const CRational & rationalNumber
	//					The fraction to subtract from the current fraction.
	//				Returns:	this*, the new fraction after subtraction.
	//
	//			CRational operator*=(const CRational & rationalNumber)
	//				multiplication with assignment
	//				Parameter:	const CRational & rationalNumber
	//					The fraction to multiply to the current fraction.
	//				Returns:	this*, the new fraction after multiplication.
	//
	//			CRational operator/=(const CRational & rationalNumber)
	//				division with assignment
	//				Parameter:	const CRational & rationalNumber
	//					The fraction to divide with the current fraction.
	//				Returns:	this*, the new fraction after division.
	//
	//			CRational operator-() const;
	//				unary negative; given a / b, (-a / b) + (a / b) should
	//					equal 0, or 0/1.
	//				Returns:	A CRational object with its numerator negated.
	//
	//			CRational operator+() const;
	//				Unary +.  Returns *this.
	//
	//			bool operator!=(const CRational &rationalNumber) const
	//				Parameters:
	//					const CRational &rationalNumber
	//					a const reference to the compared	
	//				Returns: true if the two are not the same
	//
	//			bool operator==(const CRational & rationalNumber) const 
	//				Parameters:	const CRational &rationalNumber 
	//					a const reference to the compared	
	//				Returns: true if the two are the same
	//
	//			bool operator!() const
	//				Returns: true if 0/1.
	//
	//			operator bool() const
	//				Returns: true if not 0/1.
	//
	//			operator double() const
	//				Returns: the fraction in floating-point decimal form.
    //
    //          void setProperForm(int numerator)
    //              Sets the proper form of the fraction if the user enters
    //                  in an integer.
    //              Parameters: int numerator: an integer to be converted to
    //                  rational form (i.e., numerator/1).
	//
	//		non-inline:
	//			CRational operator+(const CRational &rationalNumber)const;
	//				addition
	//			CRational operator-(const CRational & rationalNumber)const;
	//				subtraction
	//			CRational operator*(const CRational & rationalNumber)const;
	//				multiplication
	//			CRational operator/(const CRational & rationalNumber)const;
	//				division
	//			CRational toThePower(int exponent) const
	//				Exponentiation using an integer exponent.
	//			CRational toThePower(int exponent) const;
	//				Raises the fraction to a given exponent, returning a
	//					CRational object.
	//			CRational operator++();
	//				pre-increment; increments by 1
	//					(given a/b, increments by b/b)
	//			CRational operator--();
	//				pre-decrement; decrements by 1
	//					(given a/b, decrements by b/b)
	//			CRational operator++(int);
	//				post-increment; increments by 1
	//				(the int is not used)
	//			CRational operator--(int);
	//				post-decrement;decrements by 1
	//				(the int is not used)
	//			CRational operator~() const
	//				Multiplicative inverse.
	//			long compareTo(const CRational & rationalNumber) const
	//				Compares current rational object to another rational
	//					object.  Returns < 0 if it's less than the other
	//					object, 0 if the two are identical, & > 0 if it's
	//					greater than.
	//			bool operator<(const CRational & rationalNumber) const
	//				Returns true if this is less than another CRational
	//			bool operator>(const CRational & rationalNumber) const
	//				Returns true if this is greater than another CRational
	//			bool operator<=(const CRational & rationalNumber) const
	//				Returns true if this is less than or equal to another 
	//				CRational
	//			bool operator>=(const CRational & rationalNumber) const
	//				Returns true if this is greater than or equal to another
	//				CRational
	//			operator string() const -- cast to string
	//				Returns: a rational number as a string
	//			void print(ostream & sout = cout) const;
    //			static long greatestCommonFactor(const long number1, const
    //              long number2)
    //				Finds the greatest common factor of two numbers.
	//			void setProperForm(long numerator, long denominator);
	//				Private function that sets the fraction to proper form
    //              using the greatestCommonFactor method.
	//			void setProperForm(double decimal)
	//				Private function that sets the fraction to proper form by
	//				converting a floating-point decimal to fractional form.
	//			long leastCommonDenominator (const CRational & comlexNumber) const
	//				Private function that returns the least common denominator
	//				of two fractions.
	//
	//    History Log:
	//		For CComplex:
	//			4/25/02  PB  completed version 1.0
	//			5/19/05  PB  modified  version 1.01
	//			2/8/12   PB  modified  version 1.02
	//		For CRational:
	//			2/18/16	DL completed version 0.2
    //          2/23/16 DL completed version 0.3, organizing the code to make
    //                                               it easier to work with.
	//			2/29/16 DL completed version 1.0
	//------------------------------------------------------------------------
	class CRational
	{
	public:
		// Constructors:
		CRational(long numerator = 0, long denominator = 1)
		{
			setProperForm(numerator, denominator);
		}
		CRational(int numerator) { setProperForm(numerator); }
		CRational(double decimal) { setProperForm(decimal); }

		// Accessors:
		long getNumerator() const { return m_numerator; }
		long getDenominator()const { return m_denominator; }

		// Operators:
		CRational operator+(const CRational &rationalNumber) const;
		CRational operator-(const CRational & rationalNumber) const;
		CRational operator/(const CRational & rationalNumber) const;
		CRational operator*(const CRational & rationalNumber) const;

		CRational operator+=(const CRational & rationalNumber)
		{
			return (*this = *this + rationalNumber);
		}
		CRational operator-=(const CRational & rationalNumber)
		{
			return (*this = *this - rationalNumber);
		}
		CRational operator*=(const CRational & rationalNumber)
		{
			return (*this = *this * rationalNumber);
		}
		CRational operator/=(const CRational & rationalNumber)
		{
			return (*this = *this / rationalNumber);
		}
		CRational toThePower(int exponent) const;
		CRational operator++();			// pre-increment
		CRational operator--();			// pre-decrement
		CRational operator++(int);		// post-increment
		CRational operator--(int);		// post-decrement
		CRational operator-() const		// unary negative
		{
			return CRational(-m_numerator, m_denominator);
		}
		CRational operator+() const { return *this; }	// unary plus
		CRational operator~() const;					// inverse
		long compareTo(const CRational & rationalNumber) const;
		// compareTo returns < 0 if this rationalNumber is less than the
		// rational number passed in; 0 if the two rationalNumbers are equal;
		// and > 0 if this rationalNumber is greater than the rational number
		// passed in.  It is used in each of the below relational operators.
		bool operator<(const CRational & rationalNumber) const;
		bool operator>(const CRational & rationalNumber) const;
		bool operator<=(const CRational & rationalNumber) const;
		bool operator>=(const CRational & rationalNumber) const;
		bool operator!=(const CRational & rationalNumber) const
		{
			return (m_numerator != rationalNumber.m_numerator
				|| m_denominator != rationalNumber.m_denominator);
		}
		bool operator==(const CRational & rationalNumber) const
		{
			return (m_numerator == rationalNumber.m_numerator
				&& m_denominator == rationalNumber.m_denominator);
		}
		bool operator!() const
		{
			return m_numerator == 0 && m_denominator == 1;
		}
		operator bool() const
		{
			return m_numerator != 0;
		}
		operator double() const
		{
			return static_cast<double>
            ((double)this->m_numerator / (double)this->m_denominator);
		}
		operator string() const;
		void print(ostream & sout) const;
		static long greatestCommonFactor
			(const long number1, const long number2);
	private:
		// properties
		long m_numerator;
		long m_denominator;
		// I've included some static properties, all of which relate to
		// converting from double to CRational.  Sometimes, when working with
		// floating-point numbers, rounding errors can occur
		// (e.g., user enters 0.2, the compiler translates it as
		// 0.199999999999 or 0.200000000001).  These static constants have
		// been included to correct this.
		static const char ERROR_MESSAGE[45];
		static const double ROUND_ERROR_HIGH;
		static const double ROUND_ERROR_LOW;
		static const short MAX_PRECISION;

		// methods
		void setProperForm(long numerator, long denominator);
		void setProperForm(int numerator)
		{
			m_numerator = numerator; m_denominator = 1;
		}
		void setProperForm(double decimal);
		long leastCommonDenominator(const CRational & rationalNumber) const;
	};

	// related function prototypes
	ostream& operator<<(ostream& sout, const CRational &rationalNumber);
	istream& operator>>(istream& sin, CRational& rationalNumber);
}

#endif