#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

/**
 *@defgroup list
 *
 *@author Jesper Andersson
 *@date 21/11-2020
 *
 *@brief Making a double linked list
 *
 *This is a program made for making doubly linked lists and managing them.
 *With it you can freely enter values into the list and delete them with
 *the help of the nodes position in the list.
 *
 * @{
 */

// The type for a node in the list.
struct node
{
    struct node *next;
    struct node *prev;
    char *value;
};

// The type for a list.
typedef struct list
{
    struct node head;
} List;

// The type for a list position.
typedef struct list_pos
{
    struct node *node;
} ListPos;

/**
 * @brief Create and return an empty list.
 * 
 * Allocates size to the list and initializes the nodes different states.
 * 
 * @return An empty list.
 */
List *list_create(void);

/**
 * @brief Deallocate the list (and all of its values, if any).
 * 
 * Deallocates the list and all of its values, if any, by calling the function
 * list_is_empty in a while loop. If it is not empty it deallocates node by node
 * until the list is empty and when there is a empty list it deallocates the
 * list itself.
 * 
 * @param lst A struct List.
 */
void list_destroy(List *lst);

/** 
 * @brief Check if the list is empty.
 * 
 * Checks the list if it is empty by comparing the first node and the last node.
 * 
 * @param lst A const struct List.
 * @return A Boolean value depending on if it is empty or not.
 */
bool list_is_empty(const List *lst);

/**
 * @brief Get the position of the first element.
 * 
 * Get the position of the first element by checking what the first node is
 * pointing to.
 * 
 * @param lst A struct List.
 * @return The position of the first element in the list.
 */
ListPos list_first(List *lst);

/** 
 * @brief Get the position after(!) the last element.
 * 
 * Get the position after(!) the last element by checking the address of what
 * the current node is pointing to.
 * 
 * @param lst A struct List.
 * @return The postion after the last element in the list.
 */
ListPos list_end(List *lst);

/**
 * @brief Check equality between two positions.
 * 
 * Check equality beetwen two positions by comparing the position the nodes are
 * pointing to.
 * 
 * @param p1 A position in the list.
 * @param p2 A position in the list.
 * @return A Boolean value depending on wether the positions are equal or not.
 */
bool list_pos_equal(ListPos p1, ListPos p2);

/**
 * @brief Forward to the next position.
 * 
 * Forward to the next position by pointing the ListPos to the next node in the
 * list.
 * 
 * @param pos The current ListPos.
 * @return The next ListPos.
 */
ListPos list_next(ListPos pos);

/**
 * @brief Backward to the previous position.
 * 
 * Backward to the previous position by pointing the ListPos to the 
 * previous node in the list.
 * 
 * @param pos The current ListPos.
 * @return The previous ListPos.
 */
ListPos list_prev(ListPos pos);

/**
 * @brief Insert the value before the position and return the position 
 * of the new element.
 * 
 * Insert the value before the position and return the position 
 * of the new element. By making a new node linking it with the previous and
 * next node in the list. May be the same node if its the head of the list.
 * 
 * @param pos The position that you want to insert the value before.
 * @param value The string you want the node to contain.
 * @return The position of the new element.
 */
ListPos list_insert(ListPos pos, const char *value);

/**
 * @brief Remove the value at the position and return the position of 
 * the next element.
 * 
 * Remove the value at the position and return the position of 
 * the next element. Make a temporay node to store the position of the node
 * and free the value of the node by the way of pointers. Link the nodes
 * previous and next position to keep it a linked list and finally free the node
 * completely.
 * 
 * @param pos The position of the value you want removed.
 * @return The position of the next element.
 */
ListPos list_remove(ListPos pos);

/**
 * @brief Get the value at the position.
 * 
 * Get the value at the position by reading the current nodes value and storing
 * it in const char.
 * 
 * @param pos The position of the value.
 * @return The value of the node.
 */
const char *list_inspect(ListPos pos);

/**
 *  @}
 */
#endif /* LIST_H */