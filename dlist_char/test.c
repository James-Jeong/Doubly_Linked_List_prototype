#include "dlist_char.h"

int main( int argc, char **argv){
	printf("*** @ dlist_char test @ ***\n\n");

	int rv;
	char *temp_test;
	node_char_t *node_char;
	dlist_char_t *list1;
	dlist_char_t list2[ 1];

	char *test1 = strdup( "dlist_char test1");
	char *test2 = strdup( "dlist_char test2");
	char *test3 = strdup( "dlist_char test3");


	// dynamic pointer
	printf("- dynamic pointer test start -\n");
	list1 = dlist_char_create();
	if( list1 == NULL){
		printf("! Fail to create list1\n");
		return rv;
	}

	rv = dlist_char_add_node( list1, test1);
	if( rv < NORMAL){
		printf("! Fail to add node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : test1)\n");
	}

	temp_test = dlist_char_find_last_node_data( list1);
	if( temp_test == NULL){
		printf("! Fail to find last node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 last node name : %s\n", temp_test);
	}

	rv = dlist_char_add_node( list1, test2);
	if( rv < NORMAL){
		printf("! Fail to add node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : test2)\n");
	}

	dlist_char_print_all( list1);

	temp_test = dlist_char_find_last_node_data( list1);
	if( temp_test == NULL){
		printf("! Fail to find last node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 last node name : %s\n", temp_test);
	}

	rv = dlist_char_del_node_by_data( list1, test1);
	if( rv < NORMAL){
		printf("! Fail to delete last node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : test1)\n");
	}

	dlist_char_print_all( list1);

	temp_test = dlist_char_find_first_node_data( list1);
	if( temp_test == NULL){
		printf("! Fail to find first node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 first node name : %s\n", temp_test);
	}

	temp_test = dlist_char_find_last_node_data( list1);
	if( temp_test == NULL){
		printf("! Fail to find last node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 last node name : %s\n", temp_test);
	}

	rv = dlist_char_del_node_by_data( list1, test2);
	if( rv < NORMAL){
		printf("! Fail to delete last node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : test2)\n");
	}

	dlist_char_print_all( list1);

	temp_test = dlist_char_find_last_node_data( list1);
	if( temp_test == NULL){
		printf("! Fail to find last node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 last node name : %s\n", temp_test);
	}

	rv = dlist_char_add_node( list1, test3);
	if( rv < NORMAL){
		printf("! Fail to add node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : test3)\n");
	}

	dlist_char_print_all( list1);

	temp_test = dlist_char_find_last_node_data( list1);
	if( temp_test == NULL){
		printf("! Fail to find last node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 last node name : %s\n", temp_test);
	}

	node_char = dlist_char_find_node_by_data( list1, test3);
	if( node_char == NULL){
		printf("! Fail to find node (data : test3) in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 node name : %s (node by data)\n", node_char->data);
	}
	
	temp_test = dlist_char_find_node_data_by_node( list1, node_char);
	if( temp_test == NULL){
		printf("! Fail to find last node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 node name : %s (node data by node)\n", temp_test);
	}

	node_char = ( dlist_char_find_node_by_node( list1, node_char));
	if( node_char == NULL){
		printf("! Fail to find last node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 node name : %s (node by node)\n", node_char->data);
	}

	rv = dlist_char_del_node_by_node( list1, node_char);
	if( rv < NORMAL){
		printf("! Fail to delete last node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : test3)\n");
	}

	dlist_char_print_all( list1);

	temp_test = dlist_char_find_first_node_data( list1);
	if( temp_test == NULL){
		printf("! Fail to find first node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 first node name : %s\n", temp_test);
	}

	temp_test = dlist_char_find_last_node_data( list1);
	if( temp_test == NULL){
		printf("! Fail to find last node in list1\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list1 last node name : %s\n", temp_test);
	}

	dlist_char_destroy( list1);

	printf("- dynamic pointer test end -\n\n");



	// static pointer
	printf("- static pointer test start -\n");

	dlist_char_init( list2);

	rv = dlist_char_add_node( list2, test1);
	if( rv < NORMAL){
		printf("! Fail to add node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : test1)\n");
	}

	temp_test = dlist_char_find_last_node_data( list2);
	if( temp_test == NULL){
		printf("! Fail to find last node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 last node name : %s\n", temp_test);
	}

	rv = dlist_char_add_node( list2,  test2);
	if( rv < NORMAL){
		printf("! Fail to add node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : test2)\n");
	}

	temp_test = dlist_char_find_last_node_data( list2);
	if( temp_test == NULL){
		printf("! Fail to find last node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 last node name : %s\n", temp_test);
	}

	rv = dlist_char_del_node_by_data( list2, test1);
	if( rv < NORMAL){
		printf("! Fail to delete last node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : test1)\n");
	}

	temp_test = dlist_char_find_first_node_data( list2);
	if( temp_test == NULL){
		printf("! Fail to find first node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 first node name : %s\n", temp_test);
	}

	temp_test = dlist_char_find_last_node_data( list2);
	if( temp_test == NULL){
		printf("! Fail to find last node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 last node name : %s\n", temp_test);
	}

	rv = dlist_char_del_node_by_data( list2, test2);
	if( rv < NORMAL){
		printf("! Fail to delete last node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : test2)\n");
	}

	temp_test = dlist_char_find_last_node_data( list2);
	if( temp_test == NULL){
		printf("! Fail to find last node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 last node name : %s\n", temp_test);
	}

	rv = dlist_char_add_node( list2, test3);
	if( rv < NORMAL){
		printf("! Fail to add node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : test3)\n");
	}

	temp_test = dlist_char_find_last_node_data( list2);
	if( temp_test == NULL){
		printf("! Fail to find last node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 last node name : %s\n", temp_test);
	}

	node_char = dlist_char_find_node_by_data( list2, test3);
	if( temp_test == NULL){
		printf("! Fail to find node (data : test3) in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 node name : %s (node by data)\n", node_char->data);
	}
	
	temp_test = dlist_char_find_node_data_by_node( list2, node_char);
	if( temp_test == NULL){
		printf("! Fail to find last node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 node name : %s (node data by node)\n", temp_test);
	}

	node_char = ( dlist_char_find_node_by_node( list2, node_char));
	temp_test = node_char->data;
	if( temp_test == NULL){
		printf("! Fail to find last node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 node name : %s (node by node)\n", temp_test);
	}

	rv = dlist_char_del_node_by_node( list2, node_char);
	if( rv < NORMAL){
		printf("! Fail to delete last node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : test3)\n");
	}

	temp_test = dlist_char_find_first_node_data( list2);
	if( temp_test == NULL){
		printf("! Fail to find first node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 first node name : %s\n", temp_test);
	}

	temp_test = dlist_char_find_last_node_data( list2);
	if( temp_test == NULL){
		printf("! Fail to find last node in list2\n");
//		return OBJECT_ERR;
	}
	else{
		printf("@ list2 last node name : %s\n", temp_test);
	}


	printf("- static pointer test end -\n\n");

	free( test1);
	free( test2);
	free( test3);
}

