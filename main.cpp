#include "dscript.h"
#include <stdlib.h>
#include "stdlib.h"
#include <fstream>

using namespace std;
using namespace dscript;

int main(int argc,char* argv[])
{	
    context ctx;
    ctx.enable_logging(&cout);
    link_stdlib(ctx);

    if(argc > 1) {
      ctx.exec(argv[1]);
    }else{
      printf("Error, argumentos invalidos\n"
        "   cpps <archivo>... [- <arg1>...]   : ejecuta un programa\n");
         exit(1);
    }

    return 0;
}