#include "funcionalidad.h"

using namespace std;

int main()
{
    bool ban_inicio= menu();
    while(ban_inicio){
        ban_inicio= juego();
    }
    cout<<"Que lastima que te vayas"<<endl;
    cout<<"Vuelve pronto!"<<endl;
    return 0;
}
