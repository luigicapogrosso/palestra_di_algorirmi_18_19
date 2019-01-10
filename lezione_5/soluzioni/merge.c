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
struct list_t *merge_list(struct list_t *list1, struct list_t *list2);
// =============================================================================
void selection_sort(struct list_t *list);
// =============================================================================
void exchange(int *n1, int *n2);
// =============================================================================
void print_list(struct list_t *list);
// =============================================================================
int main(int argc, char const *argv[]) {

    struct list_t *list1;
    struct list_t *list2;
    struct list_t *list3 = NULL;

    list1 = construct(2,
                construct(3,
                    construct(4,
                        construct(98,
                            construct(56,
                                construct(21,
                                    construct(72,
                                        construct(-99, NULL))))))));

    list2 = construct(123,
                construct(54,
                    construct(43,
                        construct(987,
                            construct(125,
                                construct(5,
                                    construct(0,
                                        construct(-98, NULL))))))));
    printf("La lista 1 è: ");
    print_list(list1);

    printf("La lista 2 è: ");
    print_list(list2);

    printf("Il merge ordinato fra lista 1 e lista 2: ");
    list3 = merge_list(list1, list2);
    selection_sort(list3);
    print_list(list3);
}
// =============================================================================
struct list_t *construct(int num, struct list_t *node1) {
    struct list_t *node2 = (struct list_t *) malloc(sizeof(struct list_t));

    node2 -> value = num;
    node2 -> next = node1;

    return node2;
}
// =============================================================================
struct list_t *merge_list(struct list_t *list1, struct list_t *list2) {
    if (list1 == NULL && list2 == NULL) {
        return NULL;
    } else if(list1 == NULL) {
        return list2;
    } else if(list2 == NULL) {
        return list1;
    } else {
        if (list1 -> value <= list2 -> value) {
            return construct(list1 -> value, merge_list(list1 -> next, list2));
        } else {
            return construct(list2 -> value, merge_list(list1, list2 -> next));
        }
    }
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
