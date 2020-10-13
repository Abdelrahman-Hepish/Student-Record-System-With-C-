#include "system.h"
#include "student.h"
#include "admin.h"
int main() {
    Init_Data();
    do {
        switch (Init_System()) {
            case ADMIN :
                Admin_System();
                break;
            case STUDENT :
                Student_System();
                break;
            default:
                /* should not be here */
                break;
        }
    }while (Ask_For_Resumption("the system ") == Resume);

    return 0;
}