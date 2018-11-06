//
//  Net.h
//
//  Created by ankit sinha.
//  Copyright © 2018 ankit sinha. All rights reserved.
//


// making sure that compiling this wont give error incase NET is already imported
#ifndef NET_H
#define NET_H

#include <vector>
#include "./Neuron.h"

typedef std::vector<Neuron> Layer;

class Net
{
public :
    Net(const std::vector<unsigned> &topology);
    void feedForward(const std::vector<double> &inputVals) ;
    void backProp(const std::vector<double> &targetVals) {};
    void getResults(std::vector<double> &resultVals) const {};

private :
   std::vector<Layer> m_layers; //usage  m_layers [layerNum] [neuronNum] 

};
#endif
