#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <iostream>
#include <cmath>
#include <limits>
#include "connection.h"

#define ACTIVATE(x) (1.0 / (1.0 + std::exp(-x)))
#define ACTIVATE_DERIVED(x) (ACTIVATE(x) * (1.0 - ACTIVATE(x)))

class Neuron
{
    friend class NeuralNetwork;
    friend class Connection;
    typedef std::vector<Connection*> Connections;

    union InstanceValue {
        double m_thresholded;
        double m_input;
    };

protected:
    Connections m_connectionsForward;
    Connections m_connectionsBackwards;
    InstanceValue m_instVal;
    static constexpr double LEARN_RATE = 0.5;
    virtual double getErrorSignal(double = std::numeric_limits<double>::signaling_NaN());
    Neuron();

public:
    Neuron(double);
    double getNet();
    virtual double evaluate();
    virtual void optimize();

    template <typename T, typename... Ts>
    std::vector<bool> areConnected(T*, Ts*...);

    template <typename T>
    bool isConnected(T*);

};

template <typename T, typename... Ts>
std::vector<bool> Neuron::areConnected(T* p_firstArg, Ts* ... p_args)
{
    std::vector<bool> resultVec = std::vector<bool>(sizeof...(p_args) + 1);
    resultVec.push_back(isConnected(p_firstArg));
    std::vector<bool> tempVec = areConnected(p_args...);
    for(auto item : tempVec)
        resultVec.push_back(item);
    return resultVec;
}

template <typename T>
bool Neuron::isConnected(T* p_arg)
{
    for(auto con : m_connectionsBackwards)
        if(con->m_neuronFront == p_arg) return true;

    for(auto con : m_connectionsForward)
        if(con->m_neuronBack == p_arg) return true;
    return false;
}


#endif // NEURON_H
