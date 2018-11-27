#include "../include/Net.h"
#include <vector>
#include "../include/Neuron.h"
#include <iostream>
#include <cassert>
#include "../include/Common.h"

void Net::backProp(const std::vector<double> &targetVals){

// calculate overall net error (RMS of output error of neuron)
    Layer &outputLayer = m_layer.back();
    m_error =  0.0;
    for(unsigned n = 0; n < outputLayer.size() - 1; ++n)
    {
        double delta = targetVals[n] - outputLayer[n].getOutputVal();
        m_error += delta * delta; // square of delta 
    }
    m_error /= outputLayer.size() - 1; // get avg error squared
    m_error = sqrt( m_error ); // root mean square

// implement a recent avg measurement

    m_recentAverageError = (m_recentAverageError * m_recentAverageSmoothingFactor + m_error)
                            / (m_recentAverageSmoothingFactor + 1.0);

// calculate output layer gradient

    for(unsigned n = 0; n < outputLayer.size() - 1; ++n){
        outputLayer.calcOutputGradients(targetVals[n]);
    } 

// calculate gradients on hidden layers

    for(usigned layerNum = m_layers[0].size()-2; layerNum > 0; --layerNum)
    {
        Layer &hiddenLayer = m_layers[layerNum];
        layer &nextLayer = m_layers[layerNum + 1];
        
        for (unsigned n = 0; n < hiddenLayer.size(); ++n)
        {
            hiddenLayer[n].calcHiddenGradients(nextLayer);
        }
    }

// for all the outputs to first hidden layer
// and update the connection weights

}

void Net::feedForward(const std::vector<double> &inputVals){
    // checking if number of input value equal to number of neuron
    assert(inputVals.size() == m_layers[0].size() - 1);
    
    // latch input values into input neurons
    for(unsigned inp = 0; inp < inputVals.size(); ++inp ){
        std::cout << "value of inputvals index !!" << std::endl;
        std::cout << inputVals[inp] << std::endl;
        m_layers[0][inp].setOutputVal(inputVals[inp]); 
       
    } 

    // forward propogation : looping through neuron of each layer
    // and asking each neuron to feed forward
    for(unsigned layerNum = 1; layerNum < m_layers.size(); ++layerNum){
        Layer &pervLayer = m_layers[layerNum-1];
        // inner loop for each neuron, because bias neuron there will be -1
        for (unsigned neur = 0; neur < m_layers[layerNum].size()-1; ++neur){
   
            // class net will loop and set value
            // class neuron does the maths
            m_layers[layerNum][neur].feedForward(pervLayer);

        }
   
    }

}


Net::Net(const std::vector<unsigned> &topology)
{    
    unsigned numLayers = topology.size();
    for(unsigned layerNum=0; layerNum<numLayers; ++layerNum)
        {
            m_layers.push_back(Layer());

            // if the its the last layer number of output should be zero
            // otherwise number of output will the next element in topology
            unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];
 
            // we made new layer, fill it with neuron and a bias neuron
            for(unsigned neuronNum=0; neuronNum <= topology[layerNum]; ++neuronNum)
            {
                // start here
                m_layers.back().push_back(Neuron(numOutputs, neuronNum));
                std::cout << "made a neuron !!" << std::endl;
            }
        }
}


