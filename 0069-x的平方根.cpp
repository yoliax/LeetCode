//实现int sqrt(int x)函数。
//
//计算并返回x的平方根，其中x 是非负整数。
//
//由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
//
//示例 1:
//
//输入: 4
//输出: 2
//示例 2:
//
//输入: 8
//输出: 2
//说明: 8 的平方根是 2.82842...,
//    由于返回类型是整数，小数部分将被舍去。

#include <iostream>

using namespace std;

int mySqrt(int a) {
    if (a == 0) return a;
    int l = 0, r = a, mid, sqrt;
    while (l <= r) {
        mid = (l + r) / 2;
        sqrt = a / mid;
        if (sqrt == mid)
            return mid;
        else if (mid > sqrt)
            r = mid - 1;
        else
            l = mid + 1;
//        cout << l << " " << r << " " << mid << " " << sqrt << endl;
    }
    return r;
}

int mySqrt2(int a) {
    long x = a;
    while (x * x > a) {
        x = (x + a / x) / 2;
    }
    return x;
}

int main() {
    cout << mySqrt2(8) << endl;
}