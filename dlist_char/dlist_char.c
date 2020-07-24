#include "dlist_char.h"

// --------------------------------

static node_char_t* node_char_create( char *data){
	node_char_t *node = ( node_char_t*)malloc( sizeof( node_char_t));
	if( node == NULL){
		return NULL;
	}

	node->prev = NULL;
	node->next = NULL;
	memcpy( node->data, data, BUF_MAX_LEN);
//	node->data = data;
	return node;
}

static void node_char_destroy( node_char_t *node){
	if( node){
		node->prev = NULL;
		node->next = NULL;
		if( node->data != NULL){
			memset( node->data, '\0', sizeof( node->data));
//			node->data = NULL;
		}
		free( node);
	}
}

static char* node_char_get_data( node_char_t *node){
	if( node == NULL){
		return NULL;
	}

	return node->data;
}

// --------------------------------


dlist_char_t* dlist_char_create(){
	dlist_char_t *list = ( dlist_char_t*)malloc( sizeof( dlist_char_t));
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

void dlist_char_init( dlist_char_t *list){
	memset( list, '\0', sizeof( dlist_char_t));
	memset( list->head, '\0', sizeof( node_char_t));
	memset( list->tail, '\0', sizeof( node_char_t));

	list->head->prev = NULL;
	list->head->next = list->tail;

	list->tail->prev = list->head;
	list->tail->next = NULL;

	list->length = 0;
}


void dlist_char_destroy( dlist_char_t *list){
	if( list){
		node_char_t *index_node = list->head;
		if( index_node->next != list->tail){
			if( index_node->next != NULL){
				while( index_node->next != NULL){
					index_node = index_node->next;
					dlist_char_del_node_by_node( list, index_node);
				}
			}
		}
		memset( list, '\0', sizeof( list));
		free( list);
	}
}

int dlist_char_add_node( dlist_char_t *list, char *data){
	node_char_t *new_node = node_char_create( data);
	if( new_node == NULL){
		printf("	| ! List : Fail to create node object in dlist_char_add_node\n");
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
		node_char_t *old_node = list->tail->prev;
		new_node->prev = old_node;
		new_node->next = list->tail;
		old_node->next = new_node;
		list->tail->prev = new_node;
		printf("	| @ List : Add tail prev\n");
	}
	else{
		printf("	| ! List : unknown case in dlist_char_add_node\n");
		return UNKNOWN;
	}

	list->length++;

	return NORMAL;
}

int dlist_char_del_node_by_node( dlist_char_t *list, node_char_t *target){
	node_char_t *head = list->head;
	node_char_t *tail = list->tail;

	if( list->head->next == NULL){
		printf("	| ! List : Not found node in list\n");
		list->length = 0;
		return NOT_EXIST;
	}

	node_char_t *index_node = list->head->next;

	while( index_node != tail){
		printf("	| @ List : index_node->data : %s\n", index_node->data);
		printf("	| @ List : data : %s (len:%d)\n", target->data, strlen( target->data));
		if( index_node == target){
			printf("		| @ List : find node : %s\n", index_node->data);
			index_node->prev->next = index_node->next;
			index_node->next->prev = index_node->prev;
			node_char_destroy( index_node);
			list->length--;
			return NORMAL;
		}

		index_node = index_node->next;
	}

	return OBJECT_ERR;
}

int dlist_char_del_node_by_data( dlist_char_t *list, char *data){
	node_char_t *head = list->head;
	node_char_t *tail = list->tail;

	if( list->head->next == NULL){
		printf("	| ! List : Not found node in list\n");
		list->length = 0;
		return NOT_EXIST;
	}

	node_char_t *index_node = list->head->next;

	while( index_node != tail){
		printf("	| @ List : index_node->data : %s (len:%d)\n", index_node->data, strlen( index_node->data));
		printf("	| @ List : data : %s (len:%d)\n", data, strlen( data));
		if( ( memcmp( index_node->data, data, strlen( index_node->data))) == 0){
			printf("		| @ List : find data : %s\n", index_node->data);
			index_node->prev->next = index_node->next;
			index_node->next->prev = index_node->prev;
			node_char_destroy( index_node);
			list->length--;
			return NORMAL;
		}

		index_node = index_node->next;
	}

	return OBJECT_ERR;
}

node_char_t* dlist_char_find_node_by_node( dlist_char_t *list, node_char_t *target){
	node_char_t *head = list->head;
	node_char_t *tail = list->tail;

	if( list->head->next == NULL){
		printf("	| ! List : Not found node in list\n");
		return NULL;
	}

	node_char_t *index_node = list->head->next;
	
	while( index_node != NULL){
		if( index_node == target){
			return index_node;
		}

		index_node = index_node->next;
	}

	return NULL;
}

char* dlist_char_find_node_data_by_node( dlist_char_t *list, node_char_t *target){
	node_char_t *head = list->head;
	node_char_t *tail = list->tail;

	if( list->head->next == NULL){
		printf("	| ! List : Not found node in list\n");
		return NULL;
	}

	node_char_t *index_node = list->head->next;

	while( index_node != NULL){
		if( index_node == target){
			return index_node->data;
		}

		index_node = index_node->next;
	}

	return NULL;
}

node_char_t* dlist_char_find_node_by_data( dlist_char_t *list, char *data){
	node_char_t *head = list->head;
	node_char_t *tail = list->tail;

	if( list->head->next == NULL){
		printf("	| ! List : Not found node in list\n");
		return NULL;
	}

	node_char_t *index_node = list->head->next;

	while( index_node != NULL){
		if( ( memcmp( index_node->data, data, sizeof( data))) == 0){
			return index_node;
		}

		index_node = index_node->next;
	}

	return NULL;
}

char* dlist_char_find_first_node_data( dlist_char_t *list){
	return ( list->head->next != list->tail)? list->head->next->data : NULL;
}

char* dlist_char_find_last_node_data( dlist_char_t *list){
	return ( list->tail->prev != list->head)? list->tail->prev->data : NULL;
}

node_char_t* dlist_char_find_last_node( dlist_char_t *list){
	return ( list->tail->prev != list->head)? list->tail->prev : NULL;
}

node_char_t* dlist_char_get_prev_node( dlist_char_t *list, node_char_t *target){
	if( target == NULL){
		return NULL;
	}

	node_char_t *node = dlist_char_find_node_by_node( list, target);
	if( node == NULL || node->prev == NULL){
		return NULL;
	}

	return node->prev;
}

void dlist_char_print_all( dlist_char_t *list){
	node_char_t *head = list->head;
	node_char_t *tail = list->tail;

	if( list->head->next == NULL){
		printf("	| ! List : Not found node in list\n");
		return ;
	}

	node_char_t *index_node = list->head->next;
	
	while( index_node != tail){
		printf("	PRINT	| index_node->data : %s\n", index_node->data);
		index_node = index_node->next;
	}
}

