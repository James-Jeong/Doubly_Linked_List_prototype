#include "dlist_ptr.h"

dlist_ptr_t* dlist_ptr_create(){
	dlist_ptr_t *list = ( dlist_ptr_t*)malloc( sizeof( dlist_ptr_t));
	if( list == NULL){
		printf("	| ! List : Fail to create list object\n");
		return NULL;
	}

	list->head->prev = NULL;
	list->head->next = list->tail;

	list->tail->prev = list->head;
	list->tail->next = NULL;

	list->length = 0;

	return list;
}

void dlist_ptr_init( dlist_ptr_t *list){
	memset( list, '\0', sizeof( dlist_ptr_t));
	memset( list->head, '\0', sizeof( node_ptr_t));
	memset( list->tail, '\0', sizeof( node_ptr_t));

	list->head->prev = NULL;
	list->head->next = list->tail;

	list->tail->prev = list->head;
	list->tail->next = NULL;

	list->length = 0;
}


void dlist_ptr_destroy( dlist_ptr_t *list){
	if( list){
		node_ptr_t *index_node = list->head;
		if( index_node->next != list->tail){
			if( index_node->next != NULL){
				while( index_node->next != NULL){
					index_node = index_node->next;
					dlist_ptr_del_node_by_node( list, index_node);
				}
			}
		}
//		free( list);
	}
}

int dlist_ptr_add_node( dlist_ptr_t *list, void *data){
	node_ptr_t *new_node = node_ptr_create( data);
	if( new_node == NULL){
		printf("	| ! List : Fail to create node object in dlist_ptr_add_node\n");
		return OBJECT_ERR; 
	}

	if( list->head->next == list->tail){
		new_node->next = list->tail;
		new_node->prev = list->head;
		list->head->next = new_node;
		list->tail->prev = new_node;
		printf("	| @ List : Add head next\n");
	}
	else if( ( list->head->next != list->tail) && ( list->tail->prev != NULL)){
		node_ptr_t *old_node = list->tail->prev;
		new_node->prev = old_node;
		new_node->next = list->tail;
		old_node->next = new_node;
		list->tail->prev = new_node;
		printf("	| @ List : Add tail prev\n");
	}
	else{
		printf("	| ! List : unknown case in dlist_ptr_add_node\n");
		return UNKNOWN;
	}

	list->length++;

	return NORMAL;
}

int dlist_ptr_del_node_by_node( dlist_ptr_t *list, node_ptr_t *target){
	node_ptr_t *head = list->head;
	node_ptr_t *tail = list->tail;
	char *index_name;
	char *name = ( char*)( ( test_t*)( target->data))->name;

	if( list->head->next == NULL){
		printf("	| ! List : Not found node in list\n");
		list->length = 0;
		return NOT_EXIST;
	}

	node_ptr_t *index_node = list->head->next;

	while( index_node != tail){
		index_name = ( char*)( ( test_t*)( index_node->data))->name;
		printf("	| @ List : index_node->data : %s (len:%d)\n", index_name, strlen( index_name));
		printf("	| @ List : data : %s (len:%d)\n", name, strlen( name));
		if( index_node == target){
			printf("	| @ List : find node : %s\n", index_name);
			index_node->prev->next = index_node->next;
			index_node->next->prev = index_node->prev;
			node_ptr_destroy( index_node);
			list->length--;
			return NORMAL;
		}

		index_node = index_node->next;
	}

	return OBJECT_ERR;
}

int dlist_ptr_del_node_by_data( dlist_ptr_t *list, void *data){
	node_ptr_t *head = list->head;
	node_ptr_t *tail = list->tail;
	char *index_name;
	char *name = ( char*)( ( test_t*)( data))->name;

	if( list->head->next == NULL){
		printf("	| ! List : Not found node in list\n");
		list->length = 0;
		return NOT_EXIST;
	}

	node_ptr_t *index_node = list->head->next;

	while( index_node != tail){
		index_name = ( char*)( ( test_t*)( index_node->data))->name;
		printf("	| @ List : index_node->data : %s (len:%d)\n", index_name, strlen(index_name));
		printf("	| @ List : data : %s (len:%d)\n", name, strlen( name));
		if( ( memcmp( index_name, name, strlen( index_name))) == 0){
			printf("	| @ List : find node : %s\n", index_name);
			index_node->prev->next = index_node->next;
			index_node->next->prev = index_node->prev;
			node_ptr_destroy( index_node);
			list->length--;
			return NORMAL;
		}

		index_node = index_node->next;
	}

	return OBJECT_ERR;
}

node_ptr_t* dlist_ptr_find_node_by_node( dlist_ptr_t *list, node_ptr_t *target){
	node_ptr_t *head = list->head;
	node_ptr_t *tail = list->tail;

	if( list->head->next == NULL){
		printf("	| ! List : Not found node in list\n");
		return NULL;
	}

	node_ptr_t *index_node = list->head->next;
	
	while( index_node != tail){
		if( index_node == target){
			return index_node;
		}

		index_node = index_node->next;
	}

	return NULL;
}

void* dlist_ptr_find_node_data_by_node( dlist_ptr_t *list, node_ptr_t *target){
	node_ptr_t *head = list->head;
	node_ptr_t *tail = list->tail;

	if( list->head->next == NULL){
		printf("	| ! List : Not found node in list\n");
		return NULL;
	}

	node_ptr_t *index_node = list->head->next;

	while( index_node != tail){
		if( index_node == target){
			return index_node->data;
		}

		index_node = index_node->next;
	}

	return NULL;
}

node_ptr_t* dlist_ptr_find_node_by_data( dlist_ptr_t *list, void *data){
	node_ptr_t *head = list->head;
	node_ptr_t *tail = list->tail;

	if( list->head->next == NULL){
		printf("	| ! List : Not found node in list\n");
		return NULL;
	}

	node_ptr_t *index_node = list->head->next;

	while( index_node != tail){
		if( ( memcmp( index_node->data, data, sizeof( data))) == 0){
			return index_node;
		}

		index_node = index_node->next;
	}

	return NULL;
}

void* dlist_ptr_find_first_node_data( dlist_ptr_t *list){
	return ( list->head->next != list->tail)? list->head->next->data : NULL;
}

void* dlist_ptr_find_last_node_data( dlist_ptr_t *list){
	return ( list->tail->prev != list->head)? list->tail->prev->data : NULL;
}

node_ptr_t* dlist_ptr_find_last_node( dlist_ptr_t *list){
	return ( list->tail->prev != list->head)? list->tail->prev : NULL;
}

node_ptr_t* dlist_ptr_get_prev_node( dlist_ptr_t *list, node_ptr_t *target){
	if( target == NULL){
		return NULL;
	}

	node_ptr_t *node = dlist_ptr_find_node_by_node( list, target);
	if( node == NULL || node->prev == NULL){
		return NULL;
	}

	return node->prev;
}

void dlist_ptr_print_all( dlist_ptr_t *list){
	node_ptr_t *head = list->head;
	node_ptr_t *tail = list->tail;

	if( list->head->next == NULL){
		printf("	| ! List : Not found node in list\n");
		return ;
	}

	node_ptr_t *index_node = list->head->next;
	
	while( index_node != tail){
		printf("	PRINT	| @ List : index_node->data : %s\n", ( char*)( ( test_t*)( index_node->data))->name);
		index_node = index_node->next;
	}
}


// --------------------------------

node_ptr_t* node_ptr_create( void *data){
	node_ptr_t *node = ( node_ptr_t*)malloc( sizeof( node_ptr_t));
	if( node == NULL){
		return NULL;
	}

	if( data == NULL){
		return NULL;
	}

	node->data = malloc( sizeof( test_t));
	memcpy( node->data, data, sizeof( test_t));

	node->prev = NULL;
	node->next = NULL;

	return node;
}

void node_ptr_destroy( node_ptr_t *node){
	if( node){
		node->prev = NULL;
		node->next = NULL;
		if( node->data != NULL){
			free( node->data);
		}
		free( node);
	}
}

void* node_ptr_get_data( node_ptr_t *node){
	if( node == NULL){
		return NULL;
	}
	return node->data;
}

