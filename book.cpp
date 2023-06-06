#include<iostream>
#include<string>
using namespace std;

struct node {
    char label[10];
    int ch_cnt;
    struct node * child[10];
} * root;

class bookTree {
    public:
    void create() {
        int i, j, tch;
        root = new node;
        cout<<"Enter the name of the book:  ";
        cin>>root->label;
        cout<<endl;
        cout<<"Enter the Number of chapters in the book: ";
        cin>>tch;
        root->ch_cnt = tch;
        cout<<endl;
        for(i = 0; i < tch; i++) {
            root->child[i] = new node;
            cout<<"Enter the name of "<< i+1 <<" Chapter: ";
            cin>>root->child[i]->label;
            cout<<"\nEnter the number of sections in "<<root->child[i]->label<<": ";
            cin>>root->child[i]->ch_cnt;
            for(j = 0; j < root->child[i]-> ch_cnt; j++) {
                root->child[i]->child[j] = new node;
                cout<<"\nEnter the name of "<< j+1 <<" section in "<<root->child[i]->label<<" : ";
                cin>>root->child[i]->child[j]->label;
            }
        }
    }
    
    void diplay(node * rt) {
        int i, j, tch;
        if(rt != NULL) {
            cout<<"The name of the book is: "<<rt->label<<endl;
            tch = rt->ch_cnt;
            for(i = 0; i < tch; i++) {
                cout<<"\nChapter number "<< i+1<< " is: "<<root->child[i]->label;
                cout<<"\nSections of "<<root->child[i]->label<< " is: ";
                for(j = 0;j < root->child[i]->ch_cnt; j++) {
                    cout<<root->child[i]->child[j]->label<<"     ";
                }
            }
        }
    }
};

int main() {
    bookTree bt;
    bt.create();
    bt.diplay(root);
    return 0;
}