#include <iostream>
using namespace std;
char s[1000010];
struct node
{
    node* pre;
    node* next;
    int val;
    node(node* p=NULL,node*n=NULL,int v=-1){
        pre = p;
        next = n;
        val = v;
    }
    void insert(int x){
        node* p = new node(this,next,x);
        next->pre = p;
        next = p;
    }
}*head,*tail,*l,*r;
int main(){
    cin>>s;
    head = new node;
    tail = new node;
    head->next = tail;
    tail->pre = head;
    l = head;
    r = tail;
    for(int i=0;s[i];i++){
        l->insert(i+1);
        if(s[i] == 'l')
            r = l->next;
        else
            l = r->pre;
    }
    for(node* i = head->next;i!=tail;i=(i->next)){
        cout<<(i->val)<<endl;
    }
}