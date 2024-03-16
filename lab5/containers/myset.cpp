#include "myset.h"

void MySet::add_element(const char *el) {
    if (q_find(el) != -1) return;
    size++;
    resize();
    int ind = 0;
    while (strcmp(pdata[ind], el) < 0) {
        ind++;
    }
    for (int i = size - 1; i > ind; i--) {
        strcpy(pdata[i], pdata[i - 1]);
    }
    strcpy(pdata[ind], el);
}
