#include<bits/stdc++.h>
using namespace std;


bool solve1(string &s){
	if(s.length() == 0){	
		return false;
	}
	
	if(s[0] == 'b'){
		return false;
	}
	
	
	bool flagA = true;
	for(int i=0;i<s.length();i++){
		if(s[i] == 'b'){
			flagA = false;
		}
		
		if(s[i] == 'a' && !flagA){
			return false;
		}
	}
	return true;

}


bool solve2(string &s){
	if(s.length() < 2){
		return false;
	}
	

	
	int n = s.length();
	
	if((s[n-1] == 'a' && s[n-2] == 'a') || (s[n-1] == 'b' && s[n-2] == 'b')){
		return true;
	}
	
	return false;

}

	
bool solve3(string &s){
	int countA = 0;
	int countB = 0;
	for(char c: s){
		if(c =='a'){
			countA++;
		}
		
		if(c == 'b'){
			countB++;
		}
	}
	
	if(((countA - countB)%4)==0){
		return true;
	}
	
	return false;
	
}


bool solve4(string&s){

	if(s.length() < 3){
		return false;
	}
	
	if(s[0] == 'b' ){
		return false;
	}
	
	if(s.substr(s.length() - 3) == "abb"){
		return true;
	}
	
	return false;
}

	
		
int main(){
	string s;
	cin>>s;
	
	
	for(auto c: s){
		if(c!='a' && c!='b'){
			cout<<"Not accepted"<<endl;
			return false;
		}
	}
	bool ans1 = solve1(s);
	cout<<ans1<<endl;
	
	
	bool ans2 = solve2(s);
	cout<<ans2<<endl;
	
	
	bool ans3 = solve3(s);
	cout<<ans3<<endl;
	
	bool ans4 = solve4(s);
	cout<<ans4<<endl;
	return 0;
}
