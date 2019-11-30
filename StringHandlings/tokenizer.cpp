changes ... 
changes 2 

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

//https://wiki.kldp.org/HOWTO/html/C++Programming-HOWTO/standard-string.html

void Tokenize(const string &str, vector<string> &tokens,
              const string& delimiters=" "){
    ssize_t lastPos = str.find_first_not_of(delimiters, 0);
    ssize_t   pos = str.find_first_of(delimiters, lastPos);
    
    cout << sizeof(size_t) << endl;
    cout << sizeof(ssize_t) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(pos) << endl;

    while (string::npos != pos || string::npos != lastPos)
    {
       
        // token을 찾았으니 vector에 추가한다
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // 구분자를 뛰어넘는다.  "not_of"에 주의하라
        lastPos = (int)str.find_first_not_of(delimiters, pos);
        // 다음 구분자가 아닌 글자를 찾는다
        pos = (int)str.find_first_of(delimiters, lastPos);
    }
}

void printFrequency(string st)
{
    // each word it mapped to it's frequency
    map<string, int> FW;
    stringstream ss(st); // Used for breaking words
    string Word; // To store individual words
    
    while (ss >> Word)
        FW[Word]++;
    
    map<string, int>::iterator m;
    for (m = FW.begin(); m != FW.end(); m++)
        cout << m->first << " -> "
        << m->second << "\n";
    cout << endl;
}

int main()
{
    /*
    string s("  the sky is blue and the sun is   yellow");
    cout << s << endl;
    vector<string> tokens;
    
    stringstream ss(s);
    string buf;
    while(ss >> buf)
        tokens.push_back(buf);
    
    copy(tokens.begin(), tokens.end(), ostream_iterator<string>(cout, ", "));
    cout << "\n" << endl;
    cout << tokens.size() << endl;
    
    printFrequency(s);
    */
    // https://www.geeksforgeeks.org/stringstream-c-applications/
    //https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=220245263973&proxyReferer=https%3A%2F%2Fwww.google.com%2F
    
    
    string s("the.sky.is.blue.and.the.sun.is.yellow");
    cout << s << endl;
    vector<string> tokens;

    /*
    ssize_t pos;
    if ((pos=s.find("sky"))!=string::npos){
        cout << "found" << "\n";
        cout <<pos << endl;
    }
    */
    
    
    
    
    
    Tokenize(s, tokens, ".");

    reverse(tokens.begin(),tokens.end());
    
    string str="";
    for(int i=0;i<tokens.size() ; ++i){
        str +=tokens[i];
        if(i!=tokens.size()-1){
            str +=".";
        }
    }

    cout << str << endl;
    
    
    
    
    
    return 0;
}

