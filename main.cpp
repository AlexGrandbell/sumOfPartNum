//题目内容：
//给出N个正整数组成的数组A，求能否从中选出若干个，使他们的和为K。如果可以，输出："YES"，否则输出"NO"。
//
//输入格式:
//第1行：2个数N、K, N为数组的长度, K为需要判断的和(2 ≤N ≤ 20，1 ≤ K ≤ 10^9)
//第2 到第 N + 1行：每行1个数，对应数组的元素A[i] (1 ≤ A[i]≤ 10^6)
//
//输出格式：
//
//如果可以，输出："YES"，否则输出"NO"。
//样例输入
//4 13
//1
//2
//4
//7
//样例输出
//YES
//
//
//输入样例：
//
//5 9
//1
//2
//3
//4
//5
//
//输出样例：
//
//YES

//使用回溯法，递归求解

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;//N个数，和为K
vector<int> A;//存储N个数
int sum = 0;//当前和

void Backtrack(int i) {
    if (i >= N) {
        if (sum == K) {
            cout << "YES" << endl;
            exit(0);
        }
        return;
    }
    sum += A[i];
    Backtrack(i + 1);
    sum -= A[i];
    Backtrack(i + 1);
}


int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    Backtrack(0);
    cout << "NO" << endl;
    return 0;
}
