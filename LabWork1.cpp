//
// Created by hamza on 1/29/2019.
//
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
    int noOfMonths;
    double loanAmount;
    double monthlyRate;
    double numonator;
    double denominator;
    double monthPaymentAmount=0;
    double paidBack;
    double interestPaid;
    cout << setprecision(2) << fixed << showpoint;
    cout<< "Enter the loan amount:"<<endl;
    cin>>loanAmount;
    cout<< "Enter the monthly interest rate (%):"<<endl;
    cin>> monthlyRate;
    monthlyRate = monthlyRate/100;
    cout<<"Enter the number of months:"<<endl;
    cin>>noOfMonths;
    numonator = (loanAmount * monthlyRate);
    denominator = 1-pow((1+monthlyRate),noOfMonths*-1);
    monthPaymentAmount = numonator/denominator;
    cout << "----------------------" << endl;
    cout<< "          Loan amount: $"<<loanAmount<<endl;
    monthlyRate = monthlyRate*100;
    cout<< "Monthly interest rate:"<<monthlyRate<<"%"<<endl;
    cout<< "   Number of payments: "<< noOfMonths<<endl;
    cout<<"      Monthly Payment: $"<<monthPaymentAmount<<endl;
    paidBack = monthPaymentAmount*noOfMonths;
    cout<<"     Amount paid back: $"<<paidBack<<endl;
    interestPaid = paidBack - loanAmount;
    cout <<"        Interest paid: $"<<interestPaid<<endl;
    cout << "----------------------" << endl;
}


