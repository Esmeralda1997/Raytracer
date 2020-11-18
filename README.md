# Raytracer

First, I had to move some files to successfully set up this project. I added 3 png header files to the include folder: png.h, pnglibconf.h, and pngconf.h. I procedded to add their paths to the makefile to make it run successfully. 

Before I changed anything else, I went ahead and ran the file to see what was already in the window. I saw that there were already 3 circles, so I decided to change the position and size of the circles. 

Part 1:
Once I had the position I wanted, I decided to put in a triangle as my other shape. So I created the new header and main Triangle file, to be able to create the traingle. Just like the sphere files I added a constructor and the HitRecord intersect function we can use to create the eigen triangle. So instead of passing one vector we will pass 3 vectors. Each will represent a vertex of the triangle. With the constructor we will store the 3 verte to 3 vertex in the triangle class as V1, V2, and V3. Inside of the new triangle file, we will use 4 matrices to calculate the matrices determinant to be able to figure out the correct result to return. After we have figured out the beta and gamma of the calculated matrices we pass if through some conditions to make sure we can even put it on the window. Notice how we just divided by MatA, because this is the starting matrix. If it passes these consitions we can go ahead and finish calculating the resulting matrix.

Part 2:
I will go into scene.cpp to change the color of the shapes. I will create a vector color that will store the colors we will use. In the trace function we will go throguh every row and column of the image so we can cast the correct color by the phong effect. There are 3 things we need to take into account when we create this effect. We need the color of the shape, the ambient light, the diffused light and the specular ligh†. So, we will add these 3 variables into the shapes class so we can store them and use them later. We will pass 3 matrices to the sphere and the triangle when we create them s they can have this effect. Now, in the scene.cpp file we will add the phong effect in the traceHelper function. With the same logic as with the previous assingment I will create a matrix with the normalized light position and the normalized vector r.

Part 4: 
Finally, I added the last part to the code. I went ahead and added a reflection algorithm to the code in scene.cpp. After creating the phong effect I calculated the reflection by find the dot product between the normalized direction matrix and the normalized r vector. Then we want to do this more than 4 times so we will use recursion to run this program until counter reaches 5 or above. We do this so we are able to find the correct light, color, and reflection for the image.



