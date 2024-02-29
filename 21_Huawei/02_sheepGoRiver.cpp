#include <vector>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    // 羊的数量 M > 狼的数据 N  狼不会吃羊, 小船的容量 X
    int M, N, X, res = 0;
    cin >> M >> N >> X;
    // 总羊 - 总狼 > 2 才能保证两岸的狼不会吃羊
    if (M - N < 2) return 0; 

    // X 为偶数时候
    if (X % 2 == 0) {
        // 第一次运输特殊考虑，eg X = 4, 在保证当前岸边羊 > 狼，尽量先运输3羊 1狼
        if (M >= X/2 && N >= X/2) {
            if (M - X / 2 - 1 > N - X / 2 + 1) {
                // 当前岸边羊 > 狼
                M -= X / 2 + 1;
                N -= X / 2 - 1;
                cout << "第一次运输羊= " << (X/2 + 1) << " 狼= " << (X/2 - 1) << endl; 
            } else {
                // 只能一半羊，一半狼 - 1了， X=4 2羊 1狼
                M -= X / 2;
                N -= X / 2 - 1;
                cout << "第一次运输羊= " << (X/2) << " 狼= " << (X/2 - 1) << endl; 
            }
            res++;
        }
        // 中间过程运输
        while (M >= X/2 && N >= X/2) {
            M -= X/2;
            N -= X/2;
            res++;
            cout << "routine运输羊= " << (X/2) << " 狼= " << (X/2) << endl;
        }
    } else {
        // 第一次运输，eg X = 5, 尽量先3羊 2狼
        if (M >= X/2 && N >= X/2) {
            M -= X/2 + 1;
            N -= X/2;
            res++;
            cout << "第一次运输羊= " << (X/2 + 1) << " 狼= " << (X/2) << endl; 
        }

        // 中间过程运输 交替来的
        bool flag = true;
        // 单数运输 X/2 + 1 羊，X/2 狼 ； 双数运输 X/2 羊, X /2 + 1 狼
        while (M >= X/2 && N >= X/2) {
            // 当前岸羊 >= 狼 + 2, 可以运输 X/2+1 的羊 ， X/2 狼
            if (M > N + 1) {
                if (flag) {
                    M -= X/2 + 1;
                    N -= X/2;
                    flag = false;
                    res++;
                    cout << "1routine运输羊= " << (X/2 + 1) << " 狼= " << (X/2) << endl;
                } else {
                    M -= X/2;
                    N -= X/2 + 1;
                    flag = true;
                    res++;
                    cout << "1routine运输羊= " << (X/2) << " 狼= " << (X/2 + 1) << endl;
                }
            } else {
                // 当前岸 羊只比狼多1只，运输羊 = 狼过去
                if (M + N > X) {
                    M -= X/2;
                    N -= X/2;
                    res++;
                    cout << "1routine运输羊= " << (X/2) << " 狼= " << (X/2) << endl;
                } else {
                    M -= X/2 + 1;
                    N -= X/2;
                    res++;
                    cout << "1routine运输羊= " << (X/2 + 1) << " 狼= " << (X/2) << endl;
                }
            }
        }
    }
        
    if (M == 0 && N == 0) {
        cout << "final res = " << res << endl;
        return 0;
    }
    // 狼不足半船，如果羊 + 狼 》 船，将狼运输完，再运输羊
    if (M + N > X) {
        M -= X - N;
        cout << "最后运输羊= " << (X - N) << " 狼= " << (N) << endl;
    } else {
        // 全部运输过去
        M -= M;
        N -= N;
        cout << "最后运输羊= " << (M) << " 狼= " << (N) << endl;
    }
    res++;
    // 还有羊，就一直运输羊
    while (M > 0) {
        M -= M;
        res++;
        cout << "最后运输羊= " << (M) << endl;
    }
    cout << "final res = " << res << endl;
    return 0;
}