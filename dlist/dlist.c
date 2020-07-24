#include "dlist.h"

static node_t* node_create(){
	node_t *node = ( node_t*)malloc( sizeof( node_t));
	if( node == NULL){
		return NULL;
	}

	node->prev = NULL;
	node->next = NULL;

	node->data = 0;

	return node;
}

static void node_destroy( node_t *node){
	if( node){
		node->prev = NULL;
		node->next = NULL;

		free( node);
	}
}


dlist_t* dlist_create(){
	dlist_t *list = ( dlist_t*)malloc( LIST_MAX_LEN);
	if( list == NULL){
		printf("	| ! List : Fail to create list object\n");
		return NULL;
	}

	// dummy head
	list->head = node_create();
	if( list->head == NULL){
		printf("	| ! List : Fail to create head node object\n");
		free( list);
		return NULL;
	}

	// dummy tail
	list->tail = node_create();
	if( list->tail == NULL){
		printf("	| ! List : Fail to create head tail object\n");
		free( list);
		return NULL;
	}

	list->head->prev = NULL;
	list->head->next = list->tail;

	list->tail->prev = list->head;
	list->tail->next = NULL;

	return list;
}

void dlist_destroy( dlist_t *list){
	if( list){
		node_t *index_node = list->head;
		while( index_node->next != list->tail){
			index_node = index_node->next;
			dlist_del_node_by_node( list, index_node);
		}

		free( list);
	}
}

int dlist_add_node( dlist_t *list, int data){
	node_t *new_node = node_create();
	if( new_node == NULL){
		printf("	| ! List : Fail to create node object in dlist_add_node\n");
		return OBJECT_ERR; 
	}

	if( list->head->next == list->tail){
		list->head->next = new_node;
		new_node->next = list->tail;
		new_node->prev = list->head;
		list->tail->prev = new_node;
	}
	else if( ( list->head->next != list->tail) && ( list->tail->prev != NULL)){
		node_t *old_node = list->tail->prev;

		old_node->next = new_node;
		new_node->prev = old_node;

		list->tail->prev = new_node;
		new_node->next = list->tail;
	}
	else{
		printf("	| ! List : unknown case in dlist_add_node\n");
		return UNKNOWN;
	}

	new_node->data = data;

	return NORMAL;
}

int dlist_del_node_by_node( dlist_t *list, node_t *target){
	node_t *head = list->head;
	node_t *index_node = list->head->next;
	node_t *tail = list->tail;

	while( index_node->next != tail){
		if( index_node == target){
			if( index_node->prev == head){
				head->prev = index_node->next;
				index_node->next->prev = head;
			}
			else if( index_node->next == tail){
				tail->next = index_node->prev;
				index_node->prev->next = tail;
			}
			else{
				index_node->prev->next = index_node->next;
				index_node->next->prev = index_node->prev;
			}

			node_destroy( index_node);
			break;
		}

		index_node = index_node->next;
	}

	return NORMAL;
}

int dlist_del_node_by_data( dlist_t *list, int data){
	node_t *head = list->head;
	node_t *index_node = list->head->next;
	node_t *tail = list->tail;

	while( index_node->next != tail){
		if( index_node->data == data){
			if( index_node->prev == head){
				head->prev = index_node->next;
				index_node->next->prev = head;
			}
			else if( index_node->next == tail){
				tail->next = index_node->prev;
				index_node->prev->next = tail;
			}
			else{
				index_node->prev->next = index_node->next;
				index_node->next->prev = index_node->prev;
			}

			node_destroy( index_node);
			break;
		}

		index_node = index_node->next;
	}

	return NORMAL;
}

node_t* dlist_find_node_by_node( dlist_t *list, node_t *target){
	node_t *head = list->head;
	node_t *index_node = list->head->next;
	node_t *tail = list->tail;

	while( index_node->next != tail){
		if( index_node == target){
			return index_node;
		}

		index_node = index_node->next;
	}

	return NULL;
}

int dlist_find_node_data_by_node( dlist_t *list, node_t *target){
	node_t *head = list->head;
	node_t *index_node = list->head->next;
	node_t *tail = list->tail;

	while( index_node->next != tail){
		if( index_node == target){
			return index_node->data;
		}

		index_node = index_node->next;
	}

	return NOT_EXIST;
}

node_t* dlist_find_node_by_data( dlist_t *list, int data){
	node_t *head = list->head;
	node_t *index_node = list->head->next;
	node_t *tail = list->tail;

	while( index_node->next != tail){
		if( index_node->data == data){
			return index_node;
		}

		index_node = index_node->next;
	}

	return NULL;
}

int dlist_find_first_node_data( dlist_t *list){
	return ( list->head->next != list->tail)? list->head->next->data : NOT_EXIST ;
}

int dlist_find_last_node_data( dlist_t *list){
	return ( list->tail->prev != list->head)? list->tail->prev->data : NOT_EXIST ;
}

void dlist_print_all( dlist_t *list){
	node_t *head = list->head;
	node_t *index_node = list->head->next;
	node_t *tail = list->tail;

	printf("	| @ List : ");
	while( index_node->next != tail){
		printf("%d ", index_node->data);

		index_node = index_node->next;
	}
	printf("\n");
}

