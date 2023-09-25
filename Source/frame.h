class frame {

private:

    unsigned int width;
    unsigned int height;


    char* buffer;
    bool* rBuffer;

    std::vector<polygon> renderStack;

    void drawLineFunc(float small, float big, float ty, float tx, float m, char c) {
    
        for (float x = small; x < big; x++) {

            float h = ty + (m * (x - tx));

            if (h < height && x < width && x > 0 && h > 0 && rBuffer[int(h) * (width + 1) + int(x)] == false) {



                buffer[int(h) * (width + 1) + int(x)] = c;
                rBuffer[int(h) * (width + 1) + int(x)] = true;
            }
        }
    
    }
    
    public: 
    

    frame(unsigned int width, unsigned int height){
        
        this->width = width;
        this->height = height;
        
        buffer = new char[ (width+1) * height - 4];
        
        for(int y = 0; y < height; y++){
            for(int x = 0; x < width; x++){
                buffer[y * (width + 1) + x] = '8'; 
                
            }
             buffer[y * (width + 1) + width] = '\n';
        }

        rBuffer = new bool[ (width+1) * height - 4];
        
        for(int y = 0; y < height; y++){
            for(int x = 0; x < width; x++){
               rBuffer[y * (width + 1) + x] = false; 
                
            }
            rBuffer[y * (width + 1) + width] = true;
        }
        
    }
    
    void show(){
        std::cout<<"\033[" << 0 << ";" << 0 << "H";
        
           //printf("%s\n", buffer[0]);
           

        printf("\033[%d;%dH", (0), (0));
        printf("%s\n", buffer);

        printf("\033[%d;%dH", (0), (0));
    }
    
  
    void clear(){

        for(int y = 0; y < height; y++){
            
            for(int x = 0; x < width; x++){
                
                buffer[y * (width + 1) + x] = ' ';
                
            }
            
        }
        for (int y = 0; y < height; y++) {

            for (int x = 0; x < width; x++) {

                rBuffer[y * (width + 1) + x] = false;

            }

        }
        
    }
    
    void drawPoint(point A){
        
        if (A.getY() < height && A.getX() < width && rBuffer[int(A.getY() * (width + 1) + A.getX())] == false) {
            buffer[int(A.getY() * (width + 1) + A.getX())] = A.getType();
            rBuffer[int(A.getY() * (width + 1) + A.getX())] = true;
        }
        
        
    }
    
    void drawLine(line L){
        
        
            
        if(!L.isVertical()){
            int small;
            small = (L.getA().getX() < L.getB().getX()) * L.getA().getX();
            small = (L.getA().getX() > L.getB().getX()) * L.getB().getX() + small;
            
            
            int big;
            big = (L.getA().getX() > L.getB().getX()) * L.getA().getX();
            big = (L.getA().getX() < L.getB().getX()) * L.getB().getX() + big;
            
            
            for(int x = small + (0.5 * width); x < big + (0.5 * width); x++){
                
                if(L.getA().getY() < height && x < width)
                buffer[int((L.getA().getY() + (0.5 * height)) + int(L.getSlope() * (x - L.getA().getX()))) * (width + 1) + x] = '#';
                
            }
            
        }
        else{
            
            
            int small;
            small = (L.getA().getY() < L.getB().getY()) * L.getA().getY();
            small = (L.getA().getY() > L.getB().getY()) * L.getB().getY() + small;
            
            
            int big;
            big = (L.getA().getY() > L.getB().getY()) * L.getA().getY();
            big = (L.getA().getY() < L.getB().getY()) * L.getB().getY() + big;
            
            for(int Y = small; Y < big; Y++){
                
                if(Y < height && L.getA().getX() < width)
                buffer[int(Y * (width + 1) + L.getA().getX())] = '#';
                
            }
            
        }
        
        
    }
    
    
    void drawLine_3d(line L, camera cam){
        
        


        point2d A(L.getA(), cam.getPoint(), width, height);
        point2d B(L.getB(), cam.getPoint(), width, height);

        double zTranslatedA = (L.getA().getZ() - cam.getZ());
        double zTranslatedB = L.getB().getZ() - cam.getZ();
            
        float rat = float(width) / float(height);
            
        if( zTranslatedA > 0 && zTranslatedB > 0 && A.drawable() && B.drawable()) {
            
            
             

            int h = A.getY();
            int x = A.getX();
            
            
                
            if(!(int(A.getX()) == int(B.getX())) ){
                
                double slope  = (A.getY() - B.getY()) /(A.getX() -B.getX());
                
                float small;
                small = (A.getX() <  B.getX()) * A.getX();
                small = (A.getX() >= B.getX()) * B.getX() + small;
                
                
                float big;
                big = (A.getX() > B.getX()) * A.getX();
                big = (A.getX() <= B.getX()) * B.getX() + big;
                 

                
                if (slope <= -0.5) {

                    drawLineFunc(small, big, A.getY(), A.getX(), slope, '/');
                }
                else if(slope >= -0.5 && slope <= 0.5){
                    
                    drawLineFunc(small, big, A.getY(), A.getX(), slope, '-');
                    
                }
                 else if(slope >= 0.5){
                    
                    drawLineFunc(small, big, A.getY(), A.getX(), slope, '\\');
                    
                }else{
                    drawLineFunc(small, big, A.getY(), A.getX(), slope, '|');
                    
                } 
            }
            else{
                
                
                float small;
                small = (A.getY() < B.getY()) * A.getY();
                small = (A.getY() >= B.getY()) * B.getY() + small;


                float big;
                big = (A.getY() > B.getY()) * A.getY();
                big = (A.getY() <= B.getY()) * B.getY() + big;
                
                
                for(int Y = small; Y < big; Y++){
                    
                    if (Y < height && A.getX() < width && Y >= 0 && A.getX() > 0 && rBuffer[int(Y) * (width + 1) + int(A.getX())] == false) {
                        buffer[int(Y) * (width + 1) + int(A.getX())] = '|';
                        rBuffer[int(Y) * (width + 1) + int(A.getX())] = true;
                    }
                    
                }
                
            }

            
        }
        
    }

    void drawLine_3d(line L, camera cam, char disp) {




        point2d A(L.getA(), cam.getPoint(), width, height);
        point2d B(L.getB(), cam.getPoint(), width, height);

        double zTranslatedA = (L.getA().getZ() - cam.getZ());
        double zTranslatedB = L.getB().getZ() - cam.getZ();

        float rat = float(width) / float(height);


        if (zTranslatedA > 0 && zTranslatedB > 0 && A.drawable() && B.drawable()) {




            int h = A.getY();
            int x = A.getX();



            if (!(int(A.getX()) == int(B.getX()))) {

                double slope = (A.getY() - B.getY()) / (A.getX() - B.getX());

                float small;
                small = (A.getX() < B.getX()) * A.getX();
                small = (A.getX() >= B.getX()) * B.getX() + small;


                float big;
                big = (A.getX() > B.getX()) * A.getX();
                big = (A.getX() <= B.getX()) * B.getX() + big;



                 
                drawLineFunc(small, big, A.getY(), A.getX(), slope, disp);
            }
            else {


                float small;
                small = (A.getY() < B.getY()) * A.getY();
                small = (A.getY() >= B.getY()) * B.getY() + small;


                float big;
                big = (A.getY() > B.getY()) * A.getY();
                big = (A.getY() <= B.getY()) * B.getY() + big;


                for (int Y = small; Y < big; Y++) {

                    if (Y < height && A.getX() < width && Y >= 0 && A.getX() > 0 && rBuffer[int(Y) * (width + 1) + int(A.getX())] == false) {
                        buffer[int(Y) * (width + 1) + int(A.getX())] = disp;
                        rBuffer[int(Y) * (width + 1) + int(A.getX())] = true;
                    }

                }

            }


        }

    }
    
    
    
    void drawPoly(polygon p){
        
        
        for(int i = 0; i < p.getNum(); i++){
            
            drawLine(p.getLine(i));
        }
        
    }
    
    /*
        void drawPoly_3d(polygon p, camera C){
            
            for(int i = 0; i < p.getNum(); i++){
                
                drawLine_3d(p.getLine(i), C);
                
            }
            
            for(int i = 0; i < p.getNum(); i++){
                
                drawLine_3d(p.getLine(i), C);
            }
            
        }
    */

    //requires that a-b is the hypotenuse

     
    
   /* void fillPoly(polygon p, camera cam) {


        point2d a(p.getLine(0).getA(), cam.getPoint(), width, height);
        point2d b(p.getLine(1).getA(), cam.getPoint(), width, height);
        point2d c(p.getLine(2).getA(), cam.getPoint(), width, height);

        if(p.getLine(0).getA().getZ() > cam.getZ() && p.getLine(1).getA().getZ() > cam.getZ() && p.getLine(2).getA().getZ() > cam.getZ())
            if (a.drawable() && b.drawable() && c.drawable()) {

                line A(point(a.getX(), a.getY(), 0), point(b.getX(), b.getY(), 0));
                line B(point(b.getX(), b.getY(), 0), point(c.getX(), c.getY(), 0));
                line C(point(c.getX(), c.getY(), 0), point(a.getX(), a.getY(), 0));

                float Al = A.getLength();
                float Bl = B.getLength();
                float Cl = B.getLength();



                std::vector<point2d> longest;
                longest.push_back(a);
                longest.push_back(b);
                longest.push_back(c);

                std::sort(longest.begin(), longest.end(), sortByHeight);


                float m1, m2;


                float xs = longest[0].getX();
                float ys = longest[0].getY();

                float dx1 = xs - longest[1].getX();
                float dx2 = xs - longest[2].getX();

                float dy1 = ys - longest[1].getY();
                float dy2 = ys - longest[2].getY();

                if (dy1 != 0 && dy2 != 0) {

                    if (longest[1].getX() < longest[2].getX())
                    {

                        m1 = (dx1) / (dy1);
                        m2 = (dx2) / (dy2);

                    }
                    else
                    {

                        m2 = (dx1) / (dy1);
                        m1 = (dx2) / (dy2);

                    }
                    for (float y = longest[0].getY(); y > longest[1].getY(); y--) {

                        float dy = y - ys;
                        float xi = (dy)*m1 + xs;
                        float xf = (dy)*m2 + xs;


                        for (int x = xi; x < xf; x++) {
                            if (y < height && x < width && x > 0 && y > 0) {



                                buffer[int(y) * (width + 1) + int(x)] = '@';

                            }
                        }

                    
                    }
                    ys = longest[2].getY();
                    xs = longest[2].getX();

                    dx1 = xs - longest[1].getX();
                    dx2 = xs - longest[0].getX();

                    float dy1 = ys - longest[1].getY();
                    float dy2 = ys - longest[0].getY();

                    if (longest[1].getX() < longest[0].getX())
                    {

                        m1 = (dx1) / (dy1);
                        m2 = (dx2) / (dy2);

                    }
                    else
                    {

                        m2 = (dx1) / (dy1);
                        m1 = (dx2) / (dy2);

                    }
                    for (float y = longest[2].getY(); y < longest[1].getY(); y++) {

                        float dy = y - ys;
                        float xi = (dy)*m1 + xs;
                        float xf = (dy)*m2 + xs;

                        for (int x = xi; x < xf; x++) {
                            if (y < height && x < width && x > 0 && y > 0) {



                                buffer[int(y) * (width + 1) + int(x)] = '@';

                            }
                        }
                    
                    }


                }


            }
            else {

                // add code for verticals
        
        
            }

        // also 

        /*
            if (int(dy1) != 0 && int(dy2) != 0) {

                m1 = (dx1) / (dy1);
                m2 = (dx2) / (dy2);
                float dy, xi, xf;


                for (float y = ys; y > longest[1].getY() ; y--) {

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



                            buffer[int(y) * (width + 1) + int(x)] = fill;
                            rBuffer[int(y) * (width + 1) + int(x)] = true;

                        }
                    }


                }
            }

            ys = longest[2].getY();
            xs = longest[2].getX();

            dx1 = -xs + longest[1].getX();
            dx2 = -xs + longest[0].getX();

            dy1 = -ys + longest[1].getY();
            dy2 = -ys + longest[0].getY();
            if (int(dy1) != 0 && int(dy2) != 0) {


                m1 = (dx1) / (dy1);
                m2 = (dx2) / (dy2);

                float dy;
                float xi, xf;
                for (float y = ys; y < longest[1].getY(); y++) {

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



                            buffer[int(y) * (width + 1) + int(x)] = fill;
                            rBuffer[int(y) * (width + 1) + int(x)] = true;

                        }
                    }

                }
            }

    
    }*/
    
    void drawHalfTriangle(point2d a, point2d b, point2d c, char fill) {


        float m1, m2;


        float xs = a.getX();
        float ys = a.getY();

        float dx1 = -xs + b.getX();
        float dx2 = -xs + c.getX();

        float dy1 = -ys + b.getY();
        float dy2 = -ys + c.getY();

        char y_s, ye;
        if (ys > b.getY()) {
            y_s = ys;
            ye = b.getY();
        }
        else {
            ye = ys;
            y_s = b.getY();
        }

        if (int(dy1) != 0 && int(dy2) != 0) {


            float m1, m2;
            m1 = (dx1) / (dy1);
            m2 = (dx2) / (dy2);
            float dy, xi, xf;


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



                        buffer[int(y) * (width + 1) + int(x)] = fill;
                        rBuffer[int(y) * (width + 1) + int(x)] = true;

                    }
                }


            }
        }

    }
    void fillPoly(polygon p, camera cam, char fill) {

        //convert 
        point2d a(p.getLine(0).getA(), cam.getPoint(), width, height);
        point2d b(p.getLine(1).getA(), cam.getPoint(), width, height);
        point2d c(p.getLine(2).getA(), cam.getPoint(), width, height);

        if (
            a.drawable() &&
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
            drawHalfTriangle(longest[2], longest[1], longest[0], fill);

            //draw bottom half of triangle
            drawHalfTriangle(longest[0], longest[1], longest[2], fill);
            


            //clear memory
            longest.pop_back();
            longest.pop_back();
            longest.pop_back();



            

        }


    }
    
    void drawPoly_3d(polygon p, camera C) {

        point a(0, 1, -1);
        point normal = p.getNormal();
        float light = normal * a;

        char disp = ' ';
        if (light > 0.99) {
            disp = '@';
        }
        else if(light > 0.9) {
        disp = '#';
        }
        else if (light > 0.5) {
            disp = '8';
        }
        else if (light > 0.3) {
            disp = '*';
        }
        else if (light > 0.1) {
            disp = '-';
        }
        else {

            disp = '.';

        }
       
        for(int i = 0; i < p.getNum(); i++){
            
            point vec = p.getPoint(0) - C.getPoint();
            if (normal * vec < 0.0) {

                //drawLine_3d(p.getLine(i), C);
                fillPoly(p, C, disp);
                
            }

            
        }

         
        
    }
    
    void drawModel(model m, camera C){
        
        for(int i = 0; i < m.getFaceNum(); i++){
            drawPoly_3d(m.getFace(i), C);
        }
        
    }

    void addModelToRenderStack(model m) {
    
        for (int i = 0; i < m.getFaceNum(); i++) {
            renderStack.push_back(m.getFace(i));
        }
    }
    void drawRenderStack(camera C) {
    
        refCam = C.getPoint();
        std::sort(renderStack.begin(), renderStack.end(), sortByZaxis);
        for (int i = 0; i < renderStack.size(); i++) {
            
            drawPoly_3d(renderStack[i], C);

        }


    }


    
};