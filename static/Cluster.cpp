#include "Cluster.h"

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int Cluster::cnt = 0;

Cluster::Cluster(string name, map<int, int> &ids, bool noise, int clusterId, vector<double> &mean) {
    this->name = name;
    this->ids = ids;
    this->clusterId = clusterId;
    this->noise = noise;
    this->mean = mean;
    this->Split = 0;
}

Cluster::Cluster(const Cluster &t) {
    this->name = t.name;
    this->ids = t.ids;
    this->clusterId = t.clusterId;
    this->noise = t.noise;
    this->mean = t.mean;
    this->Split = t.Split;
}

Cluster::Cluster() {
    this->name = "";
    this->clusterId = -1;
    this->Split = 0;
}

int Cluster::size() {
    return (this->ids).size();
}

string &Cluster::getName() {
    return this->name;
}

map<int, int> &Cluster::getIds() {
    return this->ids;
}

int Cluster::getClusterId() {
    return this->clusterId;
}

vector<int> Cluster::getIdKeys() {
    vector<int> idKeys;
    for (auto x : (this->ids))
        idKeys.push_back(x.first);
    return idKeys;
}

bool Cluster::isNoise() {
    return this->noise;
}

int Cluster::getSplit() {
    return this->Split;
}

void Cluster::setName(string &name) {
    this->name = name;
}

void Cluster::setIds(map<int, int> &ids) {
    this->ids = ids;
}

void Cluster::setNoise(bool noise) {
    this->noise = noise;
}

void Cluster::setClusterId(int clusterId) {
    this->clusterId = clusterId;
}

void Cluster::setSplit(int split) {
    this->Split = split;
}

void Cluster::insertId(int id, int neighCount) {
    (this->ids).insert(make_pair(id, neighCount));
}

void Cluster::deleteId(int id) {
    (this->ids).erase(id);
}

void Cluster::print() {
    cout << "name = " << this->name << '\n';
    cout << "ids = ";
    for (auto x : this->ids)
        cout << "(" << x.first << ":" << x.second << ") ";
    cout << '\n';

    cout << "mean = ";
    for (auto x : this->mean)
        cout << x << ' ';
    cout << '\n';
}

Cluster &Cluster::operator=(const Cluster &t) {
    if (this != &t) {
        this->name = t.name;
        this->ids = t.ids;
        this->clusterId = t.clusterId;
        this->noise = t.noise;
        this->mean = t.mean;
        this->Split = t.Split;
    }
    return *this;
}

void Cluster::incrementSplit() {
    this->Split++;
}

void Cluster::resetSplit() {
    this->Split = 0;
}
