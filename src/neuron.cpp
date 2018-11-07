#include "../include/Neuron.h"
#include "../include/Connection.h"
#include <iostream>
#include <cmath>

double Neuron::transferFunction(double x){

    // we are usng tanh output [1.0....-1.0]
    return tanh(x);    

}

double Neuron::transferFunctionDerivative(double x){

    // tanh derivative
    return 1.0 - x * x;

}

void Neuron::feedForward(const Layer &prevLayer){
    //math part for feed forward
    double sum = 0.0;
    
    // sum the previous layer output
    // Include bias node from previous layer
    // sum of  input*weight of all neuron
    for (unsigned neur = 0; neur < prevLayer.size(); ++ neur){
    
    sum += prevLayer[neur].getOutputVal() * prevLayer[neur].m_outputWeights[m_myIndex].weight;
    }
    // magic function, 
    m_outputVal = Neuron::transferFunction(sum);
}

Neuron::Neuron(unsigned numOutputs, unsigned myIndex){
    for (unsigned connect=0; connect < numOutputs; ++connect)
    {
        m_outputWeights.push_back(Connection());
        m_outputWeights.back().weight = randomWeight();
        std::cout << "random weight of each neuron" << std::endl;
        std::cout << randomWeight() << std::endl; 
    }
    m_myIndex = myIndex;
}
