#include <iostream>
#include <algorithm>
#include <list>

#include "graph.h"
#include <stack>
#include <set>
#include "commandspool.h"
#include "commandline.h"
//#include <opencv2/opencv.hpp>
#include <iostream>
//#include <opencv2/core/mat.hpp>
#include "graphnode.h"

//using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
	//std::cout << "dcdsc";
	//Mat img = imread("C:\\Users\\mikod\\Downloads\\varpet.jpg");
	//namedWindow("image", WINDOW_NORMAL);
	//imshow("image", img);
	//waitKey(0);

  //QApplication a(argc, argv);
  //engine.createGraph<int, Rectangle>();
  //engine.findPath<Rectangle>();
  //MainWindow w;
  //w.show();
    CommandsPool::init();
    CommandLine cLine;
    cLine.exec();
	
	Graph<int> obj;
    Node<int>* ccA = new Node<int>("A");
    Node<int>* ccB = new Node<int>("B");
    Node<int>* ccC = new Node<int>("C");
    Node<int>* ccD = new Node<int>("D");
    Node<int>* ccE = new Node<int>("E");
    Node<int>* ccF = new Node<int>("F");
    Node<int>* ccX = new Node<int>("X");
    Node<int>* ccY = new Node<int>("Y");
	
    obj.addNode(ccA);
    obj.addNode(ccB);
    obj.addNode(ccC);
    obj.addNode(ccD);
    obj.addNode(ccE);
    obj.addNode(ccF);
    obj.addNode(ccX);
    obj.addNode(ccY);
	
    obj.connNodes(ccA, ccB, 1);
    obj.connNodes(ccB, ccC, 1);
    obj.connNodes(ccC, ccD, 1);
    obj.connNodes(ccD, ccE, 1);
    obj.connNodes(ccE, ccF, 1);
    obj.connNodes(ccA, ccX, 2);
    obj.connNodes(ccX, ccY, 2);
    obj.connNodes(ccY, ccF, 2);
    obj.connNodes(ccA, ccF, 10);
	
	
    //std::vector<Node<int>*> shortVec = ShortestPathProblem<int>::shortestPath(obj, ccA, ccF);
    //std::cout << "------------------Shortest Path---------------------- " << std::endl;
	//
    //std::for_each(shortVec.begin(), shortVec.end(), [](Node<int>* it) {std::cout << "<< " << it->name(); });
    //std::cout << std::endl;
	
    std::vector<Node<int>*> nodes = obj.BFS();
    std::cout << "------------------BFS---------------------- " << std::endl;
	
    std::for_each(nodes.begin(), nodes.end(), [](Node<int>* it) {std::cout << "<< " << it->name(); });
    std::cout << std::endl;
    std::vector<int> vec;
    std::cout << "-----------------DFS--------------------- " << std::endl;
	
    std::vector<Node<int>*> list = obj.DFS();
    std::for_each(list.begin(), list.end(), [](Node<int>* it) {std::cout << "<< " << it->name(); });
	
    std::cout << "\n-----------------print--------------------- " << std::endl;
	
	obj.print();
	
	
	
	
    return 0;
}
