#include<iostream>
#include<string>
using namespace std;

#include"hash_interface.h"

/* this function get the index from a certain key (string) through some algorithm


*/
Hash :: Hash()
{
    //size_HashTable=100;
    //create the items of hashtable and initalize them 
    for(int i=0;i<size_HashTable;i++)
    {
        hashtable[i]=new item;
        hashtable[i]->key="Empty";
        hashtable[i]->next=NULL;
    }
  //  hashtable[3]->next->key="lkffkk";
}
void Hash :: Hash_AddItem(string key)
{
    //get the index from the key via the hash function code
    int index=Hash_Function(key);
    cout<<"index is "<<index<<endl;
    
    if(hashtable[index]->key=="Empty")
    {
        hashtable[index]->key=key;
    }
    
    else
   {
        //create anode and append it 
        item* iterator=new item;
        iterator=hashtable[index];
        item * addeditem=new item;
        addeditem->key=key;
        addeditem->next=NULL;
        while(iterator->next!=NULL)
        {
            iterator=iterator ->next;
        }
        iterator->next=addeditem;
    }


    
}


void Hash :: Hash_DisplayTable(void)
{
    for(int i=0;i<size_HashTable;i++)
    {
       // cout<<"the key is"<<hashtable[i]->key;
        item* iterator= hashtable[i];
        cout<<iterator->key;
        while(iterator->next!=NULL)
        {
            iterator=iterator->next;
            cout<<" -> "<<iterator->key;
           
        }
        cout<<endl;
    }
        

    
}
    int Hash ::Hash_Function(string Key)
    {
        int sum=0;
        for(int i=0;i<Key.length();i++)
        {
            sum+=(int)Key[i];
        }
        //cout<<"ddddddddddddddddddd"<<endl;
        sum=sum%size_HashTable;
        return sum;
    }