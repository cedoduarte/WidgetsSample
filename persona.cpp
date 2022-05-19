#include "persona.h"

void Persona::initialize()
{
    qRegisterMetaType<Persona>("Persona");
}

Persona::Persona(QObject *parent)
    : QObject(parent)
{
    m_nombre = "";
    m_edad = -1;
    m_salario = 0.0;
}

Persona::Persona(const QString &nombre, int edad, double salario, QObject *parent)
    : QObject(parent)
{
    m_nombre = nombre;
    m_edad = edad;
    m_salario = salario;
}

Persona::Persona(const Persona &other)
    : Persona(other.parent())
{
    m_nombre = other.m_nombre;
    m_edad = other.m_edad;
    m_salario = other.m_salario;
}

Persona::~Persona()
{
    // nothing to do here
}

void Persona::setNombre(const QString &nombre)
{
    if (m_nombre != nombre)
    {
        m_nombre = nombre;
        emit nombreChanged();
    }
}

void Persona::setEdad(int edad)
{
    if (m_edad != edad)
    {
        m_edad = edad;
        emit edadChanged();
    }
}

void Persona::setSalario(double salario)
{
    if (m_salario != salario)
    {
        m_salario = salario;
        emit salarioChanged();
    }
}
