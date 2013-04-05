#include <iostream>

using namespace std;
int a,b,c;
bool ** ss;
class Cup{
public:
    Cup(int x,int y,int z)
    {
        a=x;
        b=y;
        c=z;
    }
    void output()
    {
        switch (c)
        {
            case 3:cout<<"fill A"<<endl;break;
            case 0:cout<<"fill B"<<endl;break;
            case 4:cout<<"empty A"<<endl;break;
            case 5:cout<<"empty B"<<endl;break;
            case 2:cout<<"pour A B"<<endl;break;
            case 1:cout<<"pour B A"<<endl;break;
        }
    }
    int a,b,c;
};


Cup* down(Cup* cup,int x )
{
    switch(x)
    {
        case 3:return cup->a == a? NULL : new Cup(a,cup->b,x);break;
        case 0:return cup->b == b? NULL : new Cup(cup->a,b,x);break;
        case 4:return cup->a == 0? NULL : new Cup(0,cup->b,x);break;
        case 5:return cup->b == 0? NULL : new Cup(cup->a,0,x);break;
        case 2:return (cup->a == 0 || cup->b == b)? NULL : (cup->a > b-cup->b?new Cup(cup->a-(b-cup->b),b,x):new Cup(0,cup->a+cup->b,x));break;
        case 1:return (cup->b == 0 || cup->a == a)? NULL : (cup->b > a-cup->a?new Cup(a,cup->b-(a-cup->a),x):new Cup(cup->a+cup->b,0,x));break;
        default:return NULL;
    }
}
class Link{
public:
    Cup* prob;
    Link* next;
    Link(Cup* p ,Link *n):prob(p),next(n){}
    void ouput(){
        if(next != NULL)
        {
            next->ouput();
            prob->output();

        }
    }
};
Link * head;
bool ans=false;
void deep()
{
    Cup *p = head->prob;
    Cup *sub = NULL;
    if(p->b == c)
    {
        head->ouput();
        cout<<"success"<<endl;
        ans=true;
    }
    else
    {
        for(int i=0;!ans&&i<6;i++)
        {
            if( (sub = down(p,i))!=NULL && ! ss[sub->a][sub->b])
            {
                head = new Link(sub,head);
                ss[sub->a][sub->b] = true;
                deep();
                head = head->next;
            }

        }
    }

}
int main()
{

    while(cin>>a>>b>>c)
    {
        Cup t(0,0,c);
        head = new Link(&t,NULL);
        ss = new bool*[a+1];
        for(int i=0;i<=a;i++)
        {
            ss[i] = new bool[b+1];
            for(int j=0;j<=b;j++)
                ss[i][j] = false;
        }
        deep();
        ans = false;
    }
    return 0;
}
