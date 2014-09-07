#ifndef OUTPUTNEURON_H
#define OUTPUTNEURON_H

class OutputNeuron;

#include "neuron.h"

class OutputNeuron : public Neuron
{
    friend class NeuralNetwork;
    friend class Connection;

private:
    double m_output;
    void optimize() override;
    double getErrorSignal(double = std::numeric_limits<double>::signaling_NaN()) override;

public:
    OutputNeuron(double);
    void setExpectedOutput(double);
    double getExpectedOutput();

};

#endif // OUTPUTNEURON_H
