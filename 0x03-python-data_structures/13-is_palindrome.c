#include "lists.h"
#include <stdlib.h>

/**
 * to_array - transform a linked lists into an array of nodes
 *
 * @head: head of the list
 *
 * @length: a pointer where the length of the array would
 *		be stored.
 *
 * Return: Array on node pointers or NULL if malloc failed.
 */
int *to_array(listint_t *head, size_t *length)
{
	int *array;
	size_t arr_size = ARRSIZE, i = 0;
	listint_t *temp = head;

	if (!head)
		return (NULL);
	array = malloc(sizeof(int) * arr_size);
	if (!array)
		return (NULL);

	while (temp)
	{
		if (i == arr_size - 1)
		{
			arr_size += 5;
			array = realloc(array, sizeof(int) * arr_size);
			if (!array)
				return (NULL);
		}
		array[i++] = temp->n;
		temp = temp->next;
	}
	*length = i;
	return (array);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 *
 * @head: the address of the head of the list.
 *
 * Return: 0 if the list is not a palindrome, 1 if it is a palindrome.
 *
 * NOTE: An empty list is considered a palindrome.
 */
int is_palindrome(listint_t **head)
{
	size_t len = 0;
	int *arr, ind = 0, rnd;

	arr = to_array(*head, &len);
	if (!arr)
		return (1);
	rnd = len - 1;
	while (ind < rnd)
		if (arr[ind++] != arr[rnd--])
		{
			free(arr);
			return (0);
		}
	free(arr);
	return (1);
}
