#include <stdio.h>
#include <stdlib.h>

Expression *expression_create()
{
	Expression *res = (Expression *) calloc(1, sizeof(Expression));
	res->arr = NULL;
	res->size = 0;
	return res;
}

void expression_destroy(Expression **exp)
{
	if (*exp == NULL)
		return;

	free((*exp)->arr);
	free(*exp);
	*exp = NULL;
}
