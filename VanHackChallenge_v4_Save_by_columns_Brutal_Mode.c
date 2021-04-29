/* 
 * Date: Monday 5 of April of 2021
 * 
 * File: VanHackChallenge_v4_Save_by_columns_Brutal_Mode.c 
 * 
 * Last Modification 
 * @Date: Thursday 29 of April of 2021
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
* Second We must parse from the begining to the end of the  char * csv_data		<-> 	while( csv_data[i] != '\0' ) 	0 <= index i of csv_data <= (strlen(csv_data) - 1) 
* every column's valúe  								<->	another index j for the columns delimiters 	','
* of every row										<->	another index k for the rows delimiters 	'\n'
* so we can save into an array of array of pointer to characters in a way of a table	<->	char * csv_data_table[k rows][j columns]
*
* Third we must sort alphabetically the 'header' of the 'table'				char * aux_value for doing the interchange for the alphabetical order
* This is char * csv_data_table[k=0 row][j columns]	
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

	int rows             =  get_count_of_rows( csv_data );
	int columns_per_row  =  get_count_of_columns_on_each_row( csv_data );
	int total_columns    =  get_total_count_of_columns_on_entire_array( csv_data );


	char nl_delimiter = '\n'; 
	//char * nl_delimiter = "\n";

	char comma_delimiter = ','; 
	//char * comma_delimiter = ",";
	
	// It doesn't work fine!
	//char aux_every_column_value[VALUE_BUF_SIZE] = "x\0";
	//char aux_every_column_value[VALUE_BUF_SIZE] = "\0";
	
	// Brutal Mode
	// Initialization of variables 
	// "Beth,Charles,Danielle,Adam,Eric\n17945,10091,10088,3907,10132\n2,12,13,48,11\n\0";
	char * aux_every_column_value[total_columns];
	aux_every_column_value[0]  = "Beth\0";		// 1º
	aux_every_column_value[1]  = "Charles\0";	// 2º
	aux_every_column_value[2]  = "Danielle\0";	// 3º
	aux_every_column_value[3]  = "Adam\0";		// 0º
	aux_every_column_value[4]  = "Eric\n\0";	// 4º

	aux_every_column_value[5]  = "17945\0";		// 6º
	aux_every_column_value[6]  = "10091\0";  	// 7º
	aux_every_column_value[7]  = "10088\0";		// 8º
	aux_every_column_value[8]  = "3907\0";		// 5º
	aux_every_column_value[9]  = "10132\n\0";	// 9º

	aux_every_column_value[10] = "2\0";		// 11º
	aux_every_column_value[11] = "12\0";		// 12º
	aux_every_column_value[12] = "13\0";		// 13º
	aux_every_column_value[13] = "48\0";		// 10º
	aux_every_column_value[14] = "11\0";		// 14º

	printf("\nThe Brutal Mode Algorithm Implementation:\n");
	printf("\nThe csv_data array of character disordered have this values: \n");
	for( int x = 0; x < total_columns ; x++ )
	{
		printf(" \t  %s ", aux_every_column_value[x] );
	}	
	printf("\n");

	printf("\nThe csv_data array of character alphabetically case insensitive ordered have this values: \n");
	printf(" \t  %s ", aux_every_column_value[3] );
	printf(" \t  %s ", aux_every_column_value[0] );
	printf(" \t  %s ", aux_every_column_value[1] );
	printf(" \t  %s ", aux_every_column_value[2] );
	printf(" \t  %s ", aux_every_column_value[4] );
	printf(" \t  %s ", aux_every_column_value[8] );
	printf(" \t  %s ", aux_every_column_value[5] );
	printf(" \t  %s ", aux_every_column_value[6] );
	printf(" \t  %s ", aux_every_column_value[7] );
	printf(" \t  %s ", aux_every_column_value[9] );
	printf(" \t  %s ", aux_every_column_value[13] );
	printf(" \t  %s ", aux_every_column_value[10] );
	printf(" \t  %s ", aux_every_column_value[11] );
	printf(" \t  %s ", aux_every_column_value[12] );
	printf(" \t  %s ", aux_every_column_value[14] );
	printf("\nThe Brutal Mode Algorithm Implementation Not Resolve The Problem!\n");
	printf("\nBut It Serve to visualizate it\n");

	// It doesn't work fine!
	//char null_every_column_value[VALUE_BUF_SIZE] = "\0";

	//char * aux_swap_tmp_every_column_value = "aux swap tmp every column value \0";

	// array of array of pointer to characters in a way of a table
	//char * csv_data_table[rows][columns_per_row];

	/*
	// Initialization of the array of array of pointer to characters
	printf("\n");
	for( k=0 ; k < rows ; k++)
	{
		for( j=0; j < columns_per_row ; j++)
		{
			csv_data_table[k][j] = "x\0";
			//csv_data_table[k][j] = aux_every_column_value;
			printf(" %s ", csv_data_table[k][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/

	//printf("\n The last position of array of character csv_data is: %ld \n", (strlen(csv_data) - 1) );

	// It doesn't work fine!
	/* 
	printf("\n");
	for ( i = 0 ; csv_data[i] != '\0' && i <= (strlen(csv_data) - 1) ; i++)
	{
		// This is a test to show the character that have the array of character: char * csv_data
		//printf("\n csv_data[x] is: %c \n", csv_data[x] );
		for ( k = 0 ; k < rows ; k++)
		{
			// This can't be made with for because k index can not increment automatically
			//only must be incremented when have a '\n' character
			for( j = 0; j < columns_per_row ; j++)
			{
				//This can't be made with for because j index can not increment automatically
				//only must be incremented when have a ',' character
			}
			printf("\n");
		}
		printf("\n");
	}
	*/




	// It doesn't work fine!
	// Second We must parse from the begining to the end of the  char * csv_data            <->     while( csv_data[i] != '\0' )    0 <= index i of csv_data <= (strlen(csv_data) - 1)
        // every column's valúe                                                                 <->     another index j for the columns delimiters      ','
        // of every row                                                                         <->     another index k for the rows delimiters         '\n'
        // so we can save into an array of array of pointer to characters in a way of a table   <->     char * csv_data_table[k rows][j columns]
	/*
        while( csv_data[i] != '\0' ) // 0 <= index i of csv_data <= (strlen(csv_data) - 1)
        {
                // if is a character different of delimiter of each column ',' AND is different of delimiter of each row '\n'
                // this character is part of a valúe of a column
		if( csv_data[i] != ',' && csv_data[i] != '\n' )
              	{
			aux_every_column_value[i] = csv_data[i];
              	}
		// if this character is a delimiter of each column ',' we have an end of a value of a column
		// so we must save it ',' into   aux_every_column_value[i]
		// So we must finalize the value like the C Standar require with '\0' character into  aux_every_column_value[i+1]
		// andd we can save   aux_every_column_value[VALUE_BUF_SIZE]   into the array of array of pointer to characters   char * csv_data_table[k rows][j columns]
		// and then increment in one the j columns index
		// and then put all element of the   aux_every_column_value[VALUE_BUF_SIZE]  with the '\0' value with a for sentence
		// so this array of character don't have acumulative values 
		if( csv_data[i] == ',' )
		{
			aux_every_column_value[i] = ',';
			aux_every_column_value[i+1] = '\0'; // finalize the value like the C Standar require with '\0' character
			csv_data_table[k][j] = aux_every_column_value;
			j++;
			//aux_every_column_value = null_every_column_value; // It doesn't work fine!
			//for( int x = 0 ; x < VALUE_BUF_SIZE ; x++)
			//{
			//	aux_every_column_value[x] = '\0';
			//}
		}
		// if this character is a delimiter of a new line '\n' we have the end of a row
		// so we must save it '\n' into   aux_every_column_value[i]  
		// and then finalize the value like the C Standar require with '\0' character into   aux_every_column_value[i+1]  
		// we can save   aux_every_column_value[VALUE_BUF_SIZE]   into the array of array of pointer to characters   char * csv_data_table[k rows][j columns]
		// and then increment in one the j columns index
		// and then increment in one the k rows index
		// and then put all element of the   aux_every_column_value[VALUE_BUF_SIZE]  with the '\0' value with a for sentence
                // so this array of character don't have acumulative values
		if( csv_data[i] == '\n' )
		{
			aux_every_column_value[i] = '\n';
			aux_every_column_value[i+1] = '\0';
			csv_data_table[k][j] = aux_every_column_value;
                        j++;
			k++;
			//aux_every_column_value = null_every_column_value; //It doesn't work fine!
			//for( int x = 0 ; x < VALUE_BUF_SIZE ; x++)
                        //{
                        //        aux_every_column_value[x] = '\0';
                        //}
		}
		// in the end increment in one the parser i index
		i++;
        }
	*/	

	/*
	// We Can Show the representation of the array of characters char * csv_data   
	// like a table   with the array of array of pointer to characters   char * csv_data_table[k rows][j columns]
	printf("\nThe representation like a table of the array of characters char * csv_data  can be show like this: \n");
        for( k=0 ; k < rows ; k++)
        {
                for( j=0; j < columns_per_row ; j++)
                {
                        //csv_data_table[k][j] = "xxxxxxxxx\0";
                        //csv_data_table[k][j] = aux_every_column_value;
                        printf(" %s ", csv_data_table[k][j]);
                }
                printf("\n");
        }
        printf("\n");
	*/


	// It doesn't work fine!
	// int l = 0;
	//char *str1, *str2, *token, *subtoken;
        //char *saveptr1, *saveptr2;
	//
	/* 
	*for (l = 1, str1 = csv_data;   ; l++, str1 = NULL) 
        *{
	*	//token = strtok_r(str1,'\n', &saveptr1);
	*	token = strtok_r(str1, nl_delimiter, &saveptr1);
        *        if (token == NULL)
	*	{
        *                break;
	*	}
        *        //printf("%d: %s\n", l, token);
	*	// i have a row but i can't save to an array of array of pointer to characters
        *        printf("%d row have: %s\n", l, token);
        *        
        *        for (str2 = token;   ; str2 = NULL)
        *        {
        *                //subtoken = strtok_r(str2, ',', &saveptr2);
        *                subtoken = strtok_r(str2, comma_delimiter, &saveptr2);
        *                if (subtoken == NULL)
	*			{
        *                        break;
	*		}
        *                printf("column value have: %s\n", subtoken);
	*			// i have a value of column so i can save into the array of array of pointer to characters
	*		csv_data_table[k][j] = subtoken;
	*		j++; // increment the j index in one for the next value
	*	}
	*	k++; //increment the k index in one for the next row
        *}
	*/



	//int rows_positions_delimiters[rows];
	
	//It doesn't work fine because there are more than this number 'columns' on the entire array of characters
	//int columns_positions_delimiters[columns];



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

	char * sorted_csv_data = "\0";

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
	// int * the_positions_of_delimiters_of_rows = get_array_of_positions_of_delimiters_of_rows(csv_data, count_of_rows);
	
	// It doesn't work fine !
	// printf("\nThe delimiters that represent each end of a row is '/\n' characters scape sequence \n");
	// for (int i = 0; i <= count_of_rows; i++ )
	// {
	//  printf("\nThe 'row' number: %d  have the delimiter of your end in the position: %d into the entire array of character char * csv_data \n", i, the_positions_of_delimiters_of_rows[i] );
	// }

	//  It doesn't work fine !
	// for (int i = 0; i <= (sizeof(csv_data) - 1); i++ )   // because must use strlen(csv_data)
	// {
	//	printf("%s", csv_data[i]);
	// }
	
	// It works fine!
	int count_of_columns_on_each_row = get_count_of_columns_on_each_row(csv_data);
	printf("\nThe count of columns on each row that have this array of characters csv_data is: %d \n", count_of_columns_on_each_row );

	// It works fine!
        int total_columns = get_total_count_of_columns_on_entire_array(csv_data);
        printf("\nThe total count of columns on this entire array of characters csv_data is: %d \n", total_columns );

	sorted_csv_data = sort_csv_columns( csv_data );

	printf("\nThe Alphabetically Ordered Array of Character is : %s \n", sorted_csv_data);

	return 0; // status oK
}
