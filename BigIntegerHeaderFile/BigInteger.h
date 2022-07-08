
// Header file for Big Integers

//  function ->
//      add        -> performs addition of two big integers
//      sub        -> performs subtraction of two big integers
//      maxInteger -> finds the maximun out of two big integers


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;



string add(string num1,string num2){
    vector<int> vec1;
    vector<int> vec2;
    vector<int> result;
// storing the numbers in a vector
    for(int i = num1.size()-1;i>=0;i--){
        vec1.push_back(num1[i]-'0');
    }
    
    for(int i = num2.size()-1;i>=0;i--){
        vec2.push_back(num2[i]-'0');
    }

    int len = min(vec1.size(),vec2.size());

    int ans = 0;
    int carry = 0;

    for(int i = 0;i<=len-1;i++){
        ans = vec1[i]+vec2[i];
        ans += carry;
        carry = ans/10;
        result.push_back(ans%10);
    }

//  adding the trailing digits into the result vector
    if(vec1.size()>len){
        for(int i = len;i<vec1.size();i++){
            ans = vec1[i];
            ans += carry;
            carry = ans/10;
            result.push_back(ans%10);
        }
        
    }

    if(vec2.size()>len){
        for(int i = len;i<vec2.size();i++){
            ans = vec2[i];
            ans += carry;
            carry = ans/10;
            result.push_back(ans%10);
        }
         
    }


    while(carry){
        result.push_back(carry%10);
        carry = carry/10;
    }

    string answer;
    for(int i = result.size()-1;i>=0;i--){
        answer.push_back(result[i]+'0');
    }

    return answer;

}


string sub(string num1,string num2){  //num1 - num2
    string answer;
    //checking if we will have negative sign in our answer;
    int large = 0;
    if(num1.size() == num2.size()){
        for(int i=0;i<num1.size();i++){
            if((num1[i]-'0') < (num2[i]-'0')){
                answer.push_back('-');
                large = 2;
                break;
            }else if((num1[i]-'0') > (num2[i]-'0')){
                large = 1;
                break;
            }else{
                continue;
            }
        }


        if(large == 0){
            answer.push_back('0');
            return answer;
        }

    }else{
        if(num1.size() < num2.size()){
            answer.push_back('-');
            large = 2;
        }else{
            large = 1;
        }
    }

    vector<int> vec1;
    vector<int> vec2;
    vector<int> result;

    if(large == 1){
        for(int i = num1.size()-1;i>=0;i--){
            vec1.push_back(num1[i]-'0');
        }
        
        for(int i = num2.size()-1;i>=0;i--){
            vec2.push_back(num2[i]-'0');
        }
    }else{
        for(int i = num2.size()-1;i>=0;i--){
            vec1.push_back(num2[i]-'0');
        }
        
        for(int i = num1.size()-1;i>=0;i--){
            vec2.push_back(num1[i]-'0');
        }
    }

    int ans = 0;
    int carry = 0;
    int len = vec2.size();

    for(int i = 0;i<=len-1;i++){
        if(vec1[i] < vec2[i]){
            vec1[i-1]--;
            result.push_back(10+vec1[i]-vec2[i]);
        }else{
            result.push_back(vec1[i] - vec2[i]);    
        }
    }

   
    for(int i = len;i<vec1.size();i++){
        result.push_back(vec1[i]);
    }


    for(int i = result.size() - 1 ;i >= 0;i--){
        answer.push_back(result[i] + '0');
    }

    return answer;
}



string maxInteger(string num1,string num2){
    
    string answer;

    if(num1.size() == num2.size()){
        for(int i=0;i<num1.size();i++){
            if((num1[i]-'0') < (num2[i]-'0')){
                return num2;
            }else if((num1[i]-'0') > (num2[i]-'0')){
                return num1;
            }else{
                continue;
            }
        }

        // if both the numbers are equal then we can return either num1 or num2;
        return num1;
    }if(num1.size() > num2.size()){
        return num1;
    }else{
        return num2;
    }
    

    
}