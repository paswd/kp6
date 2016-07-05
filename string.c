#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "string.h"

String get_str(void)
{
	String str;
	str.size = scanf("%s", &(str.value));
	return str;
}

String str_clear(void)
{
	String str;
	str.size = 0;
	return str;
}

String str_add(String str, char sym)
{
	if (str.size >= STR_SIZE - 1)
		return str;

	str.value[str.size] = sym;
	str.size++;
	return str;
}

bool is_str_equal(String str1, String str2)
{
	if (str1.size != str2.size)
		return false;

	for (int i = 0; i < str1.size; i++) {
		if (str1.value[i] != str2.value[i])
			return false;
	}
	return true;
}
