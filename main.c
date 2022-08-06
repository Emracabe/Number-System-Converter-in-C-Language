/*
	Author: EmRaCaBe 
	Copyright © December 2020
	Description:
		A C program which converts the following number systems:
			-Binary
			-Decimal
			-Octal
			-Hexadecimal
			
		C Language Concepts used:
			-Variables
			-Input/Output Statements
			-Control Flow Structure (Conditional and Loop Statements)
			-Strings and Arrays
			-Functions (Standard Library Functions and User-Defined Functions)
*/

// --------------------------------- START OF PROGRAM --------------------------------- //

// IMPORTING LIBRARIES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ------------ FUNCTION PROTOTYPING ------------- //

// Void Functions
void Binary();
void Decimal();
void Octal();
void Hexadecimal();


// ----Return Functions----

// Binary to Other Number System Converting Functions
int binaryOctal(long long bin);
int binaryDecimal(long long bin);

// Decimal to Other Number System Converting Functions
long long decimalBinary(int dec);
int decimalOctal(int dec);

// Octal to Other Number System Converting Functions
long long octalBinary(int oct);
int octalDecimal(int oct);


// Start of Menu Function
void menu()
{
	char again;
	
	printf("\n\n");
		
	printf(" Convert again? (Y/N)? ");
	scanf("%s", &again);
	
	switch(toupper(again))
	{
		case 'Y':
			main();
			break;
		
		case 'N':
			printf("\n Thank you for converting with us!");
			exit(0);
			break;
		
		default:
			printf("\n ERROR! INVALID INPUT!");
			printf("\n Exiting the program...");
			system("pause");
			exit(1);	
	}
	
	return;
}
// End of Menu Function


// START OF MAIN FUNCTION
int main()
{
	int order;
	
	system("clear");
	printf("\n");
	printf(" --- WELCOME TO NUMBER SYSTEM CONVERTER ---\n");
	
	printf("\n\t [1] = Binary");
	printf("\n\t [2] = Decimal");
	printf("\n\t [3] = Octal");
	printf("\n\t [4] = Hexadecimal");
	
	printf("\n\n Enter the CODE of NUMBER SYSTEM to be CONVERTED: ");
	scanf("%d", &order);
	
	// Start of Switch-Case Statement
	switch (order)
	{
		// If order is equals to 1 proceed to Binary Conversion Function
		case 1:
			system("clear");
			Binary();
			break;
		
		// If order is equals to 2 proceed to Decimal Conversion Function
		case 2:
			system("clear");
			Decimal();
			break;
		
		// If order is equals to 3 proceed to Octal Conversion Function
		case 3:
			system("clear");
			Octal();
			break;
		
		// If order is equals to 4 proceed to Hexadecimal Conversion Function	
		case 4:
			system("clear");
			Hexadecimal();
			break;
			
		// Else proceed to this case
		default:
			printf("\t ERROR! INVALID INPUT! \n");
			printf("\t Exiting the program...");
			system("pause");
			exit(1);
			break;
	}
	// End of Switch-Case Statement
	
	return 0;
}
// END OF MAIN FUNCTION


// -------------------- BINARY FUNCTIONS --------------------- //

// Start of Binary Number System Conversion
void Binary()
{
	int order;
	long long binary;
	int result;
	
	printf("\n");
	printf(" --- WELCOME TO BINARY NUMBER SYSTEM CONVERTER ---\n");
	
	printf("\n Enter the BINARY NUMBER to be CONVERTED: ");
	scanf("%lld", &binary);
	
	printf("\n\t [1] = Binary to Octal");
	printf("\n\t [2] = Binary to Decimal");
	printf("\n\t [3] = Binary to Hexadecimal");
	
	printf("\n\n Enter the code of conversion: ");
	scanf("%d", &order);
	
	// Start of Switch-Case Statement
	switch (order)
	{
		// IF ORDER is EQUALS to 1 proceed to this BINARY to OCTAL CONVERSION CASE
		case 1:
			result = binaryOctal(binary);
			printf("\n Result (Octal Number): %d", result);
			break;
		
		// IF ORDER is EQUALS to 2 proceed to this BINARY to DECIMAL CONVERSION CASE
		case 2:
			result = binaryDecimal(binary);
			printf("\n Result (Decimal Number): %d", result);
			break;
			
		// IF ORDER is EQUALS to 3 proceed to this BINARY to HEXADECIMAL CONVERSION CASE
		case 3:
			result = binaryDecimal(binary);
			printf("\n Result (Hexadecimal Number): %x", result);
			break;
			
		// ELSE proceed to this ERROR CASE
		default:
			printf("\n ERROR! INVALID INPUT!");
			printf("\n Exiting the program...");
			system("pause");
			exit(1);
			break;
	}
	// End of Switch-Case Statement
	
	menu();
	return;
}
// End of Binary Number System Conversion


// Start of Binary to Octal Conversion Function
int binaryOctal(long long bin)
{
	int oct = 0, rem, dec = 0;
	int i = 0;
	
	while (bin != 0)
	{
		rem = bin % 10;
		bin /= 10;
		dec += rem * pow(2, i);
		++i;
	}
	
	i = 0;
	rem = 0;
	
	while (dec != 0)
	{
		rem = dec % 8;
		dec /= 8;
		oct += rem * pow(10, i);
		++i;
	}
	
	return oct;
}
// End of Binary to Octal Conversion Function


// Start of Binary to Decimal Conversion Function
int binaryDecimal(long long bin)
{
	int rem, dec = 0;
	int i = 0;
	
	while (bin != 0)
	{
		rem = bin % 10;
		bin /= 10;
		dec += rem * pow(2, i);
		++i;
	}
	
	return dec;
}
// End of Binary to Decimal Conversion Function

// -------------------- BINARY FUNCTIONS --------------------- //



// -------------------- DECIMAL FUNCTIONS --------------------- //

// Start of Decimal Number System Conversion
void Decimal()
{
	int order;
	int decimal;
	long long res;
	int result;
	
	printf("\n");
	printf(" --- WELCOME TO DECIMAL NUMBER SYSTEM CONVERTER ---\n");
	
	printf("\n Enter the DECIMAL NUMBER to be CONVERTED: ");
	scanf("%d", &decimal);
	
	printf("\n\t [1] = Decimal to Binary");
	printf("\n\t [2] = Decimal to Octal");
	printf("\n\t [3] = Decimal to Hexadecimal");

	printf("\n\n Enter the code of conversion: ");
	scanf("%d", &order);
	
	// Start of Switch-Case Statement
	switch (order)
	{
		// IF ORDER is EQUALS to 1 proceed to this DECIMAL to BINARY CONVERSION CASE
		case 1:
			res = decimalBinary(decimal);
			printf("\n Result (Binary Number): %lld", res);
			break;
		
		// IF ORDER is EQUALS to 2 proceed to this DECIMAL to OCTAL CONVERSION CASE
		case 2:
			result = decimalOctal(decimal);
			printf("\n Result (Octal Number): %d", result);
			break;
		
		// IF ORDER is EQUALS to 3 proceed to this DECIMAL to HEXADECIMAL CONVERSION CASE
		case 3:
			printf("\n Result (Hexadecimal Number): %x", decimal);
			break;
			
		// ELSE proceed to this ERROR CASE
		default:
			printf("\n ERROR! INVALID INPUT!");
			printf("\n Exiting the program...");
			system("pause");
			exit(1);
			break;
	}
	// End of Switch-Case Statement
	
	menu();
	return;
}
// End of Decimal Number System Conversion


// Start of Decimal to Binary Conversion Function
long long decimalBinary(int dec)
{
	long long bin = 0;
	int i = 0, rem;
	
	while (dec != 0)
	{
		rem = dec % 2;
		dec /= 2;
		bin += rem * pow(10, i);
		++i;
	}
	
	return bin;
}
// End of Decimal to Binary Conversion Function


// Start of Decimal to Octal Conversion Function
int decimalOctal(int dec)
{
	int oct = 0, i = 0, rem;
	
	while (dec != 0)
	{
		rem = dec % 8;
		dec /= 8;
		oct += rem * pow(10, i);
		++i;
	}
	
	return oct;
}
// End of Decimal to Octal Conversion Function

// -------------------- DECIMAL FUNCTIONS --------------------- //



// -------------------- OCTAL FUNCTIONS --------------------- //

// Start of Octal Number System Conversion
void Octal()
{
	int order;
	int octal;
	int result;
	long long res;
	
	printf("\n");
	printf(" --- WELCOME TO OCTAL NUMBER SYSTEM CONVERTER ---\n");
	
	printf("\n Enter the OCTAL NUMBER to be CONVERTED: ");
	scanf("%d", &octal);
	
	printf("\n\t [1] = Octal to Binary");
	printf("\n\t [2] = Octal to Decimal");
	printf("\n\t [3] = Octal to Hexadecimal");

	printf("\n\n Enter the code of conversion: ");
	scanf("%d", &order);
	
	// Start of Switch-Case Statement
	switch (order)
	{
		// IF ORDER is EQUALS to 1 proceed to this OCTAL to BINARY CONVERSION CASE
		case 1:
			res = octalBinary(octal);
			printf("\n Result (Binary Number): %lld", res);
			break;
		
		// IF ORDER is EQUALS to 2 proceed to this OCTAL to DECIMAL CONVERSION CASE
		case 2:
			result = octalDecimal(octal);
			printf("\n Result (Decimal Number): %d", result);
			break;
			
		// IF ORDER is EQUALS to 3 proceed to this OCTAL to HEXADECIMAL CONVERSION CASE
		case 3:
			result = octalDecimal(octal);
			printf("\n Result (Hexadecimal Number): %x", result);
			break;	
			
		// ELSE proceed to this ERROR CASE
		default:
			printf("\n ERROR! INVALID INPUT!");
			printf("\n Exiting the program...");
			system("pause");
			exit(1);
			break;
	}
	// End of Switch-Case Statement
	
	menu();
	return;
}
// End of Octal Number System Conversion


// Start of Octal to Binary Conversion Function
long long octalBinary(int oct)
{
	long long bin = 0;
	int rem, dec = 0;
	int i = 0;
	
	while (oct != 0)
	{
		rem = oct % 10;
		oct /= 10;
		dec += rem * pow(8, i);
		++i;
	}
	
	i = 0;
	rem = 0;
	
	while (dec != 0)
	{
		rem = dec % 2;
		dec /= 2;
		bin += rem * pow(10, i);
		++i;
	}
	
	return bin;
}
// End of Octal to Binary Conversion Function


// Start of Octal to Decimal Conversion Function
int octalDecimal(int oct)
{
	int i = 0, dec = 0;
	int rem;
	
	while (oct != 0)
	{
		rem = oct % 10;
		oct /= 10;
		dec += rem * pow(8, i);
		++i;
	}
	
	return dec;
}
// End of Octal to Decimal Conversion Function

// -------------------- OCTAL FUNCTIONS --------------------- //



// -------------------- HEXADECIMAL FUNCTIONS --------------------- //

// Start of Hexadecimal Number System Conversion Functions
void Hexadecimal()
{
	int order, i = 0, rem, dec = 0, len;
	long long res;
	int result;
	char hex[17];
	
	printf("\n");
	printf(" --- WELCOME TO HEXADECIMAL NUMBER SYSTEM CONVERTER ---\n");
	
	printf("\n Enter the HEXADECIMAL NUMBER to be CONVERTED: ");
	scanf("%s", hex);
	
	printf("\n\t [1] = Hexadecimal to Binary");
	printf("\n\t [2] = Hexadecimal to Octal");
	printf("\n\t [3] = Hexadecimal to Decimal");

	printf("\n\n Enter the code of conversion: ");
	scanf("%d", &order);
	
	// Getting the Length of Entered Hexadecimal Number
	len = strlen(hex);
	len--;
	
	// Loop for Converting Hexadecimal to Decimal Number System
	for (i = 0; hex[i] != '\0'; i++)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			rem = hex[i] - 48;
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f')
		{
			rem = hex[i] - 97 + 10;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			rem = hex[i] - 65 + 10;	
		}
		
		dec += rem * pow(16, len);
		len--;
	}
	
	
	// Start of Switch-Case Statement
	switch (order)
	{
		// IF ORDER is EQUALS to 1 proceed to this HEXADECIMAL TO BINARY CONVERSION CASE
		case 1:
			res = decimalBinary(dec);
			printf("\n Result (Binary Number): %lld", res);
			break;
		
		// IF ORDER is EQUALS to 2 proceed to this HEXADECIMAL TO OCTAL CONVERSION CASE
		case 2:
			result = decimalOctal(dec);
			printf("\n Result (Octal Number): %d", result);
			break;
			
		// IF ORDER IS EQUALS to 3 proceed to this HEXADECIMAL to DECIMAL CONVERSION CASE	
		case 3:
			printf("\n Result (Decimal Number): %d", dec);
			break;	
			
		// ELSE proceed to ERROR CASE
		default:
			printf("\n ERROR! INVALID INPUT!");
			printf("\n Exiting the program...");
			system("pause");
			exit(1);
			break;
	}
	// End of Switch-Case Statement
	
	menu();
	return;
}
// End of Hexadecimal Number System Conversion Functions

// -------------------- HEXADECIMAL FUNCTIONS --------------------- //

// --------------------------------- END OF PROGRAM --------------------------------- //