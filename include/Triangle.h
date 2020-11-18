#ifndef Triangle_h
#define Triangle_h

#include "Shape.h"

namespace Raytracer148 {
    class Triangle : public Shape {
    public:
        Triangle(Eigen::Vector3d &vertex0, Eigen::Vector3d &vertex1, Eigen::Vector3d &vertex2, Eigen::Vector3d &Ambient, Eigen::Vector3d &Diffuse, Eigen::Vector3d &Specular) :
            a(vertex0),b(vertex1),c(vertex2)
        {
            A=Ambient;
            D=Diffuse;
            S=Specular;
        }
        virtual HitRecord intersect (const Ray &ray);
    private:
        Eigen::Vector3d a;
        Eigen::Vector3d b;
        Eigen::Vector3d c;
    };
}

#endif /* Triangle_h */
