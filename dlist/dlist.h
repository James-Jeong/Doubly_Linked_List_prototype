#pragma once
#ifndef __DLIST_H__
#define __DLIST_H__

#include "../common.h"

#define LIST_MAX_LEN 1024


/// @struct node_t
/// @brief 리스트의 구성 요소(노드) 구조체
typedef struct node_s node_t;
struct node_s{
	/// 이전 노드 객체
	struct node_s *prev;
	/// 다음 노드 객체
	struct node_s *next;
	/// 사용자 정의 data
	int data;
};

/// @struct dlist_t
/// @brief 이중 연결 리스트를 관리하기 위한 구조체
typedef struct dlist_s dlist_t;
struct dlist_s{
	/// 리스트 첫번째 노드 객체
	node_t *head;
	/// 리스트 마지막 노드 객체
	node_t *tail;
	/// 사용자 정의 data
	void *data;
};


dlist_t* dlist_create();
void dlist_destroy( dlist_t *list);
int dlist_add_node( dlist_t *list, int data);
int dlist_del_node_by_node( dlist_t *list, node_t *target);
int dlist_del_node_by_data( dlist_t *list, int data);
node_t* dlist_find_node_by_node( dlist_t *list, node_t *target);
int dlist_find_node_data_by_node( dlist_t *list, node_t *target);
node_t* dlist_find_node_by_data( dlist_t *list, int data);
int dlist_find_first_node_data( dlist_t *list);
int dlist_find_last_node_data( dlist_t *list);
void dlist_print_all( dlist_t *list);

node_t* node_create();
void node_destroy( node_t *node);

#endif

