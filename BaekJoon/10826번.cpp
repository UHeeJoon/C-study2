#include <bits/stdc++.h>
using namespace std;

using cpd = complex<double>;
const double PI = acos(-1);

void fft(vector<cpd>& v, bool inv) {
    int n = v.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(v[i], v[j]);
    }

    double ang = -2 * PI / n;
    if (inv) ang = -ang;

    vector<cpd> twd(n >> 1);
    for (int i = 0; i < n / 2; i++) twd[i] = cpd(cos(ang * i), sin(ang * i));

    for (int i = 2; i <= n; i <<= 1) {
        int idx = n / i;
        for (int j = 0; j < n; j += i) {
            for (int k = 0; k < i / 2; k++) {
                cpd o = v[j + k];
                cpd e = v[j + k + i / 2] * twd[idx * k];
                v[j + k] = o + e;
                v[j + k + i / 2] = o - e;
            }
        }
    }

    if (inv) for (int i = 0; i < n; i++) v[i] /= n;
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<cpd> a_fft(a.begin(), a.end());
    vector<cpd> b_fft(b.begin(), b.end());

    int n = 1;
    while (n <= (int)max(a.size(), b.size())) n <<= 1;
    n <<= 1;
    a_fft.resize(n);
    b_fft.resize(n);

    fft(a_fft, 0);
    fft(b_fft, 0);
    for (int i = 0; i < n; i++) a_fft[i] *= b_fft[i];
    fft(a_fft, 1);

    vector<int> ret(n);
    for (int i = 0; i < n; i++) ret[i] = round(a_fft[i].real());

    return ret;
}

typedef struct INTT {
    string s;
    friend ostream& operator << (ostream& os, const INTT& a) {
        return os << a.s;
    }
    friend istream& operator >> (istream& is, INTT& a) {
        return is >> a.s;
    }
    inline bool operator < (const INTT& o) const {
        return s < o.s;
    }
    inline bool operator > (const INTT& o) const {
        return s > o.s;
    }
    inline bool operator <= (const INTT& o) const {
        return s <= o.s;
    }
    inline bool operator >= (const INTT& o) const {
        return s >= o.s;
    }
    inline bool operator == (const INTT& o) const {
        return s == o.s;
    }
    INTT operator = (const INTT& o) {
        s = o.s;
        return *this;
    }
    INTT operator + (const INTT& o) const {
        INTT ret = *this > o ? *this : o;
        INTT a = *this < o ? *this : o;
        int size = max(a.s.size(), ret.s.size());
        reverse(a.s.begin(), a.s.end());
        reverse(ret.s.begin(), ret.s.end());
        a.s.resize(size, '0');
        ret.s.resize(size, '0');
        for (int i = 0; i < size; i++) {
            ret.s[i] += a.s[i] - '0';
            if (ret.s[i] > '9') {
                if (i == size - 1) ret.s += "1";
                else ret.s[i + 1]++;
                ret.s[i] -= 10;
            }
        }
        reverse(ret.s.begin(), ret.s.end());
        return ret;
    }
    INTT operator += (const INTT& o) {
        *this = *this + o;
        return *this;
    }
    INTT& operator++() {
        *this += {"1"};
        return *this;
    }
    INTT operator++(int) {
        INTT tmp = *this;
        ++* this;
        return tmp;
    }
    INTT operator * (const INTT& o) const {
        INTT a = *this;
        INTT b = o;
        reverse(a.s.begin(), a.s.end());
        reverse(b.s.begin(), b.s.end());
        while (a.s.length() & 1) a.s += "0";
        while (b.s.length() & 1) b.s += "0";

        vector<int> av(a.s.length() >> 1);
        vector<int> bv(b.s.length() >> 1);

        for (int i = 0; i < a.s.length(); i += 2) {
            av[i >> 1] = a.s[i] - '0' + (a.s[i + 1] - '0') * 10;
        }

        for (int i = 0; i < b.s.length(); i += 2) {
            bv[i >> 1] = b.s[i] - '0' + (b.s[i + 1] - '0') * 10;
        }

        vector<int> t = multiply(av, bv);

        for (int i = 0; i < t.size(); i++) {
            if (t[i] / 100) {
                if (i == t.size() - 1) t.emplace_back(t[i] / 100);
                else t[i + 1] += t[i] / 100;
                t[i] %= 100;
            }
        }
        reverse(t.begin(), t.end());

        int st = -1;

        for (int i = 0; i < t.size(); i++) {
            if (t[i]) {
                st = i; break;
            }
        }

        if (st == -1) return { "0" };

        INTT ret;
        ret.s = to_string(t[st]);
        for (int i = st + 1; i < t.size(); i++) {
            ret.s += t[i] < 10 ? '0' + to_string(t[i]) : to_string(t[i]);
        }

        return ret;
    }
    INTT operator *= (const INTT& o) {
        *this = *this * o;
        return *this;
    }
}big_int;

typedef struct {
    big_int arr[2][2];
} mat;

mat init_iden() {
    mat ret;
    ret.arr[0][0] = { "1" };
    ret.arr[0][1] = { "0" };
    ret.arr[1][0] = { "0" };
    ret.arr[1][1] = { "1" };
    return ret;
}

mat matmul(const mat& a, const mat& b) {
    mat ret;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            big_int cur = { "0" };
            for (int k = 0; k < 2; k++) {
                cur += a.arr[i][k] * b.arr[k][j];
            }
            ret.arr[i][j] = cur;
        }
    }

    return ret;
}

mat matpow(const mat& a, int b) {
    mat ret = init_iden(), piv = a;

    while (b) {
        if (b & 1) ret = matmul(ret, piv);
        b >>= 1;
        piv = matmul(piv, piv);
    }

    return ret;
}

big_int fibo(int n) {
    mat initf;
    initf.arr[0][0] = { "1" };
    initf.arr[0][1] = { "1" };
    initf.arr[1][0] = { "1" };
    initf.arr[1][1] = { "0" };
    return matpow(initf, n).arr[1][0];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    cout << fibo(n);
}