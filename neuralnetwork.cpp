#include "neuralnetwork.h"

NeuralNetwork::NeuralNetwork()
    : m_neurons()
{
}

Neuron* NeuralNetwork::getNeuron(std::size_t p_index)
{
    if(p_index >= m_neurons.size() || p_index < 0)
      return nullptr;
    return  m_neurons.at(p_index);
}

void NeuralNetwork::addNeuron(Neuron *p_neuron)
{
    m_neurons.push_back(p_neuron);
}

void NeuralNetwork::addOutputNeuron(OutputNeuron *p_neuron)
{
    addNeuron(p_neuron);
    m_outputNeurons.push_back(p_neuron);
}

bool NeuralNetwork::connectNeurons(std::size_t p_firstNeuronIndex, std::size_t p_secondNeuronIndex, double p_weight)
{
    Neuron* p_firstNeuron = getNeuron(p_firstNeuronIndex);
    Neuron* p_secondNeuron = getNeuron(p_secondNeuronIndex);
    if(p_firstNeuron && p_secondNeuron)
    {
        if(p_firstNeuron->isConnected(p_secondNeuron))
            return true;
        else
        {
            Connection *con = new Connection;
            con->m_weight = p_weight;
            con->m_neuronFront = p_firstNeuron;
            con->m_neuronBack = p_secondNeuron;
            p_firstNeuron->m_connectionsForward.push_back(con);
            p_secondNeuron->m_connectionsBackwards.push_back(con);
            return p_firstNeuron->isConnected(p_secondNeuron);
        }
    }
    return false;
}

void NeuralNetwork::optimize()
{
    for(int i = 0; i < 10; i++)
    {
        for(auto n : m_neurons)
            n->optimize();
        std::cout << getError() << std::endl;
    }
}

double NeuralNetwork::getError()
{
    double error = .0;
    for(auto n : m_outputNeurons)
        error += std::pow(n->m_output - n->evaluate(), 2.0);
    return 0.5 * error;
}
