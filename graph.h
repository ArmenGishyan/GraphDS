#include <list>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <sstream>

template<class T>
struct Node
{
	Node(std::string name, T value = T()) :
		name(name), value(value)
	{}
	int getIndex() const
	{
		std::stringstream str(name);
		int x = 0;
		str >> x;
		
		return x;
	}
	std::string name;
	T value;
};

template<class E>
class Graph
{
public:
	Graph() = default;
	Graph(int nodeCount);
	void addNode(Node<E>*);
	void connNodes(Node<E>*, Node<E>*);
	std::vector<Node<E>*> BFS() const;
	void print() const;


private:
	std::vector<std::list<Node<E>*>> m_adj;
};

template<class T>
void Graph<T>::addNode(Node<T>* node)
{
	std::list<Node<T>* > nodeTemp;
	
	nodeTemp.push_back(node);
	m_adj.push_back(nodeTemp);
}

template<class T>
void Graph<T>::connNodes(Node<T>* node1, Node<T>* node2)
{
	auto it = m_adj.begin();
	while (it != m_adj.end()) {
		bool flag1 = true;
		bool flag2 = true;
		auto itFirst = it->begin();
		if (flag1 && (*itFirst)->name == node1->name) {
			it->push_back(node2);
			flag1 = false;
		}
		if (flag2 && (*itFirst)->name == node2->name) {
			it->push_back(node1);
			flag2 = false;
		}
		if (!flag1 && !flag2)
			break;
		++it;
	}
}

template<class T>
void Graph<T>::print() const
{
	auto it = m_adj.begin();
	while (it != m_adj.end()) {
		auto itFirst = it->begin();
		while (itFirst != it->end()) {
			std::cout << (*itFirst)->name << ", ";
			itFirst++;
		}
		std::cout << std::endl;
		++it;
	}
}


template<class T>
Graph<T>::Graph(int nodeCount)
{
	for (int i = 0; i < nodeCount; ++i)
	{
		addNode(new Node<T>("A" + std::to_string(i)));
	}
}

template<class T>
std::vector<Node<T>*> Graph<T>::BFS() const
{
	std::bitset<100> visited;
	std::queue<Node<T>*> queue;
	std::vector<Node<T>*> BFSnods;

	auto it = m_adj.begin();
	queue.push(*(it->begin()));
	
	visited[0] = true;
	while (!queue.empty()) 
	{
		Node<T>* node = queue.front();
		BFSnods.push_back(node);
		queue.pop();
		int index = node->getIndex();
		visited[index] = true;

		for (auto const& item : m_adj[index]) {
			if (!visited[item->getIndex()]) {
				visited[item->getIndex()] = true;
				queue.push(item);
			}
		}
	}
	return BFSnods;
}

sirumemqez