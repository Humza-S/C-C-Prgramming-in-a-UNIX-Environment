#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// callback function
static int printRecords(void *NotUsed, int argc, char **argv, char **colNames) {
	char const *ldv = "last_date_visited";
	for (int i = 0; i < argc; i++) { // loop through all returned results
		printf("%s = %s\n",
		(strcmp(colNames[i], "datetime(last_visit_time/1000000-11644473600, \"unixepoch\")") == 0) ? ldv : colNames[i] ,
		argv[i] ? argv[i] : "NULL"); // print field, then print the value or print null if no value
	}
	printf("\n"); // print new line
	return 0;
}

// main function
int main() {

	sqlite3 *db; // holds database 
	char sql_pattern[500]; // maximum of 500 for input buffer
	char const *sql_command_start;
	char const *sql_command_end;
	char *data = 0;
	char *errMsg = 0;
	int status = 0;

	printf("Enter a url substring (like \"google\"): "); // get url substring from user
	scanf("%s", sql_pattern); // save user response

	status = sqlite3_open("History.db", &db); // open chrome history database

	if (status) {
		printf("Error opening database: %s\n", sqlite3_errmsg(db));
		return 0;
	}	

	sql_command_start = "SELECT title, url, datetime(last_visit_time/1000000-11644473600, \"unixepoch\"), visit_count from urls WHERE url LIKE '%"; // first part of sql command
	sql_command_end = "%';"; // third and final part of sql command

	// find lengths of each part of the string
	int const size1 = strlen(sql_command_start);  
	int const size2 = strlen(sql_pattern);
	int const size3 = strlen(sql_command_end);
	
	// concatenate all strings into one single sql command
	char *sql_command = (char*)malloc(size1+size2+size3+1);
	strcat(sql_command, sql_command_start);
	strcat(sql_command, sql_pattern);
	strcat(sql_command, sql_command_end);

	status = sqlite3_exec(db, sql_command, printRecords, (void*)data, &errMsg); // execute sql_command
	
	if (status != SQLITE_OK) { // if error encountered, print error message
		printf("Error executing SQL query: %s\n", errMsg);
	}

	sqlite3_close(db); // close the database
}
