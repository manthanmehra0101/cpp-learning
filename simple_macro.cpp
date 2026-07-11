#include <iostream>
#define PR_DEBUG 1
/* changing  mode into debug or release via code if not provided in
code editor */ 
//simple example
#ifdef PR_DEBUG
#define p(x) std::cout << x << "\n"
#elif defined(PR_RELEASE)
#define p(x)
#endif

/* stupid example */
#define STOP std::cin.get()

int main(){
    p("Hi, Console!");//simple
    p(100);//simple
    STOP;//dumb
    return 0;
}
