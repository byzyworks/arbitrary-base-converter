#include <iostream>

using namespace std;

void ProgramCode()
{
	long number;
	short base;
	long number_calc;
	long base_calc;
	unsigned short digit_orders;
	cout << "This program converts a base-10 number into any allowable positive integer base." << endl;
	cout << endl;
	// The end user is prompted for the number and the base they want to convert it to.
	cout << "Enter a base." << endl;
	cout << endl;
	cin >> base;
	cout << endl;
	while (base < 1)
	{
		cout << "INVALID INPUT:" << endl;
		cout << "You cannot use 0 or a negative number as a base.  Try a different number." << endl;
		cout << endl;
		cout << "Enter a base." << endl;
		cout << endl;
		cin >> base;
		cout << endl;
	}
	cout << "Enter a base-10 number to be converted to that base." << endl;
	cout << endl;
	cin >> number;
	cout << endl;
	if (base == 1)
	{
		// Since base 1, aka. the unary number system is not logarithmic as are higher bases, it is handled rather simply.
		cout << "The base 10 number " << number << " looks like ";
		for (long i = 0; i < number; i++)
		{
			cout << '1';
		}
	}
	else
	{
		number_calc = number;
		base_calc = base;
		digit_orders = 1;
		/* Step 1 of converting a logarithmic number system like base 10 into another logarithmic number system involves determining the highest
		 * order of digits that your number will use once it is converted. */
		while (base_calc <= number)
		{
			base_calc *= base;
			digit_orders++;
		}
		/* In step 2, we create a dynamic array to hold the values of each digit, and then determine the values of each digit one-by-one
		 * accounting for all the base's possible values for single digits. */
		unsigned short* digit_count = new unsigned short[digit_orders];
		for (short i = digit_orders - 1; i >= 0; i--) // If the condition ever allows the (decrementing) control variable to equal 0, make sure the control variable is not unsigned.
		{
			base_calc /= base;
			digit_count[i] = number_calc / base_calc;
			number_calc -= (digit_count[i] * base_calc);
		}
		/* Finally, step 3 gives us our visual representation of the number in its converted form with digits larger than 9 enclosed by braces.
		 * Each digit's value is, likewise, represented in decimal form, so single digits in bases larger than base 10 may hold values that must
		 * be represented as multiple digits in base 10, meaning the separation is needed for such large digits to be identified individually. */
		cout << "The base 10 number " << number << " looks like ";
		for (short i = digit_orders - 1; i >= 0; i--)
		{
			if (digit_count[i] < 10)
			{
				cout << digit_count[i];
			}
			else
			{
				cout << '{' << digit_count[i] << '}';
			}
		}
		delete[] digit_count;
	}
	cout << " in base " << base << '.' << endl;
	cout << endl;
}

int main()
{
	char retry;
	do
	{
		ProgramCode();
		cout << "Enter Y to retry the program or N to exit the program." << endl;
		cout << endl;
		cin >> retry;
		cout << endl;
		while (retry != 'Y' && retry != 'N')
		{
			cout << "INVALID INPUT:" << endl;
			cout << "To retry the program, input must be the case-sensitive letter \"Y\"." << endl;
			cout << "To exit the program, input must be the case-sensitive letter \"N\"." << endl;
			cout << endl;
			cout << "Enter Y to retry the program or N to exit the program." << endl;
			cout << endl;
			cin >> retry;
			cout << endl;
		}
	} while (retry == 'Y');
	return 0;
}