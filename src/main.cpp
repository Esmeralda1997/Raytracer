#include <iostream>
#include "Image.h"
#include "Scene.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Shader.h"
#include <cmath>

// GLM Mathematics
#define GLM_FORCE_RADIANS // force everything in radian
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;
using namespace Raytracer148;
using namespace Eigen;

int main() {
    Image im(400, 400);

    Scene scene;

    Vector3d center,kAmb,kDif,kSpec,triangleV_1, triangleV_2, triangleV_3;

    //Sphere 1
    kAmb[0]=0.1;
    kAmb[1]=0.1;
    kAmb[2]=0;
    
    kDif[0]=0.5;
    kDif[1]=0.5;
    kDif[2]=0;
    
    kSpec[0]=1.0;
    kSpec[1]=1.0;
    kSpec[2]=1.0;
    
    center[0] = 1;
    center[1] = 1;
    center[2] = 4;
    scene.addShape(new Sphere(center, 2, kAmb, kDif, kSpec));

    
    //Sphere 2
    kAmb[0]=0.05;
    kAmb[1]=0;
    kAmb[2]=0.2;
    
    kDif[0]=0.25;
    kDif[1]=0;
    kDif[2]=0.5;
    
    kSpec[0]=1.0;
    kSpec[1]=1.0;
    kSpec[2]=1.0;
   
    center[0] = -1;
    center[1] = 1;
    center[2] = 2.5;
    scene.addShape(new Sphere(center, .5, kAmb, kDif, kSpec));

    
    //Sphere 3
    kAmb[0]=0.1;
    kAmb[1]=0;
    kAmb[2]=0.1;
    
    kDif[0]=0.5;
    kDif[1]=0;
    kDif[2]=0.5;
    
    kSpec[0]=1.0;
    kSpec[1]=1.0;
    kSpec[2]=1.0;
    
    center[0]=1;
    center[1]=-1;
    center[2]=3;
    scene.addShape(new Sphere(center, .5,kAmb,kDif,kSpec));
    
    //Problem 1
    kAmb[0]=0;
    kAmb[1]=0.1;
    kAmb[2]=0;
    
    kDif[0]=0;
    kDif[1]=0.5;
    kDif[2]=0;
    
    kSpec[0]=1.0;
    kSpec[1]=1.0;
    kSpec[2]=1.0;
    
    triangleV_1[0]=-1;
    triangleV_1[1]=-1;
    triangleV_1[2]=1;
    
    triangleV_2[0]=0.5;
    triangleV_2[1]=-1;
    triangleV_2[2]=1.5;
    
    triangleV_3[0]=0;
    triangleV_3[1]=0;
    triangleV_3[2]=2;
    scene.addShape(new Triangle(triangleV_1,triangleV_2,triangleV_3,kAmb,kDif,kSpec));
    
    
    scene.render(im);

    im.writePNG("test.png");

    return 0;
}

