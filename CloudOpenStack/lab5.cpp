
#include <iostream>  
#include <cmath>  
#include <iomanip> 
#include <vector>
#include <fstream>


const double p = 3.14159;
const double Ro = 500; // PLOTNOST MATERIA
const double g = 9.80665;; // gravity acceleration
const double Lfarad = p / 6.0; //UGOL POVOROT
const double H = 0.25; //H_CONUS
const double Rog = 1000.0; // PLOTNOST VECHECTVA
const double Fk = 15.0; // KOEF SOPROT
const double t0 = .0; //start time
const double t1 = 10.0;//end time
const int shagovN = 5000;
const double shag_time = (t1 - t0) / (double)shagovN;
const double m = (p / 3.0) * Ro * pow(tan(Lfarad), 2) * pow(H, 3); //MASS 
const double h0 = H * pow(Ro / Rog, 1.0 / 3.0);

double x[5000]; //peremesh
double v[5000]; //skorost
double t[5000]; //vrem
double a[5000]; //uskoren

using namespace std; 

double formula(double x, double v)
{
	double c = p * pow(tan(Lfarad), 2) * pow(h0 - x, 2) / m *(Rog * (h0 - x) * g / 3.0 - Fk * v / sin(Lfarad)) - g;
	return c;
}
int func1()
{
	for (int i = 0; i < shagovN; i++)
	{
		t[i] = i * shag_time;
	}
	
	x[0] = 0.05;
	

	v[0] = 0.;
	a[0] = formula(x[0], v[0]);

	ofstream xf;
	ofstream vf;
	ofstream tf;
	xf.clear();
	vf.clear();
	tf.clear();
	xf.open("xf1.csv");
	vf.open("vf1.csv");
	tf.open("tf1.csv");

	xf << x[0] << "\n";
	vf << v[0] << "\n";
	tf << t[0] << "\n";

	cout << "x=0.5" << endl;
	cout << t[0] << " " << v[0] << " " << x[0] << endl;
	for (int i = 1; i < shagovN; i++)
	{
		
		x[i] = x[i - 1] + shag_time * v[i - 1];
		v[i] = v[i - 1] + shag_time * a[i - 1];

		a[i] = formula(x[i], v[i]);

		xf << x[i] << "\n";
		vf << v[i] << "\n";
		tf << t[i] << "\n";
		
		cout << t[i] << " " << v[i] << " " << x[i] << endl;
		
	}

	xf.close();
	vf.close();
	tf.close();

	return 0;
}
int func2()
{
	for (int i = 0; i < shagovN; i++)
	{
		t[i] = i * shag_time;
	}
	
	x[0] = 0.1;
	

	v[0] = 0.;
	a[0] = formula(x[0], v[0]);

	ofstream xf;
	ofstream vf;
	ofstream tf;
	xf.clear();
	vf.clear();
	tf.clear();
	xf.open("xf2.csv");
	vf.open("vf2.csv");
	tf.open("tf2.csv");

	xf << x[0] << "\n";
	vf << v[0] << "\n";
	tf << t[0] << "\n";

	cout << "x=0.1" << endl;
	cout << t[0] << " " << v[0] << " " << x[0] << endl;
	for (int i = 1; i < shagovN; i++)
	{
		
		x[i] = x[i - 1] + shag_time * v[i - 1];
		v[i] = v[i - 1] + shag_time * a[i - 1];

		a[i] = formula(x[i], v[i]);
		
		cout << t[i] << " " << v[i] << " " << x[i] << endl;

		xf << x[i] << "\n";
		vf << v[i] << "\n";
		tf << t[i] << "\n";
	}

	xf.close();
	vf.close();
	tf.close();

	return 0;
}
int func3()
{
	for (int i = 0; i < shagovN; i++)
	{
		t[i] = i * shag_time;
	}

	x[0] = 0.15;


	v[0] = 0.;
	a[0] = formula(x[0], v[0]);

	ofstream xf;
	ofstream vf;
	ofstream tf;
	xf.clear();
	vf.clear();
	tf.clear();
	xf.open("xf3.csv");
	vf.open("vf3.csv");
	tf.open("tf3.csv");

	xf << x[0] << "\n";
	vf << v[0] << "\n";
	tf << t[0] << "\n";

	cout << "x=0.15" << endl;
	cout << t[0] << " " << v[0] << " " << x[0] << endl;
	for (int i = 1; i < shagovN; i++)
	{
	
		x[i] = x[i - 1] + shag_time * v[i - 1];
		v[i] = v[i - 1] + shag_time * a[i - 1];

		a[i] = formula(x[i], v[i]);
		
		cout << t[i] << " " << v[i] << " " << x[i] << endl;


		xf << x[i] << "\n";
		vf << v[i] << "\n";
		tf << t[i] << "\n";
	}

	xf.close();
	vf.close();
	tf.close();

	return 0;
}
int main()
{
	cout << "t" << " " << "v" << " " << "x" << endl;
	func1();
	func2();
	func3();
	return 0;
}
