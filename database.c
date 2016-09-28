#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "note.h"
#include "queue.h"
#include "database.h"
#include "expression.h"

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
	if (db == NULL)
		return;

	free(db->note);
	db->size = 0;
}

Database *database_select(Database *db, Expression *where)
{
	
}

void database_insert(Database *db, Note note)
{

}

void database_update(Database *db, Expression *set, Expression *where)
{

}

void database_delete_note(Database *db, Expression *where)
{

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
	fclose(in);
	return true;
}

bool database_export(Database *db)
{
	FILE *out = fopen("database.db", "wb");
	for (size_t i = 0; i < db->size; i++)
		fwrite(&(db->note[i]), sizeof(Note), 1, out);

	fclose(out);
	return true;
}

size_t get_note_size()
{
	return sizeof(Note);
	//return sizeof(size_t) + 3 * sizeof(String) + 4 * sizeof(char) + sizeof(bool);
}

bool is_expression_satisfied(Note note, Expression *exp)
{
	for (size_t i = 0; i < exp->size; i++) {
		switch (exp->arr[i].type) {
			case ID:
				if (note.id != exp->arr[i].data.id)
					return false;
				break;
			case SURNAME:
				if (note.surname != exp->arr[i].data.surname)
					return false;
				break;	
			case INITIALS:
				if (note.initials != exp->arr[i].data.initials)
					return false;
				break;
			case GENDER:
				if (note.gender != exp->arr[i].data.gender)
					return false;
				break;
			case GROUP:
				if (note.group != exp->arr[i].data.group)
					return false;
				break;
			case MARK_LINAL:
				if (note.mark_linal != exp->arr[i].data.mark_linal)
					return false;
				break;
			case MARK_DM:
				if (note.mark_dm != exp->arr[i].data.mark_dm)
					return false;
				break;
			case MARK_MATAN:
				if (note.mark_matan != exp->arr[i].data.mark_matan)
					return false;
				break;
			case MARK_INF:
				if (note.mark_inf != exp->arr[i].data.mark_inf)
					return false;
				break;
		}
	}
	return true;
}

