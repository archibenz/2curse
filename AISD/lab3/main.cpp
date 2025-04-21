#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <chrono>
#include <random>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <limits>
using namespace std;
using clk = chrono::high_resolution_clock;

// 1. factorial & sum (iterative/recursive)
long long factorial_iter(int n) { long long r=1; for(int i=1;i<=n;i++) r*=i; return r; }
long long factorial_rec(int n) { return n<=1?1: n*factorial_rec(n-1); }
long long sum_iter(int n) { long long s=0; for(int i=1;i<=n;i++) s+=i; return s; }
long long sum_rec(int n)  { return n<=1? n: n+sum_rec(n-1); }

// 2. Stack / Queue / Deque
template<typename T>
class Stack {
    vector<T> v;
public:
    void push(const T& x){ v.push_back(x); }
    T pop(){ T x=v.back(); v.pop_back(); return x; }
    void print(){ for(auto& i:v) cout<<i<<" "; cout<<"\n"; }
};

template<typename T>
class Queue {
    deque<T> d;
public:
    void enqueue(const T& x){ d.push_back(x); }
    T dequeue(){ T x=d.front(); d.pop_front(); return x; }
    void print(){ for(auto& i:d) cout<<i<<" "; cout<<"\n"; }
};

template<typename T>
class Deque {
    deque<T> d;
public:
    void push_front(const T& x){ d.push_front(x); }
    void push_back (const T& x){ d.push_back(x); }
    T pop_front(){ T x=d.front(); d.pop_front(); return x; }
    T pop_back() { T x=d.back();  d.pop_back();  return x; }
    void print(){ for(auto& i:d) cout<<i<<" "; cout<<"\n"; }
};

// 3. BST
struct BSTNode { int key; BSTNode *l, *r; BSTNode(int k):key(k),l(nullptr),r(nullptr){} };
class BST {
    BSTNode* root=nullptr;
    BSTNode* ins(BSTNode* n,int k){
        if(!n) return new BSTNode(k);
        if(k<n->key) n->l=ins(n->l,k);
        else            n->r=ins(n->r,k);
        return n;
    }
    void pre(BSTNode* n, vector<int>&a){ if(n){a.push_back(n->key); pre(n->l,a); pre(n->r,a);} }
    void in (BSTNode* n, vector<int>&a){ if(n){ in(n->l,a); a.push_back(n->key); in(n->r,a);} }
    void post(BSTNode* n,vector<int>&a){ if(n){ post(n->l,a); post(n->r,a); a.push_back(n->key);} }
public:
    void insert(int k){ root=ins(root,k); }
    vector<int> preorder()  { vector<int>a; pre(root,a);  return a; }
    vector<int> inorder()   { vector<int>a; in(root,a);   return a; }
    vector<int> postorder() { vector<int>a; post(root,a); return a; }
};

// 4. AVL
struct AVLNode { int key, h; AVLNode *l, *r; AVLNode(int k):key(k),h(1),l(nullptr),r(nullptr){} };
int  height(AVLNode* n){ return n? n->h:0; }
int  bf(AVLNode* n){ return n? height(n->l)-height(n->r):0; }
AVLNode* rotR(AVLNode* y){
    auto x=y->l; auto T2=x->r;
    x->r=y; y->l=T2;
    y->h=1+max(height(y->l),height(y->r));
    x->h=1+max(height(x->l),height(x->r));
    return x;
}
AVLNode* rotL(AVLNode* x){
    auto y=x->r; auto T2=y->l;
    y->l=x; x->r=T2;
    x->h=1+max(height(x->l),height(x->r));
    y->h=1+max(height(y->l),height(y->r));
    return y;
}
AVLNode* insertAVL(AVLNode* node,int key){
    if(!node) return new AVLNode(key);
    if(key<node->key) node->l=insertAVL(node->l,key);
    else              node->r=insertAVL(node->r,key);
    node->h=1+max(height(node->l),height(node->r));
    int balance=bf(node);
    if(balance>1 && key<node->l->key)            return rotR(node);
    if(balance<-1&& key>node->r->key)            return rotL(node);
    if(balance>1 && key>node->l->key){ node->l=rotL(node->l); return rotR(node); }
    if(balance<-1&& key<node->r->key){ node->r=rotR(node->r); return rotL(node); }
    return node;
}
void inorderAVL(AVLNode* n, vector<int>&a){ if(n){ inorderAVL(n->l,a); a.push_back(n->key); inorderAVL(n->r,a);} }

int main(){
    std::vector<std::string> generatedFiles;
    mt19937 rng(time(0));
    while(true){
        std::system("clear");
        cout
        <<"1. factorial iterative\n"
        <<"2. factorial recursive\n"
        <<"3. sum iterative\n"
        <<"4. sum recursive\n"
        <<"5. compare times\n"
        <<"6. stack/queue/deque demo\n"
        <<"7. binary tree demo\n"
        <<"8. AVL balance demo\n"
        <<"9. exit\nSelect: ";
        int c; if(!(cin>>c) || c==9) break;

        if(c>=1 && c<=4){
            int n; cout<<"n="; cin>>n;
            if(c==1) cout<<factorial_iter(n)<<"\n";
            if(c==2) cout<<factorial_rec(n)<<"\n";
            if(c==3) cout<<sum_iter(n)<<"\n";
            if(c==4) cout<<sum_rec(n)<<"\n";
        }
        else if(c==5){
            ofstream f1("factorial_times.txt"), f2("sum_times.txt");
            generatedFiles.push_back("factorial_times.txt");
            generatedFiles.push_back("sum_times.txt");
            for(int n=1;n<=20;n++){
                auto t1=clk::now(); factorial_iter(n); auto t2=clk::now();
                auto t3=clk::now(); factorial_rec(n); auto t4=clk::now();
                auto dt1=chrono::duration_cast<chrono::nanoseconds>(t2-t1).count();
                auto dt2=chrono::duration_cast<chrono::nanoseconds>(t4-t3).count();
                f1<<n<<" "<<dt1<<" "<<dt2<<"\n";
                t1=clk::now(); sum_iter(n); t2=clk::now();
                t3=clk::now(); sum_rec(n);  t4=clk::now();
                dt1=chrono::duration_cast<chrono::nanoseconds>(t2-t1).count();
                dt2=chrono::duration_cast<chrono::nanoseconds>(t4-t3).count();
                f2<<n<<" "<<dt1<<" "<<dt2<<"\n";
            }
            cout<<"[+] Times saved.\n";
            // explicitly close to flush buffers
            f1.close();
            f2.close();
            // now run the plotter
            cout<<"[*] Building graphs...\n";
            std::system("python3 plot.py");
        }
        else if(c==6){
            Stack<int> s;    s.push(1); s.push(2);
            cout<<"Stack: ";  s.print(); s.pop(); cout<<"After pop: "; s.print();
            Queue<int> q;    q.enqueue(1); q.enqueue(2);
            cout<<"Queue: ";  q.print(); q.dequeue(); cout<<"After dq: "; q.print();
            Deque<int> d;    d.push_back(1); d.push_front(2);
            cout<<"Deque: ";  d.print(); d.pop_back(); cout<<"After pb: "; d.print();
        }
        else if(c==7){
            ofstream out("traversals.txt");
            generatedFiles.push_back("traversals.txt");
            for(auto sz:{8,10,12}){
                set<int> st;
                while((int)st.size()<sz) st.insert(rng()%100);
                BST tree; for(int v:st) tree.insert(v);
                auto p=tree.preorder(); auto i=tree.inorder(); auto o=tree.postorder();
                out<<"Pre "<<sz<<": "; for(int v:p) out<<v<<" "; out<<"\n";
                out<<"In  "<<sz<<": "; for(int v:i) out<<v<<" "; out<<"\n";
                out<<"Post"<<sz<<": "; for(int v:o) out<<v<<" "; out<<"\n";
            }
            cout<<"[+] Traversals saved.\n";
        }
        else if(c==8){
            ofstream out("avl_before_after.txt");
            generatedFiles.push_back("avl_before_after.txt");
            for(auto sz:{9,10,11}){
                set<int> st; while((int)st.size()<sz) st.insert(rng()%100);
                vector<int> keys(st.begin(),st.end());
                out<<"Before "<<sz<<": "; for(int v:keys) out<<v<<" "; out<<"\n";
                AVLNode* root=nullptr;
                for(int v:keys) root=insertAVL(root,v);
                vector<int> in; inorderAVL(root,in);
                out<<"After  "<<sz<<": "; for(int v:in) out<<v<<" "; out<<"\n";
            }
            cout<<"[+] AVL saved.\n";
        }
        cout<<"Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
    return 0;
}