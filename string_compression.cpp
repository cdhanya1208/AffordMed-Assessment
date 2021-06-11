#include<iostream>
#include<string>
using namespace std;
class Codec{
	public:
		char* compress(string input_string){
			int string_len = input_string.size();
			char *compressed_string = new char();
			compressed_string[0]=input_string[0];
			int count = 1,j=0;
			for(int i=1;i<string_len;i++){
				if(input_string[i-1]==input_string[i]){
					++count;
				}
				else{
					if(count!=1){
					compressed_string[++j] = count +'0';
					compressed_string[++j] =input_string[i];
					count = 1;
				    }
				    else if(count==1){
				    	compressed_string[++j]=input_string[i];
		
					}
				}
			}
			if(count>1){
			compressed_string[++j]=count + '0';
		    }
			return compressed_string;
		}
		char* decompress(string str){
			int len = str.size();
			char* new_str = new char();
			int j=0;
			for(int i=0;i<len;i++){
				int temp = int(str[i]);
				if((temp>=97&&temp<=122)||(temp>=65&&temp<=90)){
					new_str[j++]=str[i];
				}
				else{
					int num = temp-'0';
					for(int k=1;k<num;k++)
					{
						new_str[j++]=str[i-1];
					}
				}
			}
			return new_str;
		}
}obj;
int main(){
	 char *input_string = new char();
	 cin>>input_string;
	 char *comp_string = new char();
	 comp_string = obj.compress(input_string);
	 cout<<comp_string<<"\n";
	 cout<<obj.decompress(comp_string);
	return 0;
}
