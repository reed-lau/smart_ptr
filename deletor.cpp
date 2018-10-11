#include <memory>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {

    shared_ptr<int> g_sp;
    {
        char *other = (char*)malloc(1024000000);
        printf("after new p = %p\n", other);
        memset(other, 0, 1024000000);
        shared_ptr<int> sp(new int(1), [&other](int *c){

                   memset(other, 1, 1024000000);
                   printf("in deletor other = %p\n", other);
                   std::cout<<"aaaa"<<std::endl;

                   memset(other, 3, 1024000000);
                });

        free(other);

        g_sp = sp;
    }

    std::cout<< "xxx" << std::endl;
}
