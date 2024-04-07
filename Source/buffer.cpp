#pragma once

const int BUFFER_MAX_SIZE = 999999;
const int BUFFER_MAX_DIMENSION = 99999;

struct buffer {

private:

    unsigned int width, height;

public:
    char** data;

    buffer() {

        width = height = 0;
        data = NULL;

    }


    buffer(int width, int height, int dimension,  int dimensionNum) {




       
        
            
        assert(width        >  0 && width           < BUFFER_MAX_SIZE);
        assert(height       >  0 && height          < BUFFER_MAX_SIZE);
        assert(dimensionNum >  0 && dimensionNum    < BUFFER_MAX_DIMENSION);
        assert(dimension    >= 0 && dimension       < dimensionNum);
         


        this->width = width;
        this->height = height;

        data = new char*[width];
        for (int i = 0; i < width; i++) {
        
            data[i] = new char[height] ;
        }
        




        delete[] data;


    }

   


    void clear() {
        for (int i = 0; i < width * height; i++) {
        
            data[i] = 0;
        }
    }
   
    void copy(buffer b) {
    
        

    }


    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }

    char** showBuffer() {

        return data;

       
    }
    void open(std::string fileName, int index) {
        



        float*** buffer = nullptr;
        



        // get the size of the required padding
        int padSize = width % 4;

        //empty char to write to
        char* c = new char[4];

        //read past the header file 
        uint8_t headerbytes[54] = {};

        std::ifstream ifs;
        ifs.open(fileName, std::ios::binary);

        if (ifs.good()) {

            ifs.read((char*)headerbytes, sizeof(headerbytes));




            for (unsigned int row = 0; row < height; row++) {
                for (unsigned int col = 0; col < width; col++) {
                    buffer[0][col][row] = float(ifs.get());
                    buffer[1][col][row] = float(ifs.get());
                    buffer[2][col][row] = float(ifs.get());

                    data[row][col] = buffer[index][col][row];
                }

                ifs.read(c, padSize);
            }
            ifs.close();



            
            
        }
        delete[] buffer;

    }





};