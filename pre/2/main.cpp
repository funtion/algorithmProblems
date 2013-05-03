#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <fstream>
using namespace std;
fstream in;
int n1,n2;
class Node
{
public:
    Node(string& ss,int p ):parent(p),s(ss) {
        in =0;
        depth=0;
        isDeleted = false;
    }
    int in;
    int depth;
    int parent;
    vector<int> out;
    string s;
    bool isDeleted;
};
Node* nodes[1024];
queue<int> qu;
int h(string &s)
{
    int x=1;
    for(string::iterator i = s.begin(); i!=s.end(); i++)
    {
        x = (x*31 + *i)%1024;
    }
    return x;
}
void print(int maxNode){
    if(nodes[maxNode]->parent != maxNode){
        print(nodes[maxNode]->parent);
    }
    cout<<nodes[maxNode]->s<<" ";

}
int main()
{
    memset(nodes,0,sizeof(nodes));
    in.open("in.txt");
    string temp,temp2;
    in>>n1>>n2;
    for(int i=0; i<n1; i++)
    {
        in>>temp;
        nodes[h(temp)] = new Node(temp,h(temp));
    }
    for(int i=0; i<n2; i++)
    {
        in>>temp>>temp2;
        nodes[h(temp)]->out.push_back(h(temp2));
        nodes[h(temp2)]->in++;
    }
    for(int i =0;i<1024;i++){
        if(nodes[i] != 0 && nodes[i]->in == 0){
            qu.push(i);
        }
    }
    int maxNode = 0,maxDepth=0;
    while(!qu.empty()){
        int cur = qu.front();
        qu.pop();
        Node *n =  nodes[cur];
        for(vector<int>::iterator i = n->out.begin();i!=n->out.end();i++){
            if(--nodes[*i]->in == 0){
                qu.push(*i);
            }
            nodes[*i]->depth = n->depth+1;
			if(nodes[*i]->depth > maxDepth){
                maxNode = *i;
				maxDepth = nodes[*i]->depth;
            }
            nodes[*i]->parent = cur;
        }
    }
    print(maxNode);
    return 0;
}
