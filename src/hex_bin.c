#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXBITS 64

int main(int argc, char *argv[]) {

/*
 * Brady Lange
 * 3/6/18
 * File name: hex_fourBits.c
 * This program coverts hexidecimal to binary and binary to hexidecimal
 */

	// Start i at 2 because you don't count 0 and x for hexidecimal numbers
	int i = 2;
	// Used for array
	int k = 0;
	// Extracts the size of the binary number
	int origLength = strlen(argv[1]);
	
	//Creating an array to store the input in so it is easier to access
	char input[MAXBITS];
	while(k != origLength)
	{
		input[k] = argv[1][k];
		k++;
	}
	
	// Loop that converts a hexidecimal number into a binary number
	while(input[i] != '\0' && input[0] == '0' && input[1] == 'x')
    {
        	switch(input[i])
        	{
       			case '0':
            			printf("0000"); 
						break;
       			case '1':
            			printf("0001"); 
						break;
        		case '2':
            			printf("0010"); 
						break;
        		case '3':
            			printf("0011"); 
						break;
        		case '4':
            			printf("0100"); 
						break;
        		case '5':
            			printf("0101"); 
						break;
        		case '6':
            			printf("0110"); 
						break;
        		case '7':
            			printf("0111"); 
						break;
        		case '8':
            			printf("1000"); 
						break;
        		case '9':
            			printf("1001"); 
						break;
        		case 'A':
            			printf("1010"); 
						break;
        		case 'B':
            			printf("1011"); 
						break;
        		case 'C':
            			printf("1100"); 
						break;
        		case 'D':
            			printf("1101"); 
						break;
        		case 'E':
            			printf("1110"); 
						break;
        		case 'F':
            			printf("1111"); 
						break;
        		case 'a':
            			printf("1010"); 
						break;
        		case 'b':
            			printf("1011"); 
						break;
        		case 'c':
            			printf("1100"); 
						break;
        		case 'd':
            			printf("1101"); 
						break;
        		case 'e':
            			printf("1110"); 
						break;
        		case 'f':
            			printf("1111"); 
						break;
        		default:
            			printf("Incorrect input. Must be a hexidecimal value: 0-9, a-f\n");
						return 1;
        	} 
		i++;
		printf(" ");
		if(input[i] == '\0')
			printf("\n");
	} // End of the while loop

	// Counters and flags
	int j = 0;
	int l = 0;

	// Counts the bits in the four bit max array
	int count = 0;
	// Array that stores only 4 bits so I can compare 4 at a time
	char fourBits[4]; 
	
	/*
	//Creating an array to store the input in so it is easier to access
	char input[MAXBITS];
	while(k != origLength)
	{
		input[k] = argv[1][k];
		k++;
	}
	*/

	// Loop that coverts binary numbers into hexdecimal digits 4 binary numbers at a time
	while((input[j] == '0' || input[j] == '1') && (input[0] != '0' || input[1] != 'x'))
	{
		// If the length meets any of these mod conditions the length will increase and the array shifted
		if(origLength % 4 == 1)
		{
			origLength = origLength + 3;
				
			for(l = origLength - 1; l >= 0; l--)
			{
				if(l > 2)
					input[l] = input[l - 3]; //input[7] == input[4]
				else
					input[l] = '0';
			}
		}
		else 
			if(origLength % 4 == 2)
			{
				origLength = origLength + 2;
		
				for(l = origLength - 1; l >= 0; l--)
				{
					if(l > 1)
						input[l] = input[l - 2]; //input[6] == input[4]
					else
						input[l] = '0';
				}

			}
			else
				if(origLength % 4 == 3)
				{
					origLength = origLength + 1;
		
					for(l = origLength - 1; l >= 0; l--)
					{
						if(l != 0)
							input[l] = input[l - 1]; //input[31] == input[30]
						else
							input[l] = '0';
					}
				}
			
		// Loop that grabs only 4 bits at a time
		while(count < 4 && input[j] != '\0')
		{
			fourBits[count] = input[j];
			j++;
			// Flag
			count++;
		}
		// Adding 0x to the hexidecimal number so represent what it is
		if(j == 4)
			printf("0x");
		// Printing out hexidecimal numbers for four bits of binarys
		if(fourBits[0] == '0' && fourBits[1] == '0' && fourBits[2] == '0' && fourBits[3] == '0')
				printf("0");
		else 
			if(fourBits[0] == '0' && fourBits[1] == '0' && fourBits[2] == '0' && fourBits[3] == '1')
				printf("1");
		else 
			if(fourBits[0] == '0' && fourBits[1] == '0' && fourBits[2] == '1' && fourBits[3] == '0')
				printf("2");
		else 
			if(fourBits[0] == '0' && fourBits[1] == '0' && fourBits[2] == '1' && fourBits[3] == '1')
				printf("3");
		else 
			if(fourBits[0] == '0' && fourBits[1] == '1' && fourBits[2] == '0' && fourBits[3] == '0')
				printf("4");
		else 
			if(fourBits[0] == '0' && fourBits[1] == '1' && fourBits[2] == '0' && fourBits[3] == '1')
				printf("5");
		else 
			if(fourBits[0] == '0' && fourBits[1] == '1' && fourBits[2] == '1' && fourBits[3] == '0')
				printf("6");
		else 
			if(fourBits[0] == '0' && fourBits[1] == '1' && fourBits[2] == '1' && fourBits[3] == '1')
				printf("7");
		else 
			if(fourBits[0] == '1' && fourBits[1] == '0' && fourBits[2] == '0' && fourBits[3] == '0')
				printf("8");
		else 
			if(fourBits[0] == '1' && fourBits[1] == '0' && fourBits[2] == '0' && fourBits[3] == '1')
				printf("9");
		else 
			if(fourBits[0] == '1' && fourBits[1] == '0' && fourBits[2] == '1' && fourBits[3] == '0')
				printf("a");
		else 
			if(fourBits[0] == '1' && fourBits[1] == '0' && fourBits[2] == '1' && fourBits[3] == '1')
				printf("b");
		else 
			if(fourBits[0] == '1' && fourBits[1] == '1' && fourBits[2] == '0' && fourBits[3] == '0')
				printf("c");
		else 
			if(fourBits[0] == '1' && fourBits[1] == '1' && fourBits[2] == '0' && fourBits[3] == '1')
				printf("d");
		else 
			if(fourBits[0] == '1' && fourBits[1] == '1' && fourBits[2] == '1' && fourBits[3] == '0')
				printf("e");
		else 
			if(fourBits[0] == '1' && fourBits[1] == '1' && fourBits[2] == '1' && fourBits[3] == '1')
				printf("f");
			else
			{
				printf("\nAn error has occured.");
				return 1;
			}
		
		// Adding this condition so that the printing looks neat
		if(j == origLength)
			printf("\n");
					
		// Setting count to 0 so that only 4 values will be stored in fourBits array
		count = 0;
		
		// Exit while loop if the length of the array has been reached
		if(j == origLength)
			break;
				
	}
	
	if(j == 0 && input[0] != 0 && input[1] != 'x')
	{
		printf("You may only enter binary numbers: 1 or 0.\nIf you want to enter a hexidecimal in you must start with 0x.\n");
		return 1;
	}
			
	return 0;
} //End of the main method
