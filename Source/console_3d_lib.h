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
    #include "polygon.h"
    #include "camera.h" 
    #include "point2d.h"
    #include "model.h"
    #include "colorFrame.h" 
    

    bool sortByZaxis(polygon a, polygon b);


    point refCam(0, 0, 0);

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
        point A1 = (a.getLine(0).getA() - refCam);
        point B1 = (b.getLine(0).getA() - refCam);

        point A2 = (a.getLine(1).getA() - refCam);
        point B2 = (b.getLine(1).getA() - refCam);

        point A3 = (a.getLine(2).getA() - refCam);
        point B3 = (b.getLine(2).getA() - refCam);
        return (A1.getZ() + A2.getZ() + A3.getZ() < B1.getZ() + B2.getZ() + B3.getZ());
    }


#endif