//OpenCV各类调用的实例

//OpenCV常见调用库
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>//core模块包含核心功能
#include <opencv2/highgui.hpp>//imgproc模块包含图像处理
#include<opencv2/imgproc.hpp>//highgui模块包含读写图像和视频
#include <iostream>

using namespace std;
using namespace cv;//OpenCV的名称空间

const string path = "/Users/zhouao/Downloads/cv2";//图片的

int main(int argc, const char * argv[])
{
    //图像对象的数据是由Mat对象进行存储
    Mat image = //Mat类型数据以矩阵方式存储图像
    imread(path + "/DSC05592.JPG",IMREAD_COLOR);//imread()函数读取指定地址的图片数据，以Mat类型返回
    //若不给参数默认以彩色(RGB)读取，若添加第二参数的宏可表示读取方式
    
    //Mat还包括一些图像的属性
    cout << image.cols << endl;//cols 长度
    cout << image.rows << endl;//rows 宽度
    cout << image.channels() << endl;//.channels()方法获取通道数
    
    namedWindow("origin");//以指定名称创建窗口
    imshow("origin", image);//将图片窗口化到目标窗口
    //在等待规定时间内接受一个按键再进行下一步的操作
    waitKey(0);//参数为0，表示一直等待下去
    
    //Mat是Opencv经过高度优化的数据结构，它自带了内存管理，可以通过检测引用数来释放不需要的内存。
    //它的赋值操作分为浅赋值和深复制，浅赋值能够不必复制大量的数据，从而提高程序的性能，最好只在需要深复制时在进行深复制。
    Mat gray(image);//初始化时使用浅赋值，这样变量的指针指向的是同一个数据
    //cvtColor()函数将图像色彩空间转换为指定类型
    cvtColor(image, gray, COLOR_RGB2GRAY);//第三个宏参数表示转换方式
    //imwrite()函数将图片写入指定位置
    imwrite("./data/picture/gray.jpg", gray);//相对地址寻址(文件放在执行文件同文件夹)
    
    return 0;
}
