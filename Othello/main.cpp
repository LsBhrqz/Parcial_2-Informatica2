#include "funcionalidad.h"

using namespace std;

int main()
{
    bool ban_inicio= menu();
    while(ban_inicio){
        ban_inicio= juego();
    }
    cout<<"\nQue lastima que te vayas"<<endl;
    cout<<"Vuelve pronto!\n"<<endl;
    return 0;
}
