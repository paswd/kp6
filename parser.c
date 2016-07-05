#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "string.h"
#include "database.h"

struct _expression_note {
	size_t field;
	union {
		size_t id;
		String surname;
		String initials;
		bool gender;
		String group;
		char mark_linal;
		char mark_dm;
		char mark_matan;
		char mark_inf;
	} data;
};

struct _expression_data {
	Exptession_Note *notes;
	size_t size;
};

bool sql_parse(Database *db, String str)
{
	/*
	select
	insert
	update
	delete
	truncate
	*/

	int mode = 0;

	if (strstr(str.value, "select") || strstr(str.value, "SELECT"))
		mode = 1;
	if (strstr(str.value, "insert") || strstr(str.value, "INSERT"))
		mode = 2;
	if (strstr(str.value, "update") || strstr(str.value, "UPDATE"))
		mode = 3;
	if (strstr(str.value, "delete") || strstr(str.value, "DELETE"))
		mode = 4;
	if (strstr(str.value, "truncate") || strstr(str.value, "TRUNCATE"))
		mode = 5;

	bool is_expression = false;
	if (strstr(str.value, "where") || strstr(str.value, "WHERE"))
		is_expression = true;


	switch (mode) {
		case 1:
		case 2:
		case 3:
		case 4:
			if (!is_expression)
				return false;


		case 5:
			database_clear(db);
			return true;
		default:
			return false;
	}


}

Expression_Data expression_parse(String str, size_t pos)
{
	
}