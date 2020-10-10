#include <stdio.h>
#include "system.h"
int main() {
    /* initialization */
    tmode  mode = admin ;
    int id = 0 ;
    do {
        switch (Init_System()) {
            case admin :
                Admin_System();
                break;
            case student :
                Student_System();
                break;
            default:
                /* should not be here */
                break;
        }
    }while (Ask_For_Resumption("in the system ") == Resume);

    return 0;
}