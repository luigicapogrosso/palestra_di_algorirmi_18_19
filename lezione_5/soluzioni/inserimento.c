#include <stdio.h>
#include <stdlib.h>
// =============================================================================
struct list_t {
    int value;
    struct list_t *next;
};
// =============================================================================
struct list_t *construct(int num, struct list_t *node1);
// =============================================================================
struct list_t *insert_on_head(struct list_t *list, int num);
// =============================================================================
struct list_t *insert_on_tail(struct list_t *list, int num);
// =============================================================================
void print_list(struct list_t *list);
// =============================================================================
int main(int argc, char const *argv[]) {
    int i;
    struct list_t *list1 = NULL;
    struct list_t *list2 = NULL;

    // Utilizzo della funzione insert_on_head
    for (i = 0; i < 10; i++) {
        list1 = insert_on_head(list1, i);
    }
    printf("La lista 1 è: ");
    print_list(list1);

    // Utilizzo della funzione insert_on_tail
    for (i = 0; i < 10; i++) {
        list2 = insert_on_tail(list2, i);
    }
    printf("La lista 2 è: ");
    print_list(list2);
}
// =============================================================================
struct list_t *construct(int num, struct list_t *node1) {
    struct list_t *node2 = (struct list_t *) malloc(sizeof(struct list_t));

    node2 -> value = num;
    node2 -> next = node1;

    return node2;
}
// =============================================================================
void print_list(struct list_t *list) {
    if (list == NULL) {
        printf("La lista è vuota!\n");
    } else {
        struct list_t *current = list;

        printf("[");

        while (current -> next != NULL) {
            printf("%i ", current -> value);
            current = current -> next;
        }

        printf("%i]\n", current -> value);
    }
}
// =============================================================================
struct list_t *insert_on_head(struct list_t *list, int num) {
    if (list == NULL) {
        return construct(num, NULL);
    } else {
        return construct(num, list);
    }
}
// =============================================================================
struct list_t *insert_on_tail(struct list_t *list, int num) {
    if (list == NULL) {
        return construct(num, NULL);
    } else {
        struct list_t *current = list;

        while (current -> next != NULL) {
            current = current -> next;
        }
        current -> next = construct(num, (current -> next));

        return list;
    }
}
// =============================================================================
