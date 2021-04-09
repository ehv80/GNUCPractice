/* 
 * Date: Monday 5 of April of 2021
 * 
 * File: VanHackChallenge_v3_Save_by_columns.c 
 * 
 * Last Modification Date: Friday 09 of April of 2021
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
* Second We must parse from the begining to the end of the  char * csv_data	<-> 	while( csv_data[i] != '\0' ) 	0 <= index i of csv_data <= (strlen(csv_data) - 1) 
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

// It doesn't Work Fine!
//Global Extern variables
//int count_of_rows;
//int positions_of_delimiters_of_rows[count_of_rows];

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
	* because must use:    strlen(char)
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
* We must know how much total of 'columns' have the entire 'table' counting the amount of ',' character 
* until the end of array of character csv_data that is '\0'
* 
*/
int get_total_count_of_columns_on_entire_array( char * csv_data )
{
        int i = 0;

        int total_count_of_columns = 0;

        /* 
        * It doesn't work fine!
        * because must use:    strlen(char)
        *for( int i=0 ; i++ ; i < (sizeof(csv_data) - 1)) //without the '\0' ending standard character
	* 
	*
	*It doesn't work fine! because this return 0
	*for(int i = 0; i++; i <= (strlen(csv_data) - 1) ) //without the '\0' ending standard character
        *{
        *  if( csv_data[i] == ',' || csv_data[i] == '\n' )
        *  {
        *        total_count_of_columns++;
        *  }
        *}
        */

        // it works fine !
        while( csv_data[i] != '\0')   // until the end of array of character: char * csv_data  and without the '\0' ending standard character
        {
                if( csv_data[i] == ',' || csv_data[i] == '\n')
                {
                        total_count_of_columns++;
                }
                i++;
        }
	
        // This Array of Character that is the same that a pointer to character csv_data have:   total_count_of_columns  columns
        return total_count_of_columns;
}


/*
* Solicited Function:  method that sorts an array of character that is represented like a table 
* that must been ordered by the columns by the names of the columns alphabetically, and case-insensitive
* @return 	char * ordered_csv_data
*
*/
char * sort_csv_columns( char * csv_data )
{
	// Input is the parameter char * csv_data disordered
	// "Beth,Charles,Danielle,Adam,Eric\n17945,10091,10088,3907,10132\n2,12,13,48,11\n\0";
	
	// Initialization of variables
	// without the '\0' standard ending of a array of character that is the same to a pointer char *
	int i = 0; //  0   <=   index i   of csv_data       <=   ( strlen(csv_data) - 1)     
	int j = 0; //  0   <=   index j   for the columns   <=    count of 'columns' delimited by ','  on each 'row'
	int k = 0; //  0   <=   index k   for the rows      <=    count of 'rows'    delimited by '\n' on the entire char * csv_data 
	
	int rows    =  get_count_of_rows( csv_data );
	int columns_per_row =  get_count_of_columns_on_each_row( csv_data );
	int total_colums    =  get_total_count_of_columns_on_entire_array( csv_data );

	char csv_data_table[rows][columns_per_row];

	//int rows_positions_delimiters[rows];
	//int columns_positions_delimiters[columns];  //It doesn't work fine because there are more than this number 'columns' on the entire array of characters
	
	//while( csv_data[i] != '\0' )
	//{


	//}

	// Output is the same parameter char * csv_data but alphabetically and case insensitive ordered
	//  "Beth,Charles,Danielle,Adam,Eric\n17945,10091,10088,3907,10132\n2,12,13,48,11\n\0";
	//   0123456789 								 74 75	indexes
	//
	//  "Adam,Beth,Charles,Danielle,Eric\n3907,17945,10091,10088,10132\n48,2,12,13,11\n\0";
	

	// Make something more foolish
	//return qsort(csv_data); // It doesn't work fine!  failed: extern void qsort (void *__base, size_t __nmemb, size_t __size,
	// 
	//return strcmp(csv_data); // It doesn't work fine!  failed:  extern int strcmp (const char *__s1, const char *__s2)
	return csv_data; 
}

int main()
{
	char * csv_data = "Beth,Charles,Danielle,Adam,Eric\n17945,10091,10088,3907,10132\n2,12,13,48,11\n\0"; // char[] csv_data is the same

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
	// printf("\nThe delimiters that represent each end of a row is '/\n' characters scape sequence \n");
	// for (int i = 0; i <= count_of_rows; i++ )
	// {
	//  printf("\nThe 'row' number: %d  have the delimiter of your end in the position: %d into the entire array of character char * csv_data \n", i, the_positions_of_delimiters_of_rows[i] );
	// }

	//  It doesn't work fine ! because must use strlen(csv_data) 
	// for (int i = 0; i <= (sizeof(csv_data) - 1); i++ )
	// {
	//	printf("%s", csv_data[i]);
	// }
	
	// It works fine!
	int count_of_columns_on_each_row = get_count_of_columns_on_each_row(csv_data);
	printf("\nThe count of columns on each row that have this array of characters csv_data is: %d \n", count_of_columns_on_each_row );

	// It works fine!
        int total_columns = get_total_count_of_columns_on_entire_array(csv_data);
        printf("\nThe total count of columns on this entire array of characters csv_data is: %d \n", total_columns );

	return 0; // status oK
}
