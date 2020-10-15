/*
 * Copyright (c) 2020 RogerYu.
 */

//#define LOG_NDEBUG 0
#define LOG_TAG "SmartPointer"

#include <utils/RefBase.h>
#include <utils/Log.h>
#include <stdlib.h>

using namespace android;

class Foo : public RefBase {
public:
    Foo(int id) : mId(id) {
        fprintf(stderr, "construct Foo(%d) instance\n", mId);
    }

    ~Foo() {
        fprintf(stderr, "release Foo(%d) instance\n", mId);
    }

private:
    int mId;
};

sp<Foo> pFoo_3;

bool mQuit = false;
void sighandler(int num)
{
    if(num == SIGINT) {
        mQuit = true;
    }
}


int main(int argc, char ** argv)
{
    signal(SIGINT, sighandler);
    
    // new 和 delete成对存在，避免内存泄漏
    fprintf(stderr, "------------------------------\nTEST-1\n");
    Foo* pFoo_1 = new Foo(1);
    delete pFoo_1;
    
    
    
    {
        // 代码块中的局部变量，代码块结束时，回收变量
        fprintf(stderr, "------------------------------\nTEST-2\n");
        sp<Foo> pFoo_2 = new Foo(2);
    }
    
    
    // 全局变量在程序结束时回收
    fprintf(stderr, "------------------------------\nTEST-3\n");
    pFoo_3 = new Foo(3); 
    
    do {
        usleep(10000);
    } while(!mQuit);
    
    
    return 0;
}