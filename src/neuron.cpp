#include "../include/Neuron.h"
#include "../include/Connection.h"
#include <iostream>

Neuron::Neuron(unsigned numOutputs){
    for (unsigned connect=0; connect < numOutputs; ++connect)
    {
        m_outputWeights.push_back(Connection());
        m_outputWeights.back().weight = randomWeight();
        std::cout << randomWeight() << std::endl; 
    }
}
