#ifndef _STRING_H_
#define _STRING_H_

#include <stdbool.h>

#define STR_SIZE 512

typedef struct {
	char value[STR_SIZE];
	size_t size;
} String;

String get_str(void);
String str_clear(void);
String str_add(String str, char sym);
bool is_str_equal(String str1, String str2);


#endif
