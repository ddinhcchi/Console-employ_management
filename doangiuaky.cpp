#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


//Ham dang nhap
void NhapChucNang();
void AdminLog();
void KiemTraAdmin(string tk, string mk);
void EmployLog();
bool KiemTraEmploy(string tk, string mk);


//Ham admin
void ChucNangAdmin();
void ThemEmploy();
void XoaEmploy();
void TimEmploy();
void CapNhatThongTin();
void HienThiThongTin();


//Ham employ
void ChucNangEmploy(string tk);
void ThayMatKhau(string tk);
void XemThongTinTaiKhoan(string tk);


//Ham ho tro
void ThayMKLanDauDangNhap(string tk);
void CapNhatSoLanTXT(string tk);
void ChangePass(string tk);

//Ham main
int main() {
	NhapChucNang();
	return 0;
}

void NhapChucNang()
{
	cout << "\nChuc vu: ";
	cout << "\n1.Admin";
	cout << "\n2.Employ";
	cout << "\n0.Thoat";
	int n;
	cout << "\nNhap chuc vu: ";
	cin >> n;
	switch (n)
	{
	case 1: AdminLog(); break;
	case 2: EmployLog(); break;
	case 0: exit(0);
	}
}

void AdminLog()
{
	SetConsoleTextAttribute(h, 14);
	cout << "\n************************************";
	cout << "\n*         ";
	SetConsoleTextAttribute(h, 10);
	cout << "DANG NHAP ADMIN";
	SetConsoleTextAttribute(h, 14);
	cout << "          *";
	cout << "\n************************************";
	SetConsoleTextAttribute(h, 2);
	cout << "\nUser:	";
	SetConsoleTextAttribute(h, 15);
	string user;
	cin >> user;
	SetConsoleTextAttribute(h, 2);
	cout << "Pass:	";
	SetConsoleTextAttribute(h, 15);
	string password;
	char c;
	do {
		c = _getch();
		if (c == '\b') {
			cout << "\b \b";
			if (!password.empty()) {
				password.erase(password.size() - 1);
			}
		}
		else if (c != 13) {
			cout << "*";
			password += c;
		}
	} while (c != 13);
	KiemTraAdmin(user, password);
}

void KiemTraAdmin(string tk, string mk)
{
	fstream admin("admin.txt", ios::in);
	string temp;
	bool flag = false;
	while (!admin.eof())
	{
		getline(admin, temp);
		if (temp == tk)
		{
			getline(admin, temp);
			if (temp == mk)
			{
				flag = true;
				SetConsoleTextAttribute(h, 4);
				cout << "\nDANG NHAP THANH CONG";
				ChucNangAdmin();
			}
		}
	}

	if (!flag) {
		SetConsoleTextAttribute(h, 4);
		cout << "\nSai User hoac Pass!!!";
		AdminLog();
	}
	admin.close();
}

void EmployLog()
{
	for (int i = 0; i < 3; i++) {
		SetConsoleTextAttribute(h, 14);
		cout << "\n************************************";
		cout << "\n*         ";
		SetConsoleTextAttribute(h, 10);
		cout <<"DANG NHAP EMPLOY";
		SetConsoleTextAttribute(h, 14);
		cout << "         *";
		cout << "\n************************************";
		SetConsoleTextAttribute(h, 2);
		cout << "\nUser:	";
		SetConsoleTextAttribute(h, 15);
		string user;
		cin >> user;
		SetConsoleTextAttribute(h, 2);
		cout << "Pass:	";
		SetConsoleTextAttribute(h, 15);
		string pass = "";
		char c;
		do {
			c = _getch();
			if (c == '\b') {
				cout << "\b \b";
				if (!pass.empty()) {
					pass.erase(pass.size() - 1);
				}
			}
			else if (c != 13) {
				cout << "*";
				pass += c;
			}
		} while (c != 13);

		if (KiemTraEmploy(user, pass)) {
			ChucNangEmploy(user);
			break;
		}
		else if (i == 2) {
			SetConsoleTextAttribute(h, 4);
			cout << "\nNhap sai 3 lan!!! Thoat chuong trinh!!!";
			SetConsoleTextAttribute(h, 15);
			exit(0);
		}
	}
}

bool KiemTraEmploy(string tk, string mk)
{
	fstream employ("employ.txt", ios::in);
	string temp;
	bool flag = false;
	while (!employ.eof())
	{
		getline(employ, temp);
		if (temp == tk)
		{
			getline(employ, temp);
			if (temp == mk)
			{
				flag = true;
				SetConsoleTextAttribute(h, 4);
				cout << "\nDANG NHAP THANH CONG";
			}
		}
	}
	employ.close();

	if (!flag) {
		SetConsoleTextAttribute(h, 4);
		cout << "\nSai User hoac Pass!!!";
		return false;
	}
	else {
		ThayMKLanDauDangNhap(tk);
		ChucNangEmploy(tk);
		return true;
	}
}


//Ham admin
void ChucNangAdmin()
{
	SetConsoleTextAttribute(h, 14);
	cout << "\n****************MENU****************";
	cout << "\n	   1.Them Employ";
	cout << "\n	   2.Xoa Employ";
	cout << "\n	   3.Tim Employ";
	cout << "\n	   4.Cap nhat Employ";
	cout << "\n	   5.Hien thi thong tin Employ";
	cout << "\n	   6.Thoat";
	cout << "\n************************************";
	int n;
	SetConsoleTextAttribute(h, 2);
	cout << "\nNhap chuc nang: ";
	SetConsoleTextAttribute(h, 15);
	cin >> n;
	switch (n)
	{
	case 1: ThemEmploy(); break;
	case 2: XoaEmploy(); break;
	case 3: TimEmploy(); break;
	case 4: CapNhatThongTin(); break;
	case 5: HienThiThongTin(); break;
	case 6: exit(0);
	}
}

void ThemEmploy()
{
	SetConsoleTextAttribute(h, 14);
	cout << "\n===========Them Employ=============\n";
	SetConsoleTextAttribute(h, 2);
	cout << "Nhap ten user: ";
	SetConsoleTextAttribute(h, 15);
	string username;
	cin >> username;

	string tmp[99];
	int i = 0;
	fstream employ("employ.txt", ios::in);
	while (!employ.eof())
	{
		employ >> tmp[i];
		if (tmp[i] == username)
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\nUser da ton tai!!!";
			ThemEmploy();
			i = 0;
		}
		else if (tmp[i] == "") {
			i--;
		}
		i++;
	}
	fstream employy("employ.txt", ios::out);
	for (int j = 0; j < i; j++)
	{
		employy << tmp[j] << endl;
	}

	employy << username;
	string matkhau = "111111";
	employy << endl << matkhau;
	employ.close();
	employy.close();
	fstream employyy(username + ".txt", ios::app);
	SetConsoleTextAttribute(h, 2);
	cout << "Nhap Ho va ten: ";
	char a[100];
	getchar();
	SetConsoleTextAttribute(h, 15);
	fgets(a, 100, stdin);
	employyy << a;
	SetConsoleTextAttribute(h, 2);
	cout << "Nhap dia chi: ";
	SetConsoleTextAttribute(h, 15);
	fgets(a, 100, stdin);
	employyy << a;
	SetConsoleTextAttribute(h, 2);
	cout << "Nhap so dien thoai: ";
	SetConsoleTextAttribute(h, 15);
	fgets(a, 100, stdin);
	employyy << a;
	SetConsoleTextAttribute(h, 2);
	cout << "Nhap Gmail: ";
	SetConsoleTextAttribute(h, 15);
	fgets(a, 100, stdin);
	employyy << a;
	employyy.close();
	fstream solan("solan.txt", ios::in);
	string solann[100];
	int m = 0;
	while (!solan.eof())
	{
		solan >> solann[m];
		if (solann[m] == "") {
			m--;
		}
		m++;
	}
	solan.close();
	fstream solan1("solan.txt", ios::out);
	for (int p = 0; p < m; p++)
	{
		solan1 << solann[p] << endl;
	}
	solan1 << username << endl;
	solan1 << 0;
	solan1.close();
	SetConsoleTextAttribute(h, 4);
	cout << "\nDa them thanh cong!!!";
	ChucNangAdmin();
}

void XoaEmploy() {
	string username, usertmp;
	SetConsoleTextAttribute(h, 2);
	cout << "Nhap ten nhan vien muon xoa: ";
	SetConsoleTextAttribute(h, 15);
	cin >> username;
	usertmp = username;
	username += ".txt";

	int ret, dem = 0;

	char filename[100] = "";

	for (int i = 0; i < username.length(); i++) {

		filename[i] = username[i];
	}

	ret = remove(filename);

	if (ret == 0)
	{
		SetConsoleTextAttribute(h, 4);
		printf("Xoa employ thanh cong !!!");
	}
	else
	{
		SetConsoleTextAttribute(h, 4);
		printf("Error: khong the xoa employ tren");
	}

	//cap nhat file employ.txt
	fstream open("employ.txt", ios::in);
	string suadoiemploy[200];
	int n = 0;
	while (!open.eof()) {
		open >> suadoiemploy[n];
		n++;
	}
	open.close();

	fstream taomoi("employ.txt", ios::out);
	if (suadoiemploy[n - 2] == usertmp) {
		for (int i = 0; i < n-2; i += 2) {
			if (suadoiemploy[i] != usertmp) {
				taomoi << suadoiemploy[i] << endl << suadoiemploy[i + 1];
				if (i + 1 != n - 3) taomoi << endl;
			}
		}
	}
	else {
		for (int i = 0; i < n; i += 2) {
			if (suadoiemploy[i] != usertmp) {
				taomoi << suadoiemploy[i] << endl << suadoiemploy[i + 1];
				if (i + 1 != n - 1) taomoi << endl;
			}
		}
	}
	taomoi.close();

	//cap nhat file solan.txt
	fstream opensolan("solan.txt", ios::in);
	string suadoisolan[200];
	n = 0;
	while (!opensolan.eof()) {
		opensolan >> suadoisolan[n];
		n++;
	}
	opensolan.close();

	fstream taomoisolan("solan.txt", ios::out);
	if (suadoisolan[n - 2] == usertmp) {
		for (int i = 0; i < n - 2; i += 2) {
			if (suadoisolan[i] != usertmp) {
				taomoisolan << suadoisolan[i] << endl << suadoisolan[i + 1];
				if (i + 1 != n - 3) taomoisolan << endl;
			}
		}
	}
	else {
		for (int i = 0; i < n; i += 2) {
			if (suadoisolan[i] != usertmp) {
				taomoisolan << suadoisolan[i] << endl << suadoisolan[i + 1];
				if (i + 1 != n - 1) taomoisolan << endl;
			}
		}
	}
	taomoisolan.close();

	ChucNangAdmin();
}

void TimEmploy() {
	SetConsoleTextAttribute(h, 2);
	cout << "Nhap ten nhan vien muon tim: ";
	string username;
	SetConsoleTextAttribute(h, 15);
	cin >> username;
	int tmp = 0;

	ifstream f;
	f.open(username + ".txt", ios::in);

	if (f.fail())
	{
		SetConsoleTextAttribute(h, 4);
		cout << "Khong tim duoc doi tuong employ!" << endl;
	}
	else {
		string line;
		while (!f.eof())          // (1)
		{
			getline(f, line); // (2)
			SetConsoleTextAttribute(h, 15);
			cout << line;
			if (tmp != 3) cout << "\n";
			tmp++;
		}
	}
	f.close();
	ChucNangAdmin();
}

void CapNhatThongTin() {
	string capnhat[4];
	string user, usertmp;
	SetConsoleTextAttribute(h, 2);
	cout << "Nhap ten nhan vien muon thay doi thong tin: ";
	SetConsoleTextAttribute(h, 15);
	cin.ignore();
	getline(cin, user);

	//kiem tra xem co nhan vien nay trong danh sach employ khong
	bool flat = false;
	fstream open("employ.txt", ios::in);
	string sosanh;
	while (!open.eof()) {
		getline(open, sosanh);
		if (sosanh == user) flat = true;
	}
	open.close();

	if (!flat) {
		SetConsoleTextAttribute(h, 4);
		cout << "Khong tim thay nhan vien nay!!!";
	}
	else {
		usertmp = user;
		user += ".txt";

		ifstream infile;
		infile.open(user);
		for (int i = 0; i < 4; i++) {
			getline(infile, capnhat[i]);
		}
		infile.close();
		SetConsoleTextAttribute(h, 14);
		cout << "1. Ho va ten" << endl;
		cout << "2. Dia chi" << endl;
		cout << "3. So dien thoai" << endl;
		cout << "4. Mail" << endl;
		cout << "Thong tin muon doi: ";
		SetConsoleTextAttribute(h, 15);

		int n;
		cin >> n;
		cin.ignore();
		if (n == 1) {
			SetConsoleTextAttribute(h, 2);
			cout << "Nhap Ho va ten: ";
			string newname;
			SetConsoleTextAttribute(h, 15);
			getline(cin, newname);

			capnhat[0] = newname;
		}
		else if (n == 2)
		{
			SetConsoleTextAttribute(h, 2);
			cout << "Nhap dia chi moi: ";
			string newdir;
			SetConsoleTextAttribute(h, 15);
			getline(cin, newdir);

			capnhat[1] = newdir;
		}
		else if (n == 3)
		{
			SetConsoleTextAttribute(h, 2);
			cout << "Nhap so dien thoai moi: ";
			string newphone;
			SetConsoleTextAttribute(h, 15);
			getline(cin, newphone);

			capnhat[2] = newphone;

		}
		else if (n == 4)
		{
			SetConsoleTextAttribute(h, 2);
			cout << "Nhap mail moi: ";
			string newmail;
			SetConsoleTextAttribute(h, 15);
			getline(cin, newmail);

			capnhat[3] = newmail;

		}

		fstream employ(usertmp + ".txt", ios::out);
		for (int i = 0; i < 4; i++) {

			employ << capnhat[i] << endl;
		}
		SetConsoleTextAttribute(h, 4);
		cout << "Cap nhat thong tin thanh cong\n";
		employ.close();
	}
	ChucNangAdmin();
}

void HienThiThongTin() {
	fstream employ("employ.txt", ios::in);
	string employee;
	int n = 0;
	while (!employ.eof()) {
		getline(employ, employee);
		if (n % 2 == 0) {
			SetConsoleTextAttribute(h, 4);
			cout << "Nhan vien " << employee << ":" << endl;
			SetConsoleTextAttribute(h, 15);
			fstream open(employee + ".txt", ios::in);
			string line;
			while (!open.eof()) {
				getline(open, line);
				cout << line << endl;
			}
			open.close();
		}
		n++;
	}
	employ.close();

	ChucNangAdmin();
}


//============Ham employ==============
void ChucNangEmploy(string tk)
{
	SetConsoleTextAttribute(h, 14);
	cout << "\n*************MENU EMPLOYEE**************" << endl;
	cout << "   " << "1. Xem thong tin tai khoan" << "   " << endl;
	cout << "   " << "2. Doi pass               " << "   " << endl;
	cout << "   " << "3. Thoat                  " << "   " << endl;
	cout << "****************************************" << endl;
	cout << "Chon chuc nang: ";
	SetConsoleTextAttribute(h, 15);
	int i;
	cin >> i;

	switch (i)
	{
	case 1: XemThongTinTaiKhoan(tk); break;
	case 2: ThayMatKhau(tk); break;
	case 3: {
		CapNhatSoLanTXT(tk);
		SetConsoleTextAttribute(h, 15);
		exit(0);
		break;
		}
	}
}

void XemThongTinTaiKhoan(string tk) {
	ifstream f;
	f.open(tk + ".txt", ios::in);

	if (f.fail())
	{
		SetConsoleTextAttribute(h, 4);
		cout << "Khong tim duoc ten ban" << endl;
	}
	else {
		string line;
		while (!f.eof())
		{
			getline(f, line);
			SetConsoleTextAttribute(h, 15);
			cout << line << "\n";
		}
	}
	f.close();
	ChucNangEmploy(tk);
}

void ThayMatKhau(string tk)
{
	SetConsoleTextAttribute(h, 14);
	cout << "\n===========Thay Mat Khau=============\n";
	fstream check("solan.txt", ios::in);
	string user;
	while (!check.eof()) {
		getline(check, user);
		if (user == tk) {
			getline(check, user);
			if (stoi(user) == 0) {
				SetConsoleTextAttribute(h, 4);
				cout << "Dang nhap tu lan 2 tro di moi duoc thay mat khau!\n";
				ChucNangEmploy(tk);
			}
			break;
		}
	}

	SetConsoleTextAttribute(h, 2);
	cout << "Nhap mat khau hien tai cua ban: ";
	string pass;
	SetConsoleTextAttribute(h, 15);
	char c;
	do {
		c = _getch();
		if (c != 13) {
			cout << "*";
			pass += c;
		}
	} while (c != 13);
	bool flag = false;

	fstream open("employ.txt", ios::in);
	string tmp;
	while (!open.eof()) {
		getline(open, tmp);
		if (tmp == tk) {
			getline(open, tmp);
			while (tmp != pass) {
				SetConsoleTextAttribute(h, 4);
				cout << "Nhap sai mat khau!\nNhap lai mat khau hien tai: ";
				pass = "";
				SetConsoleTextAttribute(h, 15);
				do {
					c = _getch();
					if (c != 13) {
						cout << "*";
						pass += c;
					}
				} while (c != 13);
			}
			flag = true;
		}
	}

	if (flag) {
		ChangePass(tk);
	}

	ChucNangEmploy(tk);
}

//================Ham ho tro===============================
void ThayMKLanDauDangNhap(string tk) {
	fstream employ("solan.txt", ios::in);
	string temp;
	bool flag = false;
	while (!employ.eof())
	{
		getline(employ, temp);
		if (temp == tk)
		{
			getline(employ, temp);
			if (temp == "0")
			{
				SetConsoleTextAttribute(h, 14);
				cout << "\nThay mat khau cho lan dau dang nhap";
				flag = true;
			}
		}
	}
	employ.close();

	if (flag) {
		ChangePass(tk);
	}
}

//cap nhat file solan.txt
void CapNhatSoLanTXT(string tk) {
	fstream solan("solan.txt", ios::in);
	string tmp[200];
	int n = 0;
	while (!solan.eof()) {
		solan >> tmp[n];
		n++;
	}
	solan.close();

	fstream solan1("solan.txt", ios::out);
	for (int i = 0; i < n-1; i += 2) {
		if (tmp[i] == tk) {
			solan1 << tmp[i] << endl;
			solan1 << stoi(tmp[i + 1]) + 1;
		}
		else {
			solan1 << tmp[i] << endl;
			solan1 << tmp[i + 1];
		}
		if (i + 1 != n - 1) solan1 << endl;
	}
	solan1.close();
}

void ChangePass(string tk) {
	SetConsoleTextAttribute(h, 2);
	cout << "\nNhap mat khau moi: ";
	string newpass;
	SetConsoleTextAttribute(h, 15);
	char c;
	do {
		c = _getch();
		if (c == '\b') {
			cout << "\b \b";
			if (!newpass.empty()) {
				newpass.erase(newpass.size() - 1);
			}
		}
		else if (c != 13) {
			cout << "*";
			newpass += c;
		}
	} while (c != 13);
	SetConsoleTextAttribute(h, 2);
	cout << "\nXac nhan lai mat khau: ";
	SetConsoleTextAttribute(h, 15);
	string repass;
	do {
		c = _getch();
		if (c == '\b') {
			cout << "\b \b";
			if (!repass.empty()) {
				repass.erase(repass.size() - 1);
			}
		}
		else if (c != 13) {
			cout << "*";
			repass += c;
		}
	} while (c != 13);

	while (newpass != repass) {
		SetConsoleTextAttribute(h, 4);
		cout << "\nXac nhan mat khau khong trung khop!\n";
		SetConsoleTextAttribute(h, 2);
		cout << "Mat khau moi: ";
		SetConsoleTextAttribute(h, 15);
		newpass = "";
		char c;
		do {
			c = _getch();
			if (c == '\b') {
				cout << "\b \b";
				if (!newpass.empty()) {
					newpass.erase(newpass.size() - 1);
				}
			}
			else if (c != 13) {
				cout << "*";
				newpass += c;
			}
		} while (c != 13);
		SetConsoleTextAttribute(h, 2);
		cout << "\nXac nhan lai mat khau: ";
		SetConsoleTextAttribute(h, 15);
		repass = "";
		do {
			c = _getch();
			if (c == '\b') {
				cout << "\b \b";
				if (!repass.empty()) {
					repass.erase(repass.size() - 1);
				}
			}
			else if (c != 13) {
				cout << "*";
				repass += c;
			}
		} while (c != 13);
	}

	//cap nhat file employ.txt
	fstream employ("employ.txt", ios::in);
	string tmp[200];
	int n = 0;
	while (!employ.eof()) {
		employ >> tmp[n];
		n++;
	}
	employ.close();

	fstream employ1("employ.txt", ios::out);
	for (int i = 0; i < n; i += 2) {
		if (tmp[i] == tk) {
			employ1 << tmp[i] << endl;
			employ1 << newpass;
			
		}
		else {
			employ1 << tmp[i] << endl;
			employ1 << tmp[i + 1];
		}
		if (i + 1 != n - 1) employ1 << endl;
	}
	employ1.close();

	SetConsoleTextAttribute(h, 4);
	cout << "\nCap nhat mat khau thanh cong";
}