#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "note.h"
#include "queue.h"
#include "database.h"

/*
typedef struct {
	size_t id;
	String surname;
	String initials;
	bool gender;
	String group;
	char mark_linal;
	char mark_dm;
	char mark_matan;
	char mark_inf;
} Note;
*/

Database *database_create(void)
{
	Database *res = (Database *) calloc(1, sizeof(Database));
	res->note = NULL;
	res->size = 0;
	return res;
}

void database_destroy(Database **db)
{
	if (*db == NULL)
		return;

	free((*db)->note);
	free(*db);
	*db = NULL;
}

void database_clear(Database *db)
{
	if (*db == NULL)
		return;

	free((*db)->note);
	(*db)->size = 0;
}

bool database_import(Database *db)
{
	FILE *in = fopen("database.db", "rb");
	if (!in)
		return false;

	Queue *queue = queue_create();
	size_t cnt = 0;
	while (!feof(in)) {
		Note note;
		fread(&note, sizeof(Note), 1, in);
		queue_push(queue, note);
		cnt++;
	}
	database_destroy(&db);
	db = database_create();
	db->size = cnt;
	db->note = (Note *) calloc(db->size, sizeof(Note));
}

bool database_export(Database *db)
{
	FILE *out = fopen("database.db", "wb")
	for (size_t i = 0; i < db->size; i++)
		fwrite(db->note[i], sizeof(Note), 1, out);

	return true;
}

size_t get_note_size(Database *db)
{
	return sizeof(Note);
	//return sizeof(size_t) + 3 * sizeof(String) + 4 * sizeof(char) + sizeof(bool);
}

