#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <bits/stdc++.h> 

using namespace std;


class Graph
{
	int no_of_vertices;
	list<int> *adj;

	void dfs_util(int v,bool visited[]) {
		visited[v]=true;
		cout << v << " ";
		list<int>::iterator it;
		for(it = adj[v].begin(); it != adj[v].end(); it++){
			if(!visited[*it]) {
				dfs_util(*it,visited);
			}
		}
	}

	public:
		Graph(int data) {
			this->no_of_vertices = data;
			this->adj = new list<int>[data]; 
		}

		void addEdge(int v, int w) {
			adj[v].push_back(w);
		}

		void dfs(int v) {
			bool *visited = new bool[this->no_of_vertices];
			for (int i=0; i<this->no_of_vertices; i++){
				visited[i] = false;
			}
			dfs_util(v,visited);
			cout << endl;
		}

		void bfs(int v) {
			vector<bool> visited(this->no_of_vertices,false); 
				
			list<int> queue;
			visited[v] = true;
			queue.push_back(v);

			while(!queue.empty()) {
				list<int>::iterator it;
				int vertex = queue.front();
				queue.pop_front();
				cout << vertex << " " ;

				for(it = adj[vertex].begin(); it!=adj[vertex].end(); it++) {
					int next = *it;
					if(!visited[next]) {
						visited[next] = true;
						queue.push_back(next);
					}
				}

			}
			cout << endl;
		}


		set<int> shortest_path(int start, int end) {
			map<int,int> visited;
			list<int> queue;
			vector<int> retval;
			queue.push_back(start);
			bool if_found = false;
			cout << "Hello" <<endl;
			while(!queue.empty()){
				list<int>:: iterator it;
				int vertex = queue.front();
				queue.pop_front();
				
				if (vertex == end) {
					break;
				}
				// vector<int> short_path;
				for (it = adj[vertex].begin(); it!=adj[vertex].end();it++) {
					int next = *it;
					//algorithm to find 
					if(visited.find(next)!=visited.end()) {
						continue;
					}
					visited[next] = vertex;
					queue.push_back(next);
				}

			}
			if (visited.find(end)==visited.end()) {
				return {};
			}
			// list<int>:: iterator it;
			int curr = end;

			for(auto it = visited.rbegin();it!=visited.rend(); ++it) {
				retval.push_back(visited[curr]);
				curr = visited[curr];
			}
			reverse(retval.begin(),retval.end());
			set<int> newret;
			newret.insert(retval.begin(),retval.end());
			return newret;
		}

};


int main()
{
	Graph g(5);
	g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2);
   
    g.addEdge(2, 4); 
    g.addEdge(1, 3); 
    g.addEdge(3, 4);
    g.dfs(0);
    g.bfs(0);

    set<int> out = g.shortest_path(0,4);
    set<int>::iterator it;

    for(auto i=out.begin();i!=out.end(); i++){
    	cout << *i << " ";
    }
    cout << endl;
	return 0;
}