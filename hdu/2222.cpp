#include<cstdio>
#include<queue>
using namespace std;
int n,t;
char tag[1000100];
struct node
{
    int cnt;
    node* fail;
    node* next[26];
    void   init(){
        fail = NULL;
        cnt = 0;
        for(int i=0; i<26; i++)next[i] = NULL;
    }
    node()
    {
        fail = NULL;
        cnt = 0;
        for(int i=0; i<26; i++)next[i] = NULL;
    }
}*root,tr[100000];
int ctr;
void ins(char* s)
{
    node* p = root;
    int index;
    for(int i=0; s[i]; i++)
    {
        index = s[i]-'a';
        if(p->next[index] == NULL )
        {
            //p->next[index] = new node();
            p->next[index] = &tr[++ctr];
            p->next[index]->init();

        }
        p = p->next[index];
    }
    p->cnt  ++;
}

void init()
{
    queue<node*> qu;
    qu.push(root);
    node* cur;
    while(!qu.empty())
    {
        cur = qu.front();
        qu.pop();
        for(int i=0; i<26; i++)
        {
            if(cur->next[i] != NULL)
            {
                if(cur == root )
                {
                    cur->next[i]->fail = root;

                }
                else
                {
                    node* temp = cur->fail;
                    while(temp!=NULL){
                        if(temp->next[i] != NULL){
                            cur->next[i]->fail = temp->next[i];
                            break;
                        }
                        temp = temp->fail;
                    }
                    if(temp == NULL){
                        cur->next[i]->fail = root;
                    }
                }
                qu.push(cur->next[i]);
            }
        }
    }
}
int fd(){
    node* p = root;
    int ans = 0;
    for(int i=0;tag[i];i++){
        int index = tag[i]-'a';
        while(p->next[index] == NULL && p!=root)
            p = p->fail;
        p = p->next[index];
        if(p == NULL)
            p = root;
        node* temp  = p;
        while(temp!=root && temp->cnt!=-1){
            ans+=temp->cnt;
            temp->cnt = -1;
            temp = temp->fail;
        }
    }
    return ans;
}
int main()
{
    char wd[100];
    root = tr;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        root->init();
        ctr = 0;
        //root = new node();
        for(int i=0; i<n; i++)
        {
            scanf("%s",wd);
            ins(wd);
        }
        scanf("%s",tag);
        init();
        int ans = fd();
        printf("%d\n",ans);
    }
}
