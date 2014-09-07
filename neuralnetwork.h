#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <vector>
#include <cmath>
#include "neuron.h"
#include "connection.h"
#include "inputneuron.h"
#include "outputneuron.h"

class NeuralNetwork
{
    typedef std::vector<Neuron*> Neurons;
    typedef std::vector<InputNeuron*> InputNeurons;
    typedef std::vector<OutputNeuron*> OutputNeurons;

private:
    Neurons m_neurons;
    InputNeurons m_inputNeurons;
    OutputNeurons m_outputNeurons;

public:
    NeuralNetwork();
    Neuron* getNeuron(std::size_t);
    void addNeuron(Neuron*);
    void addOutputNeuron(OutputNeuron*);
    bool connectNeurons(std::size_t, std::size_t, double = 1);
    void optimize();
    double getError();

};

#endif // NEURALNETWORK_H
