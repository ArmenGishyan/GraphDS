#include <list>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_set>

template<class T>
struct Node
{
	Node(std::string name, T value = T(), int weight = 1) :
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
	int weight;
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
	std::vector<Node<E>*> DFS() const;
	void print() const;


private:
	std::vector<std::unordered_set<Node<E>*>> m_adj;
};

template<class T>
void Graph<T>::addNode(Node<T>* node)
{
	std::unordered_set<Node<T>* > nodeTemp;
	
	nodeTemp.insert(node);
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
			it->insert(node2);
			flag1 = false;
		}
		if (flag2 && (*itFirst)->name == node2->name) {
			it->insert(node1);
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

template<class T>
std::vector<Node<T>* > Graph<T>::DFS() const
{
	std::vector<Node<T>* > dfsList;
	if (m_adj.empty()) {
		return dfsList;
	}
	std::bitset<10> visited;
	std::stack<Node<T>* > st;

	st.push(*m_adj[0].begin());
	dfsList.push_back(*m_adj[0].begin());
	visited[(*m_adj[0].begin())->getIndex()] = true;
	int count = 0;
	std::unordered_set<Node<T>*> current = m_adj[0];

	while (!st.empty()) 
	{
		count = 0;
		for (auto it = current.begin(); it != current.end(); ++it) {
			if (!visited[(*it)->getIndex()]) {
				visited[(*it)->getIndex()] = true;
				st.push(*it);
				dfsList.push_back(*it);
				current = m_adj[(*it)->getIndex()];
				break;
			}
			else {
				count++;
			}
		}

		if (count == current.size()) {
			current = m_adj[st.top()->getIndex()];
			if (!st.empty()) {
				st.pop();
			}
		}
	}
	return dfsList;

}