#ifndef LINKEDLIST
#define LINKEDLIST
#include "entity.h"
typedef struct item Item;
struct item {
    Enemy *value;
    Item *next;
};

typedef struct {
    char *name;
    Item *first;
} List;

Item *init_item(Enemy *value);
List *init_list(char *name, Item *first);
int append(List *list, Item *item);
int remove_item(List *list, int index);
Item *search(List *list, int index);
void item_deinit(Item *item);
void list_deinit(List *list);

#endif
