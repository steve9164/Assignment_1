#ifndef BODY_H
#define BODY_H

#include <QColor>
#include <QPointF>

// gravitational constant
#define G (6.67428e-11)

// astronomical unit
#define AU (1.4960000e+11)

class Body
{
private:
    // mass of body
    double m_mass;

    // radius of body
    double m_radius;

    // color of body
    QColor m_color;

    // position vector of body
    QPointF m_position;

    // velocity vector of body
    QPointF m_velocity;

    // Extra variables for summing forces
    QPointF m_totalForce;

public:
    Body(double mass,
         double radius,
         QPointF position,
         QPointF velocity,
         QColor color) :
         m_mass(mass),
         m_radius(radius),
         m_position(position),
         m_velocity(velocity),
         m_color(color) { }

    virtual ~Body() { }

    // get body mass
    double getMass() const { return m_mass; }

    // get body radius
    double getRadius() const { return m_radius; }

    // get body color
    QColor getColor() const { return m_color; }

    // get position of body
    QPointF getPosition() const { return m_position; }

    // get velocity of body
    QPointF getVelocity() const { return m_velocity; }

    // get Euclidean distance to other body
    double getDistance(const Body &other) const;

    // add exerted force vector from body "other"
    void addAttraction(const Body &other);

    // update velocity and position by total force for one time step
    void update(double timestep);
};

#endif // BODY_H
