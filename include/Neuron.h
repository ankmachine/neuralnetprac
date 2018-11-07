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
#include "Common.h"

class Neuron {
    public :
        Neuron(unsigned numOutputs, unsigned myIndex);
        void setOutputVal(double val){m_outputVal = val;}
        double getOutputVal(void) const {return m_outputVal;}
        void feedForward(const Layer &pervLayer);

    private :
        static double transferFunction(double x);
        static double transferFunctionDerivative(double x);
        static double randomWeight(void){ return rand()/double(RAND_MAX); }
        double m_outputVal;
        std::vector<Connection> m_outputWeights;
        unsigned m_myIndex ;
};

#endif
