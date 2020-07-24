#pragma once
#ifndef __DLIST_PTR_H__
#define __DLIST_PTR_H__

#include "../common.h"

#define BUF_MAX_LEN 100
#define NODE_MAX_SIZE 1000
#define LIST_MAX_SIZE 1024


/// @struct buf_t
/// @brief proxy 에서 thread 별 user buffer 관리를 위한 구조체
typedef struct node_char_s node_char_t;
struct node_char_s{
	/// 사용자 정의 data
	char data[ BUF_MAX_LEN];
	/// 이전 노드 객체
	struct node_char_s *prev;
	/// 다음 노드 객체
	struct node_char_s *next;
};

/// @struct buf_t
/// @brief proxy 에서  위한 구조체
typedef struct dlist_char_s dlist_char_t;
struct dlist_char_s{
	/// 리스트 노드 객체 개수
	int length;
	/// 리스트 첫번째 노드 객체 (dummy)
	node_char_t head[ 1];
	/// 리스트 마지막 노드 객체 (dummy)
	node_char_t tail[ 1];
	/// 사용자 정의 data
	void *data;
};


dlist_char_t* dlist_char_create();
void dlist_char_init( dlist_char_t *list);
void dlist_char_destroy( dlist_char_t *list);
int dlist_char_add_node( dlist_char_t *list, char *data);
int dlist_char_del_node_by_node( dlist_char_t *list, node_char_t *target);
int dlist_char_del_node_by_data( dlist_char_t *list, char *data);
node_char_t* dlist_char_find_node_by_node( dlist_char_t *list, node_char_t *target);
char* dlist_char_find_node_data_by_node( dlist_char_t *list, node_char_t *target);
node_char_t* dlist_char_find_node_by_data( dlist_char_t *list, char *data);
char* dlist_char_find_first_node_data( dlist_char_t *list);
char* dlist_char_find_last_node_data( dlist_char_t *list);
node_char_t* dlist_char_find_last_node( dlist_char_t *list);
node_char_t* dlist_char_get_prev_node( dlist_char_t *list, node_char_t *target);
void dlist_char_print_all( dlist_char_t *list);

#endif

