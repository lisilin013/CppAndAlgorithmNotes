#include <iostream>

using namespace std;


//---------------------------------------------------
// 问题：framework作为父类希望能够得到多年后创造的子类的信息
//---------------------------------------------------

enum imageType {
    LSAT, SPOT
};

/**
 * @brief: protype模式父类的定义
 */
class Image {
public:
    // 【必须是纯虚函数】，子类必须重新实现
    // 因为不同的子类，调用此函数的行为是不同的
    virtual void draw() = 0;

    // 【必须是static类型】，由prototype设计模式的调用方式决定
    // 调用方法：Image::findAndClone(imageType);
    // 当需要一个子类对应类型的实例对象的时候，通过调用该函数获取
    // 原理：根据子类的返回类型，调用子类实现的clone函数，返回对应的一个子类对象
    static Image *findAndClone(const imageType &type) {
        for (int i = 0; i < _nextSlot; i++)
            if (_prototypes[i]->returnType() == type)
                return _prototypes[i]->clone();

        // 万一没找对对应的type的处理方法
        // 事实上不会出现，因为ImageType的对象是提前定义好的
        // 如果传进来的是一个类型不符合的，编译期间就不会通过
        std::cerr << "Wrong Image Type\n";
        return nullptr;
    }

protected:
    // 【必须是纯虚函数】，用于获取子类的类型。子类中必须重新实现，告诉父类自己的类型情况
    virtual imageType returnType() = 0;

    // 【必须是纯虚函数】，子类重新实现，在里面创建一个自己，返回给父类调用
    virtual Image *clone() = 0;

    // 子类需要调用这个函数，相当于身份注册，告诉父类子类的存在
    // 【不一定必须是static成员函数】。这个地方之所以写成static形式是为了表明他是一个公有的身份
    static void addPrototype(Image *image) {
        _prototypes[_nextSlot++] = image;
    }
private:
    // addPrototype() 将每一个子类的prototype保存在这里
    // 【必须用static】，因为Image只有一份，所有的Image的Object都要存放在这里
    static Image *_prototypes[10];
    static int _nextSlot; // 下标移动，初始化为0
};

// static变量定义
Image *Image::_prototypes[];
int Image::_nextSlot;


/**
 * @brief: 未来创造的新的子类
 */
class LandSatImage : public Image {
public:
    // 告诉父类子类的类型，override表明显式重写
    imageType returnType() override {
        return LSAT;
    }

    // 该子类独有的行为
    void draw() override {
        cout << "LandSatImage::draw " << _id << endl;
    }

    // 父类调用想要clone的时候，调用的是子类的该函数
    // 返回该子类的一个object
    Image *clone() override {
        return new LandSatImage(1);//调用的是一个精心设计的构造函数，传入的参数没有实际意义，只是为了不想调用默认构造函数
    }
protected:
    // 这是一个非常经典的写法，是prototype里面的一个核心细节。
    // dummy并不会被用到，只是为了和默认构造函数相区分
    // 返回该子类的对象的构造函数，只会在clone里面被调用，所以设置为private区域也可以
    LandSatImage(int dummy) {
        _id = _count++;
    }
private:
    // 只会在子类的static LandSatImage _landSatImage成员初始化的时候调用
    LandSatImage() : _id(-1) {
        addPrototype(this);
    }

    // 调用上面的默认构造函数，然后调用父类中的addPrototype
    // 相当于将子类的type在父类的管理系统中进行了注册
    // 也就是无论以后有多少个该子类的object，只需要注册一次就行，告诉父类，现在存在这样一种子类的类型存在
    // 你可能要管理，父类就将子类的这种类型保存到了_prototypes[]数组中了
    // 以后有需要创建该子类的时候，父类通过查询子类的类型就知道，哦，我有你这种类型
    // 然后对应调用子类相对应的clone函数即可
    static LandSatImage _landSatImage;

    // 每一个该子类的实例都有一个独立的id
    int _id;
    static int _count; // id计数
};

LandSatImage LandSatImage::_landSatImage; // 初始化子类的static成员，告诉父类注册该子类的类型
int LandSatImage::_count = 1; // 每一个该子类的object都有一个不同的id


/**
 * @brief: 未来创造的新的子类
 */
class SpotImage : public Image {
public:
    imageType returnType() override {
        return SPOT;
    }
    void draw() override {
        cout << "SpotImage::draw " << _id << endl;
    }
    Image *clone() override {
        return new SpotImage(1);
    }
protected:
    SpotImage(int dummy) {
        _id = _count++;
    }
private:
    SpotImage() : _id(-1) {
        addPrototype(this);
    }
    static SpotImage _spotImage;
    int _id;
    static int _count;
};

SpotImage SpotImage::_spotImage; // 初始化子类的static成员，告诉父类注册该子类的类型
int SpotImage::_count = 1; // 每一个该子类的object都有一个不同的id


int main() {
    // 需要创建的图像请求输入流
    const int NUM_IMAGES = 8;
    imageType input[NUM_IMAGES] = {LSAT, LSAT, LSAT, SPOT, LSAT, SPOT, SPOT, LSAT};

    // 创建原形类数组对象，管理未来的输入流
    Image *images[NUM_IMAGES];

    // 根据输入流的图像类型，父类调用findAndClone函数，根据子类的返回类型，调用clone函数
    // 得到对应类型的子类object并返回，使用子类数组对象存储管理这些新创建的子类类型object
    for (int i = 0; i < NUM_IMAGES; i++)
        images[i] = Image::findAndClone(input[i]);

    // 对每一个不同种类的对象，执行对应的不同操作
    for (int i = 0; i < NUM_IMAGES; i++)
        images[i]->draw();

    // 释放原型数组对象，因为不是使用new[]，所以应该逐个delete
    for (int i = 0; i < NUM_IMAGES; i++)
        delete images[i];
}
