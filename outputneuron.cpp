#include "outputneuron.h"

void OutputNeuron::optimize()
{
    for(auto con : m_connectionsBackwards)
    {
        double e = getErrorSignal(m_output);
        double deltaWeight = LEARN_RATE * e * evaluate();
        con->m_weight += deltaWeight * MOMENTUM * m_prevDeltaWeight;
        m_prevDeltaWeight = deltaWeight;
    }
}

double OutputNeuron::getErrorSignal(double p_value)
{
    if(p_value == std::numeric_limits<double>::signaling_NaN())
        return .0;
    return ACTIVATE_DERIVED(getNet()) * (p_value - evaluate());
}

OutputNeuron::OutputNeuron(double p_thresholded)
    : Neuron(p_thresholded),
      m_output(1.0)
{
}

void OutputNeuron::setExpectedOutput(double p_expectedOutput)
{
    m_output = p_expectedOutput;
}

double OutputNeuron::getExpectedOutput()
{
    m_output;
}
