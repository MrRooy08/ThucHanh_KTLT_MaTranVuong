
#include <iostream>
using namespace std;
const int DAT = 50;
struct MTV {
	int list[DAT][DAT];
	int n;
}a, b, c;
void Nhap_MTV(MTV& a)
{
	do {
		cout << "\n Nhap cap cho MTV A: ";
		cin >> a.n;
		for (int i = 0; i < a.n; i++)
			for (int j = 0; j < a.n; j++)
			{
				cout << "\n a[" << i << "][" << j << "]=";
				cin >> a.list[i][j];
			}
		cout << "\n Nhap cap cho MTV B: ";
		cin >> b.n;
		for (int i = 0; i < b.n; i++)
			for (int j = 0; j < b.n; j++)
			{
				cout << "\n a[" << i << "][" << j << "]=";
				cin >> b.list[i][j];
			}
		if (a.n != b.n) {
			cout << "\n Da Nhap Sai Cap Ma Tran. Vui Long Nhap Lai Voi Yeu Cau Ma Tran Cung Cap!!!";
		}
	} while (a.n != b.n);
}

void Xuat_MTV(MTV a)
{
	cout << "\n Xuat Ma Tran Vuong A: " << endl;
	for (int i = 0; i < a.n; i++)
	{
		cout << endl;
		for (int j = 0; j < a.n; j++) {
			cout.width(5);
			cout << " " << a.list[i][j];
		}
	}
	cout << "\n Xuat Ma Tran Vuong B: " << endl;
	for (int i = 0; i < b.n; i++)
	{
		cout << endl;
		for (int j = 0; j < b.n; j++) {
			cout.width(5);
			cout << " " << b.list[i][j];
		}
	}
}

//Tìm đường chéo chính trong ma trận vuông 
void Tim_DCC(MTV a)
{
	int i;
	int main_diagonal = 0; //đường chéo chính 
	cout << "\n Cac duong cheo chinh co trong ma tran vuong la: ";
	// cách 1: vì chỉ số i==j là giống nhau nên ta có thể để [i][i] thay vì [i][j] và chỉ tốn 1 vòng lặp rút gọn code 
	for (i = 0; i < a.n; i++) {
		main_diagonal = a.list[i][i];
		cout << " " << main_diagonal;
		//cách 2: vì đường chéo chính có chỉ số mảng i và j giống nhau nên chỉ cần xét điều kiện là xong
		/*for (int i = 0; i < a.n; i++) {
			for (int j = 0; j < a.n; j++)
				if (i == j) {
					main_diagonal = a.list[i][j];
					cout <<" "<< main_diagonal;
				}
		}*/
	}
}
//Tìm đường chéo phụ trong ma trận vuông
void Tim_DCP(MTV a)
{
	int secondary_diagonal = 0; //đường chéo phụ 
	cout << "\n Cac Duong Cheo Phu Co Trong Ma Tran Vuong La: ";
	for (int i = 0; i < a.n; i++) {
		secondary_diagonal = a.list[i][a.n - i - 1];
		cout << " " << secondary_diagonal;
	}
}

//Tìm Tồng 2 Đường Chéo Trong Ma Trận Vuông 
int Sum_Diagonal(MTV a) {
	int s_diagonal = 0;
	for (int i = 0; i < a.n; i++)
	{
		s_diagonal += a.list[i][i];
		s_diagonal += a.list[i][a.n - i - 1];
	}
	return s_diagonal;
}

//Đường chéo chính trong tam giác 
void Under_triangle(MTV a) //tam giác dưới 
{
	int triangle = 0;
	cout << "\n Xuat Tam Giac Duoi Duong Cheo Chinh Trong Ma Tran Vuong La: " << endl;
	for (int i = 0; i < a.n; i++)
	{
		for (int j = 0; j < a.n; j++)
			if (i >= j) {
				triangle = a.list[i][j];
				cout << triangle << "\t ";
			}
		cout << endl;
	}
}

void Top_Triangle(MTV a) //tam giác trên 
{
	int triangle = 0;
	cout << "\n Xuat Tam Giac  Tren Duong Cheo Chinh Trong Ma Tran Vuong La:" << endl;
	for (int i = 0; i < a.n; i++)
	{
		for (int j = 0; j < a.n; j++) {
			if (i <= j) {
				triangle = a.list[i][j];
				cout << triangle << " ";
			}
		}
		cout << " " << endl;
	}
}

// Đường chéo phụ trong tam giác 
void under_triangle_sec(MTV a) //Tam Giác Dưới 
{
	int triangle = 0;
	cout << "\n Xuat Tam Giac Duoi Theo Duong Cheo Phu Trong Ma Tran Vuong La: " << endl;
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++)
			if (i + j >= a.n - 1)
			{
				triangle = a.list[i][j];
				cout << triangle << " ";
			}
		cout << endl;
	}
}

void top_triangle_sec(MTV a) //Tam Giác Trên 
{
	int triangle = 0;
	cout << "\n Xuat Tam Giac Tren Theo Duong Cheo Phu Trong Ma Tran Vuong La: " << endl;
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			if (i + j <= a.n - 1) //duyệt theo mảng đi từ a[0][0] thì i=0,j=0 cộng lại bé hơn a.n-1 = 3-1=2 nên thỏa đk if
			{
				triangle = a.list[i][j];
				cout << " " << triangle;
			}
		}
		cout << endl;
	}
}

//Tìm Phần Tử Có Trong Ma Trận Vuông 
int Tim_X(MTV a, int x) {
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			if (a.list[i][j] == x)
				return 1;
		}
	}
	return 0;
}

void tim_x(MTV a, int x) {
	if (Tim_X(a, x) == 1)
	{
		cout << "\n Co So " << x << " Tren Ma Tran ";
	}
	else
	{
		cout << "\n Ko Co So " << x << " Tren Ma Tran ";
	}
}

//Tìm Phần Tử Có Trong Đường Chéo Chính 
int Tim_PT_DCC(MTV a, int x) {
	int i;
	for (i = 0; i < a.n; i++) {
		if (a.list[i][i] == x) {
			return 1;
		}
	}
	return 0;
}

void Xuat_PT_DCC(MTV a, int x) {
	if (Tim_PT_DCC(a, x) == 1)
	{
		cout << "\n Co So " << x << " Tren Duong Cheo Chinh Cua Ma Tran ";
	}
	else
	{
		cout << "\n Ko Co So " << x << " Tren Duong Cheo Chinh Cua Ma Tran ";
	}
}

//Tìm Phần Tử Có Trong Đường Chéo Phụ 
int Tim_PT_DCP(MTV a, int x) {
	int i;
	for (i = 0; i < a.n; i++) {
		if (a.list[i][a.n - i - 1] == x)
		{
			return 1;
		}
	}
	return 0;
}

void Xuat_PT_DCP(MTV a, int x) {
	if (Tim_PT_DCP(a, x) == 1)
	{
		cout << "\n Co So " << x << " Tren Duong Cheo Phu Cua Ma Tran ";
	}
	else
	{
		cout << "\n Ko Co So " << x << " Tren Duong Cheo Phu Cua Ma Tran ";
	}
}

//Tìm Max trên đường chéo chính 
int Max_DCC(MTV a) {
	int max = a.list[0][0];
	for (int i = 0; i < a.n; i++) {
		if (max < a.list[i][i])
			max = a.list[i][i];
	}
	return max;
}

//Tìm Max trên đường chéo phụ 
int Max_DCP(MTV a) {
	int max = a.list[0][0];
	for (int i = 0; i < a.n; i++)
	{
		if (max < a.list[i][a.n - i - 1]) {
			max = a.list[i][a.n - i - 1];
		}
	}
	return max;
}

//Tìm Các Phần Tử Không Phải Là Đường Chéo Chính Và Phụ 
void Tim_PT_Alone(MTV a) {
	int i, j;
	for (i = 0; i < a.n; i++) {
		a.list[i][i] = 0;
		a.list[i][a.n - i - 1] = 0;
	}
	cout << "\n Xuat Cac Phan Tu Khong Nam Tren Duong Cheo Chinh Va Phu: " << endl;
	for (i = 0; i < a.n; i++)
	{
		for (j = 0; j < a.n; j++)
		{
			cout << " " << a.list[i][j];

		}
		cout << endl;
	}
}

//Kiểm Tra  Số Nguyên Tố 
int check_SNT(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return 0;
	}
	return n > 1;
}

void Xuat_MT_SNT(MTV a) {
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			if (check_SNT(a.list[i][j]) == 1) {
				cout << "\n Cac So Nguyen To Co Trong Ma Tran La:  " << a.list[i][j];
			}
		}
	}
}
//Tìm Ma Trận Vuông Chuyển Vị 
void Tim_MT_Chuyen_Vi(MTV a) {
	//Cách 1
	int hoandoi = 0;
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < i; j++) {
			hoandoi = a.list[i][j];
			a.list[i][j] = a.list[j][i];
			a.list[j][i] = hoandoi;
		}
	}
	cout << "\n Ma Tran Chuyen Vi: " << endl;
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			cout << " " << a.list[i][j];
		}
		cout << endl;
	}
	//Cách 2: 
		/*cout << "\n Ma Tran Chuyen Vi: " << endl;
		for (int i = 0; i < a.n; i++) {
			for (int j = 0; j < a.n; j++) {
				cout << " " << a.list[j][i];
			}
			cout << endl;
		}*/
}
//Tìm Ma Trận Đơn Vị 
int MT_Don_Vi(MTV a) {
	int i, j;
	//cách 1
	/*for (i = 0; i < a.n; i++) {
		if (a.list[i][i] != 1) {
			return 0;
		}
	}
	for (i = 0; i < a.n; i++) {
		for (j = i+1; j < a.n; j++) {
			if ((a.list[i][j] != 0)||(a.list[j][i]!=0)) {
				return 0;
			}
		}
	}*/
	//cách 2
	for (i = 0; i < a.n; i++) {
		for (j = 0; j < a.n; j++) {
			if (a.list[i][i] != 1 && a.list[i][j] != 0) {
				return 0;
			}
		}
	}
	return 1;
}

void Xuat_MT_Don_Vi(MTV a) {
	int i, j;
	cout << endl;
	for (i = 0; i < a.n; i++) {
		for (j = 0; j < a.n; j++) {
			a.list[i][j] = 0;
			a.list[i][i] = 1;
		}
	}
	cout << "\n Xuat Ma Tran Don Vi: " << endl;
	for (i = 0; i < a.n; i++) {
		for (j = 0; j < a.n; j++) {
			cout << " " << a.list[i][j];
		}
		cout << endl;
	}
}
//Kiểm Tra Ma Trận Đối Xưng Nhau trên đường chéo chính 
//Ma Trận vuông đối xứng nhau trên đường chéo chính có nghĩa là a[i][j]=a[j][i]
int check_MT_Doi_Xung(MTV a) {
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			if (a.list[i][j] != a.list[j][i])
				return 0;
		}
	}
	return 1;
}
//Hàm Tính Tổng Ma Trận A
int Tong_A(MTV a) {
	int sum = 0;
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			sum += a.list[i][j];
		}
	}
	return sum;
}
//Hàm Tính Tổng B
int Tong_B(MTV b) {
	int sum = 0;
	for (int i = 0; i < b.n; i++) {
		for (int j = 0; j < b.n; j++) {
			sum += b.list[i][j];
		}
	}
	return sum;
}

//hàm tính tổng 2 ma trận theo chỉ số i và j
void Tong_Hai_MT(MTV a) {
	int i, j;
	cout << "\n Tong 2 Ma Tran Theo Chi So i Va j La: " << endl;
	for (i = 0; i < a.n; i++) {
		cout << endl;
		for (j = 0; j < a.n; j++) {
			cout.width(5);
			c.list[i][j] = a.list[i][j] + b.list[i][j];
			cout << " " << c.list[i][j];
		}
	}
}

//Hoán đổi giá trị các phần tử nằm đối xứng trên đường chéo chính và phụ 
void MT_Hoan_Doi(MTV a) {
	int i, j;
	for (i = 0; i < a.n; i++) {
		int hoandoi = a.list[i][i];
		a.list[i][i] = a.list[i][a.n - i - 1];
		a.list[i][a.n - i - 1] = hoandoi;
	}
	cout << "\n Xuat Ma Tran Hoan Doi Gia Tri Cac Phan Tu Nam Doi Xung Tren Duong Cheo Chinh Va Phu: " << endl;
	for (i = 0; i < a.n; i++)
	{
		for (j = 0; j < a.n; j++)
		{
			cout << " " << a.list[i][j];

		}
		cout << endl;
	}
}

//Kiểm Tra Ma Trận Đối Xứng Nhau Trên Đường Chéo Phụ 
//Đối xứng nhau qua đường chéo phụ là những phần tử xung quanh trên đường chéo phụ bằng nhau 
int check_MT_Doi_Xung_DCP(MTV a) {
	int i, j;
	//cách 1
	for (i = 0; i < a.n; i++) {
		for (j = 0; j < a.n; j++) {
			if (a.list[i][j] != a.list[a.n - j - 1][a.n - i - 1])
				return 0;
			/*a[0][0]=a[2][2]
			* a[0][1]=a[1][2]
			* a[1][0]=a[2][1]
			* => a[i][j]=a[n-1-j][n-1-i] này sẽ bằng với đường chéo chính
			* ta chỉnh cần return 0 để ngược lại với dcc là ra dcp khi trục của 2 phần tử trên dcp và dcc sẽ thay đổi
			* theo chiều ngang khác phía nhau
			*/

		}
	}
	return 1;
	//cách 2: cách này đi ngược lại điều kiện với đường chéo chính 
	/*for (i = 0; i < a.n; i++) {
		for (j = 0; j < a.n; j++) {
			if (a.list[i][j] != a.list[j][i])
				return 1;
		}
	}
	return 0;*/
}

int main()
{
	MTV a;
	int x;
	Nhap_MTV(a);
	Xuat_MTV(a);
	Tong_Hai_MT(a);
	cout << "\n Nhap Gia Tri x: ";
	cin >> x;
	cout << "\n ========================================================== ";

	Tim_DCC(a);
	cout << "\n ========================================================== ";

	Tim_DCP(a);
	cout << "\n ========================================================== ";

	cout << "\n Tong 2 Duong Cheo Trong Ma Tran Vuong La: " << Sum_Diagonal(a);
	cout << "\n ========================================================== ";

	Under_triangle(a);
	cout << "\n ========================================================== ";

	Top_Triangle(a);

	cout << "\n ========================================================== ";
	under_triangle_sec(a);

	cout << "\n ========================================================== ";
	top_triangle_sec(a);

	cout << "\n ========================================================== ";
	tim_x(a, x);

	cout << "\n ========================================================== ";
	Xuat_PT_DCC(a, x);

	cout << "\n ========================================================== ";
	Xuat_PT_DCP(a, x);

	cout << "\n ========================================================== ";
	if (Max_DCC(a) > Max_DCP(a))
	{
		cout << "\n So Lon Nhat Tren Duong Cheo Chinh va Phu: " << Max_DCC(a) << endl;
	}
	else {
		cout << "\n So Lon Nhat Tren Duong Cheo Chinh va Phu: " << Max_DCP(a) << endl;
	}
	Tim_PT_Alone(a);
	cout << "\n ========================================================== ";
	Xuat_MT_SNT(a);
	cout << "\n ========================================================== ";
	Tim_MT_Chuyen_Vi(a);
	cout << "\n ========================================================== ";
	if (MT_Don_Vi(a) == 1) {
		cout << "\n Day La Ma Tran Don Vi ";
	}
	else
	{
		cout << "\n Day Ko Phai La Ma Tran Don Vi ";
	}
	cout << "\n ========================================================== ";
	Xuat_MT_Don_Vi(a);
	cout << "\n ========================================================== ";
	if (check_MT_Doi_Xung(a) == 1) {
		cout << "\n Ma Tran Nay Doi Xung Nhau ";
	}
	else {
		cout << "\n Ma Tran Nay KHONG Doi Xung Nhau ";
	}
	cout << "\n ========================================================== ";
	cout << "\n Tong  Ma Tran A La: " << Tong_A(a) << endl;

	cout << "\n ========================================================== ";
	cout << "\n Tong  Ma Tran BLa: " << Tong_B(b) << endl;

	cout << "\n ========================================================== ";
	cout << "\n Tong Hai Ma Tran A va B La: " << Tong_A(a) + Tong_B(b) << endl;

	cout << "\n ========================================================== ";
	Tong_Hai_MT(a);

	cout << "\n ========================================================== ";
	MT_Hoan_Doi(a);

	cout << "\n ========================================================== ";
	if (check_MT_Doi_Xung_DCP(a) == 1) {
		cout << "\n Ma Tran Nay Doi Xung Nhau Qua Duong Cheo Phu ";
	}
	else {
		cout << "\n Ma Tran Nay KHONG Doi Xung Nhau Qua Duong Cheo Phu ";
	}

	return 0;
}