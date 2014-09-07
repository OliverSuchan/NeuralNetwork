#include "inputneuron.h"

double InputNeuron::evaluate()
{
    return m_instVal.m_input;
}

InputNeuron::InputNeuron(double p_input) : Neuron()
{
    m_instVal.m_input = p_input;
}

void InputNeuron::setInput(double p_input)
{
    m_instVal.m_input = p_input;
}
