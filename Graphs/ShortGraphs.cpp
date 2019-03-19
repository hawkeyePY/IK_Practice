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

	// bool detectCycleHelper(Vertex* v, unordered_map<int, bool>& visited, int parent) {
	// 	visited[v->getVal()] = true;

	// 	return true;
	// }

};


	bool detectCycle(list<Vertex*> vlist) {
		//for all vertices in list do a dfs
		// unordered_map<int, bool> visited(vlist.size(), false);	

		for(int i=0; i<vlist.size(); i++) {
			cout << i<< endl;

			Vertex* v = vlist.front();
			cout << v->getVal() <<endl;
			break;
			// if(!visited[vlist[i]->getVal()]) {
			// 	if(detectCycleHelper(vlist[i]), visited, -1) {
			// 		return true;
			// 	}
			// }
			vlist.pop_front();
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
