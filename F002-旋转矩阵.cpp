//给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
//
//不占用额外内存空间能否做到？
//
//示例 1:
//
//给定 matrix =
//[
//[1,2,3],
//[4,5,6],
//[7,8,9]
//],
//
//原地旋转输入矩阵，使其变为:
//[
//[7,4,1],
//[8,5,2],
//[9,6,3]
//]
//示例 2:
//
//给定 matrix =
//[
//[ 5, 1, 9,11],
//[ 2, 4, 8,10],
//[13, 3, 6, 7],
//[15,14,12,16]
//],
//
//原地旋转输入矩阵，使其变为:
//[
//[15,13, 2, 5],
//[14, 3, 4, 1],
//[12, 6, 8, 9],
//[16, 7,10,11]
//]
//


#include <iostream>
#include <vector>

using namespace std;

// 转置
void T(vector <vector<int>> &M) {
    for (int i = 0; i < M.size(); i++) {
        for (int k = 0; k <= i; k++) {
            swap(M[i][k], M[k][i]);
        }
    }
}

// 按行反转
void C(vector <vector<int>> &M) {
    for (int i = 0; i < M.size(); i++) {
        int l = 0, r = M.size() - 1;
        while (l < r) {
            swap(M[i][l], M[i][r]);
            l++;
            r--;
        }
    }
}


int main() {
//    vector <vector<int>> M = {{1, 2, 3},
//                              {4, 5, 6},
//                              {7, 8, 9}};
    vector <vector<int>> M = {
            {15, 13, 2,  5},
            {14, 3,  4,  1},
            {12, 6,  8,  9},
            {16, 7,  10, 11}
    };
    cout << "原始矩阵" << endl;
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M.size(); j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }

    T(M);
    cout << "转置" << endl;
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M.size(); j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }

    C(M);
    cout << "按行反转" << endl;
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M.size(); j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
