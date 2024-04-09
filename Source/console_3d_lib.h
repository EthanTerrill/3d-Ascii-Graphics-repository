#ifndef __console_3d_lib__
    #define __console_3d_lib__

    #include <iostream>
    #include <time.h>
    #include <thread>
    #include <math.h>
    #include <float.h>

    #include <io.h>

    #include <windows.h>
    #include <cwchar> 

    #include <vector>
    #include <fstream>
    #include <algorithm>


    #include <cassert>
    
#undef small
    
    #include "color.h"
    #include "point.h"
    #include "timer.h" 
    #include "line.h"
    #include "camera.h" 
    #include "polygon.h"
    #include "point2d.h"
    #include "model.h"
    #include "colorFrame.h" 
    

    bool sortByZaxis(polygon a, polygon b);


    point origin = point(0, 0, 0);
    point refCam(0, 0, 0);
    float tX = 0;
    float tY = 0;
    float tZ = 0;

    #include "buffer.cpp"
    #include "image.cpp"

    #include "color.cpp"
    #include "point.cpp"
    #include "line.cpp"
    #include "polygon.cpp"
    #include "camera.cpp"
    #include "point2d.cpp"
    #include "model.cpp"
    #include "ColorFrame.cpp"


    bool sortByZaxis(polygon a, polygon b)
    {

        return (a.getTPoint(0).getZ() + a.getTPoint(1).getZ() + a.getTPoint(2).getZ() < b.getTPoint(0).getZ() + b.getTPoint(1).getZ() + b.getTPoint(2).getZ());
    }


#endif