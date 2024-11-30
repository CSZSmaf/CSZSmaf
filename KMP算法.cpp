// #include<iostream>
// using namespace std;
// int n,m;
// constexpr int M=1e6+10;
// constexpr int N=1e5+10;
// int ne[M];
// char p[N];//要找的字符串
// char s[M];//更长的字符串（在其中查找）
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin>>n;
//     for(int i=0;i<n;i++) {
//         cin>>p[i];
//     }
//     cin>>m;
//     for(int i=0;i<m;i++) {
//         cin>>s[i];
//     }
//     //输入结束
//     //构建next数组
//     ne[0]=0;
//     int l=0;//表示相同的字符串长度
//     for(int i=1;i<m;i++) {
//         if(s[i]==p[l]) {
//             l++;
//             ne[i]=l;
//         }
//         //i=j+1;//会不会出现i在之后又加1的情况？
//         else {
//             while(s[i]!=p[l]&&l!=0){
//                 l=ne[l];
//             }
//             if(l==0) {
//                 if(s[i]==p[l]){l++;}
//                 ne[i]=l;
//             }
//             else{ne[i]=0;}
//         }
//     }
//     //对于next数组已经构建完成，进行比较操作
//     int j=0;//指着子序列的位置
//     for(int i=0;i<m;i++) {
//         if(j==n-1) {
//             cout<<i-n-1<<' ';
//             j=ne[j];
//         }
//         else if(s[i]==p[j]) {
//             j++;
//         }
//         else {
//             while(s[i]!=p[j]&&j!=0) {
//                 j=ne[j];
//             }
//         }
//     }
// }





// #include<iostream>
// using namespace std;
// constexpr int N=1000010;
// char p[N],s[N];
// int ne[N];
// int n,m;
// int main() {
//     cin>>n>>p>>m>>s;//注意输入的方式
//     ne[0]=-1;
//     for(int i=1,j=-1;i<n;i++) {
//         while(j!=-1&&p[i]!=p[j+1]) {
//             j=ne[j];
//         }
//         if(p[i]==p[j+1]) {
//             j++;
//         }
//         ne[i]=j;
//     }
//     for(int i=0,j=-1;i<m;i++) {
//         while(j!=-1&&s[i]!=p[j+1]) {
//             j=ne[j];
//         }
//         if(s[j]==p[j+1]) {
//             j++;
//         }
//         if(j==n-1) {
//             cout<<i-j<<' ';
//         }
//         j=ne[j];
//     }
//     return 0;
// }





#include<iostream>
using namespace std;
int n,m;
constexpr int M=1e6+10;
constexpr int N=1e5+10;
int ne[M];
char p[N];//要找的字符串
char s[M];//更长的字符串（在其中查找）
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>p[i];
    }
    cin>>m;
    for(int i=0;i<m;i++) {
        cin>>s[i];
    }
    //输入结束
    //构建next数组
    ne[0]=0;
    int l=0;//表示相同的字符串长度
    for(int i=1;i<n;i++) {//遍历数组，求每个位置的next//注意遍历的对象是要查找的长度短的数组
        if(p[i]==p[l]) {//错开一位？//注意前面检验的数组也是p
            l++;
            ne[i]=l;//加1，注意  ×不用加1
        }
        //i=j+1;//会不会出现i在之后又加1的情况？
        else {
            while(p[i]!=p[l]&&l!=0){
                l=ne[l-1];//注意要减一，长度和下标的对应关系
            }
            if(l!=0)ne[i]=l+1;
            if(l==0) {
                if(p[i]==p[l]){l++;ne[i]=l;}
                else{ne[i]=0;};
            }
        }
    }
    //对于next数组已经构建完成，进行比较操作
    int j=0;//指着子序列的位置
    for(int i=0;i<m;i++) {
        if(j==n) {
            cout<<i-n+1<<' ';
            j=ne[j-1];
        }
        else if(s[i]==p[j]) {
            j++;
        }
        else {
            while(s[i]!=p[j]&&j!=0) {
                j=ne[j-1];
            }
        }
    }
}






#include <iostream>
using namespace std;

int n, m;
constexpr int M = 1e6 + 10;
constexpr int N = 1e5 + 10;
int ne[N]; // next数组
char p[N]; // 要找的字符串
char s[M]; // 更长的字符串（在其中查找）

void build_ne() {
    ne[0] = 0; // ne[0] 总是 0
    int l = 0; // 表示相同的字符串长度
    for (int i = 1; i < n; i++) { // 遍历模式串，求每个位置的next
        while (l > 0 && p[i] != p[l]) {
            l = ne[l - 1]; // 回退到上一个最长前后缀
        }
        if (p[i] == p[l]) {
            l++;
        }
        ne[i] = l; // 记录当前的最长前后缀长度
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n; // 输入模式串长度
    for (int i = 0; i < n; i++) {
        cin >> p[i]; // 输入模式串
    }

    cin >> m; // 输入文本串长度
    for (int i = 0; i < m; i++) {
        cin >> s[i]; // 输入文本串
    }

    build_ne(); // 构建next数组

    int j = 0; // 指向模式串的位置
    for (int i = 0; i < m; i++) {
        while (j > 0 && s[i] != p[j]) {
            j = ne[j - 1]; // 回退到上一个最长前后缀
        }
        if (s[i] == p[j]) {
            j++;
        }
        if (j == n) { // 找到一个匹配
            cout << i - n + 1 << ' '; // 输出匹配的起始位置
            j = ne[j - 1]; // 继续查找下一个匹配
        }
    }
    return 0;
}

#include<iostream>
using namespace std;
int n,m;
constexpr int N=1e6+10;
int p[N];
int s[N];//这里错了，应该是char
int ne[N];
void build_ne() {
    ne[0]=0;
    for(int i=1,l=0;i<n;i++) {//j表示相同的字符串的长度
        while(p[i]!=p[l]&&l!=0){l=ne[l-1];}
        if(p[i]==p[l]) l++;ne[i]=l;//如果等于0且不等就会返回0
    }
}
int main() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i];
    cin>>m;
    for(int i=0;i<m;i++) cin>>s[i];//这样的输入方式错了，应该是cin>>n>>p>>m>>s;
    build_ne();
    //进行KMP搜索
    for(int i=0,j=0;i<m;i++) {
        while(s[i]!=p[j]&&j!=0){j=ne[j-1];}
        if(s[i]==p[j]) j++;
        if(j==n-1) cout<<i-n+1<<' ';
    }
}
