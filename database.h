#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <stdbool.h>
#include "string.h"
#include "note.h"
#include "expression.h"

typedef struct {
	Note *note;
	size_t size;
} Database;

Database *database_create(void);
void database_destroy(Database **db);

void database_clear(Database *db);
Database *database_select(Database *db, Expression_Data *where);
void database_insert(Database *db, Note note);
void database_update(Database *db, Expression_Data *set, Expression_Data *where);
void database_delete_note(Database *db, Expression_Data *where);

bool database_import(Database *db);
bool database_export(Database *db);
size_t get_note_size();

#endif
