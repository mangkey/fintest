#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "Appliance.h"
using namespace std;
extern vector<vector<shared_ptr<Appliance>>> prodList;

class Fileio {
public:
    Fileio();
	~Fileio();
};