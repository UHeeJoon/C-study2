#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <string>

using namespace std;

typedef complex<double> cpx;

const double PI = acos(-1);

void FFT(vector<cpx>& f, cpx w)
{
	const int n = static_cast<int>(f.size());

	if (n == 1)
		return;

	vector<cpx> even(n / 2);
	vector<cpx> odd(n / 2);

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			even[i / 2] = f[i];
		else
			odd[i / 2] = f[i];
	}

	FFT(even, w * w);
	FFT(odd, w * w);

	cpx wp(1, 0); 

	for (int i = 0; i < n / 2; i++) {
		f[i] = even[i] + wp * odd[i];
		f[i + n / 2] = even[i] - wp * odd[i];
		wp *= w;
	}
}

vector<cpx> multiply(vector<cpx> a, vector<cpx> b)
{
	int n = 1;
	while ((n < a.size() + 1) || (n < b.size() + 1))
		n *= 2;
	n *= 2;

	a.resize(n);
	b.resize(n);

	vector<cpx> c(n);

	const cpx w(cos((2 * PI) / n), sin((2 * PI) / n)); 

	FFT(a, w);
	FFT(b, w);

	for (int i = 0; i < n; i++) {
		c[i] = a[i] * b[i];
	}

	FFT(c, cpx(1, 0) / w);

	for (int i = 0; i < n; i++) {
		c[i] /= cpx(n, 0);

		c[i] = cpx(round(c[i].real()), round(c[i].imag()));
	}

	return c;
}

vector<cpx> stringToComplexVectorBasedDecimal(const string s)
{
	const int length = static_cast<int>(s.size());

	vector<cpx> f(length);

	for (int i = 0; i < length; i++) {
		const int num = s[length - i - 1] - '0';
		f[i] = cpx(num, 0);
	}

	return f;
}

string ComplexVectorBasedDecimalToString(vector<cpx> f)
{
	string s = const_cast<char*>("");

	for (vector<cpx>::size_type i = 0; i < f.size(); i++) {
		constexpr int dec = 10;
		if (f[i].real() >= dec) {
			if (i == f.size() - 1)
				f.emplace_back(static_cast<int>(f[i].real()) / dec, 0);
			else
				f[i + 1] += cpx(static_cast<int>(f[i].real() / dec), 0);
			f[i] = cpx(static_cast<int>(f[i].real()) % dec, 0);
		}
	}

	reverse(f.begin(), f.end());

	vector<cpx>::size_type zeroCheck = 0;
	for (vector<cpx>::size_type i = 0; i < f.size(); i++) {
		if (f[i].real() != 0) {
			zeroCheck = i;
			break;
		}
	}

	for (vector<cpx>::size_type i = zeroCheck; i < f.size(); i++) {
		s += to_string(static_cast<unsigned long long>(f[i].real()));
	}

	return s;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s1, s2;

	cin >> s1 >> s2;

	if (s1 == "0" || s2 == "0") {
		cout << 0;
		return 0;
	}

	vector<cpx> A = stringToComplexVectorBasedDecimal(s1);
	vector<cpx> B = stringToComplexVectorBasedDecimal(s2);

	vector<cpx> C = multiply(A, B);

	string res = ComplexVectorBasedDecimalToString(C);

	cout << res;
}