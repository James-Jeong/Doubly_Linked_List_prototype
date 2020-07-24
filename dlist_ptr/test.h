#ifndef __TEST_H__
#define __TEST_H__

#include "dlist_ptr.h"

#define BUF_MAX_LEN 1024

typedef struct test_s test_t;
struct test_s{
	int data;
	char name[ BUF_MAX_LEN];
};

test_t* test_init( char *name);
void test_destroy( test_t *test);
int test_set_data( test_t *test, int data);
int test_set_name( test_t *test, char *name);
int test_get_data( test_t *test);
char* test_get_name( test_t *test);

#endif

