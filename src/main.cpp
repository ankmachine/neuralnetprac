//
//  main.cpp
//
//  Created by ankit sinha on 19/10/18.
//  Copyright © 2018 ankit sinha. All rights reserved.
//

#include <iostream>
#include <vector>
#include "../include/Net.h"

int main(int argc, const char * argv[]) {
    // this the main class
    std::cout << "Starting the Neural Network Simulator!\n";
    
    // eg: {3,2,1} 3 inout layer, 2 neuron layer and 1 output
    std::vector<unsigned> topology;
    // testing purpose dummy data
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(1);

    // calling contructore here
    Net myNet(topology);
    
    // vector of double
    std::vector <double> inputVals;   

    myNet.feedForward(inputVals);

    std::vector <double> targetVals;
    myNet.backProp(targetVals);

    std::vector <double> resultVals;
    myNet.getResults(resultVals);
    return 0;
}

