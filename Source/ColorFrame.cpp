

//class constructor 
colorFrame::colorFrame(unsigned int width, unsigned int height) {

    this->width = width;
    this->height = height;
    std::cout << "1";


    ////////////////////////////////////////////////
    // Initialize buffer
    ///////////////////////////////////////////



    buffer = new char[(width * 12 + 1) * height];
    for (int y = 0; y < (width * 12 + 1) * height; y++) {



        buffer[y] = ' ';


    }

    std::cout << "3";

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            char color[12] = "\033[38;5;001m";

            for (int i = 0; i < 11; i++) {

                buffer[y * (width * 12 + 1) + x * 12 + i] = color[i];

                char col = (rand() % 10) + 48;

                setPixelColor(x, y, '0', '0', col);
            }

            buffer[y * (width * 12 + 1) + x * 12 + 11] = '2';


        }
        buffer[y * (width * 12 + 1) + width * 12] = '\n';
    }


    std::cout << "4";






    ////////////////////////////////////////////////
    // Initialize readBuffer
    ///////////////////////////////////////////


    rBuffer = new bool[(width + 1) * height];

    std::cout << "6";
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            rBuffer[y * (width + 1) + x] = false;

        }
        rBuffer[y * (width + 1) + width] = true;
    }

}


inline void colorFrame::setPixel(int x, int y, char c) {

    buffer[y * (width * 12 + 1) + x * 12 + 11] = c;

}
inline void colorFrame::setPixelColor(int x, int y, char a, char b, char c) {

    buffer[y * (width * 12 + 1) + x * 12 + 11 - 4] = a;
    buffer[y * (width * 12 + 1) + x * 12 + 11 - 3] = b;
    buffer[y * (width * 12 + 1) + x * 12 + 11 - 2] = c;
}


inline void colorFrame::setPixelColor(int x, int y, color col) {

    buffer[y * (width * 12 + 1) + x * 12 + 11 - 4] = col.getA() + 48;
    buffer[y * (width * 12 + 1) + x * 12 + 11 - 3] = col.getB() + 48;
    buffer[y * (width * 12 + 1) + x * 12 + 11 - 2] = col.getC() + 48;
}


void colorFrame::drawLineFunc(float small, float big, float ty, float tx, float m, char c) {

    for (float x = small; x < big; x++) {

        float h = ty + (m * (x - tx));

        if (h < height && x < width && x > 0 && h > 0 && rBuffer[int(h) * (width + 1) + int(x)] == false) {

            setPixel(x, h, c);
            rBuffer[int(h) * (width + 1) + int(x)] = true;

        }
    }

}
void colorFrame::drawLineFunc(float small, float big, float ty, float tx, float m, char c, color col) {

    for (float x = small; x < big; x++) {

        float h = ty + (m * (x - tx));

        if (h < height && x < width && x > 0 && h > 0 && rBuffer[int(h) * (width + 1) + int(x)] == false) {

            setPixelColor(x, h, col);
            setPixel(x, h, c);
            rBuffer[int(h) * (width + 1) + int(x)] = true;

        }
    }

}

void colorFrame::setBufferColorsRandom() {

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            char color[12] = "\033[38;5;001m";

            for (int i = 0; i < 11; i++) {

                buffer[y * (width * 12 + 1) + x * 12 + i] = color[i];

                char col = (rand() % 10) + 48;

                setPixelColor(x, y, '0', '0', col);
            }

           


        }
        buffer[y * (width * 12 + 1) + width * 12] = '\n';
    }

}


void colorFrame::show() {

    
    isPrinting = true;
    //display buffer
    printf("%s", buffer);

    //reset cursor to 0
    printf("\033[0;0H");
    isPrinting = false;

}


void colorFrame::clear() {

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            setPixel(x, y, ' ');
        }
    }

    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {

            rBuffer[y * (width + 1) + x] = false;

        }
    }

}

void colorFrame::drawHalfTriangle(point2d a, point2d b, point2d c, char fill) {



    // get starting points
    float xs = a.getX();
    float ys = a.getY();






    // calculate deltaX, deltaY
    float dx1 = -xs + b.getX();
    float dx2 = -xs + c.getX();

    float dy1 = -ys + b.getY();
    float dy2 = -ys + c.getY();



    //check to see which line is the start nd which is the end
    char y_s, ye;
    if (ys > b.getY()) {
        y_s = ys;
        ye = b.getY();


    }
    else {
        ye = ys;
        y_s = b.getY();

    }




    if (
        // check to make sure division is possible
        int(dy1) != 0 &&
        int(dy2) != 0 &&

        // check to make sure the points can be drawn
        a.drawable() &&
        b.drawable() &&
        c.drawable()
        )
    {

        //caclulate slope of line
        float m1, m2;
        m1 = (dx1) / (dy1);
        m2 = (dx2) / (dy2);
        float dy, xi, xf;

        //draw from first line to last line 
        for (float y = y_s; y > ye; y--) {



            dy = y - ys;
            xi = (dy)*m1 + xs;
            xf = (dy)*m2 + xs;


            if (xi > xf) {
                float t = xi;
                xi = xf;
                xf = t;
            }


            for (int x = xi; x < xf; x++) {



                if (y < height && x < width && x > 0 && y > 0 && rBuffer[int(y) * (width + 1) + int(x)] == false) {


                    setPixel(x, y, fill);

                    rBuffer[int(y) * (width + 1) + int(x)] = true;

                }
            }


        }
    }

}
void colorFrame::drawHalfTriangle(point2d a, point2d b, point2d c, char fill, color col) {



    // get starting points
    float xs = a.getX();
    float ys = a.getY();






    // calculate deltaX, deltaY
    float dx1 = -xs + b.getX();
    float dx2 = -xs + c.getX();

    float dy1 = -ys + b.getY();
    float dy2 = -ys + c.getY();



    //check to see which line is the start nd which is the end
    char y_s, ye;
    if (ys > b.getY()) {
        y_s = ys;
        ye = b.getY();


    }
    else {
        ye = ys;
        y_s = b.getY();

    }




    if (
        // check to make sure division is possible
        int(dy1) != 0 &&
        int(dy2) != 0 &&

        // check to make sure the points can be drawn
        a.drawable() &&
        b.drawable() &&
        c.drawable()
        )
    {

        //caclulate slope of line
        float m1, m2;
        m1 = (dx1) / (dy1);
        m2 = (dx2) / (dy2);
        float dy, xi, xf;

        //draw from first line to last line 
        for (float y = y_s; y > ye; y--) {



            dy = y - ys;
            xi = (dy)*m1 + xs;
            xf = (dy)*m2 + xs;


            if (xi > xf) {
                float t = xi;
                xi = xf;
                xf = t;
            }


            for (int x = xi; x < xf; x++) {



                if (y < height && x < width && x > 0 && y > 0 && rBuffer[int(y) * (width + 1) + int(x)] == false) {

                    setPixelColor(x, y, col);
                    setPixel(x, y, fill);

                    rBuffer[int(y) * (width + 1) + int(x)] = true;

                }
            }


        }
    }

}

void colorFrame::fillPoly(polygon p, camera cam, char fill) {

    //convert to 2d
    point2d a(p.getLine(0).getA(), cam, width, height);
    point2d b(p.getLine(1).getA(), cam, width, height);
    point2d c(p.getLine(2).getA(), cam, width, height);


    
    if (
        a.drawable() && //make sure all points are drawable
        b.drawable() &&
        c.drawable()


        )
    {
        //sort points by height on screen
        std::vector<point2d> longest;
        longest.push_back(a);
        longest.push_back(b);
        longest.push_back(c);
        std::sort(longest.begin(), longest.end(), sortByHeight);


        //draw top half of triangle
        drawHalfTriangle(longest[2], longest[1], longest[0], fill, p.getColor());

        //draw bottom half of triangle
        drawHalfTriangle(longest[0], longest[1], longest[2], fill, p.getColor());



        //clear memory
        longest.pop_back();
        longest.pop_back();
        longest.pop_back();





    }


}

void colorFrame::drawLine_3d(line L, camera cam) {




    point2d A(L.getA(), cam, width, height);
    point2d B(L.getB(), cam, width, height);

    double zTranslatedA = (L.getA().getZ() - cam.getZ());
    double zTranslatedB = L.getB().getZ() - cam.getZ();



    float rat = float(width) / float(height);

    if (A.drawable() && B.drawable()) {




        float Ay = A.getY();
        float Ax = A.getX();

        float By = B.getY();
        float Bx = B.getX();



        if (!(Ax == Bx)) {

            double slope = (Ay -By) / float(Ax - Bx);

            
            float big, small;

            if (Ax > Bx) {

                big     = Ax;
                small   = Bx;
            }
            else {

                big     = Bx;
                small   = Ax;
            }


            //decide which character to use while drawing the line

            char c = ' ';
            if (slope <= -0.5) {

                c = '/';
            }
            else if (slope >= -0.5 && slope <= 0.5) {

                c = '-';
            }
            else if (slope >= 0.5) {

                c = '\\';
            }
            else {

                c = '|';
            }


            drawLineFunc(small, big, Ay, Ax, slope, c);
        }
        


    }

}

void colorFrame::drawLine_3d(line L, camera cam, color col) {




    point2d A(L.getA(), cam, width, height);
    point2d B(L.getB(), cam, width, height);

    double zTranslatedA = (L.getA().getZ() - cam.getZ());
    double zTranslatedB = L.getB().getZ() - cam.getZ();



    float rat = float(width) / float(height);

    if (A.drawable() && B.drawable()) {




        float Ay = A.getY();
        float Ax = A.getX();

        float By = B.getY();
        float Bx = B.getX();



        if (!(Ax == Bx)) {

            double slope = (Ay - By) / float(Ax - Bx);


            float big, small;

            if (Ax > Bx) {

                big = Ax;
                small = Bx;
            }
            else {

                big = Bx;
                small = Ax;
            }


            //decide which character to use while drawing the line

            char c = ' ';
            if (slope <= -0.5) {

                c = '/';
            }
            else if (slope >= -0.5 && slope <= 0.5) {

                c = '-';
            }
            else if (slope >= 0.5) {

                c = '\\';
            }
            else {

                c = '|';
            }

            
            drawLineFunc(small, big, Ay, Ax, slope, c, col);
        }



    }

}
char colorFrame::getLightLevel(float light) {

    if (light > 0.99) {

        return '@';
    }
    else if (light > 0.9) {

        return '#';
    }
    else if (light > 0.5) {

        return '8';
    }
    else if (light > 0.3) {

        return '*';
    }
    else if (light > 0.1) {

        return '-';
    }
    else {

        return '.';
    }
};


void colorFrame::drawPoly_3d(polygon p, camera C) {

    point lightRay(0, 1, -1);

    //Find normal Vector
    point normal = p.getNormal();

    //normal dotted with light ray
    // gives amount of surface perpendicular to light i.e.
    // how bright surface should be

    float light = normal * lightRay;


    //get the character for associate birghtness
    char disp = getLightLevel(light);
    

    for (int i = 0; i < p.getNum(); i++) {

        point vec = p.getPoint(0) - C.getPoint();

        if (normal * vec < 0.0) {

           // drawLine_3d(p.getLine(i), C, p.getEdgeColor());


        }

    }

    point vec = p.getPoint(0) - C.getPoint();
    if (normal * vec < 0.0) {



        fillPoly(p, C, disp);


    }




}

void colorFrame::drawModel(model m, camera C) {

    for (int i = 0; i < m.getFaceNum(); i++) {
        drawPoly_3d(m.getFace(i), C);
    }

}

void colorFrame::addModelToRenderStack(model m) {

    for (int i = 0; i < m.getFaceNum(); i++) {
        renderStack.push_back(m.getFace(i));
    }
}
void colorFrame::drawRenderStack(camera C) {

    refCam = C.getPoint();
    std::sort(renderStack.begin(), renderStack.end(), sortByZaxis);
    for (int i = 0; i < renderStack.size(); i++) {

        drawPoly_3d(renderStack[i], C);

    }


}


boolean colorFrame::printing() {

    return isPrinting;
  
}