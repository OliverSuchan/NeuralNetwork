#include "neuron.h"

double Neuron::LEARN_RATE = 1.0;

double Neuron::evaluate()
{
    double net = getNet();
    return ACTIVATE(net - m_instVal.m_thresholded);
}

void Neuron::optimize()
{
    for(auto backCons : m_connectionsBackwards)
    {
        double e  =  getErrorSignal();
        double deltaWeight = LEARN_RATE * e * evaluate();
        backCons->m_weight += deltaWeight + MOMENTUM * m_prevDeltaWeight;
        m_prevDeltaWeight = deltaWeight;
    }
}

double Neuron::getErrorSignal(double p_value)
{
    double sum = .0;
    for(auto forCons : m_connectionsForward)
    {
        sum += forCons->m_neuronBack->getErrorSignal() * forCons->m_weight;
    }
    return ACTIVATE_DERIVED(getNet()) * sum;
}

Neuron::Neuron()
    : m_connectionsForward(),
      m_connectionsBackwards(),
      m_prevDeltaWeight(.0)
{
}

Neuron::Neuron(double p_thresholded)
    : m_connectionsForward(),
      m_connectionsBackwards(),
      m_prevDeltaWeight(.0)
{
    m_instVal.m_thresholded = p_thresholded;
}

double Neuron::getNet()
{
    double net = .0;
    for(auto con : m_connectionsBackwards)
    {
        net += con->m_neuronFront->evaluate() * con->m_weight;
    }
    return net;
}
