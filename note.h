#ifndef _NOTE_H_
#define _NOTE_H_

#include <stdbool.h>
#include "string.h"

typedef enum {
	ID,
	SURNAME,
	INITIALS,
	GENDER,
	GROUP,
	MARK_LINAL,
	MARK_DM,
	MARK_MATAN,
	MARK_INF
} ExpressionName;

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

typedef struct {
	ExpressionName type;
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
} ExpressionData;

#endif
