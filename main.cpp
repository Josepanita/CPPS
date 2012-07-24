#include "dscript.h"
#include "stdlib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
using namespace dscript;

int main(int argc,char* argv[])
{
    context ctx;
    
    link_stdlib(ctx);

    if(argc > 1) {
		if(strcmp(argv[1], "-l") == 0){
			
	    	ctx.enable_logging(&cout);
	    	ctx.dump_file(cout, argv[2]);
	    	ctx.compile(argv[2]);
	   		ctx.exec_compiled(argv[2]);

	    }else{
	   		ctx.compile(argv[1]);
	   		ctx.exec_compiled(argv[1]);
	   	}
	}else{
		printf("Error, argumentos invalidos\n"
				"		%s <archivo>... [- <arg1>...]		: compila y ejecuta un programa\n"
				"		%s -l <archivo>... [- <arg1>...]	: crea un log de ejecucion \n", argv[0],argv[0]);
        exit(1);
	}

    return 0;
}
