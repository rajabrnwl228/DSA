// M-1
string replaceSpaces(string &str){
	// Write your code here.
	string t="";
	int n=str.size();
	for(int i=0;i<n;i++){
		if(str[i]==' '){
			t.push_back('@');
			t.push_back('4');
			t.push_back('0');
		}else
		t.push_back(str[i]);
	}
	return t;
}
// M-2
string replaceSpaces(string &str){
	// Write your code here.
	int n=str.size();
	for(int i=0;i<n;i++){
		if (str[i] == ' ') {
			str.push_back('@');
			str.push_back('@');
		}
    }
	int lt=str.size()-1;
	n--;
	while(n>=0){
		if(str[n]==' '){
			str[lt--]='0';
			str[lt--]='4';
			str[lt--]='@';
            }
		 else {
            str[lt--] = str[n];
            }
			n--;
        }
	return str;
}