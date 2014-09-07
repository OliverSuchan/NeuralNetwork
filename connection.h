#ifndef CONNECTION_H
#define CONNECTION_H

class Neuron;

class Connection
{
    friend class Neuron;
    friend class OutputNeuron;
    friend class NeuralNetwork;

private:
    Neuron *m_neuronFront;
    Neuron *m_neuronBack;
    double m_weight;

public:
    Connection(double p_weight = 1);
};

#endif // CONNECTION_H
