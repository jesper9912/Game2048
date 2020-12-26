#include <stdlib.h>
#include <string.h>
#include "list.h"

static char *clone_string(const char *in)
{
    size_t len = strlen(in);
    char *out = calloc(len + 1, sizeof(char));
    strcpy(out, in);
    return out;
}


static struct node *make_node(const char *value)
{   
    struct node *first = malloc(sizeof(*first));

    first->value = clone_string(value);
    first->next = NULL;
    first->prev = NULL;

    return first;
}


List *list_create(void)
{   
    List *lst = malloc(sizeof(*lst));

    lst->head.value = NULL;
    lst->head.next = &lst->head;
    lst->head.prev = &lst->head;

    return lst; 
}


void list_destroy(List *lst)
{   
    while (!list_is_empty(lst)) {
        ListPos p = list_first(lst);

        list_remove(p);
    }
    free(lst);
    
}


bool list_is_empty(const List *lst)
{
    return &lst->head == lst->head.next;
}


ListPos list_first(List *lst)
{
    ListPos pos = {
        .node = lst->head.next
    };
    return pos;
}


ListPos list_end(List *lst)
{
    ListPos pos = {
        .node = &lst->head
    };
    return pos;
}


bool list_pos_equal(ListPos p1, ListPos p2)
{
    return p1.node == p2.node;
}


ListPos list_next(ListPos pos)
{
    ListPos nextpos = {
        .node = pos.node->next

    };

    return nextpos;
}


ListPos list_prev(ListPos pos)
{
    ListPos prevpos = {
        .node = pos.node->prev

    };

    return prevpos;
}


ListPos list_insert(ListPos pos, const char *value)
{
    // Create a new node.
    struct node *node = make_node(value);

    // Find nodes before and after (may be the same node: the head of the list).
    struct node *before = pos.node->prev;
    struct node *after = pos.node;

    // Link to node after.
    node->next = after;
    after->prev = node;

    // Link to node before.
    node->prev = before;
    before->next = node;

    // Return the position of the new element.
    pos.node = node;
    return pos;
}


ListPos list_remove(ListPos pos)
{   
    struct node *n = pos.node;

    n->prev->next = n->next;
    n->next->prev = n->prev;
    
    free(n->value);

    pos.node = n->next;
   
    free(n);

    return pos;
}


const char *list_inspect(ListPos pos)
{
    const char *value = pos.node->value;

    return value;
}