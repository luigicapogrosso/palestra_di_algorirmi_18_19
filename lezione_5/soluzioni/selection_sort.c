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
void selection_sort(struct list_t *list);
// =============================================================================
void exchange(int *n1, int *n2);
// =============================================================================
void print_list(struct list_t *list);
// =============================================================================
int main(int argc, char const *argv[]) {

    struct list_t *list1;
    list1 = construct(2,
                construct(3,
                    construct(4,
                        construct(98,
                            construct(56,
                                construct(21,
                                    construct(72,
                                        construct(-99, NULL))))))));
    printf("La lista è: ");
    print_list(list1);
    selection_sort(list1);
    printf("La lista ordinata è: ");
    print_list(list1);
}
// =============================================================================
struct list_t *construct(int num, struct list_t *node1) {
    struct list_t *node2 = (struct list_t *) malloc(sizeof(struct list_t));

    node2 -> value = num;
    node2 -> next = node1;

    return node2;
}
// =============================================================================
void selection_sort(struct list_t *list) {
    struct list_t *current;

    while (list != NULL) {
        current = list -> next;

        while (current != NULL) {
            if (list -> value > current -> value) {
                exchange(&(list -> value), &(current -> value));
            }
            current = current -> next;
        }

        list = list -> next;
    }
}
// =============================================================================
void exchange(int *n1, int *n2) {
    int n;
    n = *n1;
    *n1 = *n2;
    *n2 = n;
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
