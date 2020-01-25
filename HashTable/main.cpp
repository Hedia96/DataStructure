#include<iostream>
#include<string>
#include"hash_interface.h"
using namespace std;
int main()
{
  
    Hash hashobj;
    int r;
    r=hashobj.Hash_Function("a");
    cout<<"the return index is "<<r<<endl;
   
    hashobj.Hash_AddItem("k");
    hashobj.Hash_AddItem("a");
    hashobj.Hash_DisplayTable();
    return 0;
}