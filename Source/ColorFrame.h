#pragma once
class colorFrame {

private:

    unsigned int width;
    unsigned int height;


    char* buffer = NULL;
    //buffer to tell if pixle is already written to
    bool* rBuffer = NULL;

    std::vector<polygon> renderStack;

    void drawLineFunc(float smal, float big, float ty, float tx, float m, char c);
    char getLightLevel(float light);


public:
    

    /*Constructor*/ colorFrame(unsigned int width, unsigned int height);


    inline void setPixel(int x, int y, char c);
    
    inline void setPixelColor(int x, int y, char a, char b, char c);

    //randomize pixel colors
    void setBufferColorsRandom();

    //Display current state of buffer
    void show();

    void clear();

    void drawModel(model m, camera C);

    void drawLine_3d(line L, camera cam);

    void drawPoly_3d(polygon p, camera C);

    void fillPoly(polygon p, camera cam, char fill);

    void drawHalfTriangle(point2d a, point2d b, point2d c, char fill);

    void addModelToRenderStack(model m);

    void drawRenderStack(camera C);



};