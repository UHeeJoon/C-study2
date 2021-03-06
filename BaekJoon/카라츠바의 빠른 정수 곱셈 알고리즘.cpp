/*

카라츠바의 빠른 정수 곱셈 알고리즘

*/

#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <chrono>

using namespace std;



//num[]의 자릿수 올림을 처리한다

void normalize(vector<int>& num)

{

    num.push_back(0);

    //자릿수 올림을 처리한다

    for (int i = 0; i < num.size() - 1; i++) //num.size()-1 중요

    {

        if (num[i] < 0)

        {

            int borrow = (abs(num[i]) + 9) / 10;

            num[i + 1] -= borrow;

            num[i] += borrow * 10;

        }

        else

        {

            num[i + 1] += num[i] / 10;

            num[i] %= 10;

        }

    }

    while (num.size() > 1 && num.back() == 0)

        num.pop_back();

}

//두 긴 자연수의 곱을 반환한다

//각 배열에는 각 수의 자릿수가 1의 자리에서부터 시작해 저장되어 있다

//예:multiply([3,2,1], [6,5,4])=123*456=56088=[8, 8, 0, 6, 5]

vector<int> multiply(const vector<int>& a, const vector<int>& b)

{

    vector<int> c(a.size() + b.size() + 1, 0);

    for (int i = 0; i < a.size(); i++)

        for (int j = 0; j < b.size(); j++)

            c[i + j] += (a[i] * b[j]);

    normalize(c);

    return c;

}



/*

//a+=b*(10^k)를 구현한다

vector<int> addTo(vector<int> &a, const vector<int> &b, int k)

{

        vector<int> b1, c;

        for (int i = 0; i < k; i++)

               b1.push_back(0);

        for (int i = 0; i < b.size(); i++)

               b1.push_back(b[i]);

        c.resize(a.size() + b1.size() + 1, 0);



        vector<int> rest = (a.size() >= b1.size()) ? a : b1; //덧셈을 마치고 더 긴 부분을 더해야한다

        int length = min(a.size(), b1.size());



        for(int i=0; i<length; i++)

               c[i] += (a[i] + b1[i]);

        if (length != rest.size()) //둘의 자릿수가 다르다면

        {

               for (int i = length; i < rest.size(); i++)

                       c[i] += rest[i];

        }

        //정규화

        for (int i = 0; i < c.size(); i++)

        {

               if (c[i] > 10)

               {

                       c[i + 1] += c[i] / 10;

                       c[i] %= 10;

               }

        }

        while (c.size() > 1 && c.back() == 0)

               c.pop_back();

        return c;

}



//a-=b;를 구현한다 a>=b를 가정한다

vector<int> subFrom(vector<int> &a, const vector<int> &b)

{

        vector<int> c;

        c.resize(a.size(), 0);

        for (int i = 0; i < b.size(); i++)//a>=b이므로

        {

               c[i] += (a[i] - b[i]);

        }

        if (a.size() != b.size()) //둘의 자릿수가 다르다면

        {

               for (int i = b.size(); i < a.size(); i++) //나머지

                       c[i] += a[i];

        }

        //정규화

        for (int i = 0; i < c.size(); i++)

               if (c[i] < 0)

               {

                       c[i] += 10;

                       c[i + 1]-=1;

               }

        while (c.size() > 1 && c.back() == 0)

               c.pop_back();

        return c;

}



//두 긴 정수의 곱을 반환한다

//(a0+a1)*(b0+b1)=(a0*b0)(=z0)+(a1*b0+a0*b1)(=z1)+(a1*b1)(=z2)의 원리

vector<int> karatsuba(const vector<int> &a, const vector<int> &b)

{

        int an = a.size(), bn = b.size();

        //a가 b보다 짧을 경우 둘을 바꾼다

        if (an < bn)

               return karatsuba(b, a);

        //기저 사례:a나 b가 비어있는 경우

        if (an == 0 || bn == 0)

               return vector<int>();

        //기저 사례:a가 비교적 짧은 경우 O(n^2) 곱셈으로 변경한다

        if (an <= 5)

               return multiply(a, b);

        int half = an / 2;

        //a와 b를 밑에서 half자리와 나머지로 분리한다

        vector<int> a0(a.begin(), a.begin() + half);

        vector<int> a1(a.begin() + half, a.end());

        vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));

        vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

        //z2=a1*b1

        vector<int> z2 = karatsuba(a1, b1);

        //z0=a0*b0

        vector<int> z0 = karatsuba(a0, b0);

        //a0=a0+a1;

        //b0=b0+b1

        a0=addTo(a0, a1, 0);

        b0=addTo(b0, b1, 0);

        //z1=(a0+a1)*(b0+b1)-z0-z2

        vector<int> z1 = karatsuba(a0, b0);

        z1=subFrom(z1, z0);

        z1=subFrom(z1, z2);

        //result=z0+z1*10^half+z2*10^(half*2)

        vector<int> result;

        result=addTo(result, z0, 0);

        result=addTo(result, z1, half);

        result=addTo(result, z2, half + half);

        return result;

}

*/



//a+=b*(10^k)를 구현한다

void addTo(vector<int>& a, const vector<int>& b, int k)

{

    int length = b.size();

    a.resize(max(a.size() + 1, b.size() + k));



    for (int i = 0; i < length; i++)

        a[i + k] += b[i]; //이렇게 함으로써 굳이 다른 vector를 선언하지 않아도 되고 간편해졌다



 //정규화              

    for (int i = 0; i < a.size(); i++)

    {

        if (a[i] >= 10)

        {

            a[i + 1] += a[i] / 10;

            a[i] %= 10;

        }

    }

}



//a-=b;를 구현한다 a>=b를 가정한다

void subFrom(vector<int>& a, const vector<int>& b)

{

    int length = b.size();

    a.resize(max(a.size() + 1, b.size()) + 1);



    for (int i = 0; i < length; i++)

        a[i] -= b[i];



    //정규화

    for (int i = 0; i < a.size(); i++)

    {

        if (a[i] < 0)

        {

            a[i] += 10;

            a[i + 1] -= 1;

        }

    }

}



//두 긴 정수의 곱을 반환한다

//(a0+a1)*(b0+b1)=(a0*b0)(=z0)+(a1*b0+a0*b1)(=z1)+(a1*b1)(=z2)의 원리

vector<int> karatsuba(const vector<int>& a, const vector<int>& b)

{

    int an = a.size(), bn = b.size();

    //a가 b보다 짧을 경우 둘을 바꾼다

    if (an < bn)

        return karatsuba(b, a);

    //기저 사례:a나 b가 비어있는 경우

    if (an == 0 || bn == 0)

        return vector<int>();

    //기저 사례:a가 비교적 짧은 경우 O(n^2) 곱셈으로 변경한다

    if (an <= 5)

        return multiply(a, b);

    int half = an / 2;

    //a와 b를 밑에서 half자리와 나머지로 분리한다

    vector<int> a0(a.begin(), a.begin() + half);

    vector<int> a1(a.begin() + half, a.end());

    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));

    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    //z2=a1*b1

    vector<int> z2 = karatsuba(a1, b1);

    //z0=a0*b0

    vector<int> z0 = karatsuba(a0, b0);

    //a0=a0+a1;

    //b0=b0+b1

    addTo(a0, a1, 0);

    addTo(b0, b1, 0);

    //z1=(a0+a1)*(b0+b1)-z0-z2

    vector<int> z1 = karatsuba(a0, b0);

    subFrom(z1, z0);

    subFrom(z1, z2);

    //result=z0+z1*10^half+z2*10^(half*2)

    vector<int> result;

    addTo(result, z0, 0);

    addTo(result, z1, half);

    addTo(result, z2, half + half);

    return result;

}



int main(void)

{

    using namespace std::chrono;



    vector<int> a, b, result;

    string number;

    high_resolution_clock::time_point t1, t2;

    duration<double> time_span; //시간 재기 위해



    cout << "첫번째 정수 입력: ";

    cin >> number;

    for (int i = number.size() - 1; i >= 0; i--)

        a.push_back(number[i] - '0');

    cout << "두번째 정수 입력: ";

    cin >> number;

    for (int i = number.size() - 1; i >= 0; i--)

        b.push_back(number[i] - '0');



    t1 = high_resolution_clock::now();

    result = multiply(a, b);

    for (int i = result.size() - 1; i >= 0; i--)

        cout << result[i];

    cout << endl;

    t2 = high_resolution_clock::now();

    time_span = duration_cast<duration<double>>(t2 - t1);

    cout << "기본 곱하기 경과시간: " << time_span.count() << "초" << endl;



    t1 = high_resolution_clock::now();

    result = karatsuba(a, b);

    t2 = high_resolution_clock::now();

    for (int i = result.size() - 1; i >= 0; i--)

        cout << result[i];

    cout << endl;

    time_span = duration_cast<duration<double>>(t2 - t1);

    cout << "카라츠바 곱하기 경과시간: " << time_span.count() << "초" << endl;



    return 0;

}