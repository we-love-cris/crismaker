#pragma once
#include "declare.h"
#include "util.h"

typedef struct linked_list {
	struct linked_list * prev;
	struct linked_list * next;
	char* content;
} ll;


int text_edit_main(status* game);

int editing_file(int prev_number);

ll* making_ll(ll* prev_line);
void deleting_ll(ll* line);

int get_input();
int char_delete(char* content, int at);
void char_input(char* content, int at, int input);
int is_hangeul(int what);