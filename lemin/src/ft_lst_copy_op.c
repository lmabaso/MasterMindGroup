#include "../includes/lem-in.h"

t_string *copy_string(t_string *L1)
{
     t_string *L2 = 0;
     t_string *preElem = 0;
     t_string *elem;

     while(L1 != 0)
     {
        if (!(elem = ft_memalloc(sizeof(t_string))))
            return (NULL);
        elem->str = ft_strdup(L1->str);
        elem->next = 0;
        if (L2 == 0)
        {
            L2 = elem;
            preElem = elem;
        }
        else
        {
            preElem->next = elem;
            preElem = elem;
		}
        L1 = L1->next;
    }
    return L2;
}

t_node      *ft_node_dup(t_node *L1)
{
    t_node *elem = NULL;

    elem = ft_memalloc(sizeof(t_node));
    if(elem == 0) {
        exit(1);
    }
    elem->data = L1->data;
    elem->data.f = L1->data.f;
    elem->data.g = L1->data.g;
    elem->data.neighbours = copy_string(L1->data.neighbours);
    elem->data.previous = NULL;
    elem->data.room_num = L1->data.room_num;
    elem->next = NULL;
    return (elem);
}

// t_node      *copy(t_node *L1)
// {
//      t_node *L2 = NULL;
//      t_node *preElem = NULL;
//      t_node *elem = NULL;

//      while(L1 != NULL) {
//           elem = ft_memalloc(sizeof(t_node));
//           if(elem == 0) {
//                exit(1);
//           }
//           elem->data = L1->data;
//           elem->data.f = L1->data.f;
//           elem->data.g = L1->data.g;
//           elem->data.neighbours = copy_string(L1->data.neighbours);
//           elem->data.previous = NULL;
//           elem->data.room_num = L1->data.room_num;
//           elem->next = NULL;
//           if (L2 == 0) {
//                 L2 = elem;
//                 preElem = elem;
//           }
//           else {
//                 preElem->next = elem;
//                 preElem = elem;
// 		  }
//           L1 = L1->next;
//     }
//     return L2;
// }