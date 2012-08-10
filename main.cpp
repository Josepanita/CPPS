#include "dscript.h"
#include <stdlib.h>
#include "stdlib.h"
#include <fstream>
#include <cstring>

using namespace std;
using namespace dscript;

int main(int argc, char const *argv[])
{	
    context ctx;
    ctx.enable_logging(&cout);
    link_stdlib(ctx);

    if(argc > 1) {
        cout<<argv[1]<<endl;
      if( strcmp(argv[1], "-i") == 0){
        string input, aux;

        cout<<"CPPS Modo interactivo:"<<endl;
        
        do{
            cout << "cpps> ";
            getline(cin, input);

            if(input=="exit" || input=="salir"){
                cout<<"Saliendo del modo interactivo"<<endl;
                break;
            }else{
                if(input.at(input.size()-1) != ';'){
                    do{
                        cout << "    > ";
                        getline(cin, aux);
                        input = input + aux;
                    }while(aux.at(aux.size()-1) != ';');
                    
                }

                input = ctx.trim(input);
                ctx.eval(input);
                cout<<endl;
                
            }

        }while(1);

        }else{
            ctx.exec(argv[1]);
        }


    }else{
        printf("Error, argumentos invalidos\n"
            "   cpps <archivo>... [- <arg1>...]   : ejecuta un programa\n");
        exit(1);
    }

    return 0;
}