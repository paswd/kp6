#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

#include <stdbool.h>
#include "string.h"
#include "note.h"

typedef struct {
	ExpressionData *arr;
	size_t size;
} Expression;

Expression *expression_create();
void expression_destroy(Expression **exp);

#endif
