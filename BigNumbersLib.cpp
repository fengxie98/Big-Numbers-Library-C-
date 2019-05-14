/*! \page page1 A documentation page
  \tableofcontents
  Leading text.
  \section sec An example section
  This page contains the subsections \ref subsection1 and \ref subsection2.
  For more info see page \ref page2.
  \subsection subsection1 The first subsection
  Text.
  \subsection subsection2 The second subsection
  More text.
*/
/*! \page page2 Another page
  Even more info.
*/	
#include "stdafx.h" 
#include "BigNumFuncsLib.h" 
#include <vector>
#include <iostream>
#include <stdexcept>

namespace BigNumFunctions
{
	BigNumber::BigNumber(std::vector<int>n) : number(n) {}
	BigNumber BigNumber::operator +(BigNumber b)
	{
		int bigN;
		if (number.size() >= b.number.size())
		{
			bigN = number.size();
		}

		else
		{
			bigN = b.number.size();
		}

		std::vector<int> nA(bigN, 0);
		std::vector<int> nB(bigN, 0);
		std::vector<int> nC(bigN, 0);

		for (int i = 0; i < number.size(); i++)
			nB[i] = (number[i]);

		for (int i = 0; i < b.number.size(); i++)
			nC[i] = (b.number[i]);

		std::reverse(nB.begin(), nB.end());
		std::reverse(nC.begin(), nC.end());
		int t = 0;

		for (int i = 0; i < bigN; i++)
		{
			int j;
			j = nB[i] + nC[i] + t;
			t = j / 10 % 10;
			nA[i] = j % 10;
		}
		if (t != 0)
			nA.push_back(t);

		std::reverse(nA.begin(), nA.end());
		return BigNumber(nA);
	}

	BigNumber BigNumber::operator -(BigNumber b)
	{
		std::vector<int> diff;
		std::vector<int> nA(size, 0);
		std::vector<int> nB(size, 0);
		int diffLength = number.size() - b.number.size();
		int t = 0;
		for (int i = b.number.size() - 1; i >= 0; i--)
		{
			int j;
			j = (number[i + diffLength] - 0) - (b.number[i] - 0) - t;
			if (j < 0)
			{
				j = j + 10;
				t = 1;
			}
			else
				t = 0;
			diff.push_back(j + 0);
		}

		for (int i = number.size() - b.number.size() - 1; i >= 0; i--)
		{
			if (number[i] == '0' && t)
			{
				diff.push_back('9');
				continue;
			}
			int sub = ((number[i] - '0') - t);
			if (i > 0 || sub > 0)
				diff.push_back(sub + '0');
			t = 0;
		}
		std::reverse(diff.begin(), diff.end());
		return BigNumber(diff);
	}

	BigNumber BigNumber::operator *(BigNumber b)
	{
		std::vector<int> nA(size, 0);
		std::vector<int> nB(b.number.size(), 0);
		for (int i = 0; i < number.size(); i++)
			nA[i] = (number[i]);
		for (int i = 0; i < b.number.size(); i++)
			nB[i] = (b.number[i]);
		int n1 = number.size();
		int n2 = b.number.size();

		if (n1 == 0 || n2 == 0)
			return b;
		std::vector<int> result(n1 + n2, 0);
		int i_n1 = 0;
		int i_n2 = 0;

		for (int i = n1 - 1; i >= 0; i--)
		{
			int carry = 0;
			int n1 = nA[i] - 0;
			i_n2 = 0;
			for (int j = n2 - 1; j >= 0; j--)
			{
				int n2 = nB[j] - 0;
				int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

				carry = sum / 10;

				result[i_n1 + i_n2] = sum % 10;
				i_n2++;
			}

			if (carry > 0)
				result[i_n1 + i_n2] += carry;
			i_n1++;
		}

		int i = result.size() - 1;
		while (i >= 0 && result[i] == 0)
			i--;
		std::reverse(result.begin(), result.end());
		BigNumber out(result);
		return out;
	}

	void BigNumber::print()
	{
		std::cout << "Vector elements are : ";

		for (int i = 0; i < number.size(); i++)
			std::cout << number.at(i) << ' ';
	}
}