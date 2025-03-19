#include <iostream>
#include <string>
#include <map>
#include <memory>
using namespace std;
// 抽象图片读取器接口
class ImageReader {
public:
    virtual void read(const string& filePath) = 0;
    virtual ~ImageReader() = default;
};

// 具体GIF图片读取器
class GifReader : public ImageReader {
public:
    void read(const string& filePath) override {
        cout << "Reading GIF image from " << filePath << endl;
    }
};

// 具体JPEG图片读取器
class JpgReader : public ImageReader {
public:
    void read(const string& filePath) override {
        cout << "Reading JPEG image from " << filePath << endl;
    }
};

// 抽象图片读取器工厂
class ImageReaderFactory {
public:
    virtual unique_ptr<ImageReader> createReader(const string& type) = 0;
    virtual ~ImageReaderFactory() = default;
};

// 具体图片读取器工厂
class ConcreteImageReaderFactory : public ImageReaderFactory {
public:
    unique_ptr<ImageReader> createReader(const string& type) override {
        if (type == "GIF") {
            return make_unique<GifReader>();
        } else if (type == "JPEG") {
            return make_unique<JpgReader>();
        }
        throw invalid_argument("Unsupported image type");
    }
};

int main() {
    ConcreteImageReaderFactory factory;
    unique_ptr<ImageReader> reader = factory.createReader("GIF");
    reader->read("example.gif");
    reader = factory.createReader("JPEG");
    reader->read("example.jpg");
    return 0;
}
