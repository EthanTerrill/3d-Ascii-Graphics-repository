#pragma once



uint32_t getBmpWidth(std::string bitmap) {


	assert(bitmap != "");


	std::ifstream ifs;
	ifs.open(bitmap, std::ios::binary);

	//read the header file 
	uint8_t headerbytes[54] = {};
	ifs.read((char*)headerbytes, sizeof(headerbytes));

	ifs.close();

	uint32_t width = *(uint32_t*)(headerbytes + 18);

	return width;
}

uint32_t getBmpHeight(std::string bitmap) {


	assert(bitmap != "");

	std::ifstream ifs;
	ifs.open(bitmap, std::ios::binary);

	//read the header file 
	uint8_t headerbytes[54] = {};
	ifs.read((char*)headerbytes, sizeof(headerbytes));

	ifs.close();
	uint32_t height = *(uint32_t*)(headerbytes + 22);

	return height;
}



class image {

private:
	unsigned int dimensionNum, width, height;


public:
	buffer* buffers;

	image() {

		width = 0;
		height = 0;
		buffers = new buffer();
		dimensionNum = 0;
	}

	image(unsigned int width, unsigned int height) {

		dimensionNum = 3;

		this->width = width;
		this->height = height;

		buffers = new buffer[3];

		for (int i = 0; i < 3; i++)
			buffers[i] = buffer(width, height, i, 3);



	}

	image(unsigned int width, unsigned int height, unsigned int dimensionNum) {



		this->width = width;
		this->height = height;
		this->dimensionNum = dimensionNum;

		buffers = new buffer[dimensionNum];

		for (int i = 0; i < dimensionNum; i++)
			buffers[i] = buffer(width, height, i, dimensionNum);
	}


	void open(std::string fileName) {

		this->dimensionNum = 3;

		this->width = getBmpWidth(fileName);
		this->height = getBmpHeight(fileName);

		this->buffers = new buffer[3];
		for (int i = 0; i < 3; i++) {
			this->buffers[i] = buffer(width, height, i, 3);
			buffers[i].open(fileName, i);
		}



	}



	int getDimensionNum() {
		return dimensionNum;
	}

	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}


	void clear() {

		for (int i = 0; i < dimensionNum; i++) {
			buffers[i].clear();
		}
	}

	buffer getBuffer(int index) {

		return buffers[index];

	}


};