#include "dlist_int.h"

int main( int argc, char **argv){
	printf("*** @ dlist_int test @ ***\n\n");

	int rv;
	node_int_t *node_int;
	dlist_int_t *list1;
	dlist_int_t list2[ 1];

	// dynamic pointer
	printf("- dynamic pointer test start -\n");
	list1 = dlist_int_create();
	if( list1 == NULL){
		printf("! Fail to create list1\n");
		return rv;
	}

	rv = dlist_int_add_node( list1, 1);
	if( rv < NORMAL){
		printf("! Fail to add node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : 1)\n");
	}

	rv = dlist_int_find_last_node_data( list1);
	if( rv < NORMAL){
		printf("! Fail to find last node in list1\n");
		return rv;
	}
	else{
		printf("@ list1 last node data : %d\n", rv);
	}

	rv = dlist_int_add_node( list1, 2);
	if( rv < NORMAL){
		printf("! Fail to add node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : 2)\n");
	}

	rv = dlist_int_find_last_node_data( list1);
	if( rv < NORMAL){
		printf("! Fail to find last node in list1\n");
		return rv;
	}
	else{
		printf("@ list1 last node data : %d\n", rv);
	}

	rv = dlist_int_del_node_by_data( list1, 1);
	if( rv < NORMAL){
		printf("! Fail to delete last node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : 1)\n");
	}

	rv = dlist_int_find_first_node_data( list1);
	if( rv < NORMAL){
		printf("! Fail to find first node in list1\n");
		return rv;
	}
	else{
		printf("@ list1 first node data : %d\n", rv);
	}

	rv = dlist_int_find_last_node_data( list1);
	if( rv < NORMAL){
		printf("! Fail to find last node in list1\n");
		return rv;
	}
	else{
		printf("@ list1 last node data : %d\n", rv);
	}

	rv = dlist_int_del_node_by_data( list1, 2);
	if( rv < NORMAL){
		printf("! Fail to delete last node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : 2)\n");
	}

	rv = dlist_int_find_last_node_data( list1);
	if( rv < NORMAL){
		printf("! Fail to find last node in list1\n");
		return rv;
	}
	else{
		printf("@ list1 last node data : %d\n", rv);
	}


	rv = dlist_int_add_node( list1, 3);
	if( rv < NORMAL){
		printf("! Fail to add node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : 3)\n");
	}

	rv = dlist_int_find_last_node_data( list1);
	if( rv < NORMAL){
		printf("! Fail to find last node in list1\n");
		return rv;
	}
	else{
		printf("@ list1 last node data : %d\n", rv);
	}

	node_int = dlist_int_find_node_by_data( list1, 3);
	if( node_int == NULL){
		printf("! Fail to find node (data : 3) in list1\n");
		return OBJECT_ERR;
	}
	else{
		printf("@ Success to find node (data : 3) (node by data)\n");
	}
	
	rv = dlist_int_find_node_data_by_node( list1, node_int);
	if( node_int == NULL){
		printf("! Fail to find node (data : 3) in list1\n");
		return rv;
	}
	else{
		printf("@ Success to find node (data : %d) (node data by node)\n", rv);
	}

	node_int = dlist_int_find_node_by_node( list1, node_int);
	if( node_int == NULL){
		printf("! Fail to find node (data : 3) in list1\n");
		return OBJECT_ERR;
	}
	else{
		printf("@ Success to find node (data : 3) (node by node)\n");
	}

	rv = dlist_int_del_node_by_node( list1, node_int);
	if( rv < NORMAL){
		printf("! Fail to delete last node in list1\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : 3)\n");
	}

	rv = dlist_int_find_first_node_data( list1);
	if( rv < NORMAL){
		printf("! Fail to find first node in list1\n");
		return rv;
	}
	else{
		printf("@ list1 first node data : %d\n", rv);
	}

	rv = dlist_int_find_last_node_data( list1);
	if( rv < NORMAL){
		printf("! Fail to find last node in list1\n");
		return rv;
	}
	else{
		printf("@ list1 last node data : %d\n", rv);
	}

	dlist_int_destroy( list1);

	printf("- dynamic pointer test end -\n\n");



	// static pointer
	printf("- static pointer test start -\n");
	dlist_int_init( list2);

	rv = dlist_int_add_node( list2, 1);
	if( rv < NORMAL){
		printf("! Fail to add node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : 1)\n");
	}

	rv = dlist_int_find_last_node_data( list2);
	if( rv < NORMAL){
		printf("! Fail to find last node in list2\n");
		return rv;
	}
	else{
		printf("@ list2 last node data : %d\n", rv);
	}

	rv = dlist_int_add_node( list2, 2);
	if( rv < NORMAL){
		printf("! Fail to add node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : 2)\n");
	}

	rv = dlist_int_find_last_node_data( list2);
	if( rv < NORMAL){
		printf("! Fail to find last node in list2\n");
		return rv;
	}
	else{
		printf("@ list2 last node data : %d\n", rv);
	}

	rv = dlist_int_del_node_by_data( list2, 1);
	if( rv < NORMAL){
		printf("! Fail to delete last node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : 1)\n");
	}

	rv = dlist_int_find_first_node_data( list2);
	if( rv < NORMAL){
		printf("! Fail to find first node in list2\n");
		return rv;
	}
	else{
		printf("@ list2 first node data : %d\n", rv);
	}

	rv = dlist_int_find_last_node_data( list2);
	if( rv < NORMAL){
		printf("! Fail to find last node in list2\n");
		return rv;
	}
	else{
		printf("@ list2 last node data : %d\n", rv);
	}

	rv = dlist_int_del_node_by_data( list2, 2);
	if( rv < NORMAL){
		printf("! Fail to delete last node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : 2)\n");
	}

	rv = dlist_int_find_last_node_data( list2);
	if( rv < NORMAL){
		printf("! Fail to find last node in list2\n");
		return rv;
	}
	else{
		printf("@ list2 last node data : %d\n", rv);
	}


	rv = dlist_int_add_node( list2, 3);
	if( rv < NORMAL){
		printf("! Fail to add node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to add node (data : 3)\n");
	}

	rv = dlist_int_find_last_node_data( list2);
	if( rv < NORMAL){
		printf("! Fail to find last node in list2\n");
		return rv;
	}
	else{
		printf("@ list2 last node data : %d\n", rv);
	}

	node_int = dlist_int_find_node_by_data( list2, 3);
	if( node_int == NULL){
		printf("! Fail to find node (data : 3) in list2\n");
		return OBJECT_ERR;
	}
	else{
		printf("@ Success to find node (data : 3) (node by data)\n");
	}
	
	rv = dlist_int_find_node_data_by_node( list2, node_int);
	if( node_int == NULL){
		printf("! Fail to find node (data : 3) in list2\n");
		return rv;
	}
	else{
		printf("@ Success to find node (data : %d) (node data by node)\n", rv);
	}

	node_int = dlist_int_find_node_by_node( list2, node_int);
	if( node_int == NULL){
		printf("! Fail to find node (data : 3) in list2\n");
		return OBJECT_ERR;
	}
	else{
		printf("@ Success to find node (data : 3) (node by node)\n");
	}

	rv = dlist_int_del_node_by_node( list2, node_int);
	if( rv < NORMAL){
		printf("! Fail to delete last node in list2\n");
		return rv;
	}
	else{
		printf("@ Success to delete node (data : 3)\n");
	}

	rv = dlist_int_find_first_node_data( list2);
	if( rv < NORMAL){
		printf("! Fail to find first node in list2\n");
		return rv;
	}
	else{
		printf("@ list2 first node data : %d\n", rv);
	}

	rv = dlist_int_find_last_node_data( list2);
	if( rv < NORMAL){
		printf("! Fail to find last node in list2\n");
		return rv;
	}
	else{
		printf("@ list2 last node data : %d\n", rv);
	}

	printf("- static pointer test end -\n\n");
}

