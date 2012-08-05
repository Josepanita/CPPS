#include "dscript.h"
#include "stdlib.h"
#include <fstream>

using namespace std;
using namespace dscript;

int main(int argc,char* argv[])
{	
	std::ofstream file ("logs/output.log");

    context ctx;
    ctx.enable_logging(&cout);
    link_stdlib(ctx);

   	//ctx.dump_file(file, "tests/99_test.cpps");
    //ctx.compile("tests/99_test.cpps");
    ctx.exec("tests/99_test.cpps");

    return 0;
}


// int main(int argc,char* argv[])
// {
//     context ctx;
    
//     link_stdlib(ctx);
	
	
//     if(argc > 1) {
// 		if(strcmp(argv[1], "-l") == 0){
	    	
// 	    	std::ofstream file ("logs/output.log");
// 	    	file << "Log"<<endl;
// 	    	ctx.enable_logging(&file);

//     		ctx.compile(argv[2]);
   			
//    			ctx.exec_compiled(argv[2]);
   			
//    			ctx.dump_file(file, argv[2]);

// 	    }else if(strcmp(argv[1], "-i") == 0){
			
// 	    	printf("CPPS V1.0\n");

// 	    }else{
// 	   		ctx.compile(argv[1]);
// 	   		ctx.exec_compiled(argv[1]);
// 	   	}
// 	}else{
// 		printf("Error, argumentos invalidos\n"
// 				"		%s <archivo>... [- <arg1>...]		: compila y ejecuta un programa\n"
// 				"		%s -l <archivo>... [- <arg1>...]	: crea un log de ejecucion \n", argv[0],argv[0]);
//         exit(1);
// 	}

//     return 0;
// }
