class model{
    
    private:
    
    std::vector<polygon> triangles;
    std::vector<point>      points;
    
    
    public:
    
    
    model(std::string fileName){
        
        std::fstream f;
        f.open(fileName);
        
        char c;
       point* myPoints = (point*)std::malloc(sizeof(point) * 3);
        
        while(!f.eof()){
            
            f>>c;
            if(c == 'v' ){ 
                
                double bufferval[3]{ 0, 0, 0 };
                for(int i = 0; i < 3; i++){
                    
                    
                    f>>c;
                    
                    if(c == '-'){
                    
                        
                        f>>c;
                        
                        while(c != '.'){
                            
                            bufferval[i] *= 10;
                            bufferval[i] -= (c - 48); 
                            
                            f>>c;
                        }
                        for(int j = 1 ; j < 7; j++){
                            
                            f>>c;
                            
                            bufferval[i] -= double(c - 48) / (10 ^ j);
                        }
                        
                        
                    }
                    else{
                        
                        while(c != '.'){
                            
                            bufferval[i] *= 10;
                            bufferval[i] += (c - 48); 
                            
                            f>>c;
                        }
                        for(int j = 1 ; j < 7; j++){
                            
                            f>>c;
                            
                            bufferval[i] += double(c - 48) / (10 ^ j);
                            
                        }
                        
                    }
                    bufferval[i] *= 10;
                }
                
                points.push_back(point(bufferval[0], bufferval[1], bufferval[2]));
            }
            else if(c == 'f'){
                
                
                
                for (int i = 0; i < 3; i++){
                    f>>c;
                    myPoints[i] = point();
                    
                    myPoints[i].setX(points[c - 49].getX());
                    
                    myPoints[i].setY(points[c - 49].getY());
                    
                    myPoints[i].setZ(points[c - 49].getZ());
                    
                    
                }
                
                triangles.push_back(polygon(3, myPoints));
                
                
            }
            else if(f.eof()){
                exit;
            }
            else{
                std::cout <<"\nERROR\n" << (int)c;
                //while(1){}
            }
        }
        
    }
    
    int getFaceNum(){
        
        
        return triangles.size();
        
    }
    
    
    polygon getFace(int n){ 
        
        return triangles[n];
        
    }
    
    void rotate(point p, double thetaX, double thetaY, double thetaZ){
        
        for(int i = 0; i < triangles.size(); i++){
            
            triangles[i].rotate(p, thetaX, thetaY, thetaZ);
            
        }
    }
    
    void move(int x, int y, int z){
        
        for(int i = 0; i < triangles.size(); i++){
            
            triangles[i].move(x, y, z);
            
        }
        
    }
    
    
};