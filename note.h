#ifndef _NOTE_H_
#define _NOTE_H_

#include <stdbool.h>

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

#endif
