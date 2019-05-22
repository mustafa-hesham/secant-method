//This code is written by Mustafa Hesham Mohamed to find the root of a function using Secant method.
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
using namespace std;
int main(){
	double xi1, xi, xi2, xdiff,accerror, apperror, resultxi, resultxi1;
	double e = 2.71828;
	string xe;
	int n, ite, iten;
	cout<<"Please enter number of terms: "<<endl;
	cin>>n;
	double coeff[n];
	double power[n];
	double xcoeff[n];
	string termtype[n];
	char xtrig;
	cout<<"Please enter Xi-1: "<<endl;
	cin>>xi1;
	cout<<"Please enter Xi: "<<endl;
	cin>>xi;
	
	for (int i=0; i<n; i++) {
		cout<<"Please enter coefficient number "<<i+1<<" (Enter 1 if it is a trigonometric function term)"<<endl;
		cin>>coeff[i];
		cout<<"Please enter power number "<<i+1<<" (Enter x if it is the power of the a number, or a trigonometric function, or e for euler number):"<<endl;
		cin>>xe;
		if(xe == "x") {
			coeff[i] = 1;
			termtype[i] ="pownum";
			cout <<"Please enter the number: "<<endl;
			cin>>power[i];
			cout <<"Please enter coefficient of x: "<<endl;
			cin>>xcoeff[i];
		}
		else if(xe =="e"){
			termtype[i] = "euler";
			power[i] = e;
			cout <<"Please enter coefficient of x: "<<endl;
			cin>>xcoeff[i];
		}
		else if(xe == "sin") {
			coeff[i] = 1;
			termtype[i] ="sin";
			cout <<"Please enter the power of sin x: "<<endl;
			cin>>power[i];
			cout <<"Please enter coefficient of sin x (Enter x if the term is x sin(x)): "<<endl;
			cin>>xtrig;
			if(xtrig == 'x'){
				termtype[i] = "xsin";
				cout <<"Please enter coefficient of x sin x: "<<endl;
				cin>>xcoeff[i];
			}
			else xcoeff[i] = xtrig - 48;
		}
		else if(xe == "cos") {
			coeff[i] = 1;
			termtype[i] ="cos";
			cout <<"Please enter the power of cos x: "<<endl;
			cin>>power[i];
			cout <<"Please enter coefficient of cos x (Enter x if the term is x cos(x)): "<<endl;
			cin>>xtrig;
			if(xtrig == 'x'){
				termtype[i] = "xcos";
				cout <<"Please enter coefficient of x cos x: "<<endl;
				cin>>xcoeff[i];
			}
			else xcoeff[i] = xtrig - 48;
		}
		else if(xe == "tan") {
			coeff[i] = 1;
			termtype[i] ="tan";
			cout <<"Please enter the power of tan x: "<<endl;
			cin>>power[i];
			cout <<"Please enter coefficient of tan x (Enter x if the term is x tan(x)): "<<endl;
			cin>>xtrig;
			if(xtrig == 'x'){
				termtype[i] = "xtan";
				cout <<"Please enter coefficient of x tan x: "<<endl;
				cin>>xcoeff[i];
			}
			else xcoeff[i] = xtrig - 48;
		}
		else{
			termtype[i] = "reg";
			istringstream iss (xe);
			iss>>power[i];
			xcoeff[i] = 0;
		}
		
	}
	
	cout<<"Please enter the accepted error (percent): "<<endl;
	cin>>accerror;
	
	cout<<"Please enter maximum number iterations: "<<endl;
	cin>>ite;
	
	for (int i=0; i<ite; i++){
		
		resultxi1  = 0;
		resultxi   = 0;
		xdiff =  xi1 - xi;
		for (int s=0; s<n; s++){
			if (power[s] == e && termtype[s] =="euler"){
				resultxi1 += coeff[s] * pow(power[s], (xi1*xcoeff[s]));
				resultxi  += coeff[s] * pow(power[s], (xi *xcoeff[s]));
			}
			
			if(power[s] != e && termtype[s] =="reg"){
			
			resultxi1 += coeff[s] * pow(xi1, power[s]);
			resultxi  += coeff[s] * pow(xi,  power[s]);
			
			}
			if(termtype[s] =="pownum"){
			
			resultxi1 += pow(power[s], (xcoeff[s]*xi1));
			resultxi  += pow(power[s], (xcoeff[s]*xi));
			
			}
			if (termtype[s] == "sin"){
			resultxi1 += coeff[s] * pow(xcoeff[s]*sin(xi1), power[s]);
			resultxi  += coeff[s] * pow(xcoeff[s]*sin(xi), power[s]);
			
			}
			if (termtype[s] == "xsin"){
	
			resultxi1 += coeff[s] * pow(xcoeff[s]*xi1*sin(xi1), power[s]);
			resultxi  += coeff[s] * pow(xcoeff[s]*xi*sin(xi), power[s]);
			
			}
			if (termtype[s] == "cos"){
			resultxi1 += coeff[s] * pow(xcoeff[s]*cos(xi1), power[s]);
			resultxi  += coeff[s] * pow(xcoeff[s]*cos(xi), power[s]);
			
			}
			if (termtype[s] == "xcos"){
	
			resultxi1 += coeff[s] * pow(xcoeff[s]*xi1*cos(xi1), power[s]);
			resultxi  += coeff[s] * pow(xcoeff[s]*xi*cos(xi), power[s]);
			
			}
				if (termtype[s] == "tan"){
			resultxi1 += coeff[s] * pow(xcoeff[s]*tan(xi1), power[s]);
			resultxi  += coeff[s] * pow(xcoeff[s]*tan(xi), power[s]);
			
			}
			if (termtype[s] == "xtan"){
	
			resultxi1 += coeff[s] * pow(xcoeff[s]*xi1*tan(xi1), power[s]);
			resultxi  += coeff[s] * pow(xcoeff[s]*xi*tan(xi), power[s]);
			
			}
			}
			
		
		xi2 = xi - (resultxi*xdiff/(resultxi1-resultxi));
		
	
			apperror = (xi2 - xi)*100/xi2;
			if(apperror<0) apperror *= -1;
			cout <<"The f(Xi-1) is "<<resultxi1<<endl;
			cout <<"The f(Xi) is "<<resultxi<<endl;
			cout <<"The Xi+1 is "<<xi2<<endl;
			cout <<"The relative error is "<<apperror<<endl;
			cout<<"----------------------------"<<endl;
	
		xi1 = xi;
		xi  = xi2;
		iten = i+1;
		if (accerror>apperror){
			
			i = ite+2;
		}	
	}
	
	cout <<"Number of iterations is "<<iten<<endl;
	cout <<"The root of this function is: "<<xi2<<endl;
		return 0;
}
