#include "../include/Net.h"
#include <vector>
#include "../include/Neuron.h"
#include <iostream>
#include <cassert>

typedef std::vector<Neuron> Layer;

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
        for (unsigned neur = 0; neur < m_layers[layerNum]-1; ++neur){
   
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
                m_layers.back().push_back(Neuron(numOutputs));
                std::cout << "made a neuron !!" << std::endl;
            }
        }
}


