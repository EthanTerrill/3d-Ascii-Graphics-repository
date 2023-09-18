class frame{
    
    private:
    
    unsigned int width;
    unsigned int height;
    
    
    char* buffer;
    
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
        
    }
    
    void show(){
        std::cout<<"\033[" << 0 << ";" << 0 << "H";
        
           //printf("%s\n", buffer[0]);
           

        printf("\033[%d;%dH", (0), (0));
        printf("%s\n", buffer);

        printf("\033[%d;%dH", (0), (0));
    }
    
    void invert(){
        
        for(int y = 0; y < height; y++){
            
            for(int x = 0; x < width; x++){
                
                buffer[y * (width + 1) + x] = (buffer[y * (width + 1) + x] == '*') * ('t') + (buffer[y * (width + 1) + x] != '*') * ('*');
                
            }
            
        }
        
    }
    void clear(){

        for(int y = 0; y < height; y++){
            
            for(int x = 0; x < width; x++){
                
                buffer[y * (width + 1) + x] = ' ';
                
            }
            
        }
        
    }
    
    void drawPoint(point A){
        
        if(A.getY() < height && A.getX() < width)
        buffer[int(A.getY() * (width + 1) + A.getX())] = A.getType();
        
        
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
        
    
        double zTranslatedA = L.getA().getZ() - cam.getZ();
        double zTranslatedB = L.getB().getZ() - cam.getZ();
            
            
            
        if( zTranslatedA > 0 && zTranslatedB > 0 ) {
            
            
            //define integers for storing the translated
            // x values of both points
            int xTranslatedA;
            int xTranslatedB;
            
            //translate according to the camera
            xTranslatedA    =   L.getA().getX() -   cam.getX();
            xTranslatedB    =   L.getB().getX() -   cam.getX();
            
            //divide by the trasnalted z value to make far away
            //objects look smaller
            xTranslatedA    =  double(xTranslatedA * 2) / double(sqrt(zTranslatedA)); 
            xTranslatedB    =  double(xTranslatedB * 2) / double(sqrt(zTranslatedB));
            
            //add 1/2 the width to the location in order
            //to make sure the point of oringin (0, 0) 
            //is in the middle of the screeen
            xTranslatedA    =   xTranslatedA + (0.5 * width);
            xTranslatedB    =   xTranslatedB + (0.5 * width);
            
            //define integers for storing the translated
            // x values of both points
            double yTranslatedA;
            double yTranslatedB;
            
            //translate according to the camera
            yTranslatedA    =   L.getA().getY() -   cam.getY();
            yTranslatedB    =   L.getB().getY() -   cam.getY();
            
            //divide by the trasnalted z value to make far away
            //objects look smaller 
            yTranslatedA    =  (yTranslatedA * 2) / double(sqrt(zTranslatedA)); 
            yTranslatedB    =  (yTranslatedB * 2) / double(sqrt(zTranslatedB));
            
            //add 1/2 the height to the location in order
            //to make sure the point of oringin (0, 0) 
            //is in the middle of the screeen
            yTranslatedA    +=   (0.5 * height);
            yTranslatedB    +=   (0.5 * height);
                
            if(!(xTranslatedA == xTranslatedB)){
                
                double slope  = double(yTranslatedA - yTranslatedB)/ double(xTranslatedA - xTranslatedB);
                
                int small;
                small = (xTranslatedA < xTranslatedB) * xTranslatedA;
                small = (xTranslatedA > xTranslatedB) * xTranslatedB + small;
                
                
                int big;
                big = (xTranslatedA > xTranslatedB) * xTranslatedA;
                big = (xTranslatedA < xTranslatedB) * xTranslatedB + big;
                
                
                
                if(slope <= -1){
                    
                    for(int x = small; x < big; x++){
                        
                        if(int(yTranslatedA + (slope * (x - xTranslatedA))) < height && x < width){
                            
                            int h = yTranslatedA + (slope * (x - xTranslatedA));
                            
                            buffer[ h * (width + 1) + x] = '\\';
                            
                        }
                    }   
                }
                else if(slope >= -0.5 && slope <= 0.5){
                    
                    for(int x = small; x < big; x++){
                        
                        if(int(yTranslatedA + (slope * (x - xTranslatedA))) < height && x < width){
                            
                            int h = yTranslatedA + (slope * (x - xTranslatedA));
                            
                            buffer[ h * (width + 1) + x] = '-';
                            
                        }
                    }   
                    
                }
                 else if(slope >= 1){
                    
                    for(int x = small; x < big; x++){
                        
                        if(int(yTranslatedA + (slope * (x - xTranslatedA))) < height && x < width){
                            
                            int h = yTranslatedA + (slope * (x - xTranslatedA));
                            
                            buffer[ h * (width + 1) + x] = '/';
                            
                        }
                    }   
                    
                }else{
                    for(int x = small; x < big; x++){
                        
                        if(int(yTranslatedA + (slope * (x - xTranslatedA))) < height && x < width){
                            
                            int h = yTranslatedA + (slope * (x - xTranslatedA));
                            
                            //buffer[ h * (width + 1) + x] = '@';
                            
                        }
                    }   
                    
                }
            }
            else{
                
                
                int small;
                small   =   (yTranslatedA < yTranslatedB) * yTranslatedA;
                small   =   (yTranslatedA > yTranslatedB) * yTranslatedB + small;
                
                
                int big;
                big = (yTranslatedA > yTranslatedB) * yTranslatedA;
                big = (yTranslatedA < yTranslatedB) * yTranslatedB + big;
                
                
                for(int Y = small; Y < big; Y++){
                    
                    if(Y < height && xTranslatedA < width)
                    buffer[int(Y) * (width + 1) + int(xTranslatedA)] = '|';
                    
                }
                
            }
            
        }
        
    }
    
    void fillPoly_3d(polygon p, camera cam){
        
        point pointA = p.getPoint(0);
        
        for(int i = 0; i < p.getLine(1).getLength(); i++){
            
            
            
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
    
    void drawPoly_3d(polygon p, camera C){
        
        for(int i = 0; i < p.getNum(); i++){
            point normal = p.getNormal();
            point vec = p.getPoint(0) - C.getPoint();
            if (normal * vec < 0.0) {
                drawLine_3d(p.getLine(i), C);
            }

            
        }
         
        
    }
    
    void drawModel(model m, camera C){
        
        for(int i = 0; i < m.getFaceNum(); i++){
            drawPoly_3d(m.getFace(i), C);
        }
        
    }
    
    
};