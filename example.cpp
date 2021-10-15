// Định nghĩa toán tử +, -, *, /, +=, -=, *=, /=, ++, -- cho CPhanSo
#include <iostream>
using namespace std;
class CPhanSo
{
private:
	int tu, mau;
public:
	friend istream& operator>>(istream&, CPhanSo&);
	friend ostream& operator<<(ostream&, CPhanSo&);
	CPhanSo& operator=(const CPhanSo&);
	CPhanSo operator+(CPhanSo);
	CPhanSo operator-(CPhanSo);
	CPhanSo operator*(CPhanSo);
	CPhanSo operator/(CPhanSo);
	CPhanSo operator+=(CPhanSo);
	CPhanSo operator-=(CPhanSo);
	CPhanSo operator*=(CPhanSo);
	CPhanSo operator/=(CPhanSo);
	CPhanSo operator++();
	CPhanSo operator--();
};
istream& operator>>(istream& is, CPhanSo& a)
{
	cout << "\nNhap tu so: "; is >> a.tu;
	do { cout << "Nhap mau so: "; is >> a.mau; } while (a.mau == 0);
	return is;
}
ostream& operator<<(ostream& os, CPhanSo& a)
{
	if (a.tu == 0) os << 0;
	else if (a.tu == a.mau) os << 1;
	else if (a.tu == -a.mau) os << -1;
	else if (a.mau < 0 && a.tu>0) os << "-" << a.tu << "/" << -a.mau;
	else if (a.tu < 0 && a.mau < 0) os << -a.tu << "/" << -a.mau;
	else os << a.tu << "/" << a.mau;
	return os;
}
CPhanSo& CPhanSo::operator=(const CPhanSo& a)
{
	tu = a.tu;
	mau = a.mau;
	return *this;
}
CPhanSo CPhanSo::operator+(CPhanSo a)
{
	CPhanSo kq;
	kq.tu = tu * a.mau + a.tu * mau;
	kq.mau = mau * a.mau;
	return kq;
}
CPhanSo CPhanSo::operator-(CPhanSo a)
{
	CPhanSo kq;
	kq.tu = tu * a.mau - a.tu * mau;
	kq.mau = mau * a.mau;
	return kq;
}
CPhanSo CPhanSo::operator*(CPhanSo a)
{
	CPhanSo kq;
	kq.tu = tu * a.tu;
	kq.mau = mau * a.mau;
	return kq;
}
CPhanSo CPhanSo::operator/(CPhanSo a)
{
	CPhanSo kq;
	kq.tu = tu * a.mau;
	kq.mau = mau * a.tu;
	return kq;
}
CPhanSo CPhanSo::operator+=(CPhanSo a)
{
	//CPhanSo kq = *this;
	return *this + a;
}
CPhanSo CPhanSo::operator-=(CPhanSo a)
{
	//CPhanSo kq = *this;
	return *this - a;
}
CPhanSo CPhanSo::operator*=(CPhanSo a)
{
	//CPhanSo kq = *this;
	return *this * a;
}
CPhanSo CPhanSo::operator/=(CPhanSo a)
{
	//CPhanSo kq = *this;
	return *this / a;
}
CPhanSo CPhanSo::operator++()
{
	CPhanSo tam;
	tam.tu = 1;
	tam.mau = 1;
	return *this + tam;
}
CPhanSo CPhanSo::operator--()
{
	CPhanSo tam;
	tam.tu = 1;
	tam.mau = 1;
	return *this - tam;
}
int main()
{
	CPhanSo a, b, c, kq;
	cout << "Nhap phan so a: "; cin >> a;
	cout << "Nhap phan so b: "; cin >> b;
	kq = a + b;
	cout << "\na + b = " << kq;
	kq = a - b;
	cout << "\na - b = " << kq;
	kq = a * b;
	cout << "\na * b = " << kq;
	kq = a / b;
	cout << "\na / b = " << kq;
	cout << "\n\nNhap phan so c: "; cin >> c;
	kq = (a += c);
	cout << "\n(a += c) = " << kq;
	kq = (a -= c);
	cout << "\n(a -= c) = " << kq;
	kq = (a *= c);
	cout << "\n(a *= c) = " << kq;
	kq = (a /= c);
	cout << "\n(a /= c) = " << kq;
	kq = ++a;
	cout << "\na++ = " << kq;
	kq = --a;
	cout << "\na-- = " << kq;
	cout << "\n\n";
	system("pause");
	return 1;
}



