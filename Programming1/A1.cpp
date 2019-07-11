#include <bits/stdc++.h>

using namespace std;

string subtraction(string n1, string n2) 
{  
    if (n1.length() < n2.length() or (n1.length() == n2.length() and n1 < n2)) 
        return "-" + subtraction(n2, n1); 
   
    string res = ""; 
   
    int nd1 = n1.length(), nd2 = n2.length(); 
    
    int carry = 0; 
  
    for (int i=0; i < nd1; i++) 
    {  
        int sub = ((n1[nd1 - i - 1]-'0') - 
                   (i < nd2 ? n2[nd2 - i - 1]-'0' : 0) - 
                   carry); 

        if (sub < 0) 
        { 
            sub = sub+10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        res.insert(res.begin(), sub + '0'); 
    } 

    return res;
}

string addition(string n1, string n2){

	if (n1.length() < n2.length()) return addition(n2, n1);

	string res = ""; 
   
    int nd1 = n1.length(), nd2 = n2.length(); 
  
    int carry = 0; 
  
    for (int i=0; i < nd1; i++) 
    {  
        int sum = ((n1[nd1 - i - 1]-'0') + 
                   (i < nd2 ? n2[nd2 - i - 1]-'0' : 0) + 
                   carry); 

        if (sum >= 10) 
        { 
            sum = sum-10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        res.insert(res.begin(), sum + '0'); 
    } 

    if (carry == 1) res.insert(res.begin(), '1');

    return res;	
}

string multiplication(string n1, string n2){

	int nDigits1 = n1.length(), nDigits2 = n2.length();

	if (nDigits1 != nDigits2 or (nDigits1%2 != 0 and nDigits1 > 1)) return "";

	if (n1.length() == 1) return to_string((n1[0] - '0') * (n2[0] - '0')); 

	string a = n1.substr(0, nDigits1/2), b = n1.substr(nDigits1/2, nDigits1/2);
	string c = n2.substr(0, nDigits1/2), d = n2.substr(nDigits1/2, nDigits1/2);
		
	string ac = multiplication(a, c) + string(nDigits1, '0');
	string bd = multiplication(b, d);
	string ad = multiplication(a, d);
	string bc = multiplication(b, c);
	string ad_bc = addition(ad, bc) + string(nDigits1/2, '0');

	return addition(addition(ac, ad_bc), bd);
}

int main(){

	cout << multiplication("3141592653589793238462643383279502884197169399375105820974944592", "2718281828459045235360287471352662497757247093699959574966967627") << endl;
	return 0;
}
