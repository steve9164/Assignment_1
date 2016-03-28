#include <cmath>
#include <QPointF>
#include "body.h"

// get Euclidean distance to other body
double Body::getDistance(const Body &other) const
{
    QPointF diff = other.getPosition() - m_position;
    return std::sqrt(QPointF::dotProduct(diff, diff));
}

// add exerted force vector from body "other"
void Body::addAttraction(const Body &other)
{
    QPointF diff = other.getPosition() - m_position;
    double lengthSquared = QPointF::dotProduct(diff, diff);

    // Add the exerted force as a vector
    m_totalForce += (G * m_mass * other.getMass() / lengthSquared) * (diff/std::sqrt(lengthSquared));
    // Formula for gravity using vectors = GMm/len(r)^2 * r_norm (where r_nrom = r/len(r))
}

// update velocity and position by an acceleration for one time step
void Body::update(double timestep)
{
    // integrate acceleration
    m_velocity += m_totalForce/m_mass * timestep;

    // integrate velocity
    m_position += m_velocity * timestep;

    // Reset total force
    m_totalForce = QPointF(0.0, 0.0);
}
