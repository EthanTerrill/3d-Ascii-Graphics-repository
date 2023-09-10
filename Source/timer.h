void WaitForMs(unsigned int t) {

    float milli_seconds = 1.0 * t;

    // Storing start time
    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds) {

    }

}