#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
using namespace std;
using namespace chrono;

template<typename T>
class Mat
{
    private:
    size_t rows;
    size_t cols;
    size_t channels;
    size_t length;
    shared_ptr<T> data;

    public:
    // 构造函数和析构函数
    Mat(size_t rows, size_t cols, size_t channels) : rows(rows), cols(cols), channels(channels){
        length = rows * cols * channels;
        T* ptr = new T[length];
        data.reset(ptr);
    }
    Mat(size_t rows, size_t cols, size_t channels, T a) : rows(rows), cols(cols), channels(channels)
    {
        length = rows * cols * channels;
        T* ptr = new T[length];
        data.reset(ptr);
        for (int i = 0; i < length; i++)
        {
            data.get()[i] = a;
        }
    }
    Mat(size_t row, size_t col, size_t channel, const shared_ptr<T>& array, size_t n) : rows(row), cols(col), channels(channel) {
        if (n != row * col * channel) {
            cerr << "传入数组长度不符！" << endl;
        } else {
            length = row * col * channel;
            data = array; 
        }  
    }

    ~Mat(){
        data.reset();
    }

    // get函数
    size_t getRows(){
        return rows;
    }
    size_t getCols(){
        return cols;
    }
    size_t getChannels(){
        return channels;
    }
    size_t getlength(){
        return length;
    }
    shared_ptr<T> getData(){
        if(data == NULL){
            return NULL;
        }else{
            return data;
        }
    }
    // 获取矩阵中的元素
    T getElement(size_t i) {
        // 进行边界检查
        if(i >= length || data == NULL){
            cerr << "无法调取元素！" << endl;
            return T();
        }else{
            return data.get()[i];
        }

    }
    T getElement(size_t row, size_t col, size_t channel) {
        if(row > rows || col > cols || channel > channels){
            cerr << "已越界！" << endl;
            return T();
        }else{
            size_t offset = (((row-1) * cols + (col-1)) * channels + (channel-1));
            return data.get()[offset];
        }
    }

    //set函数
    bool setElement(size_t i, T value){
        if(i >= length){
            cerr << "传入参数越界！" << endl;
            return false;
        }
        data.get()[i] = value;
        return true;
    }
    bool setElement(size_t row, size_t col, size_t channel, T value){
        if(row == 0 || col == 0 || channel == 0){
            cerr << "传入参数越界！" << endl;
            return false;
        }
        size_t offset = (((row-1) * cols + (col-1)) * channels + (channel-1));
        data.get()[offset] = value;
        return true;
    }

    // 操作符的重载
    Mat &operator()(const Mat& other)
    {
        if (other.data == NULL)
        {
            cerr << "传入空指针！" << endl;
            return *this;
        }
        else
        {
            rows = other.rows;
            cols = other.cols;
            channels = other.channels;
            data = other.data;
            return *this;
        }
    }
    Mat &operator=(const Mat& other)
    {
        if (other.data == NULL)
        {
            cerr << "传入空指针！" << endl;
            return *this;
        }
        else
        {
            rows = other.rows;
            cols = other.cols;
            channels = other.channels;
            data = other.data;
            return *this;
        }
    }
    bool operator==(const Mat& other)
    {
        // 对输入矩阵进行检查
        if (rows != other.rows || cols != other.cols || channels != other.channels)
        {
            return false;
        }
        else
        {
            T *raw_ptr1 = data.get(); // 获取指向数组的原始指针
            const T *raw_ptr2 = other.data.get();
            for (int i = 0; i < length; i++)
            {
                if (raw_ptr1[i] != raw_ptr2[i])
                {
                    return false;
                }
            }
            return true;
        }
    }

    template <typename T2>
    friend Mat<T2> operator+(const Mat<T2> &lhs, const Mat<T2> &rhs);
    template <typename T2>
    friend Mat<T2> operator+(T2 a, const Mat<T2> &lhs);
    template <typename T2>
    friend Mat<T2> operator-(const Mat<T2> &lhs, const Mat<T2> &rhs);
    template <typename T2>
    friend Mat<T2> operator-(T2 a, const Mat<T2> &lhs);
    template <typename T2>
    friend Mat<T2> operator*(const Mat<T2> &lhs, const Mat<T2> &rhs);
    template <typename T2>
    friend Mat<T2> operator*(T2 a, const Mat<T2> &lhs);

};

// 加法
template <typename T2>
Mat<T2> operator+(const Mat<T2> &lhs, const Mat<T2> &rhs)
{
    Mat<T2> result(lhs.rows,lhs.cols,lhs.channels);
    // 对输入矩阵进行检查
    if (lhs.rows != rhs.rows || lhs.cols != rhs.cols || lhs.channels != rhs.channels)
    {
        cerr << "矩阵大小不一致！" << endl;
        return result;
    }
    else
    {
        T2 *ptr = result.data.get();
        const T2 *raw_ptr1 = lhs.data.get(); // 获取指向数组的原始指针
        const T2 *raw_ptr2 = rhs.data.get();
        for (int i = 0; i < lhs.length; i++)
        {
            ptr[i] = raw_ptr1[i] + raw_ptr2[i]; // 修改元素值
        }
        return result;
    }
}
template <typename T2>
Mat<T2> operator+(T2 a, const Mat<T2> &lhs)
{
    Mat<T2> result(lhs.rows, lhs.cols, lhs.channels);
    Mat<T2> rhs(lhs.rows, lhs.cols, lhs.channels, a);
    // 对输入矩阵进行检查
    T2 *ptr = result.data.get();
    const T2 *raw_ptr1 = lhs.data.get(); // 获取指向数组的原始指针
    const T2 *raw_ptr2 = rhs.data.get();
    for (int i = 0; i < lhs.length; i++)
    {
        ptr[i] = raw_ptr1[i] + raw_ptr2[i]; // 修改元素值
    }
    return result;
}
template <typename T2>

// 减法
Mat<T2> operator-(const Mat<T2> &lhs, const Mat<T2> &rhs)
{
    Mat<T2> result(lhs.rows,lhs.cols,lhs.channels);
    // 对输入矩阵进行检查
    if (lhs.rows != rhs.rows || lhs.cols != rhs.cols || lhs.channels != rhs.channels)
    {
        cerr << "矩阵大小不一致！" << endl;
        return result;
    }
    else
    {
        T2 *ptr = result.data.get();
        const T2 *raw_ptr1 = lhs.data.get(); // 获取指向数组的原始指针
        const T2 *raw_ptr2 = rhs.data.get();
        for (int i = 0; i < lhs.length; i++)
        {
            ptr[i] = raw_ptr1[i] - raw_ptr2[i]; // 修改元素值
        }
        return result;
    }
}
template <typename T2>
Mat<T2> operator-(T2 a, const Mat<T2> &lhs)
{
    Mat<T2> result(lhs.rows, lhs.cols, lhs.channels);
    Mat<T2> rhs(lhs.rows, lhs.cols, lhs.channels, a);
    // 对输入矩阵进行检查
    T2 *ptr = result.data.get();
    const T2 *raw_ptr1 = lhs.data.get(); // 获取指向数组的原始指针
    const T2 *raw_ptr2 = rhs.data.get();
    for (int i = 0; i < lhs.length; i++)
    {
        ptr[i] = raw_ptr1[i] - raw_ptr2[i]; // 修改元素值
    }
    return result;
}

template <typename T2>
Mat<T2> operator*(const Mat<T2> &lhs, const Mat<T2> &rhs)
{
    Mat<T2> result(lhs.rows,lhs.cols,lhs.channels);
    // 对输入矩阵进行检查
    if (lhs.rows != rhs.rows || lhs.cols != rhs.cols || lhs.channels != rhs.channels)
    {
        cerr << "矩阵大小不一致！" << endl;
        return result;
    }
    else
    {
        T2 *ptr = result.data.get();
        const T2 *raw_ptr1 = lhs.data.get(); // 获取指向数组的原始指针
        const T2 *raw_ptr2 = rhs.data.get();
        for (int i = 0; i < lhs.length; i++)
        {
            ptr[i] = raw_ptr1[i] * raw_ptr2[i]; // 修改元素值
        }
        return result;
    }
}
template <typename T2>
Mat<T2> operator*(T2 a, const Mat<T2> &lhs)
{
    Mat<T2> result(lhs.rows, lhs.cols, lhs.channels);
    Mat<T2> rhs(lhs.rows, lhs.cols, lhs.channels, a);
    // 对输入矩阵进行检查
    T2 *ptr = result.data.get();
    const T2 *raw_ptr1 = lhs.data.get(); // 获取指向数组的原始指针
    const T2 *raw_ptr2 = rhs.data.get();
    for (int i = 0; i < lhs.length; i++)
    {
        ptr[i] = raw_ptr1[i] * raw_ptr2[i]; // 修改元素值
    }
    return result;
}


int main(){
    auto start = high_resolution_clock::now();
    
    int* array1 = new int[6]{1,2,3,4,5,6};
    int* array2 = new int[6]{1,1,1,1,1,1};

    shared_ptr<int> sp1(array1);
    shared_ptr<int> sp2(array2);

    // 初始化矩阵
    Mat <int> A(2,1,3,sp1,6);
    Mat <int> B(2,1,3,sp2,6);

    // 测试get和set
    cout << "before set: " << A.getElement(2,1,3) << endl;
    A.setElement(2,1,3,2);
    cout << "after set: " << A.getElement(2,1,3) << endl;

    // 测试构造函数
    float* array3 = new float[6]{1.0f,1.1f,1.2f,1.3f,1.4f,1.5f};
    shared_ptr<float> sp3(array3);
    Mat <float> C(2,1,3,sp3,6);
    Mat <int> D(2,1,3);
    Mat <int> E(2,1,3,1);
    cout << "方法一：";
    for(int i = 0; i < 6; i++){
        cout << D.getElement(i) << " ";
    }
    cout << endl;
    cout << "方法二：";
    for(int i = 0; i < 6; i++){
        cout << E.getElement(i) << " ";
    }
    cout << endl;
    cout << "方法三："; 
    for(int i = 0; i < 6; i++){
        cout << C.getElement(i) << " ";
    }
    cout << endl;

    // 测试（）和 = 
    Mat <float> C1 = C;
    Mat <float> C2(C);
    cout << "C: ";
    for(int i = 0; i < 6; i++){
        cout << C.getElement(i) << " ";
    }
    cout << endl;
    cout << "C1: ";
    for(int i = 0; i < 6; i++){
        cout << C1.getElement(i) << " ";
    }
    cout << endl;
    cout << "C2: ";
    for(int i = 0; i < 6; i++){
        cout << C2.getElement(i) << " ";
    }
    cout << endl;
    int a = C1 == C2;
    cout << "C1,C2是否相等: " << a << endl;

    // 测试 + 和 -
    C = C1 + C2;
    cout << "C1 + C2 = : ";
    for(int i = 0; i < 6; i++){
        cout << C.getElement(i) << " ";
    }
    cout << endl;
    C = C1 - C2;
    cout << "C1 - C2 = : ";
    for(int i = 0; i < 6; i++){
        cout << C.getElement(i) << " ";
    }
    cout << endl;

    // 测试 *
    C = C1 * C2;
    cout << "C1 * C2 = : ";
    for(int i = 0; i < 6; i++){
        cout << C.getElement(i) << " ";
    }
    cout << endl;
    C = 2.0f * C1;
    cout << "2 * C1 = : ";
    for(int i = 0; i < 6; i++){
        cout << C.getElement(i) << " ";
    }
    cout << endl;

        // 测试 + 和 -
    // 测试 *, 做 100000 次测量性能
    for (int i = 0; i < 100000; i++)
    {
         C = C1 + C2;
    }
    cout << "C1 + C2 = : ";
    for(int i = 0; i < 6; i++){
        cout << C.getElement(i) << " ";
    }
    cout << endl;
    // 测试 *, 做 100000 次测量性能
    for (int i = 0; i < 100000; i++)
    {
         C = C1 - C2;
    }
    cout << "C1 - C2 = : ";
    for(int i = 0; i < 6; i++){
        cout << C.getElement(i) << " ";
    }
    cout << endl;

    // 测试 *, 做 100000 次测量性能
    for (int i = 0; i < 100000; i++)
    {
         C = C1 * C2;
    }
    cout << "C1 * C2 = : ";
    for(int i = 0; i < 6; i++){
        cout << C.getElement(i) << " ";
    }
    cout << endl;
    C = 2.0f * C1;
    cout << "2 * C1 = : ";
    for(int i = 0; i < 6; i++){
        cout << C.getElement(i) << " ";
    }
    cout << endl;

    auto end = high_resolution_clock::now();

    // Calculate the duration
    auto duration = duration_cast<milliseconds>(end - start);

    // Output the duration
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;

    return 0;
}