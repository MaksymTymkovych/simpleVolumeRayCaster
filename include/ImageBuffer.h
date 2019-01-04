#ifndef IMAGEBUFFER_H
#define IMAGEBUFFER_H


class ImageBuffer
{
    public:
        ImageBuffer();
        ImageBuffer(const size_t w, const size_t h);
        void getMemory(const size_t w, const size_t h);
        void fill(const unsigned char value);
        void setValue(const size_t x, const size_t y, const unsigned char value);
        void saveToBitmap(const std::string fileName);
        size_t getWidth();
        size_t getHeight();
        virtual ~ImageBuffer();
    protected:
    private:
        size_t w, h;
        unsigned char * data;
};

#endif // IMAGEBUFFER_H
