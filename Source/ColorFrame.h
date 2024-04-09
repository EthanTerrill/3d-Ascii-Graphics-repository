#pragma once
class colorFrame {

private:

    sf::RectangleShape* rects;
    sf::RenderWindow* window;

    unsigned int width;
    unsigned int height;
    bool isPrinting = false;
   
    //buffer to tell if pixle is already written to
    bool* rBuffer = NULL;

    std::vector<polygon> renderStack;

    void drawLineFunc(float smal, float big, float ty, float tx, float m, char c);
    void drawLineFunc(float smal, float big, float ty, float tx, float m, float light, color col);
    char getLightLevel(float light);


public:


    /*Constructor*/ colorFrame(unsigned int width, unsigned int height, sf::RenderWindow* window);

    void resize();

    inline void setPixel(int x, int y, char c);

    inline void setPixelColor(int x, int y, char a, char b, char c);
    inline void setPixelColor(int x, int y, color col, float light);

    //randomize pixel colors
    void setBufferColorsRandom();

    //Display current state of buffer
    void show();

    void clear();

    void drawModel(model m, camera C);

    void drawLine_3d(line L, camera cam);
    void drawLine_3d(line L, camera cam, color c, float light);


    void drawPoly_3d(polygon p, camera C);

    void fillPoly(polygon p, camera cam, float light);

    void drawHalfTriangle(point2d a, point2d b, point2d c, float light);
    void drawHalfTriangle(point2d a, point2d b, point2d c, float lightl, color col);

    void addModelToRenderStack(model m);

    void drawRenderStack(camera C);

    boolean printing();



};