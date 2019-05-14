/*!
 *  \brief     Header file of static library for BigNumbers
 *  \details   This header file contains the operators for the BigNumberLibrary
 *  \author    Feng Xie
 *  \version   1.0
 *  \date      May 14 2019
 *  \pre       First initialize the system.
 *  \bug       May or may not be linked to QT Calculator, the division operator and mod operator are not working due to no code for the specific operators in the linked header file. 
 *  \warning   This program will hopefully allow me to pass this course
 *  \copyright FengXie.LLC
 */

#pragma once
#include <vector>
#include <iostream>
namespace BigNumFunctions
{
	class BigNumber
	{
	public:
/*!var std::vector<int> number;
* \brief Pass in a integer into the vector*/
		std::vector<int> number;
		int size = number.size();

/*!fn BigNumber(std::vector<int>n);
* \brief Pass in an integer vector argument into the BigNumber function*/
		BigNumber(std::vector<int>n);

/*! \fn BigNumber operator +(BigNumber b);
*  \brief This is the operator overloading for the addition operator.\n
*	This operator will add the number you input in the vector values.
*/
		BigNumber operator +(BigNumber b);

/*! \fn BigNumber operator -(BigNumber b);
 *  \brief This is the operator overloading for the subtraction operator. \n
 *	This operator will subtract the number you input in the vector values.
 */
		BigNumber operator -(BigNumber b);

/*! \fn BigNumber operator *(BigNumber b);
 *  \brief This is the operator overloading for the multiplication operator. \n
 *	This operator will multiply the number you input in the vector values.
 */
		BigNumber operator *(BigNumber b);

/*! \fn BigNumber operator /(BigNumber b);
 *  \brief NOTE: NOT WORKING, This is the operator overloading for the division operator. \n
  *	This operator will divide the numbers you input in the vector values.
 */
		BigNumber operator /(BigNumber b);

/*! \fn BigNumber operator %(bigNumber b);
 *	\brief NOTE: NOT WORKING, This is the operator overloading for the mod operator. \n
  *	This operator will find the remainder of the numbers you input in the vector values.
 */
		BigNumber operator %(BigNumber b);

/*! \fn void print();
 *  \brief This will print the value
 */
		void print();
	};
}