#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;


class Vertex {
	int val;
	vector<Vertex*> adj;
public:
	Vertex(){}
	Vertex(int k)  {val = k;}
	~Vertex(){}

	void addEdge(Vertex* v){
		adj.push_back(v);
	}

	int getVal() {
		return val;
	}

	vector<Vertex*> getadjList() {
		return adj;
	}

	void printAdjList(vector<Vertex*> adjList) {
		int size = adjList.size();
		for(int it =0;  it<size; it++) {
			cout << adjList[it]->getVal() << " ";
		}
		cout << endl;
	}
	Vertex* getVertex() {
		return this;
	}
};

bool detectCycleHelper(Vertex* v, unordered_map<int, int>& visited, int parent) {
	visited[v->getVal()] = 1;
	cout << v->getVal() << endl;
	vector<Vertex*> adjList = v->getadjList();
	for(int i=0; i< adjList.size();i++) {
		if(!visited[v->getVal()]) {	
			cout << v->getVal() <<endl;
			if(detectCycleHelper(adjList[i], visited, adjList[i]->getVal())) {
				return true;
			} else if(parent != adjList[i]->getVal()) {
				return true;
			}
		}
	}
	return false;
}

bool detectCycle(list<Vertex*> vlist) {
	//for all vertices in list do a dfs
	unordered_map<int, int> visited(vlist.size());	

	for(auto ver: vlist) {
		//cout << i<< endl;

		// Vertex* v = vlist.front();
		if (!visited[ver->getVal()]) {
			if(detectCycleHelper(ver, visited, -1)) {
				return true;
			}	
		}
		
		// vlist.pop_front();
	}
	return false;

}

int main()  {

	Vertex* a = new Vertex(1);
	Vertex* b = new Vertex(2);
	Vertex* c = new Vertex(3);
	a->addEdge(b);
	b->addEdge(a);
	b->addEdge(c);
	c->addEdge(b);
	c->addEdge(a);
	a->addEdge(c);
	
	list<Vertex*> vList;
	vList.push_back(a);
	vList.push_back(b);
	vList.push_back(c);

	cout << vList.size() <<endl;
	cout << (detectCycle(vList)?"true":"false") <<endl;
	// a->printAdjList(a->getadjList());
	

	return 0;
}
