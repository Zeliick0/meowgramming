#include "list.h"

#include <stdio.h>
#include <stdlib.h>

Item *init_item(Enemy *value)
{
    Item *item = malloc(sizeof(*item));
    if (item == NULL) {
        fprintf(stderr, "Unable to allocate memory.");
        return NULL;
    }

    item->value = value;
    item->next = NULL;

    return item;
}

List *init_list(char *name, Item *first)
{
    List *list = malloc(sizeof(*list));
    if (list == NULL) {
        fprintf(stderr, "Unable to allocate memory.");
        return NULL;
    }

    list->name = name;
    list->first = first;

    return list;
}

int append(List *list, Item *item)
{
    if (list == NULL) {
        fprintf(stderr, "Unable to append to a nonexisting list.");
        return 1;
    }
    
    Item *current_item = list->first;

    while (current_item->next != NULL) {
        current_item = current_item->next;
    }

    current_item->next = item;

    return 0;
}

Item *search(List *list, int index)
{
    Item *current_item = list->first;

    for (int i = 0; i <= index; i++) {
        current_item = current_item->next;

        if (current_item == NULL) {
            fprintf(stderr, "Invalid index.");
            return NULL;
        }
    }

    return current_item;
}

int remove_item(List *list, int index)
{
    if (index == 0) {
        Item *to_remove = list->first;
        list->first = list->first->next;
        item_deinit(to_remove);

        return 0;
    }

    Item *previous = list->first;
    Item *current = previous->next;

    for (int i = 0; i < index; i++) {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;
    
    item_deinit(current);

    return 0;
}

void item_deinit(Item *item)
{
    if (item != NULL) {
        free(item);
    }
}

void list_deinit(List *list)
{
    Item *temp = list->first;

    while (list->first != NULL) {
        list->first = temp->next;
        item_deinit(temp);
        temp = list->first;
    }

    if (list != NULL) {
        free(list);
    }
}
