#ifndef __console_3d_lib__
    #define __console_3d_lib__
    #include <vector>
    #include <fstream>
    #include <algorithm>
    
    
    
    #include "point.h"
   // #include "physical.h"
   // #include "TheLiteralVoidThatBindsTheUniverseTogether.h"
    //TheLiteralVoidThatBindsTheUniverseTogether TheLiteralVoid;
    
   // #include "circle.h"
    #include "timer.h" 
    #include "line.h"


    #include "polygon.h"
    #include "camera.h" 

    #include "point2d.h"
    
    point refCam(0,0,0);
    bool sortByZaxis(polygon a, polygon b)
    {
        point A1 = (a.getLine(0).getA() - refCam);
        point B1 = (b.getLine(0).getA() - refCam);

        point A2 = (a.getLine(1).getA() - refCam);
        point B2 = (b.getLine(1).getA() - refCam);

        point A3 = (a.getLine(2).getA() - refCam);
        point B3 = (b.getLine(2).getA() - refCam);
        return (A1.getZ() + A2.getZ()  + A3.getZ() < B1.getZ() + B2.getZ() + B3.getZ());
    }
    
    #include "model.h"

    #include "frame.h" 
#endif