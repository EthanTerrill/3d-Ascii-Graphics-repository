#pragma once

const double ys = 2;

class point2d {
private:
    char type;
    double x;
    double y;
    bool canDraw;




public:
    point2d() {

        x = 0;
        y = 0; 

        type = '_';
        canDraw = true;
    };

    point2d(int x, int y) {

        this->x = x;
        this->y = y; 

        type = '_';
        canDraw = true;

    };

    point2d(point p, point camera, int bufferWidth, int bufferHeight) {
        

        point pT = p - camera;

        float z = pT.getZ();

        if (z > 0 ) {



            //create ratio value

            float ratio = 1;// float(bufferWidth) / float(bufferHeight);

            x = pT.getX() * ratio / z;
            y = pT.getY() / z;


            x += 1.0;
            y += 1.0;


            x *= 0.5 * bufferWidth;
            y *= 0.5 * bufferHeight * ys;


            if (y >= 0 && x >= 0 && y < bufferHeight && x < bufferWidth) {

                canDraw = true;
                

            }
            else {

                canDraw = false;
                x = 0;
                y = 0;
            }
        
        }
        else {

            canDraw = false;
            x = 0;
            y = 0;
        }
         
    };

    bool drawable() {
    
        return canDraw;
    }
    //setter functions

    void setX(double x) {

        this->x = x;


    }

    void setY(double y) {

        this->y = y;

    }
     

    void setType(char newType) {

        this->type = newType;
    }
    //getter functions

    double getX() {

        return x;


    }

    double getY() {

        return y;

    }
     

    char getType() {

        return type;
    }

    void move(int x, int y, int z) {

        this->x += x;
        this->y += y; 

    }


    double getDistanceFrom(point other) {

        double nx = x - other.getX();
        double ny = y - other.getY();

        return sqrt(nx * nx + ny * ny);




    }

    


    float getMagnitude() {


        return sqrt(x * x + y * y);

    }
    void normalize() {


        float mag = getMagnitude();

        if (mag != 0) {

            x /= mag;
            y /= mag; 


        }


    }
    void subtr(point2d a, point2d b) {

        point ret;

        this->x = a.getX() - b.getX();
        this->y = a.getY() - b.getY(); 

    }

    //function overloads


    point2d& operator=(point other) {

        this->x = other.getX();
        this->y = other.getY(); 

        return *this;

    }

    point2d& operator+(point2d other) {

        point2d ret(this->x + other.getX(), this->y + other.getY());

        return ret;

    }

    point2d operator-(point2d other) {

        point2d ret = point2d(this->x - other.getX(), this->y - other.getY());

        return ret;

    }

    float operator*(point other) {

        float ret = this->x * other.getX() + this->y * other.getY();

        return ret;

    }

    float cross(point other) {

        float ret = this->x * other.getY() - this->y * other.getX(); 


        return ret;
    }



};


bool sortByHeight(point2d a, point2d b)
{
    return (a.getY()) > (b.getY());
}

bool sortByX(point2d a, point2d b)
{
    return (a.getX()) > (b.getX());
}