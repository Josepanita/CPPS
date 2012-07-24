#include "dscript.h"
#include "stdlib.h"
#include <stdio.h>

using namespace std;
using namespace dscript;

int main(int argc,char* argv[])
{
    context ctx;
//    ctx.enable_logging(&cout);
    link_stdlib(ctx);

  //  ctx.dump_file(cout, "test.txt");
	if(argc > 1) {
	    ctx.compile(argv[1]);
	    ctx.exec_compiled(argv[1]);
	}else{
		printf("Formato: ./dscript <archivo>");
	}

    return 0;
}
