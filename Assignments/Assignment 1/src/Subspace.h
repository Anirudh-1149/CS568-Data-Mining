#ifndef SUBSPACE_H
#define SUBSPACE_H

#include <iostream>
#include <vector>
#include <map>
#include "Cluster.h"

using namespace std;

class Subspace
{
private:
    vector<int> dimensions;
    int dimensionality;
    map<int,pair<int,int>> neighCounts;
    map<int,Cluster> clusters;
    int next_cluster;

public:
    // Create a 1-dimensional subspace
    Subspace(int dimension);

    // Default Constructor
    Subspace();

    // Create a subspace with given dimensions
    Subspace(vector<int> &dimensions);

    // Getters
    vector<int> &getDimensions();
    int& getDimensionality();

    // Add or Remove dimensions
    void addDimension(int dimension);
    void removeDimension(int dimension);

    // Joins subspaces to create new subspace
    Subspace join(Subspace &other);
    vector<int> joinLastDimensions(Subspace &other);

    // Checks if the space is a subspace of the argument or not
    bool isSubspace(Subspace &subspace);

    // Checks if ith dimension is present in the subspace
    bool hasDimension(int i);

    // Displays dimensions and dimensionality
    void print();
    bool isValid();

    //defining < operator
    bool operator<(const Subspace &s2) const;

    // Getters and Setters
    map<int,pair<int,int>>& getNeighcounts();
    map<int,Cluster>& getClusters();
    void setNeighCounts(map<int,pair<int,int>>& neighCounts);
    void setClusters(map<int, Cluster>& clusters);

    void setClusters(vector<Cluster>& clustering);

    void incrNext();

    int getNext();
};

#endif
