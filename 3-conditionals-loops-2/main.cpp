#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	const int MaxIter = 500;
	double y,xn,xk,dx,T, eps;
	int n;
	const double keps = 1e-15;
	cout << "Enter value |xn|<1: ";
	cin >> xn;
	cout << "Enter value |xk|<1: ";
	cin >> xk;
	cout << "Enter value dx: ";
	cin >> dx;
	cout << "Enter value accuracy ers!=0 : ";
	cin >> eps;
	if ((abs(xn) >= 1) || (abs(xk) >= 1) || (abs(dx) < eps) || (abs(eps) < keps)) {
		cout << "\t\ERROR IN THE VALUES OF VARIABLES\t\ "<<endl;
		cout << "\t\NEED: |xn|<1 , |xk|<1 , eps>0 , |dx|>=eps "<<endl;
	}	else{
		cout << "|\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4|\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4|\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4|\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4|" << endl;
		cout << "|" << setw(6) << "x" << setw(3) << "|" << setw(11) << "F" <<setw(3)<<"|"<<setw(11)<<"T"<<setw(3) << "|" << setw(6) << "ITER" << setw(3) << "|" << endl;
		cout << "|\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4|\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4|\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4|\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4|" << endl;













	}
	//long double ln = 1, y = ln;
	//for ( n = 0; fabs(ln) > eps; n++) {
		//ln *= (pow(x, 2)*(2 * n + 1)) / (2 * n + 3);
		//y += 2*ln;
		//if (n > MaxIter) {
			//cout << "The series diverges!";
		//	break;
		//}
		//if (n< maxIter) {
		//	cout << "Function value "<<y<<"for x ="<<x<<endl;
		//	cout << "calculated after "<< n+1 << "iteration"<<endl;
		//}
	//}



	return 0;
}
