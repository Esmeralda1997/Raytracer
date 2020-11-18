#include "Scene.h"
#include <cmath>
#include <tgmath.h>
#include <iostream>
using namespace Raytracer148;
using namespace std;
using namespace Eigen;

HitRecord Scene::closestHit(const Ray &ray) {
    HitRecord result;
    result.t = -1;
    bool foundSomething = false;

    for (unsigned int i = 0; i < shapes.size(); i++) {
        HitRecord r = shapes[i]->intersect(ray);
        if (r.t > std::numeric_limits<double>::epsilon() && (!foundSomething || r.t < result.t)) {
            result = r;
            foundSomething = true;
        }
    }

    return result;
}

// Problem 2-4
Vector3d Scene::traceHelper(const Ray &ray, int counter) {
    
    HitRecord r = closestHit(ray);
    HitRecord srec;
    
    Vector3d result;
    result[0] = result[1] = result[2] = 0;
    
    if (r.t < numeric_limits<double>::epsilon()) return result;
    
    result=r.sh->A;
    r.position=ray.origin+r.t*ray.direction-ray.direction*0.00000000000001;
    
    
    Vector3d viewDir,lightDir, norm, halfVector;
    float sp,temp;

    viewDir[0]=0;
    viewDir[1]=0;
    viewDir[2]=1;
    
    norm=r.normal.normalized();
    
    //Diffuse
    lightDir = (lightPos - r.position).normalized();
    double dot = lightDir.dot(r.normal);
    if (dot < 0) dot = 0;
    
    Ray sray;
    sray.origin=r.position;
    sray.direction=lightDir.normalized();
    srec = closestHit(sray);
    
    halfVector=(-ray.direction.normalized()+lightDir).normalized();
    temp=norm.dot(halfVector);
    if(temp<0){
        temp=0;
    }
    
    sp=pow(temp,64);
    
    //Reflection
   result=result+r.sh->S*sp +r.sh->D*dot;

    Vector3d ref;
    ref=ray.direction.normalized()-2*(ray.direction.normalized().dot(r.normal))*r.normal;
    Ray reflectingRay;
    reflectingRay.origin=r.position;
    reflectingRay.direction=ref;

    float m=0.35;
    if(counter > 5){
        return result;
    }else{
        counter++;
        return result=result+m*traceHelper(reflectingRay,counter);
    }
    return result;
}

Vector3d Scene::trace(const Ray &ray) {
    return traceHelper(ray,1);
}


void Scene::render(Image &image) {
    // We make the assumption that the camera is located at (0,0,0)
    // and that the image plane happens in the square from (-1,-1,1)
    // to (1,1,1).

    assert(image.getWidth() == image.getHeight());

    int size = image.getWidth();
    double pixelSize = 2. / size;
    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++) {
            Ray curRay;
            curRay.origin[0] = curRay.origin[1] = curRay.origin[2] = 0;

            curRay.direction[0] = (x + 0.5) * pixelSize - 1;
            curRay.direction[1] = 1 - (y + 0.5) * pixelSize;
            curRay.direction[2] = 1;

            Vector3d color = trace(curRay);
            image.setColor(x, y, color[0], color[1], color[2]);
        }
}
