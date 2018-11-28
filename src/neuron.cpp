#include "../include/Neuron.h"
#include "../include/Connection.h"
#include <iostream>
#include <cmath>

double Neuron::eta = 0.15;
double Neuron::alpha = 0.5;


void Neuron::updateInputWeights(Layer &prevLayer)
{

    // the weights are updated in connection container
    // in the neuron in the preceding layer
    for (unsigned n = 0; n < prevLayer.size(); ++n)
    {
        Neuron &neuron = prevLayer[n];
        double oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeight;
        double newDeltaWeight = 
        // individual input modified my gradient and train rate
            eta
            * neuron.getOutputVal()
            * m_gradient
       // also add momentum = a fraction of previous delta weight
            + alpha
            * oldDeltaWeight;

        neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;
        neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight; 
    } 

}


double Neuron::sumDow(const Layer &nextLayer) const
{

    double sum = 0.0;
    // sum of out contributions of the errors at the node we feed
    for(unsigned n = 0; n < nextLayer.size() - 1; ++n)
    {
        sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
        
    }
    
    return sum;

}


void Neuron::calcHiddenGradients(const Layer &nextLayer){

    double dow = sumDow(nextLayer);
    m_gradient = dow * Neuron::transferFunctionDerivative(m_outputVal);
    

}


void Neuron::calcOutputGradients(double targetVal){

    double delta = targetVal - m_outputVal;
    m_gradient = delta * Neuron::transferFunctionDerivative(m_outputVal);

}


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
