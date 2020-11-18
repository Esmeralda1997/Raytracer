# Raytracer

First, I had to move some files to successfully set up this project. I added 3 png header files to the include folder: png.h, pnglibconf.h, and pngconf.h. I procedded to add their paths to the makefile to make it run successfully. 

Before I changed anything else, I went ahead and ran the file to see what was already in the window. I saw that there were already 3 circles, so I decided to change the position and size of the circles. 

Once I had the position I wanted, I decided to put in a triangle as my other shape. So I created the new header and main Triangle file, to be able to create the traingle. Just like the sphere files I added a constructor and the HitRecord intersect function we can use to create the eigen triangle. So instead of passing one vector we will pass 3 vectors. Each will represent a vertex of the triangle. With the constructor we will store the 3 verte to 3 vertex in the triangle class as V1, V2, and V3. Inside of the new triangle file, we will use 4 matrices to calculate the 


