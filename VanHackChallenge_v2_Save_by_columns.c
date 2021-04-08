/* 
 * Date: Monday 5 of April of 2021
 * 
 * File: VanHackChallenge_v2_Save_by_columns.c 
 * 
 * Last Modification Date: Martes 06 of April of 2021
 * @Autor: Ezequiel Hernán Villanueva
 */

/*
* Here we have one Example
*
* char * csv_data = "Beth,Charles,Danielle,Adam,Eric\n17945,10091,10088,3907,10132\n2,12,13,48,11\n\0"		<-> char csv_data[i]
*		     012 ... 									   75
*		    [       header                 ] [    row1                   ] [ row2        ] ... rown
* 
* That is represented like a table on this way:
*
* 0	1	2	 3	4	Indexes of Columns
*
* Beth	Charles	Danielle Adam	Eric					0 Indexes 
* 17945	10091	10088	 3907	10132					1 of
* 2	12    	13	 48	11					2 Rows
*
*
* And We Must obtain the same array of character but sorted by the names of the columns alphabetically, and case-insensitive 	<-> char csv_data[i]
* 
* char * csv_ordered = "Adam,Beth,Charles,Danielle,Eric\n3907,17945,10091,10088,10132\n48,2,12,13,11\n\0";
*
* That is represented like a table alphabetically ordered by the name of the columns on this way:
* 
*
* 0     1       2        3      4       Indexes of Columns
*
* Adam	Beth	Charles	Danielle Eric					0 Indexes
* 3907	17945	10091	10088	10132					1 of
* 48	2	12	13	11					2 Rows
*
*
* An Algorithm to trie to resolv the problem:
* -------------------------------------------
* First We must know:
*
* 	how much 'rows' have the 'table' counting the amount of '\n' scape character sequence that have the:  char * csv_data 	
* 	[ 0, 1, 2, ... index of rows ... n ]
*
* 	how much 'columns' have each 'row' of the 'table' counting ',' characters that have the: char * csv_data  between each '\n' scape character sequence 
* 	[ 0, 1, 2, ... index of columns ... n ]
*
* Second We must parse from the begining to the end of the  char * csv_data	<-> 	while( csv_data[i] != '\0' ) 	0 <= index i of csv_data <= (sizeof(csv_data) - 1) 
* every column's valúe  							<->	another index j for the columns delimiters 	','
* of every row									<->	another index k for the rows delimiters 	'\n'
* so we can save into an array of array of characters in a way of a table	<->	char csv_data_table[k rows][j columns]
*
* Third we must sort alphabetically the 'header' of the 'table'				char * aux_value for doing the interchange for the alphabetical order
* This is 	csv_data_table[k=0 row][j columns]	
* For make this order we need								char * aux_value   for doing the temporal interchange for the alphabetical order
*
* 											int aux_new_row_order_like_header[j columns] 
* 											here save the old position of each value that is reordered on the header [k=0 row]
* 											so we can reuse this k rows indexes for the every each of another rows
* 											
* 											The C Language Function to make the order this can be strcmp or qsort
*/

// Inclusion of the Standard C Libraries needed
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Definition of Constants Values
// 512 characters for the temporal aux_value
#define	VALUE_BUF_SIZE	512
#define	MAX_ARRAY_SIZE	1024

// Global Extern variables
int count_of_rows;
int positions_of_delimiters_of_rows[count_of_rows];

/*
* We must know how much rows have the table counting the amount of '\n' scape character sequence
* that have the: char * csv_data
*/
int get_count_of_rows( char * csv_data )
{
	int i = 0;
	int count_of_rows = 0;
	
	/* 
	* It doesn't work fine
	*for( int i=0 ; i++ ; i < (sizeof(csv_data) - 1)) //without the '\0' ending standard character
	*{
	*  if( csv_data[i] == '\n' )
	*  {
	*        count_of_rows++;
	*  }
	*}
	*/

	// it works fine !
	while(csv_data[i] != '\0')
	{
		if( csv_data[i] == '\n')
		{
			count_of_rows++;
		}
		i++;

	}
	// This Array of Character that is the same that a pointer to character csv_data have:   count_of_rows  rows
	return count_of_rows;
}

/*
* We must know how much 'columns' have each 'row' that have the 'table' counting the amount of ','character 
* until the firs appareance of the first delimiter of end of a 'row' that is '\n'
* that have the: char * csv_data
*/
int get_count_of_columns_on_each_row( char * csv_data )
{
        int i = 0;
        //int count_of_rows = 0;
	int count_of_columns_on_each_row = 0;

        /* 
        * It doesn't work fine
        *for( int i=0 ; i++ ; i < (sizeof(csv_data) - 1)) //without the '\0' ending standard character
        *{
        *  if( csv_data[i] == '\n' )
        *  {
        *        count_of_rows++;
        *  }
        *}
        */

        // it works fine !
        //while(csv_data[i] != '\0')   // Not until the end of array of character: char * csv_data
	while( csv_data[i]  != '\n'  ) // Until the end of first row 
        {
                if( csv_data[i] == ',')
                {
                        count_of_columns_on_each_row++;
                }
                i++;
        }
	// When the while bucle end is because there are a '\n' so we must increment the count of columns on each row one more time
	count_of_columns_on_each_row++;
        // This Array of Character that is the same that a pointer to character csv_data have:   count_of_rows  rows
        return count_of_columns_on_each_row;
}

/*
* We must obtain the positions of the indexes of the delimiters '\n' that contain the array of character char * csv_data
* that correspond to each 'row' of the 'table' 
* @return int[] 	that represent first element of the array of integers
*
*  It doesn't work fine !
*
*/
//int[] get_array_of_positions_of_delimiters_of_rows ( char * csv_data, int count_of_rows )
int * get_array_of_positions_of_delimiters_of_rows ( char * csv_data, int count_of_rows )
{
	// array of integers that contain the positions of delimiters of rows that is '\n' 

	// it doesn't work fine !
	// can't return address memory of local variable so must defined like a global extern variable
	extern int positions_of_delimiters_of_rows[count_of_rows];
	int i = 0; // index for the array of charactes	 char * csv_data
	int j = 0; // index for the array of integers	positions_of_delimiters_of_rows

	/*
	*for( int i=0 ; i++; i < (sizeof(csv_data) - 1))
	*{
	*	if( csv_data[i] == '\n' && csv_data[i] != '\0')
	*}
	*/	

	while(csv_data[i] != '\0')
        {
                if( csv_data[i] == '\n')
                {
                        positions_of_delimiters_of_rows[j] = i;
			j++;
                }
                i++;

        }
	// The array are passed by reference on C because is not convenient pass by value, is not convenient copy all entire elements of a array
	return positions_of_delimiters_of_rows;
}


/*
* Solicited Function
*char * sort_csv_columns( char* csv_data )
*{
*	//Initialization of variables
*	// this is the solicited result the array of character alphabetically ordered by columns and case insensitive
*	//char * sorted_csv_data = memalloc (sizeof(csv_data)); // verify if it is ok
*	int i = 0; // 0 <= index i of csv_data     <= ( sizeof(csv_data) - 1)   without the '\0' standard ending of a array of character that is the same char *  
*	int j = 0; // 0 <= index j for the columns <=  count of 'columns' delimited by ','  on each 'row'
*	int k = 0; // 0 <= index k for the rows    <=  count of 'rows'    delimited by '\n' on the entire char * csv_data 
*	int columns = 0; //  
*	int rows = 0;    //
*	//char * aux_value = memalloc(VALUE_BUF_SIZE); // verify if it is ok
*
*	//for(int i = 0; i <= sizeof(csv_data) - 1 && csv_data[i] != '\0'; i++)
*	//{
*	//	if(csv_data[i] != ',' && csv_data[i] != '\n')
*	//	{
*			// In One Only parse cant resolve this.
*	//	}
*
*	//}
*
*	// array of integer that save the old position of each value that is reordered on the header [k=0 row]
*	// so we can reuse this k rows indexes for the every each of another rows
*	//int aux_new_row_order_like_header[columns]; 
*
*	// array of array of character to save each value on the same way like a table
*	//char csv_data_table[rows][columns];
*	
*	//return &sorted_csv_data;
*	return sorted_csv_data;
*}
*
*/

int main()
{
	char * csv_data = "Beth,Charles,Danielle,Adam,Eric\n17945,10091,10088,3907,10132\n2,12,13,48,11\n\0";

	printf("\nThe Array of Character, that is the equal to an pointer to a character string, named csv_data have this disordered elements\n");
	
	printf("%s", csv_data);

	// The count of rows that have this array of characters csv_data
	int count_of_rows = get_count_of_rows(csv_data);
	printf("\nThe count of rows that have this array of characters csv_data is: %d \n", count_of_rows );
	
	// An array of integers that contain the positions of delimiters of each 'row' that is '\n' character scape sequence
	// It doesn't work fine !
	// int the_positions_of_delimiters_of_rows[count_of_rows] = get_array_of_positions_of_delimiters_of_rows(csv_data, count_of_rows);
	
	// A pointer to integer that contain the positions of delimiters of each 'row' that is '\n' character scape sequence
	// It doesn't work fine !
	//int * the_positions_of_delimiters_of_rows = get_array_of_positions_of_delimiters_of_rows(csv_data, count_of_rows);
	
	// It doesn't work fine !
	//printf("\nThe delimiters that represent each end of a row is '/\n' characters scape sequence \n");
	//for (int i = 0; i <= count_of_rows; i++ )
	//{
	//  printf("\nThe 'row' number: %d  have the delimiter of your end in the position: %d into the entire array of character char * csv_data \n", i, the_positions_of_delimiters_of_rows[i] );
	//}

	//  It doesn't work fine !
	//for (int i = 0; i <= (sizeof(csv_data) - 1); i++ )
	//{
	//	printf("%s", csv_data[i]);
	//}
	
	// It works fine
	int count_of_columns_on_each_row = get_count_of_columns_on_each_row(csv_data);
	printf("\nThe count of columns on each row that have this array of characters csv_data is: %d \n", count_of_columns_on_each_row );

	return 0; // status oK
}
