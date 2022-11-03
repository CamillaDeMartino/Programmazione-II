#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct node_elem {
	short info;
	short row;
	short column;
	struct node_elem *next_elem;
};

struct node_row {
	short row_num;
	struct node_row *next_row;
	struct node_elem *first_elem;
};

typedef struct node_elem ELEMENT;
typedef ELEMENT *ELINK;
ELINK ehead, epunt;

typedef struct node_row ROW;
typedef ROW *LINK;
LINK head, punt;

void *make_rows();
void mat_1_maker(short, short);
void head_inseriment(short, ROW *, ROW **);
void elem_inseriment(short, ELEMENT *, ELEMENT **);

int main()
{
    srand(time(NULL));
	head = (ROW *)make_rows();
    mat_1_maker(4, 5);

    punt = head;
    while(punt != NULL) {
        printf("Row %hd\t -> ", punt->row_num);

        if((epunt = ehead) == NULL)
        {
            printf("Empty row..\n");
        }
        else
            {
            while(epunt != NULL)
            {
                printf("Elem: %hd\t", epunt->info);
                epunt = epunt->next_elem;
            }
        }

        punt = punt->next_row;
        printf("\n");
    }
    return 0;
}



void *make_rows()
{
	char *head = NULL;
	return head;
}

void mat_1_maker(short rows, short columns) {
    short i = 0, j = 0;
    ROW *row_ptr;
    ELEMENT *ele_ptr;

    for(i = 0; i < rows; i++) {
        if(rand()%2 == 0) {
            row_ptr = (ROW *)calloc(1, sizeof(ROW));
            row_ptr->row_num = i;
            row_ptr->first_elem = (ELEMENT *)calloc(1, sizeof(ELEMENT));

            ehead = NULL;

            head_inseriment(sizeof(ROW), row_ptr, &head);

            for(j = 0; j < columns; j++) {
                if(rand()%2 != 0) {
                    (row_ptr->first_elem)->info = rand() % 100;
                    (row_ptr->first_elem)->row = i;
                    (row_ptr->first_elem)->column = j;

                    elem_inseriment(sizeof(ELEMENT), row_ptr->first_elem, &ehead);
                }
            }

            free(row_ptr->first_elem);
            free(row_ptr);
        }
    }
}

void head_inseriment(short len_info, ROW *data, ROW **head) {
    ROW *ptr = (ROW *)calloc(1, sizeof(ROW));
    memcpy(ptr, data, len_info);

    ptr->next_row = *head;
    *head = ptr;
}

void elem_inseriment(short len_info, ELEMENT *data, ELEMENT **ehead) {
    ELEMENT *ptr = (ELEMENT *)calloc(1, sizeof(ELEMENT));
    memcpy(ptr, data, len_info);

    ptr->next_elem = *ehead;
    *ehead = ptr;
}
