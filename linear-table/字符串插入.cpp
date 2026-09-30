// A:字符串插入
// 查看提交统计提问
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 有两个字符串str和substr，str的字符个数不超过10，substr的字符个数为3。（字符个数不包括字符串结尾处的'\0'。）
//将substr插入到str中ASCII码最大的那个字符后面，若有多个最大则只考虑第一个。
// 输入
// 输入包括若干行，每一行为一组测试数据，格式为
// str substr
// 输出
// 对于每一组测试数据，输出插入之后的字符串。
// 样例输入
// abcab eee
// 12343 555
// 样例输出
// abceeeab
// 12345553
#include<iostream>
#include<string>

using namespace std;

int main(){
    string str,sub;
    while(cin>>str>>sub){
       int index=0;
       char cmp=str[0];
       for (int i=0;i<str.size();++i){
         if(cmp<str[i]){
           index=i;
            cmp=str[i];
         }
      } 
      str.insert(index+1,sub);
      cout<<str<<endl;
    }
    return 0;
} 

/*
·這道題目的思路很簡單，分爲兩個部分解決
1.找出最大ascII碼的元素位置
2.在該位置的下一個位置插入
·在解決問題的過程中犯了如下錯誤
1.循環時i的範圍不對，寫爲小於str.size()-1,而不是小於等於
2.str.insert()應該是將該位置上的元素先右移，再插入，因而Insert的位置應該是index+1而不是index;
并且返回的是原字符串的引用，所以不需要創建新字符串
·對於優化，可以采用已經有的max_element進行尋找，優化代碼如下:

#include<iostream>
#include<string>

using namespace std;

int main(){
    string str,sub;
    while(cin>>str>>sub){
      auto id=max_element(str.begin(),std.end());
      str.insert(id+1,sub);
      cout<<str<<endl;
    }
}
*/

