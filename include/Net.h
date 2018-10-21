//
//  Net.h
//
//  Created by ankit sinha.
//  Copyright © 2018 ankit sinha. All rights reserved.
//


// making sure that compiling this wont give error incase NET is already imported
#ifndef NET_H
#define NET_H

#include vector

class Net
{
public :
    Net(topology);
    void feedForward(const std::vector<double> &inputVals);
    void backProp(const std::vector<double> &targetVals);
    void getResults(std::vector<double> &resultVals) const;

private :

}
#endif
