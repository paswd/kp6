#ifndef _PARSER_H_
#define _PARSER_H_

#include <stdbool.h>
#include "exptession.h"

//typedef _expression_data Expression_data;

Expression *expression_parse(String str);
Expression *update_set_parse(String str);
Database *sql_parse(Database *db, String str);

#endif
