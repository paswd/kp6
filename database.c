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
	Database *res = database_create();
	Queue *queue = queue_create();
	size_t cnt = 0;
	for (size_t i = 0; i < db->size; i++) {
		if (is_expression_satisfied(db->note[i], where)) {
			queue_push(queue, db->note[i]);
			cnt++;
		}
	}
	res->size = cnt;
	res->note = (Note *) calloc(res->size, sizeof(Note));
	for (size_t i = 0; i < res->size; i++) {
		res->note[i] = queue_pop(queue);
	}
	queue_destroy(&queue);
	return res;
}

void database_insert(Database *db, Note note)
{
	db->size++;
	db->note = (Note *) realloc(db->note, db->size * sizeof(Note));
	db->note[db->size - 1] = note;
}

void database_update(Database *db, Expression *set, Expression *where)
{
	for (size_t i = 0; i < db->size; i++) {
		if (is_expression_satisfied(db->note[i], where)) {
			for (size_t j = 0; j < set->size; j++) {
				switch (set->arr[j].type) {
					case ID:
						db->note[i].id = set->arr[j].id;
						break;
					case SURNAME:
						db->note[i].id = set->arr[j].id;
						break;	
					case INITIALS:
						db->note[i].id = set->arr[j].id;
						break;
					case GENDER:
						db->note[i].id = set->arr[j].id;
						break;
					case GROUP:
						db->note[i].id = set->arr[j].id;
						break;
					case MARK_LINAL:
						db->note[i].id = set->arr[j].id;
						break;
					case MARK_DM:
						db->note[i].id = set->arr[j].id;
						break;
					case MARK_MATAN:
						db->note[i].id = set->arr[j].id;
						break;
					case MARK_INF:
						db->note[i].id = set->arr[j].id;
						break;
				}
			}
		}
	}
}

void database_delete_note(Database *db, Expression *where)
{
	size_t deleted = 0;
	for (size_t i = 0; i < db->size; i++) {
		if (is_expression_satisfied(db->note[i], where)) {
			deleted++;
			continue;
		}
		db->note[i - deleted] = db->note[i];
	}
	db->size -= deleted;
	db->note = (Note *) realloc(db->note, db->size * sizeof(Note));
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
				if (note.id != exp->arr[i].id)
					return false;
				break;
			case SURNAME:
				if (!is_str_equal(note.surname, exp->arr[i].surname))
					return false;
				break;	
			case INITIALS:
				if (!is_str_equal(note.initials, exp->arr[i].initials))
					return false;
				break;
			case GENDER:
				if (note.gender != exp->arr[i].gender)
					return false;
				break;
			case GROUP:
				if (!is_str_equal(note.group, exp->arr[i].group))
					return false;
				break;
			case MARK_LINAL:
				if (note.mark_linal != exp->arr[i].mark_linal)
					return false;
				break;
			case MARK_DM:
				if (note.mark_dm != exp->arr[i].mark_dm)
					return false;
				break;
			case MARK_MATAN:
				if (note.mark_matan != exp->arr[i].mark_matan)
					return false;
				break;
			case MARK_INF:
				if (note.mark_inf != exp->arr[i].mark_inf)
					return false;
				break;
		}
	}
	return true;
}

