#ifndef PERSONA_H
#define PERSONA_H

#include <QObject>
#include <QString>
#include <QMetaType>

class Persona : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nombre READ nombre WRITE setNombre NOTIFY nombreChanged)
    Q_PROPERTY(int edad READ edad WRITE setEdad NOTIFY edadChanged)
    Q_PROPERTY(double salario READ salario WRITE setSalario NOTIFY salarioChanged)
public:
    static void initialize();
    Persona(QObject *parent = nullptr);
    Persona(const QString &nombre, int edad, double salario, QObject *parent = nullptr);
    Persona(const Persona &other);
    virtual ~Persona();
    void setNombre(const QString &nombre);
    void setEdad(int edad);
    void setSalario(double salario);

    QString nombre() const
    {
        return m_nombre;
    }

    int edad() const
    {
        return m_edad;
    }

    double salario() const
    {
        return m_salario;
    }
signals:
    void nombreChanged();
    void edadChanged();
    void salarioChanged();
private:
    QString m_nombre;
    int m_edad;
    double m_salario;
};
Q_DECLARE_METATYPE(Persona)

#endif // PERSONA_H
