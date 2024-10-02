#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elem {
    struct elem* prec;
    int val;
    struct elem* svt;
} telement;
typedef telement* tlisteDC;

void initListeDC(tlisteDC liste) {
    liste->prec = NULL;
    liste->val = 0;
    liste->svt = NULL;
}
  
int main() {
    tlisteDC lDC;
    initListeDC(lDC);

    return 0;
}