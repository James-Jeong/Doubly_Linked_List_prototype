#include "test.h"

int main( int argc, char **argv){
	printf("*** @ dlist_ptr test @ ***\n\n");

	int rv;
	test_t *temp_test;
	node_ptr_t *node_ptr;
	dlist_ptr_t *list1;
	dlist_ptr_t list2[ 1];

	test_t *test1 = test_init( "test");
	if( test1 == NULL){
		printf("! Fail to create test1 object\n");
		return OBJECT_ERR;
	}

	rv = test_set_data( test1, 1);
	if( rv < NORMAL){
		printf("! Fail to set data in test1 object\n");
		return rv;
	}

	rv = test_set_name( test1, "dlist_ptr test1");
	if( rv < NORMAL){
		printf("! Fail to set data in test1 object\n");
		return rv;
	}
	else{
		printf("	@ test1 name : %s\n", test1->name);
	}

	test_t *test2 = test_init( "test");
	if( test2 == NULL){
		printf("! Fail to create test2 object\n");
		return OBJECT_ERR;
	}

	rv = test_set_data( test2, 2);
	if( rv < NORMAL){
		printf("! Fail to set data in test2 object\n");
		return rv;
	}

	rv = test_set_name( test2, "dlist_ptr test2");
	if( rv < NORMAL){
		printf("! Fail to set data in test2 object\n");
		return rv;
	}
	else{
		printf("	@ test2 name : %s\n", test2->name);
	}

	test_t *test3 = test_init( "test");
	if( test3 == NULL){
		printf("! Fail to create test3 object\n");
		return OBJECT_ERR;
	}

	rv = test_set_data( test3, 3);
	if( rv < NORMAL){
		printf("! Fail to set data in test3 object\n");
		return rv;
	}

	rv = test_set_name( test3, "dlist_ptr test3");
	if( rv < NORMAL){
		printf("! Fail to set data in test3 object\n");
		return rv;
	}
	else{
		printf("	@ test3 name : %s\n", test3->name);
	}
	printf("\n\n");


	// dynamic pointer
	printf("- dynamic pointer test start -\n");
	list1 = dlist_ptr_create();
	if( list1 == NULL){
		printf("! Fail to create list1\n");
		return rv;
	}

	rv = dlist_ptr_add_node( list1, ( void*)( test1));
	if( rv < NORMAL){
		printf("! Fail to add node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : test1)\n");
	}

	temp_test = ( test_t*)( dlist_ptr_find_last_node_data( list1));
	if( temp_test == NULL){
		printf("! Fail to find last node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 last node data : %d\n", temp_test->data);
		printf("@ list1 last node name : %s\n", temp_test->name);
	}

	rv = dlist_ptr_add_node( list1, ( void*)( test2));
	if( rv < NORMAL){
		printf("! Fail to add node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : test2)\n");
	}

	temp_test = ( test_t*)( dlist_ptr_find_last_node_data( list1));
	if( temp_test == NULL){
		printf("! Fail to find last node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 last node data : %d\n", temp_test->data);
		printf("@ list1 last node name : %s\n", temp_test->name);
	}

	dlist_ptr_print_all( list1);

	rv = dlist_ptr_del_node_by_data( list1, ( void*)( test1));
	if( rv < NORMAL){
		printf("! Fail to delete last node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : test1)\n");
	}

	dlist_ptr_print_all( list1);

	temp_test = ( test_t*)( dlist_ptr_find_first_node_data( list1));
	if( temp_test == NULL){
		printf("! Fail to find first node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 first node data : %d\n", temp_test->data);
		printf("@ list1 first node name : %s\n", temp_test->name);
	}

	temp_test = ( test_t*)( dlist_ptr_find_last_node_data( list1));
	if( temp_test == NULL){
		printf("! Fail to find last node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 last node data : %d\n", temp_test->data);
		printf("@ list1 last node name : %s\n", temp_test->name);
	}

	rv = dlist_ptr_del_node_by_data( list1, ( void*)( test2));
	if( rv < NORMAL){
		printf("! Fail to delete last node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : test2)\n");
	}

	dlist_ptr_print_all( list1);

	temp_test = ( test_t*)( dlist_ptr_find_last_node_data( list1));
	if( temp_test == NULL){
		printf("! Fail to find last node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 last node data : %d\n", temp_test->data);
		printf("@ list1 last node name : %s\n", temp_test->name);
	}

	rv = dlist_ptr_add_node( list1, ( void*)( test3));
	if( rv < NORMAL){
		printf("! Fail to add node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : test3)\n");
	}

	temp_test = ( test_t*)( dlist_ptr_find_last_node_data( list1));
	if( temp_test == NULL){
		printf("! Fail to find last node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 last node data : %d\n", temp_test->data);
		printf("@ list1 last node name : %s\n", temp_test->name);
	}

	node_ptr = dlist_ptr_find_node_by_data( list1, ( void*)( test3));
	if( node_ptr == NULL){
		printf("! Fail to find node (data : test3) in list1\n");
//		return OBJECT_ERR;
	}
	else{
		temp_test = ( test_t*)( node_ptr->data);
		printf("@ list1 node data : %d (node by data)\n", temp_test->data);
		printf("@ list1 node name : %s (node by data)\n", temp_test->name);
	}
	
	temp_test = dlist_ptr_find_node_data_by_node( list1, ( void*)( test3));
	if( temp_test == NULL){
		printf("! Fail to find last node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 node data : %d (node data by node)\n", temp_test->data);
		printf("@ list1 node name : %s (node data by node)\n", temp_test->name);
	}

	node_ptr = ( dlist_ptr_find_node_by_node( list1, node_ptr));
	if( node_ptr == NULL){
		printf("! Fail to find last node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		temp_test = ( test_t*)( node_ptr->data);
		printf("@ list1 node data : %d (node by node)\n", temp_test->data);
		printf("@ list1 node name : %s (node by node)\n", temp_test->name);
	}

	rv = dlist_ptr_del_node_by_node( list1, node_ptr);
	if( rv < NORMAL){
		printf("! Fail to delete last node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : test3)\n");
	}

	temp_test = ( test_t*)( dlist_ptr_find_first_node_data( list1));
	if( temp_test == NULL){
		printf("! Fail to find first node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 first node data : %d\n", temp_test->data);
		printf("@ list1 first node name : %s\n", temp_test->name);
	}

	temp_test = ( test_t*)( dlist_ptr_find_last_node_data( list1));
	if( temp_test == NULL){
		printf("! Fail to find last node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 last node data : %d\n", temp_test->data);
		printf("@ list1 last node name : %s\n", temp_test->name);
	}

	dlist_ptr_destroy( &list1);

	printf("- dynamic pointer test end -\n\n");


	// static pointer
	printf("- static pointer test start -\n");

	dlist_ptr_init( list2);

	rv = dlist_ptr_add_node( list2, ( void*)( test1));
	if( rv < NORMAL){
		printf("! Fail to add node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : test1)\n");
	}

	temp_test = ( test_t*)( dlist_ptr_find_last_node_data( list2));
	if( temp_test == NULL){
		printf("! Fail to find last node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 last node data : %d\n", temp_test->data);
		printf("@ list2 last node name : %s\n", temp_test->name);
	}

	rv = dlist_ptr_add_node( list2, ( void*)( test2));
	if( rv < NORMAL){
		printf("! Fail to add node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : test2)\n");
	}

	temp_test = ( test_t*)( dlist_ptr_find_last_node_data( list2));
	if( temp_test == NULL){
		printf("! Fail to find last node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 last node data : %d\n", temp_test->data);
		printf("@ list2 last node name : %s\n", temp_test->name);
	}

	rv = dlist_ptr_del_node_by_data( list2, ( void*)( test1));
	if( rv < NORMAL){
		printf("! Fail to delete last node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : test1)\n");
	}

	temp_test = ( test_t*)( dlist_ptr_find_first_node_data( list2));
	if( temp_test == NULL){
		printf("! Fail to find first node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 first node data : %d\n", temp_test->data);
		printf("@ list2 first node name : %s\n", temp_test->name);
	}

	temp_test = ( test_t*)( dlist_ptr_find_last_node_data( list2));
	if( temp_test == NULL){
		printf("! Fail to find last node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 last node data : %d\n", temp_test->data);
		printf("@ list2 last node name : %s\n", temp_test->name);
	}

	rv = dlist_ptr_del_node_by_data( list2, ( void*)( test2));
	if( rv < NORMAL){
		printf("! Fail to delete last node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : test2)\n");
	}

	temp_test = ( test_t*)( dlist_ptr_find_last_node_data( list2));
	if( temp_test == NULL){
		printf("! Fail to find last node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 last node data : %d\n", temp_test->data);
		printf("@ list2 last node name : %s\n", temp_test->name);
	}

	rv = dlist_ptr_add_node( list2, ( void*)( test3));
	if( rv < NORMAL){
		printf("! Fail to add node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : test3)\n");
	}

	temp_test = ( test_t*)( dlist_ptr_find_last_node_data( list2));
	if( temp_test == NULL){
		printf("! Fail to find last node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 last node data : %d\n", temp_test->data);
		printf("@ list2 last node name : %s\n", temp_test->name);
	}

	node_ptr = dlist_ptr_find_node_by_data( list2, ( void*)( test3));
	if( node_ptr == NULL){
		printf("! Fail to find node (data : test3) in list2\n");
//		return OBJECT_ERR;
	}
	else{
		temp_test = ( test_t*)( node_ptr->data);
		printf("@ list2 node data : %d (node by data)\n", temp_test->data);
		printf("@ list2 node name : %s (node by data)\n", temp_test->name);
	}
	
	temp_test = dlist_ptr_find_node_data_by_node( list2, ( void*)( test3));
	if( temp_test == NULL){
		printf("! Fail to find last node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 node data : %d (node data by node)\n", temp_test->data);
		printf("@ list2 node name : %s (node data by node)\n", temp_test->name);
	}

	node_ptr = ( dlist_ptr_find_node_by_node( list2, node_ptr));
	if( node_ptr == NULL){
		printf("! Fail to find last node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		temp_test = ( test_t*)( node_ptr->data);
		printf("@ list2 node data : %d (node by node)\n", temp_test->data);
		printf("@ list2 node name : %s (node by node)\n", temp_test->name);
	}

	rv = dlist_ptr_del_node_by_node( list2, node_ptr);
	if( rv < NORMAL){
		printf("! Fail to delete last node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : test3)\n");
	}

	temp_test = ( test_t*)( dlist_ptr_find_first_node_data( list2));
	if( temp_test == NULL){
		printf("! Fail to find first node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 first node data : %d\n", temp_test->data);
		printf("@ list2 first node name : %s\n", temp_test->name);
	}

	temp_test = ( test_t*)( dlist_ptr_find_last_node_data( list2));
	if( temp_test == NULL){
		printf("! Fail to find last node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 last node data : %d\n", temp_test->data);
		printf("@ list2 last node name : %s\n", temp_test->name);
	}


	printf("- static pointer test end -\n\n");

	test_destroy( &test1);
	test_destroy( &test2);
	test_destroy( &test3);
}

test_t* test_init( char *name){
	test_t *test = ( test_t*)malloc( sizeof( test_t));
	if( test == NULL){
		return NULL;
	}
	int name_len = strlen( name);
	if( name_len > BUF_MAX_LEN){
		return NULL;
	}
	memset( test->name, '\0', BUF_MAX_LEN);
	memcpy( test->name, name, name_len);
	test->data = 0;
	return test;
}

void test_destroy( test_t **test){
	if( *test){
		free( *test);
		*test = NULL;
	}
}

int test_set_data( test_t *test, int data){
	if( test){
		test->data = data;
		return NORMAL;
	}
	return OBJECT_ERR;
}

int test_set_name( test_t *test, char *name){
	if( test){
		int name_len = strlen( name);
		if( name_len > BUF_MAX_LEN){
			return BUF_ERR;
		}
		memcpy( test->name, name, name_len);
		return NORMAL;
	}
	return OBJECT_ERR;
}

int test_get_data( test_t *test){
	if( test){
		return test->data;
	}
	return OBJECT_ERR;
}

char* test_get_name( test_t *test){
	if( test){
		return test->name;
	}
	return NULL;
}

