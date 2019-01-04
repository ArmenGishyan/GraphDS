#include <iostream>
#include <algorithm>
#include "graph.h"




int main()
{
	
	Graph<int> obj;
	Node<int>* cc1 = new Node<int>("0");
	Node<int>* cc2 = new Node<int>("1");
	Node<int>* cc3 = new Node<int>("2");
	Node<int>* cc4 = new Node<int>("3");
	Node<int>* cc5 = new Node<int>("4");
	Node<int>* cc6 = new Node<int>("5");

	obj.addNode(cc1);
	obj.addNode(cc2);
	obj.addNode(cc3);
	obj.addNode(cc4);
	obj.addNode(cc5);
	obj.addNode(cc6);

	obj.connNodes(cc1, cc2);
	obj.connNodes(cc2, cc3);
	obj.connNodes(cc3, cc1);
	obj.connNodes(cc2, cc5);
	obj.connNodes(cc2, cc4);
	obj.connNodes(cc3, cc5);
	obj.connNodes(cc4, cc5);
	obj.connNodes(cc4, cc6);
	obj.connNodes(cc5, cc6);

	std::vector<Node<int>*> nodes = obj.BFS();
	std::cout << "------------------BFS---------------------- " << std::endl;

	std::for_each(nodes.begin(), nodes.end(), [](Node<int>* it) {std::cout << "<< " << it->name; });
	std::cout << std::endl;
	std::vector<int> vec;
	std::cout << "-----------------DFS--------------------- " << std::endl;

	std::vector<Node<int>*> list = obj.DFS();
	std::for_each(list.begin(), list.end(), [](Node<int>* it) {std::cout << "<< " << it->name; });

	std::cout << "\n-----------------print--------------------- " << std::endl;

	obj.print();

	system("pause");
	return 0;
}