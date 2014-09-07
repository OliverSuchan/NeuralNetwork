#ifndef INPUTNEURON_H
#define INPUTNEURON_H

class InputNeuron;

#include "neuron.h"

class InputNeuron : public Neuron
{
    friend class NeuralNetwork;
    friend class Connection;

public:
    InputNeuron(double);
    void setInput(double);
    double evaluate() override;

};

#endif // INPUTNEURON_H
