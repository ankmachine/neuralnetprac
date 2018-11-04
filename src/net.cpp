#include "../include/Net.h"
#include <vector>
#include "../include/Neuron.h"
#include <iostream>

typedef std::vector<Neuron> Layer;

Net::Net(const std::vector<unsigned> &topology)
{    
    unsigned numLayers = topology.size();
    for(unsigned layerNum=0; layerNum<numLayers; ++layerNum)
        {
            m_layers.push_back(Layer());
        // we made new layer, fill it with neuron and a bias neuron
            for(unsigned neuronNum=0; neuronNum <= topology[layerNum]; ++neuronNum)
            {
                // start here
                m_layers.back().push_back(Neuron());
                std::cout << "made a neuron !!" << std::endl;
            }
        }
}
