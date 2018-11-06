//
//  Neuron.h
//
//  Created by ankit sinha.
//  Copyright © 2018 ankit sinha. All rights reserved.
//


// making sure that compiling this wont give error incase NEURON is already imported
#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include "./Connection.h"
#include <cstdlib>

class Neuron {
    public :
        Neuron(unsigned numOutputs);
        void feedForward(Layer &pervLayer);

    private :
        static double randomWeight(void){ return rand()/double(RAND_MAX); }
        double m_outputVal;
        std::vector<Connection> m_outputWeights;
};

#endif
