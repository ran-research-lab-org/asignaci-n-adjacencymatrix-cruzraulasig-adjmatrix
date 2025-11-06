#include <iostream>
#include <vector>
#include <stack>
#include <stdexcept>
using namespace std;

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    // Crea un vector de 2D n x n
    Graph(int n) : numVertices(n), adjMatrix(n, std::vector<int>(n, 0)) {}

    // Add a vertex from node u to node v
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjMatrix[u][v] = 1;
        } else {
            std::out_of_range("Vertice fuera de rango");
        }
    }

    // Imprime la matriz de adyacencias
    void print() const {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Implementar!! 
    // Devuelve la cantidad de aristas
    int numEdges() const {
        int edgeNum = 0;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if(adjMatrix[i][j]!=0){edgeNum += adjMatrix[i][j];}
            }
        }
        return edgeNum;
    }

    // Completa esta función
    // Devuelve el in-degree de un vertice
    int inDegree(int u) const {
        int degreeNum = 0;
        if (u < 0 || u >= numVertices)
            throw std::out_of_range("Vertice fuera de rango");
        else {
            for (int j = 0; j < numVertices; ++j) {
                if(adjMatrix[j][u]!=-1){degreeNum += adjMatrix[j][u];}//std::cout << adjMatrix[j][2] << " ";}
            }
        }
        return degreeNum;
    }

    // Completa esta función
    // Devuelve cierto si u es el nodo con mayor inDegree.
    // En caso de que haya varios nodos que tengan el mayor inDegree,
    // devuelve true si u es uno de ellos
    bool isInfluencer(int u) const  {
        int inDegreeAmount = -1, currAmount = -1;
        stack<int> topNums;
        for (int j = 0; j < numVertices; ++j) {
            currAmount = inDegree(j);
            if(currAmount>inDegreeAmount){
                while(!topNums.empty()){
                    topNums.pop();
                }
                topNums.push(j);
                inDegreeAmount = currAmount;
            }
            else if(currAmount==inDegreeAmount){topNums.push(j);}
        }
        for(int i = 0; i < topNums.size();){
            if(topNums.top()==u){return true;}
            else{topNums.pop();}
        }
        return false;
    }
};

