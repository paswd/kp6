#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <stdbool.h>
#include "string.h"
#include "note.h"

typedef struct {
	Note *note;
	size_t size;
} Database;

Database database_create(void);
void database_destroy(Database **db)

bool database_import(Database *db);
bool database_export(Database *db);
size_t database_get_note_size(Database *db);

#endif
