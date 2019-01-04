#ifndef VOLUME_H
#define VOLUME_H

class Volume
{
    public:
        Volume();
        Volume(const size_t w, const size_t h, const size_t d);
        void getMemory(const size_t w, const size_t h, const size_t d);
        void fill(const unsigned char value);
        void setValue(const size_t x, const size_t y, const size_t z, const unsigned char value);
        void saveToFile(const std::string filename);
        void loadFromFile(const std::string filename);
        size_t getWidth();
        size_t getHeight();
        size_t getDepth();
        const unsigned char getValue(const size_t x, const size_t y, const size_t z);
        const unsigned char getValue(const float x, const float y, const float z);
        virtual ~Volume();
    protected:
    private:
        size_t w, h, d;
        unsigned char *data;
};

#endif // VOLUME_H
