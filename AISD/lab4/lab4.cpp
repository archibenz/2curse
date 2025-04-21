/******************************************************
 * Лабораторная №4 «Остовные деревья» (вариант 7, γ=18)
 * Реализация алгоритмов Крускала и Прима
 * Автор: (ваше‑имя)
 *****************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>      // для iota
#include <queue>        // для priority_queue
using namespace std;

/*** Структуры данных ***/
struct Edge { int u, v, w; };               // ребро (u,v) с весом w
bool operator<(const Edge& a, const Edge& b){ return a.w < b.w; }

struct DSU {                                // непересекающиеся множества
    vector<int> p, sz;
    DSU(int n): p(n), sz(n,1){ iota(p.begin(), p.end(), 0); }
    int find(int v){ return p[v]==v? v: p[v]=find(p[v]); }
    bool unite(int a, int b){
        a = find(a);  b = find(b);
        if (a==b) return false;
        if (sz[a] < sz[b]) swap(a,b);
        p[b] = a;  sz[a] += sz[b];
        return true;
    }
};

/*** Крускал ***/
vector<Edge> kruskal(int n, vector<Edge> edges){
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    vector<Edge> mst;
    for(const Edge& e: edges)
        if(dsu.unite(e.u, e.v)){
            mst.push_back(e);
            if(mst.size() == n-1) break;
        }
    return mst;
}

/*** Прим (O(E log V) через очередь) ***/
vector<Edge> prim(int n, const vector<vector<pair<int,int>>>& g){
    const int INF = 1e9;
    vector<int> key(n, INF), parent(n, -1);
    vector<char> used(n, 0);
    key[0] = 0;

    using P = pair<int,int>;                // (key, vertex)
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        int v = pq.top().second; pq.pop();
        if(used[v]) continue;
        used[v] = 1;
        for(auto [to,w]: g[v])
            if(!used[to] && w < key[to]){
                key[to] = w; parent[to] = v;
                pq.push({key[to], to});
            }
    }
    vector<Edge> mst;
    for(int v=1; v<n; ++v) mst.push_back({v, parent[v], key[v]});
    return mst;
}

/*** Утилиты ***/
void print(const vector<Edge>& mst){
    int sum = 0;
    cout << "u  v  w\n";
    for(auto e: mst){ cout << e.u+1 << "  " << e.v+1 << "  " << e.w << '\n'; sum += e.w; }
    cout << "Σ = " << sum << "\n";
}

int main(){
    int mode;
    cout << "Введите 7 для готового графа или 0 для ручного ввода: ";
    cin >> mode;

    int n, m;
    vector<Edge> edges;

    if(mode == 7){                     // --- граф варианта 7 (стр.48) ---
        n = 8;
        Edge tmp[] = {                 // (сверьтесь с рисунком!)
            {0,1, 2}, {1,2, 1}, {2,3,17},
            {0,2, 2}, {1,3, 3},        // диагонали «крыши»
            {0,4, 3},
            {1,5,10}, {2,5,35}, {3,6,13},
            {4,5,11}, {5,6,15},
            {4,7,20}, {5,7,12}, {6,7,10},
            {1,4,10}, {2,4,14}, {2,6,16}, {3,5,18}
        };
        m = sizeof(tmp)/sizeof(tmp[0]);
        edges.assign(tmp, tmp+m);
    }else{                             // --- свободный ввод ---
        cout << "n (вершин) и m (рёбер): "; cin >> n >> m;
        cout << "Введите m строк: u v w\n";
        edges.resize(m);
        for(auto &e: edges){ cin >> e.u >> e.v >> e.w; --e.u; --e.v; }
    }

    /* список смежности для Прима */
    vector<vector<pair<int,int>>> g(n);
    for(auto e: edges){ g[e.u].push_back({e.v,e.w}); g[e.v].push_back({e.u,e.w}); }

    cout << "\n=== Крускал ===\n";
    print( kruskal(n, edges) );

    cout << "\n=== Прим ===\n";
    print( prim(n, g) );
}