#include <iostream>
#include "neuralnetwork.h"

int main()
{
    NeuralNetwork nn;
    InputNeuron *in1 = new InputNeuron(2);
    InputNeuron *in2 = new InputNeuron(3);
    OutputNeuron *out1 = new OutputNeuron(1);
    nn.addNeuron(in1);
    nn.addNeuron(in2);
    nn.addOutputNeuron(out1);
    out1->setExpectedOutput(1);
    if(nn.connectNeurons(0, 2) &&  nn.connectNeurons(1, 2))
    {
        nn.optimize();
        std::cout << out1->evaluate() << std::endl;
    }
    return 0;
}

